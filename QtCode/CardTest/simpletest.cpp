#include "simpletest.h"
#include "ui_simpletest.h"

simpleTest::simpleTest(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::simpleTest)
{
    ui->setupUi(this);
}

simpleTest::~simpleTest()
{
    delete ui;
}

void simpleTest::init(Card* init_card)
{
    card=init_card;
    ui->LabelTitle->setText(card->get_title());
    ui->Txt_Prob->setText(card->get_prob());

    ui->ButYES->setText("I remember :)");
    ui->ButSubmit->setText("Check my answer XD");
    if(card->option(6)=="hint")
        ui->ButNO->setText("Show hint");
    else
        ui->ButNO->setText("I don't remember >_<");
}

void simpleTest::on_ButSubmit_clicked()
{
    QString str=card->option(9,ui->Txt_Ans->toPlainText());
    if(str[0]=='0')
    {
        ui->ButNO->setText("Next->");
        ui->ButYES->setText("Wrong!");
        ui->ButYES->setDisabled(true);
        ui->ButSubmit->setVisible(false);
        str.remove(0,1);
        ui->Txt_Ans->setText(str);
        str=card->option(10,str);
        while(str.size())
        {
            int i=0;
            while(str[i]!='-') i++;
            int s=str.left(i).toInt();
            str.remove(0,i+1);
            i=0;
            while(str[i]!=';') i++;
            int t=str.left(i).toInt();
            str.remove(0,i+1);
            select(s,t);
        }
    }
    else
    {
        ui->ButYES->setText("Correct!");
        ui->ButNO->setVisible(false);
        ui->ButSubmit->setVisible(false);
    }
}

void simpleTest::on_ButNO_clicked()
{
    if(ui->ButNO->text()[0]=='S')
    {
        ui->Txt_Ans->setText(card->option(6));
        ui->ButNO->setText("I don't remember >_<");
        return;
    }
    if(ui->ButNO->text()[0]=='I')
    {
        ui->Txt_Ans->setText(card->option(8));
        ui->ButNO->setText("Next->");
        ui->ButSubmit->setVisible(false);
        ui->ButYES->setVisible(false);
        return;
    }
    if(ui->ButNO->text()[0]=='N')
    {
        card->test_update(0);
        emit finished();
        this->close();
    }
}

void simpleTest::on_ButYES_clicked()
{
    card->test_update(1);
    emit finished();
    this->close();
}

void simpleTest::select(int st,int en)
{
    QTextCursor cur = ui->Txt_Ans->textCursor();
    cur.setPosition(st);
    cur.setPosition(en+1, QTextCursor::KeepAnchor);
 //   cur.select(QTextCursor::WordUnderCursor);
    QTextCharFormat fmt;
    fmt.setForeground(QColor(255,0,0));
    cur.mergeCharFormat(fmt);
    ui->Txt_Ans->setTextCursor(cur);
    ui->Txt_Ans->mergeCurrentCharFormat(fmt);
    cur.setPosition(cur.selectionEnd());
    ui->Txt_Ans->setTextCursor(cur);
}
