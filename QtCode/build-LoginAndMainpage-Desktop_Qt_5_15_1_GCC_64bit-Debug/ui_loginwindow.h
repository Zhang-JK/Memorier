/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWindow
{
public:
    QWidget *centralwidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *usernameLable;
    QLineEdit *usernameInput;
    QPushButton *submitButton;
    QLabel *label;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *passwordLable;
    QLineEdit *passwordInput;
    QLabel *errorMsg;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName(QString::fromUtf8("LoginWindow"));
        LoginWindow->resize(600, 350);
        QIcon icon;
        icon.addFile(QString::fromUtf8("images/icontest.png"), QSize(), QIcon::Normal, QIcon::Off);
        LoginWindow->setWindowIcon(icon);
        LoginWindow->setStyleSheet(QString::fromUtf8("background-color:rgb(114, 159, 207);"));
        centralwidget = new QWidget(LoginWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(120, 100, 371, 71));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        usernameLable = new QLabel(horizontalLayoutWidget);
        usernameLable->setObjectName(QString::fromUtf8("usernameLable"));
        QFont font;
        font.setPointSize(20);
        usernameLable->setFont(font);

        horizontalLayout->addWidget(usernameLable);

        usernameInput = new QLineEdit(horizontalLayoutWidget);
        usernameInput->setObjectName(QString::fromUtf8("usernameInput"));

        horizontalLayout->addWidget(usernameInput);

        submitButton = new QPushButton(centralwidget);
        submitButton->setObjectName(QString::fromUtf8("submitButton"));
        submitButton->setGeometry(QRect(250, 260, 89, 25));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 20, 471, 81));
        QFont font1;
        font1.setPointSize(29);
        label->setFont(font1);
        horizontalLayoutWidget_2 = new QWidget(centralwidget);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(120, 170, 371, 71));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        passwordLable = new QLabel(horizontalLayoutWidget_2);
        passwordLable->setObjectName(QString::fromUtf8("passwordLable"));
        passwordLable->setFont(font);

        horizontalLayout_2->addWidget(passwordLable);

        passwordInput = new QLineEdit(horizontalLayoutWidget_2);
        passwordInput->setObjectName(QString::fromUtf8("passwordInput"));
        passwordInput->setEchoMode(QLineEdit::Password);

        horizontalLayout_2->addWidget(passwordInput);

        errorMsg = new QLabel(centralwidget);
        errorMsg->setObjectName(QString::fromUtf8("errorMsg"));
        errorMsg->setGeometry(QRect(0, 300, 601, 21));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Fira Code"));
        font2.setPointSize(12);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(9);
        errorMsg->setFont(font2);
        errorMsg->setStyleSheet(QString::fromUtf8("color:rgb(239, 41, 41);\n"
"font: 75 12pt \"Fira Code\";"));
        LoginWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(LoginWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        LoginWindow->setStatusBar(statusbar);

        retranslateUi(LoginWindow);

        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QMainWindow *LoginWindow)
    {
        LoginWindow->setWindowTitle(QCoreApplication::translate("LoginWindow", "MainWindow", nullptr));
        usernameLable->setText(QCoreApplication::translate("LoginWindow", "Username:     ", nullptr));
        usernameInput->setText(QString());
        usernameInput->setPlaceholderText(QCoreApplication::translate("LoginWindow", "Please enter username here", nullptr));
        submitButton->setText(QCoreApplication::translate("LoginWindow", "Log In!", nullptr));
        label->setText(QCoreApplication::translate("LoginWindow", "Welcome to Use Memorier", nullptr));
        passwordLable->setText(QCoreApplication::translate("LoginWindow", "Password:      ", nullptr));
        passwordInput->setText(QString());
        passwordInput->setPlaceholderText(QCoreApplication::translate("LoginWindow", "Please enter password here", nullptr));
        errorMsg->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
