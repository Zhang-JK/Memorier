#include "test.h"
#include "ui_test.h"
#include "AddCard/addcard.h"

#include <QtSql>

test::test(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::test)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(addCard_push()));
}

void test::addCard_push()
{
    AddCard *addcard = new AddCard(this);
    connect(addcard, SIGNAL(addcard_sendInfo(Card *)), this, SLOT(addCard_data(Card *)));
    addcard->show();
}

void test::addCard_data(Card *temp)
{
    QSqlQuery update;
    long timestamp = QDateTime::currentDateTime().toSecsSinceEpoch();
    QString sqlUpdate = QString("INSERT INTO Memorier.card (`type`,account,title,review_times,ac_time,create_time,last_review,question,answer,proficiency) VALUES (%1,%2,'%3',%4,%5,%6,%7,'%8','%9',%10);")
                            .arg(int(temp->get_type()))  // type
                            .arg(1)                    // accountId
                            .arg(temp->title)          // title
                            .arg(0)                    // review_times
                            .arg(0)                    // ac_time
                            .arg(timestamp)            // create_time
                            .arg(timestamp)            // last_review
                            .arg(temp->get_prob())     // question
                            .arg(temp->option(3))      // answer
                            .arg(0);                   // proficiency
    qDebug() << "Generated sql: " << sqlUpdate;
    if (!update.exec(sqlUpdate))
        qDebug() << "Query Error: " << update.lastError().driverText();
}

test::~test()
{
    delete ui;
}
