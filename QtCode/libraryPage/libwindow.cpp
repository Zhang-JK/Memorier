#include "libwindow.h"
#include "ui_libwindow.h"
#include "LoginInfo.h"

#include <QtSql>

LibWindow::LibWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LibWindow)
{
    ui->setupUi(this);

    setWindowTitle("Memerior");

    QPixmap pixmap(":/image/images/bg_resize.jpg"); //设定图片
    QPalette palette;                               //创建一个调色板对象
    palette.setBrush(backgroundRole(), QBrush(pixmap));
    setPalette(palette);         //设置窗口调色板为palette，窗口和画笔相关联
    setAutoFillBackground(true); //设置窗体自动填充背景

    connect(ui->add, SIGNAL(clicked()), this, SLOT(addCard_push()));
    connect(ui->review, SIGNAL(clicked()),this , SLOT(review_push()));
}

void LibWindow::addCard_push()
{
    AddCard *addcard = new AddCard(this);
    connect(addcard, SIGNAL(addcard_sendInfo(Card *)), this, SLOT(addCard_data(Card *)));
    addcard->show();
}

void LibWindow::review_push()
{
    reviewMain* reviewmain = new reviewMain(this);
    reviewmain->generate_review_list();
    reviewmain->show();
}

void LibWindow::addCard_data(Card *temp)
{
    QSqlQuery update;
    long timestamp = QDateTime::currentDateTime().toSecsSinceEpoch();
    temp->set_id(LoginInfo::getId());
    temp->set_init_time(timestamp);
    QString sqlUpdate = QString("INSERT INTO card (`type`,account,title,review_times,ac_time,create_time,last_review,question,answer,next_review) VALUES (%1,%2,'%3',%4,%5,%6,%7,'%8','%9',%10)")
                            .arg(int(temp->get_type()))     // type
                            .arg(temp->get_id())            // accountId
                            .arg(temp->title)               // title
                            .arg(0)                         // review_times
                            .arg(0)                         // ac_time
                            .arg(timestamp)                 // create_time
                            .arg(timestamp)                 // last_review
                            .arg(temp->get_prob())          // question
                            .arg(temp->option(3))           // answer
                            .arg(temp->get_nextReview());   // next_review
    qDebug() << "Generated sql: " << sqlUpdate;
    if (!update.exec(sqlUpdate))
        qDebug() << "Query Error: " << update.lastError().driverText();
}

LibWindow::~LibWindow()
{
    delete ui;
}
