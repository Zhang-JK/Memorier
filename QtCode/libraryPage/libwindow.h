#ifndef LIBWINDOW_H
#define LIBWINDOW_H

#include <QMainWindow>
#include "addcard.h"
#include "managecard.h"
#include "Cards.h"
#include "Review/reviewmain.h"

namespace Ui {
class LibWindow;
}

class LibWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit LibWindow(QWidget *parent = nullptr);
    ~LibWindow();


private slots:
    void addCard_push();
    void manageCard_push();
    void review_push();
    void addCard_data(Card*);

private:
    Ui::LibWindow *ui;
};

#endif // LIBWINDOW_H
