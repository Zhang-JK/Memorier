#include "signupwindow.h"
#include "tools.h"
#include "ui_signupwindow.h"

#include <QMessageBox>
#include <QtSql>

SignUpWindow::SignUpWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::SignUpWindow)
{
    ui->setupUi(this);
    setWindowTitle("SignUp");
    setFixedSize(600, 350);
    connect(ui->submitButton, SIGNAL(clicked()), this, SLOT(inputValidator()));
}

SignUpWindow::~SignUpWindow()
{
    delete ui;
}

void SignUpWindow::inputValidator()
{
    ui->errorMsg->clear();
    QString username = ui->usernameInput->text();
    QString password1 = ui->passwordInput1->text();
    QString password2 = ui->passwordInput2->text();

    if (username == "")
    {
        ui->errorMsg->setText("Username can not be empty");
        ui->errorMsg->setAlignment(Qt::AlignCenter);
        return;
    }

    if (password1 == "" || password2 == "")
    {
        ui->errorMsg->setText("Password can not be empty");
        ui->errorMsg->setAlignment(Qt::AlignCenter);
        return;
    }

    if (password1.length() < 6)
    {
        ui->errorMsg->setText("Password must be longer than 5 charaters");
        ui->errorMsg->setAlignment(Qt::AlignCenter);
        return;
    }

    if (password1 != password2)
    {
        ui->errorMsg->setText("The password entries are inconsistent!");
        ui->errorMsg->setAlignment(Qt::AlignCenter);
        return;
    }

    QSqlQuery query;
    QString sqlQuery = QString("SELECT id FROM account WHERE username = '%1'").arg(username);
    qDebug() << "Generated sql: " << sqlQuery;
    if (!query.exec(sqlQuery))
        qDebug() << "Query Error: " << query.lastError().driverText();
    if (query.next())
    {
        ui->errorMsg->setText("Username has been occupied!");
        ui->errorMsg->setAlignment(Qt::AlignCenter);
        return;
    }

    //if valid
    if (updateUserData(username, password1))
    {
        int id = 0;
        QString sqlQueryId = QString("SELECT id FROM account WHERE username = '%1'").arg(username);
        qDebug() << "Generated sql: " << sqlQueryId;
        if (!query.exec(sqlQueryId))
            qDebug() << "Query Error: " << query.lastError().driverText();
        if (query.next())
            id = query.value(query.record().indexOf("id")).toInt();
        InsertLog(id, "Sign Up");
        if (!(QMessageBox::information(this, tr("Success"), tr("Sign up successfully!\nPlease click continue to log in."), tr("Continue"))))
        {
            this->close();
            emit sendLoginInfo(username, id);
        }
    }
    else
    {
        if (!(QMessageBox::information(this, tr("Failed"), tr("Sign up failed!\nClick continue to try again."), tr("Continue"))))
        {
            ui->errorMsg->clear();
            ui->usernameInput->clear();
            ui->passwordInput1->clear();
            ui->passwordInput2->clear();
        }
    }
}

bool SignUpWindow::updateUserData(QString username, QString password)
{
    QString salt = getRandomString(32);
    uint hashPassword = qHash(password + salt);
    QSqlQuery update;
    QString sqlUpdate = QString("INSERT INTO account (username,password,salt,create_at) VALUES ('%1','%2','%3','%4')")
                            .arg(username)
                            .arg(hashPassword)
                            .arg(salt)
                            .arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
    qDebug() << "Generated sql: " << sqlUpdate;
    if (!update.exec(sqlUpdate))
    {
        qDebug() << "Update Error: " << update.lastError().driverText();
        return false;
    }
    return true;
}
