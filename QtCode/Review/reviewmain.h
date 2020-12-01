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
    explicit reviewMain(QWidget *parent = nullptr);
    ~reviewMain();
    void generate_review_list();

private:
    Ui::reviewMain *ui;
    Card** review_list;
    int num, i;

private slots:
    void on_Butstart_clicked();
    void next_card();
};

#endif // REVIEWMAIN_H
