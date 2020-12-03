#ifndef ADDCARD_H
#define ADDCARD_H

#include <QMainWindow>
#include "addcardmain.h"
#include "addtext.h"
#include "addchoices.h"
#include "../Cards/Cards.h"

QT_BEGIN_NAMESPACE
namespace Ui { class AddCard; }
QT_END_NAMESPACE

class AddCard : public QMainWindow
{
    Q_OBJECT

public:
    AddCard(QWidget *parent = nullptr);
    ~AddCard();

signals:
    void addcard_sendInfo(Card*);

private slots:
    void on_ButPlain_clicked();
    void on_ButWord_clicked();
    void on_ButChoices_clicked();
    void on_ButText_clicked();
    void on_ButEnd_clicked();

    void send_data();   // transform data and tackle global variable
    void add_choices(); // display another window for special card type
    void add_text();    // display another window for special card type

private:
    Ui::AddCard *ui;
};
#endif // ADDCARD_H
