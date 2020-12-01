#ifndef SIMPLEREVIEW_H
#define SIMPLEREVIEW_H

#include <QMainWindow>
#include "../Cards/Cards.h"

namespace Ui {
class simpleReview;
}

class simpleReview : public QMainWindow
{
    Q_OBJECT

public:
    explicit simpleReview(QWidget *parent = nullptr);
    ~simpleReview();
    void init(Card*);


protected:  
     void closeEvent(QCloseEvent *event); 

signals:
    void finished();
    void forceQuit();

private:
    Ui::simpleReview *ui;
    int showAns=0;
    int showExtra=0;
    Card* card;

private slots:
    void on_But_show_clicked();
    void on_But_finish_clicked();
    void on_But_extra_clicked();

};

#endif // SIMPLEREVIEW_H
