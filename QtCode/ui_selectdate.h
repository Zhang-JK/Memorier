/********************************************************************************
** Form generated from reading UI file 'selectdate.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECTDATE_H
#define UI_SELECTDATE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_selectDate
{
public:
    QComboBox *dateBox;
    QCheckBox *CheckAll;
    QPushButton *Butfinish;
    QCheckBox *CheckPlain;
    QCheckBox *CheckText;
    QCheckBox *CheckWord;
    QCheckBox *CheckChoices;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *selectDate)
    {
        if (selectDate->objectName().isEmpty())
            selectDate->setObjectName(QString::fromUtf8("selectDate"));
        selectDate->resize(278, 244);
        dateBox = new QComboBox(selectDate);
        dateBox->setObjectName(QString::fromUtf8("dateBox"));
        dateBox->setGeometry(QRect(130, 10, 71, 22));
        CheckAll = new QCheckBox(selectDate);
        CheckAll->setObjectName(QString::fromUtf8("CheckAll"));
        CheckAll->setGeometry(QRect(130, 50, 71, 16));
        CheckAll->setChecked(true);
        Butfinish = new QPushButton(selectDate);
        Butfinish->setObjectName(QString::fromUtf8("Butfinish"));
        Butfinish->setGeometry(QRect(90, 200, 71, 23));
        CheckPlain = new QCheckBox(selectDate);
        CheckPlain->setObjectName(QString::fromUtf8("CheckPlain"));
        CheckPlain->setGeometry(QRect(130, 80, 91, 16));
        CheckPlain->setChecked(true);
        CheckText = new QCheckBox(selectDate);
        CheckText->setObjectName(QString::fromUtf8("CheckText"));
        CheckText->setGeometry(QRect(130, 110, 81, 16));
        CheckText->setChecked(true);
        CheckWord = new QCheckBox(selectDate);
        CheckWord->setObjectName(QString::fromUtf8("CheckWord"));
        CheckWord->setGeometry(QRect(130, 140, 81, 16));
        CheckWord->setChecked(true);
        CheckChoices = new QCheckBox(selectDate);
        CheckChoices->setObjectName(QString::fromUtf8("CheckChoices"));
        CheckChoices->setGeometry(QRect(130, 170, 81, 16));
        CheckChoices->setChecked(true);
        label = new QLabel(selectDate);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 10, 101, 16));
        label_2 = new QLabel(selectDate);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 50, 71, 17));

        retranslateUi(selectDate);

        QMetaObject::connectSlotsByName(selectDate);
    } // setupUi

    void retranslateUi(QDialog *selectDate)
    {
        selectDate->setWindowTitle(QCoreApplication::translate("selectDate", "Dialog", nullptr));
        CheckAll->setText(QCoreApplication::translate("selectDate", "All", nullptr));
        Butfinish->setText(QCoreApplication::translate("selectDate", "Go!", nullptr));
        CheckPlain->setText(QCoreApplication::translate("selectDate", "Plain text", nullptr));
        CheckText->setText(QCoreApplication::translate("selectDate", "Hol text", nullptr));
        CheckWord->setText(QCoreApplication::translate("selectDate", "Word", nullptr));
        CheckChoices->setText(QCoreApplication::translate("selectDate", "Choices", nullptr));
        label->setText(QCoreApplication::translate("selectDate", "Created since", nullptr));
        label_2->setText(QCoreApplication::translate("selectDate", "Card Type", nullptr));
    } // retranslateUi

};

namespace Ui {
    class selectDate: public Ui_selectDate {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTDATE_H
