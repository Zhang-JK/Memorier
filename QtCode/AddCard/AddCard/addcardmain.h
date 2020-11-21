#ifndef ADDCARDMAIN_H
#define ADDCARDMAIN_H

#include <QMainWindow>
#include "../Cards/Cards.h"

namespace Ui {
class addcardMain;
}

class addcardMain : public QMainWindow
{
    Q_OBJECT

public:
    explicit addcardMain(QWidget *parent = nullptr);
    ~addcardMain();
    void set_type(Card::cardType type_);

private slots:
    void on_Butconfirm_clicked();
    void on_Butcancel_clicked();

private:
    Ui::addcardMain *ui;
    Card::cardType type;
};

#endif // ADDCARDMAIN_H
