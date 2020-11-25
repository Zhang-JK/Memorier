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
    this->close();
}

void AddCard::on_ButPlain_clicked()
{
    __card = new Plain;
    addcardMain* addmain = new addcardMain(this);
    connect(addmain, SIGNAL(pre_finish()), this, SLOT(send_data()));
    addmain->set_type(Card::cardType::Plain);
    addmain->show();
}

void AddCard::on_ButWord_clicked()
{
    __card = new Word;
    addcardMain *addmain = new addcardMain(this);
    connect(addmain, SIGNAL(pre_finish()), this, SLOT(send_data()));
    addmain->set_type(Card::cardType::Word);
    addmain->show();
}

void AddCard::on_ButChoices_clicked()
{
    __card = new Choices;
    addcardMain *addmain = new addcardMain(this);
    connect(addmain, SIGNAL(pre_finish()), this, SLOT(add_choices()));
    addmain->set_type(Card::cardType::Choices);
    addmain->show();
}

void AddCard::on_ButText_clicked()
{
    __card = new Text;
    addcardMain* addmain = new addcardMain(this);
    connect(addmain, SIGNAL(pre_finish()), this, SLOT(add_text()));
    addmain->set_type(Card::cardType::Plain);
    addmain->show();
}

void AddCard::send_data()
{
    emit addcard_sendInfo(__card);
    if(__card!=nullptr) delete __card;
    __card = nullptr;
}

void AddCard::add_choices()
{
    addChoices* addch= new addChoices(this);
    addch->init();
    connect(addch, SIGNAL(second_finish()), this, SLOT(send_data()));
    addch->show();
}

void AddCard::add_text()
{
    addText* addtext = new addText(this);
    addtext->show();
}

AddCard::~AddCard()
{
    delete ui;
}

