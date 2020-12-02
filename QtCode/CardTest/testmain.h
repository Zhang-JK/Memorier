#ifndef TESTMAIN_H
#define TESTMAIN_H

#include <QMainWindow>
#include "simpletest.h"

namespace Ui {
class testMain;
}

class testMain : public QMainWindow
{
    Q_OBJECT

public:
    explicit testMain(QWidget *parent = nullptr);
    ~testMain();

private:
    enum TestType{Self, Today};
    Ui::testMain *ui;
    Card** testlist;
    int num, currentCard;
    long generateTimestamp;
    void generate_testlist(TestType);
    void display_test(Card*);

private slots:
    void on_ButSelf_clicked();
    void on_ButToday_clicked();
    void next_card();
};

#endif // TESTMAIN_H
