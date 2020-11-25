#include "addchoices.h"
#include "ui_addchoices.h"
#include <QMessageBox>

addChoices::addChoices(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::addChoices)
{
    ui->setupUi(this);
}

addChoices::~addChoices()
{
    delete ui;
}

void addChoices::init()
{
    extern Card* __card;
    ui->text->setText(__card->get_prob());
    num=2;
    Inac[1] = ui->Inac1;
    Inac[2] = ui->Inac2;
    Inac[3] = ui->Inac3;
    Inac[4] = ui->Inac4;
    Inac[5] = ui->Inac5;
    Intxt[1] = ui->Intxt1;
    Intxt[2] = ui->Intxt2;
    Intxt[3] = ui->Intxt3;
    Intxt[4] = ui->Intxt4;
    Intxt[5] = ui->Intxt5;
    for(int i=3;i<=5;++i)
    {
        Inac[i]->setVisible(false);
        Intxt[i]->setVisible(false);
    }
}

void addChoices::on_Butadd_clicked()
{
    if(num==5)
    {
        QMessageBox* temp = new QMessageBox;
        temp->addButton("OK", QMessageBox::AcceptRole);
        temp->setText("You can add atmost 5 options");
        temp->setIcon(QMessageBox::Warning);
        temp->show();
        return;
    }
    num++;
    Inac[num]->setVisible(true);
    Intxt[num]->setVisible(true);
}

void addChoices::on_Butfinish_clicked()
{
    extern Card* __card;
    for(int i=1;i<=num;++i)
    {
        __card->option(1,Intxt[i]->toPlainText()+(Inac[i]->isChecked()?"T":"F"));
    }
    this->close();
    emit second_finish();
}
