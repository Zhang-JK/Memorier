/********************************************************************************
** Form generated from reading UI file 'addcardmain.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDCARDMAIN_H
#define UI_ADDCARDMAIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_addcardMain
{
public:
    QWidget *centralwidget;
    QLabel *Lable_1;
    QLabel *Lable_type;
    QTextEdit *Input_title;
    QLabel *Lable_title;
    QTextEdit *Input_prob;
    QLabel *Lable_prob;
    QLabel *Lable_ans;
    QTextEdit *Input_ans;
    QPushButton *Butconfirm;
    QPushButton *Butcancel;

    void setupUi(QMainWindow *addcardMain)
    {
        if (addcardMain->objectName().isEmpty())
            addcardMain->setObjectName(QString::fromUtf8("addcardMain"));
        addcardMain->resize(698, 372);
        centralwidget = new QWidget(addcardMain);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Lable_1 = new QLabel(centralwidget);
        Lable_1->setObjectName(QString::fromUtf8("Lable_1"));
        Lable_1->setGeometry(QRect(30, 30, 81, 31));
        Lable_1->setStyleSheet(QString::fromUtf8("font: 75 24pt \"Times New Roman\";"));
        Lable_type = new QLabel(centralwidget);
        Lable_type->setObjectName(QString::fromUtf8("Lable_type"));
        Lable_type->setGeometry(QRect(120, 30, 301, 31));
        Lable_type->setStyleSheet(QString::fromUtf8("font: 75 24pt \"Times New Roman\";"));
        Input_title = new QTextEdit(centralwidget);
        Input_title->setObjectName(QString::fromUtf8("Input_title"));
        Input_title->setGeometry(QRect(240, 80, 391, 41));
        Input_title->setStyleSheet(QString::fromUtf8("font: 75 18pt \"Times New Roman\";"));
        Lable_title = new QLabel(centralwidget);
        Lable_title->setObjectName(QString::fromUtf8("Lable_title"));
        Lable_title->setGeometry(QRect(60, 90, 171, 21));
        Lable_title->setStyleSheet(QString::fromUtf8("font: 75 18pt \"Times New Roman\";"));
        Input_prob = new QTextEdit(centralwidget);
        Input_prob->setObjectName(QString::fromUtf8("Input_prob"));
        Input_prob->setGeometry(QRect(240, 130, 391, 81));
        Input_prob->setStyleSheet(QString::fromUtf8("font: 12pt \"Times New Roman\";"));
        Lable_prob = new QLabel(centralwidget);
        Lable_prob->setObjectName(QString::fromUtf8("Lable_prob"));
        Lable_prob->setGeometry(QRect(60, 140, 171, 21));
        Lable_prob->setStyleSheet(QString::fromUtf8("font: 75 18pt \"Times New Roman\";"));
        Lable_ans = new QLabel(centralwidget);
        Lable_ans->setObjectName(QString::fromUtf8("Lable_ans"));
        Lable_ans->setGeometry(QRect(60, 230, 171, 21));
        Lable_ans->setStyleSheet(QString::fromUtf8("font: 75 18pt \"Times New Roman\";"));
        Input_ans = new QTextEdit(centralwidget);
        Input_ans->setObjectName(QString::fromUtf8("Input_ans"));
        Input_ans->setGeometry(QRect(240, 220, 391, 81));
        Input_ans->setStyleSheet(QString::fromUtf8("font: 12pt \"Times New Roman\";"));
        Butconfirm = new QPushButton(centralwidget);
        Butconfirm->setObjectName(QString::fromUtf8("Butconfirm"));
        Butconfirm->setGeometry(QRect(550, 320, 111, 41));
        Butcancel = new QPushButton(centralwidget);
        Butcancel->setObjectName(QString::fromUtf8("Butcancel"));
        Butcancel->setGeometry(QRect(420, 320, 111, 41));
        addcardMain->setCentralWidget(centralwidget);

        retranslateUi(addcardMain);

        QMetaObject::connectSlotsByName(addcardMain);
    } // setupUi

    void retranslateUi(QMainWindow *addcardMain)
    {
        addcardMain->setWindowTitle(QCoreApplication::translate("addcardMain", "MainWindow", nullptr));
        Lable_1->setText(QCoreApplication::translate("addcardMain", "Add a ", nullptr));
        Lable_type->setText(QCoreApplication::translate("addcardMain", "TBD", nullptr));
        Lable_title->setText(QCoreApplication::translate("addcardMain", "lable title", nullptr));
        Lable_prob->setText(QCoreApplication::translate("addcardMain", "lable prob", nullptr));
        Lable_ans->setText(QCoreApplication::translate("addcardMain", "lable ans", nullptr));
        Butconfirm->setText(QCoreApplication::translate("addcardMain", "Add\357\274\201", nullptr));
        Butcancel->setText(QCoreApplication::translate("addcardMain", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addcardMain: public Ui_addcardMain {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDCARDMAIN_H
