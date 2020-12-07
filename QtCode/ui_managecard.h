/********************************************************************************
** Form generated from reading UI file 'managecard.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANAGECARD_H
#define UI_MANAGECARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ManageCard
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLineEdit *titleSelect;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QTableWidget *tableInfo;
    QComboBox *typeSelect;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *search;
    QPushButton *deleteCard;
    QPushButton *editCard;
    QPushButton *back;
    QLabel *cardIndicator;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ManageCard)
    {
        if (ManageCard->objectName().isEmpty())
            ManageCard->setObjectName(QString::fromUtf8("ManageCard"));
        ManageCard->resize(800, 600);
        centralwidget = new QWidget(ManageCard);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 801, 51));
        QFont font;
        font.setPointSize(32);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        titleSelect = new QLineEdit(centralwidget);
        titleSelect->setObjectName(QString::fromUtf8("titleSelect"));
        titleSelect->setGeometry(QRect(390, 60, 211, 31));
        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(0, 100, 801, 421));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 799, 419));
        tableInfo = new QTableWidget(scrollAreaWidgetContents);
        tableInfo->setObjectName(QString::fromUtf8("tableInfo"));
        tableInfo->setGeometry(QRect(0, 0, 791, 421));
        scrollArea->setWidget(scrollAreaWidgetContents);
        typeSelect = new QComboBox(centralwidget);
        typeSelect->addItem(QString());
        typeSelect->addItem(QString());
        typeSelect->addItem(QString());
        typeSelect->addItem(QString());
        typeSelect->addItem(QString());
        typeSelect->setObjectName(QString::fromUtf8("typeSelect"));
        typeSelect->setGeometry(QRect(80, 60, 161, 31));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 60, 71, 31));
        QFont font1;
        font1.setPointSize(16);
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(320, 60, 71, 31));
        label_3->setFont(font1);
        label_3->setAlignment(Qt::AlignCenter);
        search = new QPushButton(centralwidget);
        search->setObjectName(QString::fromUtf8("search"));
        search->setGeometry(QRect(650, 60, 111, 31));
        deleteCard = new QPushButton(centralwidget);
        deleteCard->setObjectName(QString::fromUtf8("deleteCard"));
        deleteCard->setGeometry(QRect(470, 530, 141, 31));
        editCard = new QPushButton(centralwidget);
        editCard->setObjectName(QString::fromUtf8("editCard"));
        editCard->setGeometry(QRect(300, 530, 141, 31));
        back = new QPushButton(centralwidget);
        back->setObjectName(QString::fromUtf8("back"));
        back->setGeometry(QRect(640, 530, 141, 31));
        cardIndicator = new QLabel(centralwidget);
        cardIndicator->setObjectName(QString::fromUtf8("cardIndicator"));
        cardIndicator->setGeometry(QRect(40, 540, 221, 17));
        ManageCard->setCentralWidget(centralwidget);
        statusBar = new QStatusBar(ManageCard);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        ManageCard->setStatusBar(statusBar);

        retranslateUi(ManageCard);

        QMetaObject::connectSlotsByName(ManageCard);
    } // setupUi

    void retranslateUi(QMainWindow *ManageCard)
    {
        ManageCard->setWindowTitle(QCoreApplication::translate("ManageCard", "Management", nullptr));
        label->setText(QCoreApplication::translate("ManageCard", "Manage Your Cards", nullptr));
        typeSelect->setItemText(0, QCoreApplication::translate("ManageCard", "ALL", nullptr));
        typeSelect->setItemText(1, QCoreApplication::translate("ManageCard", "Plain Text", nullptr));
        typeSelect->setItemText(2, QCoreApplication::translate("ManageCard", "Hollow Text", nullptr));
        typeSelect->setItemText(3, QCoreApplication::translate("ManageCard", "Word", nullptr));
        typeSelect->setItemText(4, QCoreApplication::translate("ManageCard", "Mult Choice", nullptr));

        label_2->setText(QCoreApplication::translate("ManageCard", "Type", nullptr));
        label_3->setText(QCoreApplication::translate("ManageCard", "Title", nullptr));
        search->setText(QCoreApplication::translate("ManageCard", "Apply", nullptr));
        deleteCard->setText(QCoreApplication::translate("ManageCard", "Delete Card", nullptr));
        editCard->setText(QCoreApplication::translate("ManageCard", "Edit Card", nullptr));
        back->setText(QCoreApplication::translate("ManageCard", "Go Back", nullptr));
        cardIndicator->setText(QCoreApplication::translate("ManageCard", "No card has been chosen", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ManageCard: public Ui_ManageCard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGECARD_H
