#include "addtext.h"


#include "ui_addtext.h"


addText::addText(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::addText)
{
    ui->setupUi(this);
    extern Card* __card;
    connect(ui->text, SIGNAL(selectionChanged()), this, SLOT(selection()));
    ui->text->setText(__card->get_prob());
    ui->ButAPI->setText("Show Suggestions");
    ui->Butauto->setVisible(false);
    ui->TxtAPI->setVisible(false);
    //ui->TxtAPI->setReadOnly(true);
    len=__card->get_prob().length();
    a=new int[len]{0};
}

addText::~addText()
{
    delete ui;
    delete [] a;
}


void addText::on_ButAPI_clicked()
{
    extern Card* __card;
    if(api==-1)
    {
        TXTapi=textRazorAPI(__card->get_prob());
        ui->TxtAPI->setVisible(true);
        ui->Butauto->setVisible(true);
        ui->ButAPI->setText("Next Suggestion");
        api=0;
    }
    if(TXTapi.size()==0) return;
    ui->TxtAPI->setText(TXTapi[api]);
    api++;
    if(api==TXTapi.size()) api=0;
}

void addText::on_Butauto_clicked()
{
    extern Card* __card;
    QString temp = ui->TxtAPI->toPlainText();
    int m = temp.length();
    if(m<2) return;
    for(int i=0;i<len;++i)
    {
        int flag=1;
        for(int j=0;j<m;++j)
        if(temp[j]!=__card->get_prob()[i+j])
        {
            flag=0;
            break;
        }
        if(flag)
        {
            QTextCursor cur = ui->text->textCursor();
            cur.setPosition(i,QTextCursor::MoveAnchor);
            cur.movePosition(QTextCursor::NoMove, QTextCursor::KeepAnchor, m);
            cur.select(QTextCursor::WordUnderCursor);
            selection(cur);
        }
    }
}

void addText::on_Butadd_clicked()
{
    QTextCursor cur = ui->text->textCursor();
    selection(cur);
}

void addText::on_Butfinish_clicked()
{
    extern Card* __card;
    for(int i=0;i<len;i++)
    if(a[i])
    {
        int j=i;
        while(a[j+1]) j++;
        __card->option(2, QString::number(i) + "-" + QString::number(j));
        i=j+1;
    }
    emit second_finish();
    close();
}

void addText::selection(QTextCursor cur)
{

    int st=cur.selectionStart(), en=cur.selectionEnd();
    for(int i=st;i<en;i++) a[i]=1;

    QTextCharFormat fmt;
    fmt.setForeground(QColor(255,0,0));
    cur.mergeCharFormat(fmt);
    ui->text->setTextCursor(cur);
    ui->text->mergeCurrentCharFormat(fmt);
    cur.setPosition(en);
    ui->text->setTextCursor(cur);
}
