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
    Card** testlist = nullptr;
    int num = 0, currentCard = 0;
    long generateTimestamp;
    bool forceQuitFlag = false;
    void generate_testlist(TestType);
    void display_test(Card*);

private slots:
    void on_ButSelf_clicked();
    void on_ButToday_clicked();
    void next_card();
    void exit();
};

#endif // TESTMAIN_H
