/********************************************************************************
** Form generated from reading UI file 'libwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LIBWINDOW_H
#define UI_LIBWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LibWindow
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *title1;
    QPushButton *add;
    QPushButton *test;
    QPushButton *review;
    QPushButton *manage;
    QLabel *tip1;
    QLabel *tip2;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *title2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *LibWindow)
    {
        if (LibWindow->objectName().isEmpty())
            LibWindow->setObjectName(QString::fromUtf8("LibWindow"));
        LibWindow->resize(800, 600);
        QIcon icon;
        icon.addFile(QString::fromUtf8("images/icontest.png"), QSize(), QIcon::Normal, QIcon::Off);
        LibWindow->setWindowIcon(icon);
        LibWindow->setAutoFillBackground(true);
        centralwidget = new QWidget(LibWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(120, 40, 551, 61));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        title1 = new QLabel(verticalLayoutWidget);
        title1->setObjectName(QString::fromUtf8("title1"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(title1->sizePolicy().hasHeightForWidth());
        title1->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("Ubuntu Condensed"));
        font.setPointSize(48);
        font.setBold(true);
        font.setWeight(75);
        title1->setFont(font);
        title1->setMouseTracking(true);
        title1->setStyleSheet(QString::fromUtf8("color: rgba(255,255,255,150)"));
        title1->setFrameShadow(QFrame::Raised);
        title1->setScaledContents(false);
        title1->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(title1);

        add = new QPushButton(centralwidget);
        add->setObjectName(QString::fromUtf8("add"));
        add->setGeometry(QRect(80, 190, 261, 121));
        sizePolicy.setHeightForWidth(add->sizePolicy().hasHeightForWidth());
        add->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setFamily(QString::fromUtf8("Fira Code"));
        font1.setPointSize(20);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(18);
        add->setFont(font1);
        add->setStyleSheet(QString::fromUtf8("font: 150 20pt \"Fira Code\";\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgba(120,194,169,70);\n"
"border:4px solid black;"));
        add->setFlat(false);
        test = new QPushButton(centralwidget);
        test->setObjectName(QString::fromUtf8("test"));
        test->setGeometry(QRect(440, 190, 261, 121));
        sizePolicy.setHeightForWidth(test->sizePolicy().hasHeightForWidth());
        test->setSizePolicy(sizePolicy);
        test->setFont(font1);
        test->setStyleSheet(QString::fromUtf8("font: 150 20pt \"Fira Code\";\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgba(120,194,169,70);\n"
"border:4px solid black;"));
        test->setFlat(false);
        review = new QPushButton(centralwidget);
        review->setObjectName(QString::fromUtf8("review"));
        review->setGeometry(QRect(80, 360, 261, 121));
        sizePolicy.setHeightForWidth(review->sizePolicy().hasHeightForWidth());
        review->setSizePolicy(sizePolicy);
        review->setFont(font1);
        review->setStyleSheet(QString::fromUtf8("font: 150 20pt \"Fira Code\";\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgba(120,194,169,70);\n"
"border:4px solid black;"));
        review->setFlat(false);
        manage = new QPushButton(centralwidget);
        manage->setObjectName(QString::fromUtf8("manage"));
        manage->setGeometry(QRect(440, 360, 261, 121));
        sizePolicy.setHeightForWidth(manage->sizePolicy().hasHeightForWidth());
        manage->setSizePolicy(sizePolicy);
        manage->setFont(font1);
        manage->setStyleSheet(QString::fromUtf8("font: 150 20pt \"Fira Code\";\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgba(120,194,169,70);\n"
"border:4px solid black;"));
        manage->setFlat(false);
        tip1 = new QLabel(centralwidget);
        tip1->setObjectName(QString::fromUtf8("tip1"));
        tip1->setGeometry(QRect(0, 520, 791, 31));
        tip1->setStyleSheet(QString::fromUtf8("color:rgb(186, 189, 182);\n"
""));
        tip1->setAlignment(Qt::AlignCenter);
        tip2 = new QLabel(centralwidget);
        tip2->setObjectName(QString::fromUtf8("tip2"));
        tip2->setGeometry(QRect(0, 550, 791, 31));
        tip2->setStyleSheet(QString::fromUtf8("color:rgb(186, 189, 182);\n"
""));
        tip2->setAlignment(Qt::AlignCenter);
        verticalLayoutWidget_2 = new QWidget(centralwidget);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(120, 100, 551, 51));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        title2 = new QLabel(verticalLayoutWidget_2);
        title2->setObjectName(QString::fromUtf8("title2"));
        sizePolicy.setHeightForWidth(title2->sizePolicy().hasHeightForWidth());
        title2->setSizePolicy(sizePolicy);
        QFont font2;
        font2.setFamily(QString::fromUtf8("Ubuntu Condensed"));
        font2.setPointSize(24);
        font2.setBold(true);
        font2.setWeight(75);
        title2->setFont(font2);
        title2->setMouseTracking(true);
        title2->setStyleSheet(QString::fromUtf8("color: rgba(255,255,255,190)"));
        title2->setFrameShadow(QFrame::Raised);
        title2->setScaledContents(false);
        title2->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(title2);

        LibWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(LibWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        LibWindow->setStatusBar(statusbar);

        retranslateUi(LibWindow);

        QMetaObject::connectSlotsByName(LibWindow);
    } // setupUi

    void retranslateUi(QMainWindow *LibWindow)
    {
        LibWindow->setWindowTitle(QCoreApplication::translate("LibWindow", "MainWindow", nullptr));
        title1->setText(QCoreApplication::translate("LibWindow", "Memerior", nullptr));
        add->setText(QCoreApplication::translate("LibWindow", "Add Card", nullptr));
        test->setText(QCoreApplication::translate("LibWindow", "Testing", nullptr));
        review->setText(QCoreApplication::translate("LibWindow", "Review", nullptr));
        manage->setText(QCoreApplication::translate("LibWindow", "Management", nullptr));
        tip1->setText(QCoreApplication::translate("LibWindow", "Today you have studied _ cards!", nullptr));
        tip2->setText(QCoreApplication::translate("LibWindow", "Add oil :)", nullptr));
        title2->setText(QCoreApplication::translate("LibWindow", "Your Library", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LibWindow: public Ui_LibWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LIBWINDOW_H
