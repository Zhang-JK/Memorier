#ifndef ADDTEXT_H
#define ADDTEXT_H

#include <QMainWindow>
#include "../Cards/Cards.h"
#include <QTextCursor>
#include <QColor>
#include <QTextCharFormat>
#include <QList>
#include "APIRequest.h"

namespace Ui
{
    class addText;
}

class addText : public QMainWindow
{
    Q_OBJECT

public:
    explicit addText(QWidget *parent = nullptr);
    ~addText();

signals:
    void second_finish();

private slots:
    void on_Butadd_clicked();
    void on_ButAPI_clicked();           // check API
    void on_Butauto_clicked();          // auto select string
    void on_Butfinish_clicked();

private:
    Ui::addText *ui;
    int len;
    int *a;
    int api = -1;
    QList<QString> TXTapi;              // API info
    void selection(QTextCursor cur);    // mark the text under cur using a different color/font
};

#endif // ADDTEXT_H
