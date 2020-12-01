#ifndef REVIEWMAIN_H
#define REVIEWMAIN_H

#include <QMainWindow>
#include "simplereview.h"

namespace Ui {
class reviewMain;
}

class reviewMain : public QMainWindow
{
    Q_OBJECT

public:
    enum ReviewType {Today = 0, Ramdom = 1};
    explicit reviewMain(QWidget *parent = nullptr);
    ~reviewMain();
    void generate_review_list(ReviewType type);

private:
    Ui::reviewMain *ui;
    Card** review_list;
    int num, currentCard = 0;
    long generateTimestamp;

private slots:
    void on_Butstart_clicked();
    void on_ButToday_clicked();
    void next_card();
};

#endif // REVIEWMAIN_H
