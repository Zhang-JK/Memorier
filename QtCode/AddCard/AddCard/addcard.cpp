#include "addcard.h"
#include "ui_addcard.h"

AddCard::AddCard(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AddCard)
{
    ui->setupUi(this);
}

Card* __card = nullptr;

void AddCard::on_ButEnd_clicked()
{
    if(__card!=nullptr)
        emit addcard_sendInfo(__card);
    this->close();
}

void AddCard::on_ButPlain_clicked()
{
    if(__card!=nullptr)
        emit addcard_sendInfo(__card);
    addcardMain* addmain = new addcardMain(this);
    addmain->set_type(Card::cardType::Plain);
    addmain->show();
}


AddCard::~AddCard()
{
    delete ui;
}

