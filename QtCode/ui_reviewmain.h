/********************************************************************************
** Form generated from reading UI file 'reviewmain.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REVIEWMAIN_H
#define UI_REVIEWMAIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_reviewMain
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QPushButton *Butstart;
    QPushButton *ButToday;
    QLabel *labelAll;
    QLabel *labelToday;
    QLabel *labelAll_2;
    QLabel *labelAll_3;

    void setupUi(QMainWindow *reviewMain)
    {
        if (reviewMain->objectName().isEmpty())
            reviewMain->setObjectName(QString::fromUtf8("reviewMain"));
        reviewMain->resize(600, 256);
        centralwidget = new QWidget(reviewMain);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 601, 81));
        QFont font;
        font.setPointSize(36);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        Butstart = new QPushButton(centralwidget);
        Butstart->setObjectName(QString::fromUtf8("Butstart"));
        Butstart->setGeometry(QRect(40, 120, 211, 61));
        ButToday = new QPushButton(centralwidget);
        ButToday->setObjectName(QString::fromUtf8("ButToday"));
        ButToday->setGeometry(QRect(320, 120, 211, 61));
        labelAll = new QLabel(centralwidget);
        labelAll->setObjectName(QString::fromUtf8("labelAll"));
        labelAll->setGeometry(QRect(20, 180, 251, 51));
        labelAll->setAlignment(Qt::AlignCenter);
        labelToday = new QLabel(centralwidget);
        labelToday->setObjectName(QString::fromUtf8("labelToday"));
        labelToday->setGeometry(QRect(300, 180, 261, 51));
        labelToday->setAlignment(Qt::AlignCenter);
        labelAll_2 = new QLabel(centralwidget);
        labelAll_2->setObjectName(QString::fromUtf8("labelAll_2"));
        labelAll_2->setGeometry(QRect(20, 100, 271, 21));
        QFont font1;
        font1.setPointSize(8);
        labelAll_2->setFont(font1);
        labelAll_2->setAlignment(Qt::AlignCenter);
        labelAll_3 = new QLabel(centralwidget);
        labelAll_3->setObjectName(QString::fromUtf8("labelAll_3"));
        labelAll_3->setGeometry(QRect(290, 100, 271, 21));
        labelAll_3->setFont(font1);
        labelAll_3->setAlignment(Qt::AlignCenter);
        reviewMain->setCentralWidget(centralwidget);

        retranslateUi(reviewMain);

        QMetaObject::connectSlotsByName(reviewMain);
    } // setupUi

    void retranslateUi(QMainWindow *reviewMain)
    {
        reviewMain->setWindowTitle(QCoreApplication::translate("reviewMain", "Review", nullptr));
        label->setText(QCoreApplication::translate("reviewMain", "Review Your Cards", nullptr));
        Butstart->setText(QCoreApplication::translate("reviewMain", "Review All Cards", nullptr));
        ButToday->setText(QCoreApplication::translate("reviewMain", "Review Today's Card", nullptr));
        labelAll->setText(QString());
        labelToday->setText(QString());
        labelAll_2->setText(QCoreApplication::translate("reviewMain", "We will randomly choose 5 cards for you to review", nullptr));
        labelAll_3->setText(QCoreApplication::translate("reviewMain", "We will choose some cards by Forgetting curve", nullptr));
    } // retranslateUi

};

namespace Ui {
    class reviewMain: public Ui_reviewMain {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REVIEWMAIN_H
