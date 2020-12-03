#ifndef SIMPLETEST_H
#define SIMPLETEST_H

#include <QMainWindow>
#include "Cards.h"
#include <QTextCursor>

namespace Ui {
class simpleTest;
}

class simpleTest : public QMainWindow
{
    Q_OBJECT

public:
    explicit simpleTest(QWidget *parent = nullptr);
    ~simpleTest();

    void init(Card*);

signals:
    void finished();

private:
    Ui::simpleTest *ui;
    Card* card;
    void select(int,int);           // mark text between the two indicator with a different color/font

private slots:
    void on_ButYES_clicked();
    void on_ButNO_clicked();
    void on_ButSubmit_clicked();
};

#endif // SIMPLETEST_H
