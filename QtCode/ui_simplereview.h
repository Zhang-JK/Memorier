/********************************************************************************
** Form generated from reading UI file 'simplereview.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIMPLEREVIEW_H
#define UI_SIMPLEREVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_simpleReview
{
public:
    QWidget *centralwidget;
    QTextBrowser *Txt_prob;
    QLabel *Txt_title;
    QTextBrowser *Txt_ans;
    QPushButton *But_finish;
    QPushButton *But_show;
    QPushButton *But_extra;

    void setupUi(QMainWindow *simpleReview)
    {
        if (simpleReview->objectName().isEmpty())
            simpleReview->setObjectName(QString::fromUtf8("simpleReview"));
        simpleReview->resize(800, 619);
        centralwidget = new QWidget(simpleReview);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Txt_prob = new QTextBrowser(centralwidget);
        Txt_prob->setObjectName(QString::fromUtf8("Txt_prob"));
        Txt_prob->setGeometry(QRect(30, 60, 731, 281));
        Txt_title = new QLabel(centralwidget);
        Txt_title->setObjectName(QString::fromUtf8("Txt_title"));
        Txt_title->setGeometry(QRect(40, 30, 54, 12));
        Txt_ans = new QTextBrowser(centralwidget);
        Txt_ans->setObjectName(QString::fromUtf8("Txt_ans"));
        Txt_ans->setGeometry(QRect(30, 360, 731, 161));
        But_finish = new QPushButton(centralwidget);
        But_finish->setObjectName(QString::fromUtf8("But_finish"));
        But_finish->setGeometry(QRect(644, 540, 121, 51));
        But_show = new QPushButton(centralwidget);
        But_show->setObjectName(QString::fromUtf8("But_show"));
        But_show->setGeometry(QRect(500, 540, 121, 51));
        But_extra = new QPushButton(centralwidget);
        But_extra->setObjectName(QString::fromUtf8("But_extra"));
        But_extra->setGeometry(QRect(360, 540, 121, 51));
        simpleReview->setCentralWidget(centralwidget);

        retranslateUi(simpleReview);

        QMetaObject::connectSlotsByName(simpleReview);
    } // setupUi

    void retranslateUi(QMainWindow *simpleReview)
    {
        simpleReview->setWindowTitle(QCoreApplication::translate("simpleReview", "MainWindow", nullptr));
        Txt_title->setText(QCoreApplication::translate("simpleReview", "Title", nullptr));
        But_finish->setText(QCoreApplication::translate("simpleReview", "Next", nullptr));
        But_show->setText(QCoreApplication::translate("simpleReview", "Show", nullptr));
        But_extra->setText(QCoreApplication::translate("simpleReview", "Extra", nullptr));
    } // retranslateUi

};

namespace Ui {
    class simpleReview: public Ui_simpleReview {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIMPLEREVIEW_H
