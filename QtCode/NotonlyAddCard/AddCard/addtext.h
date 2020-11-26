#ifndef ADDTEXT_H
#define ADDTEXT_H

#include <QMainWindow>
#include "../Cards/Cards.h"
#include <QTextCursor>
#include <QColor>
#include <QBrush>
#include <QTextCharFormat>
#include <QList>
#include "../APIs/APIRequest.h"

namespace Ui {
class addText;
}

class addText : public QMainWindow
{
    Q_OBJECT

public:
    explicit addText(QWidget *parent = nullptr);
    ~addText();
    void init();

signals:
    void second_finish();

private slots:
    void on_Butadd_clicked();
    void on_ButAPI_clicked();
    void on_Butauto_clicked();
    void on_Butfinish_clicked();

private:
    Ui::addText *ui;
    int len;
    int* a;
    int api = -1;
    QList<QString> TXTapi;
    void selection(QTextCursor cur);
};

#endif // ADDTEXT_H
