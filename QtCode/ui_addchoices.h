/********************************************************************************
** Form generated from reading UI file 'addchoices.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDCHOICES_H
#define UI_ADDCHOICES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_addChoices
{
public:
    QWidget *centralwidget;
    QTextBrowser *text;
    QPushButton *Butadd;
    QPushButton *Butfinish;
    QTextEdit *Intxt1;
    QCheckBox *Inac1;
    QTextEdit *Intxt2;
    QCheckBox *Inac2;
    QTextEdit *Intxt3;
    QCheckBox *Inac3;
    QTextEdit *Intxt4;
    QCheckBox *Inac4;
    QTextEdit *Intxt5;
    QCheckBox *Inac5;

    void setupUi(QMainWindow *addChoices)
    {
        if (addChoices->objectName().isEmpty())
            addChoices->setObjectName(QString::fromUtf8("addChoices"));
        addChoices->resize(800, 600);
        centralwidget = new QWidget(addChoices);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        text = new QTextBrowser(centralwidget);
        text->setObjectName(QString::fromUtf8("text"));
        text->setGeometry(QRect(50, 30, 691, 191));
        text->setStyleSheet(QString::fromUtf8("font: 12pt \"Times New Roman\";"));
        Butadd = new QPushButton(centralwidget);
        Butadd->setObjectName(QString::fromUtf8("Butadd"));
        Butadd->setGeometry(QRect(50, 230, 111, 31));
        Butfinish = new QPushButton(centralwidget);
        Butfinish->setObjectName(QString::fromUtf8("Butfinish"));
        Butfinish->setGeometry(QRect(640, 540, 111, 31));
        Intxt1 = new QTextEdit(centralwidget);
        Intxt1->setObjectName(QString::fromUtf8("Intxt1"));
        Intxt1->setGeometry(QRect(180, 270, 451, 41));
        Intxt1->setStyleSheet(QString::fromUtf8("font: 12pt \"Times New Roman\";"));
        Inac1 = new QCheckBox(centralwidget);
        Inac1->setObjectName(QString::fromUtf8("Inac1"));
        Inac1->setGeometry(QRect(150, 280, 31, 21));
        Intxt2 = new QTextEdit(centralwidget);
        Intxt2->setObjectName(QString::fromUtf8("Intxt2"));
        Intxt2->setGeometry(QRect(180, 320, 451, 41));
        Intxt2->setStyleSheet(QString::fromUtf8("font: 12pt \"Times New Roman\";"));
        Inac2 = new QCheckBox(centralwidget);
        Inac2->setObjectName(QString::fromUtf8("Inac2"));
        Inac2->setGeometry(QRect(150, 330, 31, 21));
        Intxt3 = new QTextEdit(centralwidget);
        Intxt3->setObjectName(QString::fromUtf8("Intxt3"));
        Intxt3->setGeometry(QRect(180, 370, 451, 41));
        Intxt3->setStyleSheet(QString::fromUtf8("font: 12pt \"Times New Roman\";"));
        Inac3 = new QCheckBox(centralwidget);
        Inac3->setObjectName(QString::fromUtf8("Inac3"));
        Inac3->setGeometry(QRect(150, 380, 31, 21));
        Intxt4 = new QTextEdit(centralwidget);
        Intxt4->setObjectName(QString::fromUtf8("Intxt4"));
        Intxt4->setGeometry(QRect(180, 420, 451, 41));
        Intxt4->setStyleSheet(QString::fromUtf8("font: 12pt \"Times New Roman\";"));
        Inac4 = new QCheckBox(centralwidget);
        Inac4->setObjectName(QString::fromUtf8("Inac4"));
        Inac4->setGeometry(QRect(150, 430, 31, 21));
        Intxt5 = new QTextEdit(centralwidget);
        Intxt5->setObjectName(QString::fromUtf8("Intxt5"));
        Intxt5->setGeometry(QRect(180, 470, 451, 41));
        Intxt5->setStyleSheet(QString::fromUtf8("font: 12pt \"Times New Roman\";"));
        Inac5 = new QCheckBox(centralwidget);
        Inac5->setObjectName(QString::fromUtf8("Inac5"));
        Inac5->setGeometry(QRect(150, 480, 31, 21));
        addChoices->setCentralWidget(centralwidget);

        retranslateUi(addChoices);

        QMetaObject::connectSlotsByName(addChoices);
    } // setupUi

    void retranslateUi(QMainWindow *addChoices)
    {
        addChoices->setWindowTitle(QCoreApplication::translate("addChoices", "MainWindow", nullptr));
        Butadd->setText(QCoreApplication::translate("addChoices", "Add a choice", nullptr));
        Butfinish->setText(QCoreApplication::translate("addChoices", "Finish", nullptr));
        Inac1->setText(QString());
        Inac2->setText(QString());
        Inac3->setText(QString());
        Inac4->setText(QString());
        Inac5->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class addChoices: public Ui_addChoices {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDCHOICES_H
