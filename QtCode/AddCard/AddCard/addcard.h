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
    void send_data();
    void add_choices();
    void add_text();

private:
    Ui::AddCard *ui;
};
#endif // ADDCARD_H
