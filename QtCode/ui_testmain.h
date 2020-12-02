/********************************************************************************
** Form generated from reading UI file 'testmain.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTMAIN_H
#define UI_TESTMAIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_testMain
{
public:
    QWidget *centralwidget;
    QLabel *Fixlabel_1;
    QLabel *TxtTest;
    QPushButton *ButToday;
    QPushButton *ButSelf;
    QLabel *TxtInfo;
    QLabel *labelAll_3;
    QLabel *labelAll_4;

    void setupUi(QMainWindow *testMain)
    {
        if (testMain->objectName().isEmpty())
            testMain->setObjectName(QString::fromUtf8("testMain"));
        testMain->resize(600, 256);
        centralwidget = new QWidget(testMain);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Fixlabel_1 = new QLabel(centralwidget);
        Fixlabel_1->setObjectName(QString::fromUtf8("Fixlabel_1"));
        Fixlabel_1->setGeometry(QRect(0, 20, 591, 81));
        QFont font;
        font.setPointSize(35);
        Fixlabel_1->setFont(font);
        Fixlabel_1->setAlignment(Qt::AlignCenter);
        TxtTest = new QLabel(centralwidget);
        TxtTest->setObjectName(QString::fromUtf8("TxtTest"));
        TxtTest->setGeometry(QRect(270, 120, 301, 21));
        TxtTest->setAlignment(Qt::AlignCenter);
        ButToday = new QPushButton(centralwidget);
        ButToday->setObjectName(QString::fromUtf8("ButToday"));
        ButToday->setGeometry(QRect(320, 140, 181, 61));
        ButSelf = new QPushButton(centralwidget);
        ButSelf->setObjectName(QString::fromUtf8("ButSelf"));
        ButSelf->setGeometry(QRect(60, 140, 171, 61));
        TxtInfo = new QLabel(centralwidget);
        TxtInfo->setObjectName(QString::fromUtf8("TxtInfo"));
        TxtInfo->setGeometry(QRect(0, 120, 271, 20));
        TxtInfo->setAlignment(Qt::AlignCenter);
        labelAll_3 = new QLabel(centralwidget);
        labelAll_3->setObjectName(QString::fromUtf8("labelAll_3"));
        labelAll_3->setGeometry(QRect(280, 200, 271, 21));
        QFont font1;
        font1.setPointSize(8);
        labelAll_3->setFont(font1);
        labelAll_3->setAlignment(Qt::AlignCenter);
        labelAll_4 = new QLabel(centralwidget);
        labelAll_4->setObjectName(QString::fromUtf8("labelAll_4"));
        labelAll_4->setGeometry(QRect(10, 200, 271, 21));
        labelAll_4->setFont(font1);
        labelAll_4->setAlignment(Qt::AlignCenter);
        testMain->setCentralWidget(centralwidget);

        retranslateUi(testMain);

        QMetaObject::connectSlotsByName(testMain);
    } // setupUi

    void retranslateUi(QMainWindow *testMain)
    {
        testMain->setWindowTitle(QCoreApplication::translate("testMain", "MainWindow", nullptr));
        Fixlabel_1->setText(QCoreApplication::translate("testMain", "Test yourself every day!", nullptr));
        TxtTest->setText(QCoreApplication::translate("testMain", "TxtTest", nullptr));
        ButToday->setText(QCoreApplication::translate("testMain", "Today's tests", nullptr));
        ButSelf->setText(QCoreApplication::translate("testMain", "Self test", nullptr));
        TxtInfo->setText(QCoreApplication::translate("testMain", "TxtInfo", nullptr));
        labelAll_3->setText(QCoreApplication::translate("testMain", "We will choose some cards by Forgetting curve", nullptr));
        labelAll_4->setText(QCoreApplication::translate("testMain", "Begin a costomized testing", nullptr));
    } // retranslateUi

};

namespace Ui {
    class testMain: public Ui_testMain {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTMAIN_H
