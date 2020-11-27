/********************************************************************************
** Form generated from reading UI file 'addcard.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDCARD_H
#define UI_ADDCARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddCard
{
public:
    QWidget *centralwidget;
    QPushButton *ButPlain;
    QLabel *ButTitle;
    QPushButton *ButText;
    QPushButton *ButWord;
    QPushButton *ButChoices;
    QPushButton *ButEnd;

    void setupUi(QMainWindow *AddCard)
    {
        if (AddCard->objectName().isEmpty())
            AddCard->setObjectName(QString::fromUtf8("AddCard"));
        AddCard->resize(311, 421);
        centralwidget = new QWidget(AddCard);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        ButPlain = new QPushButton(centralwidget);
        ButPlain->setObjectName(QString::fromUtf8("ButPlain"));
        ButPlain->setGeometry(QRect(70, 100, 171, 51));
        ButPlain->setStyleSheet(QString::fromUtf8("font: 20pt \"Times New Roman\";"));
        ButTitle = new QLabel(centralwidget);
        ButTitle->setObjectName(QString::fromUtf8("ButTitle"));
        ButTitle->setGeometry(QRect(30, 40, 231, 31));
        ButTitle->setTextFormat(Qt::AutoText);
        ButText = new QPushButton(centralwidget);
        ButText->setObjectName(QString::fromUtf8("ButText"));
        ButText->setGeometry(QRect(70, 160, 171, 51));
        ButWord = new QPushButton(centralwidget);
        ButWord->setObjectName(QString::fromUtf8("ButWord"));
        ButWord->setGeometry(QRect(70, 220, 171, 51));
        ButChoices = new QPushButton(centralwidget);
        ButChoices->setObjectName(QString::fromUtf8("ButChoices"));
        ButChoices->setGeometry(QRect(70, 280, 171, 51));
        ButEnd = new QPushButton(centralwidget);
        ButEnd->setObjectName(QString::fromUtf8("ButEnd"));
        ButEnd->setGeometry(QRect(70, 340, 171, 51));
        AddCard->setCentralWidget(centralwidget);

        retranslateUi(AddCard);

        QMetaObject::connectSlotsByName(AddCard);
    } // setupUi

    void retranslateUi(QMainWindow *AddCard)
    {
        AddCard->setWindowTitle(QCoreApplication::translate("AddCard", "AddCard", nullptr));
        ButPlain->setText(QCoreApplication::translate("AddCard", "Plain text", nullptr));
        ButTitle->setText(QCoreApplication::translate("AddCard", "<html><head/><body><p><span style=\" font-size:16pt; font-weight:600;\">Choose a card type</span></p></body></html>", nullptr));
        ButText->setText(QCoreApplication::translate("AddCard", "Hollow text", nullptr));
        ButWord->setText(QCoreApplication::translate("AddCard", "Word", nullptr));
        ButChoices->setText(QCoreApplication::translate("AddCard", "Choice", nullptr));
        ButEnd->setText(QCoreApplication::translate("AddCard", "No more card", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddCard: public Ui_AddCard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDCARD_H
