#include "reviewmain.h"
#include "ui_reviewmain.h"
#include <QMessageBox>

reviewMain::reviewMain(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::reviewMain)
{
    ui->setupUi(this);
}

reviewMain::~reviewMain()
{
    delete ui;
}

void reviewMain::generate_review_list()
{
    // SQL operation and UI setting TBD
    // storage pointer in Card* review_list

    // for debug below, should be deleted
    review_list = new Card* [4];
    Card* cd1 = new Plain;
    cd1->set_title("plain");
    cd1->set_prob("plain prob");
    cd1->option(1,"plain answer");
    Card* cd2 = new Word;
    cd2->set_title("word");
    cd2->set_prob("word prob");
    cd2->option(1,"word trans");
    Card* cd3 = new Choices;
    cd3->set_title("choices");
    cd3->set_prob("choices prob");
    cd3->option(1,"choices hint");
    cd3->option(2,"ac_qus1T");
    cd3->option(2,"wa_qus2F");
    cd3->option(2,"ac_qus3T");
    cd3->option(2,"wa_qus4F");
    Card* cd4 = new Text;
    cd4->set_title("text");
    cd4->set_prob("text prob,abcdefghijklmnopqrstuvwzyz1234567890abcdefghijklmnopqrstuvwxyz");
    cd4->option(1,"text hint");
    cd4->option(2,"3-5");
    cd4->option(2,"12-20");
    cd4->option(2,"26-28");
    cd4->option(2,"40-45");
    cd4->option(2,"```");
    review_list[0]=cd1;
    review_list[1]=cd2;
    review_list[2]=cd3;
    review_list[3]=cd4;
    num=4;
    //debug end
}

void reviewMain::on_Butstart_clicked()
{
    i=0;
    simpleReview* temp = new simpleReview(this);
    temp->init(review_list[0]);
    connect(temp, SIGNAL(finished()), this, SLOT(next_card()));
    temp->show();
}

void reviewMain::next_card()
{
    i++;
    if(i==num)
    {
        QMessageBox* temp = new QMessageBox;
        temp->addButton("OK", QMessageBox::AcceptRole);
        temp->setText("No more cards to review!");
        temp->setIcon(QMessageBox::Information);
        temp->show();
        this->close();
    }
    else
    {
        simpleReview* temp = new simpleReview(this);
        temp->init(review_list[i]);
        connect(temp, SIGNAL(finished()), this, SLOT(next_card()));
        temp->show();
    }

}
