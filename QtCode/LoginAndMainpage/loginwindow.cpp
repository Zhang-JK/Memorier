#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "LoginInfo.h"

#include <QtSql>
#include <QMessageBox>

// set the ui and background
LoginWindow::LoginWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    ui->directLoginButton->setVisible(false);
    setWindowTitle("Login");
    setFixedSize(600, 350);
    connect(ui->submitButton, SIGNAL(clicked()), this, SLOT(inputValidator()));
    LoginInfo::readLoginInfo();
    if(LoginInfo::isLogin()) {
        ui->directLoginButton->setVisible(true);
        ui->directLoginButton->setText("Use " + LoginInfo::getUsername() + " to Log In");
        connect(ui->directLoginButton, SIGNAL(clicked()), this->parent(), SLOT(directLogin()));
        connect(ui->directLoginButton, SIGNAL(clicked()), this, SLOT(close()));
    }
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

// a validator for checking the user input
// and set the notice label for showing the mistake
void LoginWindow::inputValidator()
{
    ui->directLoginButton->setVisible(false);
    ui->errorMsg->clear();
    QString username = ui->usernameInput->text();
    QString password = ui->passwordInput->text();

    if (username == "")
    {
        ui->errorMsg->setText("Username can not be empty");
        ui->errorMsg->setAlignment(Qt::AlignCenter);
        return;
    }

    if (password == "")
    {
        ui->errorMsg->setText("Password can not be empty");
        ui->errorMsg->setAlignment(Qt::AlignCenter);
        return;
    }

    QSqlQuery query;
    uint hashPassword = 0;
    QString salt = "";
    int id = 0;
    QString sqlQuery = QString("SELECT id, password, salt FROM account WHERE username = '%1'").arg(username);
    qDebug() << "Generated sql: " << sqlQuery;
    if (!query.exec(sqlQuery))
    {
        qDebug() << "Query Error: " << query.lastError().driverText();
        ui->errorMsg->setText("Internal Error");
        ui->errorMsg->setAlignment(Qt::AlignCenter);
        return;
    }
    else
    {
        // QSqlRecord rec = query.record();
        if (query.next())
        {
            hashPassword = query.value(query.record().indexOf("password")).toUInt();
            salt = query.value(query.record().indexOf("salt")).toString();
            id = query.value(query.record().indexOf("id")).toInt();
        }
        else
        {
            ui->errorMsg->setText("Wrong Username or Password!");
            ui->errorMsg->setAlignment(Qt::AlignCenter);
            return;
        }
    }

    if (qHash(password + salt) != hashPassword)
    {
        ui->errorMsg->setText("Wrong Username or Password!");
        ui->errorMsg->setAlignment(Qt::AlignCenter);
        return;
    }

    if (!(QMessageBox::information(this, tr("Success"), tr("Log in successfully!\nPlease click continue."), tr("Continue"))))
    {
        this->close();
        emit sendLoginInfo(username, id);
    }
}
