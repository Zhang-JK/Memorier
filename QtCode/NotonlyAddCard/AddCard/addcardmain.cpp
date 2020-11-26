#include "addcardmain.h"
#include "ui_addcardmain.h"

addcardMain::addcardMain(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::addcardMain)
{
    ui->setupUi(this);
}

void addcardMain::set_type(Card::cardType type_)
{
    extern Card* __card;
    type = type_;
    ui->Lable_type->setText(Card::typeName[type]);
    ui->Lable_title->setText(__card->add(1));
    ui->Lable_prob->setText(__card->add(2));
    ui->Lable_ans->setText(__card->add(3));
    if(type==Card::cardType::Word)
    {
        connect(ui->Input_ans, SIGNAL(selectionChanged()), this, SLOT(option()));
    }
}

void addcardMain::option()
{
    extern Card* __card;
    if(type==Card::cardType::Word)
    {
        disconnect(ui->Input_ans, SIGNAL(selectionChanged()), this, SLOT(option()));
        QString temp = __card->option(2,ui->Input_prob->toPlainText());
        if(temp!="null")
            ui->Input_ans->setText(temp);
    }
}

void addcardMain::on_Butcancel_clicked()
{
    extern Card* __card;
    if(__card!=nullptr)
        delete __card;
    __card=nullptr;
    this->close();
}

void addcardMain::on_Butconfirm_clicked()
{
    extern Card* __card;
    __card->set_title(ui->Input_title->toPlainText());
    __card->set_prob(ui->Input_prob->toPlainText());
    __card->option(1,ui->Input_ans->toPlainText());
    this->close();
    emit pre_finish();
}

addcardMain::~addcardMain()
{
    delete ui;
}
