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
    type = type_;
//    ui->Lable_type->setText(Card::typeName[type]);
    ui->Lable_type->setText("Plain");
    ui->Lable_prob->setText("The question:");
    ui->Lable_ans->setText("The answer:");
}

void addcardMain::on_Butcancel_clicked()
{
    extern Card* __card;
    __card=nullptr;
    this->close();
}

void addcardMain::on_Butconfirm_clicked()
{
    extern Card* __card;
    __card = new Plain;
    __card->set_title(ui->Input_title->toPlainText());
    __card->set_prob(ui->Input_prob->toPlainText());
    __card->option(0,ui->Input_ans->toPlainText());
    this->close();
}

addcardMain::~addcardMain()
{
    delete ui;
}
