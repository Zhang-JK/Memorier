/********************************************************************************
** Form generated from reading UI file 'addtext.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDTEXT_H
#define UI_ADDTEXT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_addText
{
public:
    QWidget *centralwidget;
    QTextEdit *text;
    QPushButton *Butadd;
    QPushButton *ButAPI;
    QPushButton *Butauto;
    QPushButton *Butfinish;
    QTextEdit *TxtAPI;

    void setupUi(QMainWindow *addText)
    {
        if (addText->objectName().isEmpty())
            addText->setObjectName(QString::fromUtf8("addText"));
        addText->resize(800, 488);
        centralwidget = new QWidget(addText);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        text = new QTextEdit(centralwidget);
        text->setObjectName(QString::fromUtf8("text"));
        text->setGeometry(QRect(20, 20, 751, 311));
        Butadd = new QPushButton(centralwidget);
        Butadd->setObjectName(QString::fromUtf8("Butadd"));
        Butadd->setGeometry(QRect(350, 350, 291, 91));
        ButAPI = new QPushButton(centralwidget);
        ButAPI->setObjectName(QString::fromUtf8("ButAPI"));
        ButAPI->setGeometry(QRect(20, 350, 171, 41));
        Butauto = new QPushButton(centralwidget);
        Butauto->setObjectName(QString::fromUtf8("Butauto"));
        Butauto->setGeometry(QRect(20, 400, 171, 41));
        Butfinish = new QPushButton(centralwidget);
        Butfinish->setObjectName(QString::fromUtf8("Butfinish"));
        Butfinish->setGeometry(QRect(680, 402, 75, 41));
        TxtAPI = new QTextEdit(centralwidget);
        TxtAPI->setObjectName(QString::fromUtf8("TxtAPI"));
        TxtAPI->setGeometry(QRect(210, 350, 104, 91));
        addText->setCentralWidget(centralwidget);

        retranslateUi(addText);

        QMetaObject::connectSlotsByName(addText);
    } // setupUi

    void retranslateUi(QMainWindow *addText)
    {
        addText->setWindowTitle(QCoreApplication::translate("addText", "MainWindow", nullptr));
        Butadd->setText(QCoreApplication::translate("addText", "Add", nullptr));
        ButAPI->setText(QCoreApplication::translate("addText", "Show suggestion", nullptr));
        Butauto->setText(QCoreApplication::translate("addText", "Apply suggestion", nullptr));
        Butfinish->setText(QCoreApplication::translate("addText", "Finish", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addText: public Ui_addText {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDTEXT_H
