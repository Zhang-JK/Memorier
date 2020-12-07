/********************************************************************************
** Form generated from reading UI file 'simpletest.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIMPLETEST_H
#define UI_SIMPLETEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_simpleTest
{
public:
    QWidget *centralwidget;
    QLabel *LabelTitle;
    QTextBrowser *Txt_Prob;
    QPushButton *ButYES;
    QPushButton *ButNO;
    QPushButton *ButSubmit;
    QTextEdit *Txt_Ans;

    void setupUi(QMainWindow *simpleTest)
    {
        if (simpleTest->objectName().isEmpty())
            simpleTest->setObjectName(QString::fromUtf8("simpleTest"));
        simpleTest->resize(664, 457);
        centralwidget = new QWidget(simpleTest);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        LabelTitle = new QLabel(centralwidget);
        LabelTitle->setObjectName(QString::fromUtf8("LabelTitle"));
        LabelTitle->setGeometry(QRect(20, 20, 131, 31));
        Txt_Prob = new QTextBrowser(centralwidget);
        Txt_Prob->setObjectName(QString::fromUtf8("Txt_Prob"));
        Txt_Prob->setGeometry(QRect(20, 60, 621, 192));
        ButYES = new QPushButton(centralwidget);
        ButYES->setObjectName(QString::fromUtf8("ButYES"));
        ButYES->setGeometry(QRect(20, 370, 201, 61));
        ButNO = new QPushButton(centralwidget);
        ButNO->setObjectName(QString::fromUtf8("ButNO"));
        ButNO->setGeometry(QRect(440, 370, 201, 61));
        ButSubmit = new QPushButton(centralwidget);
        ButSubmit->setObjectName(QString::fromUtf8("ButSubmit"));
        ButSubmit->setGeometry(QRect(230, 370, 201, 61));
        Txt_Ans = new QTextEdit(centralwidget);
        Txt_Ans->setObjectName(QString::fromUtf8("Txt_Ans"));
        Txt_Ans->setGeometry(QRect(20, 270, 621, 91));
        simpleTest->setCentralWidget(centralwidget);

        retranslateUi(simpleTest);

        QMetaObject::connectSlotsByName(simpleTest);
    } // setupUi

    void retranslateUi(QMainWindow *simpleTest)
    {
        simpleTest->setWindowTitle(QCoreApplication::translate("simpleTest", "MainWindow", nullptr));
        LabelTitle->setText(QCoreApplication::translate("simpleTest", "LableTitle", nullptr));
        ButYES->setText(QCoreApplication::translate("simpleTest", "ButYES", nullptr));
        ButNO->setText(QCoreApplication::translate("simpleTest", "ButNO", nullptr));
        ButSubmit->setText(QCoreApplication::translate("simpleTest", "ButSubmit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class simpleTest: public Ui_simpleTest {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIMPLETEST_H
