#include "simplereview.h"
#include "ui_simplereview.h"

simpleReview::simpleReview(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::simpleReview)
{
    ui->setupUi(this);
}

simpleReview::~simpleReview()
{
    delete ui;
}

// config the ui interface
void simpleReview::init(Card* init_card)
{
    card = init_card;
    ui->Txt_title->setText(card->get_title());
    ui->Txt_prob->setText(card->get_prob());
    ui->Txt_ans->setText(card->option(5));
    ui->Txt_ans->setVisible(false);
    ui->But_show->setText("Show " + card->option(6));
    if(card->option(7)!="null")
    {
        ui->But_extra->setVisible(true);
        ui->But_extra->setText(card->option(7));
    }
    else ui->But_extra->setVisible(false);
}

void simpleReview::on_But_finish_clicked()
{
    this->close();
    emit finished();
}

void simpleReview::on_But_show_clicked()
{
    showAns^=1;
    ui->Txt_ans->setVisible(showAns);
    ui->But_show->setText((showAns==1?"Hide ":"Show ") +card->option(6));
}

void simpleReview::on_But_extra_clicked()
{
    if(card->get_type()==Card::cardType::Choices)
    {
        ui->But_extra->setText(card->option(8));
        return;
    }
    if(card->get_type()==Card::cardType::Text)
    {
        if(showExtra==0)
        {
            ui->Txt_prob->setText(card->option(8));
            ui->But_extra->setText("Hide answer");
        }
        else
        {
            ui->Txt_prob->setText(card->get_prob());
            ui->But_extra->setText("Show answer");
        }
        showExtra^=1;
        return;
    }
}


void simpleReview::closeEvent(QCloseEvent *event)  
{  
    emit forceQuit();
}
