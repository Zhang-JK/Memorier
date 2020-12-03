/********************************************************************************
** Form generated from reading UI file 'signupwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNUPWINDOW_H
#define UI_SIGNUPWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SignUpWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *usernameLable;
    QLineEdit *usernameInput;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *passwordLable;
    QVBoxLayout *verticalLayout;
    QLineEdit *passwordInput1;
    QLineEdit *passwordInput2;
    QPushButton *submitButton;
    QLabel *errorMsg;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SignUpWindow)
    {
        if (SignUpWindow->objectName().isEmpty())
            SignUpWindow->setObjectName(QString::fromUtf8("SignUpWindow"));
        SignUpWindow->resize(600, 350);
        QIcon icon;
        icon.addFile(QString::fromUtf8("images/icontest.png"), QSize(), QIcon::Normal, QIcon::Off);
        SignUpWindow->setWindowIcon(icon);
        SignUpWindow->setStyleSheet(QString::fromUtf8("background-color:rgb(114, 159, 207)"));
        centralwidget = new QWidget(SignUpWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 0, 471, 81));
        QFont font;
        font.setPointSize(29);
        label->setFont(font);
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(110, 70, 371, 71));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        usernameLable = new QLabel(horizontalLayoutWidget);
        usernameLable->setObjectName(QString::fromUtf8("usernameLable"));
        QFont font1;
        font1.setPointSize(20);
        usernameLable->setFont(font1);

        horizontalLayout->addWidget(usernameLable);

        usernameInput = new QLineEdit(horizontalLayoutWidget);
        usernameInput->setObjectName(QString::fromUtf8("usernameInput"));

        horizontalLayout->addWidget(usernameInput);

        horizontalLayoutWidget_2 = new QWidget(centralwidget);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(110, 150, 371, 121));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        passwordLable = new QLabel(horizontalLayoutWidget_2);
        passwordLable->setObjectName(QString::fromUtf8("passwordLable"));
        passwordLable->setFont(font1);

        horizontalLayout_2->addWidget(passwordLable);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        passwordInput1 = new QLineEdit(horizontalLayoutWidget_2);
        passwordInput1->setObjectName(QString::fromUtf8("passwordInput1"));
        passwordInput1->setEchoMode(QLineEdit::Password);

        verticalLayout->addWidget(passwordInput1);

        passwordInput2 = new QLineEdit(horizontalLayoutWidget_2);
        passwordInput2->setObjectName(QString::fromUtf8("passwordInput2"));
        passwordInput2->setEchoMode(QLineEdit::Password);

        verticalLayout->addWidget(passwordInput2);


        horizontalLayout_2->addLayout(verticalLayout);

        submitButton = new QPushButton(centralwidget);
        submitButton->setObjectName(QString::fromUtf8("submitButton"));
        submitButton->setGeometry(QRect(250, 280, 89, 25));
        errorMsg = new QLabel(centralwidget);
        errorMsg->setObjectName(QString::fromUtf8("errorMsg"));
        errorMsg->setGeometry(QRect(0, 305, 601, 20));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Fira Code"));
        font2.setPointSize(12);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(9);
        errorMsg->setFont(font2);
        errorMsg->setStyleSheet(QString::fromUtf8("color:rgb(239, 41, 41);\n"
"font: 75 12pt \"Fira Code\";"));
        SignUpWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(SignUpWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        SignUpWindow->setStatusBar(statusbar);

        retranslateUi(SignUpWindow);

        QMetaObject::connectSlotsByName(SignUpWindow);
    } // setupUi

    void retranslateUi(QMainWindow *SignUpWindow)
    {
        SignUpWindow->setWindowTitle(QCoreApplication::translate("SignUpWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("SignUpWindow", "Welcome to Use Memorier", nullptr));
        usernameLable->setText(QCoreApplication::translate("SignUpWindow", "Username:     ", nullptr));
        usernameInput->setText(QString());
        usernameInput->setPlaceholderText(QCoreApplication::translate("SignUpWindow", "Please enter username here", nullptr));
        passwordLable->setText(QCoreApplication::translate("SignUpWindow", "Password:      ", nullptr));
        passwordInput1->setText(QString());
        passwordInput1->setPlaceholderText(QCoreApplication::translate("SignUpWindow", "Please enter password here", nullptr));
        passwordInput2->setText(QString());
        passwordInput2->setPlaceholderText(QCoreApplication::translate("SignUpWindow", "Please enter password again", nullptr));
        submitButton->setText(QCoreApplication::translate("SignUpWindow", "Sign Up!", nullptr));
        errorMsg->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SignUpWindow: public Ui_SignUpWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUPWINDOW_H
