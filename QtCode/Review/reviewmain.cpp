#include "reviewmain.h"
#include "ui_reviewmain.h"
#include "LoginInfo.h"
#include "selectdate.h"

#include <QMessageBox>
#include <QtSql>

reviewMain::reviewMain(QWidget *parent) : QMainWindow(parent),
                                          ui(new Ui::reviewMain)
{
    ui->setupUi(this);

    QSqlQuery query;
    QString sql = QString("SELECT COUNT(*) AS `row` FROM card WHERE account = %1").arg(LoginInfo::getId());
    qDebug() << "Generated sql: " << sql;
    if (!query.exec(sql))
    {
        qDebug() << "Query Error: " << query.lastError().driverText();
        return;
    }
    if (query.first())
    {
        int num_all = query.value("row").toInt();
        ui->labelAll->setText((num_all == 0) ? ("You do not have any cards!") : (QString("You have %1 card(s) in total!").arg(num_all)));
    }

    generateTimestamp = QDateTime::currentDateTime().toSecsSinceEpoch();
    sql = QString("SELECT COUNT(*) AS `row` FROM card WHERE account = %1 AND next_review < %2").arg(LoginInfo::getId()).arg(generateTimestamp);
    qDebug() << "Generated sql: " << sql;
    if (!query.exec(sql))
    {
        qDebug() << "Query Error: " << query.lastError().driverText();
        return;
    }
    if (query.first())
    {
        int num_today = query.value("row").toInt();
        ui->labelToday->setText((num_today == 0) ? ("Today's review has finished!") : (QString("You have %1 card(s) to review today!").arg(num_today)));
    }
}

reviewMain::~reviewMain()
{
    delete ui;
    for(int i = 0; i < num; i++) delete review_list[i];
    delete [] review_list;
}

// fetch data from the database to generate the review card list
void reviewMain::generate_review_list(ReviewType type)
{
    num = 0;
    currentCard = 0;
    QSqlQuery query;
    QString sql = QString("SELECT COUNT(*) AS `row` FROM card WHERE account = %1 ").arg(LoginInfo::getId());
    if(type == Today)
        sql.append(QString("AND next_review < %1").arg(generateTimestamp));
    if(type == Ramdom)
        sql.append(selectDate::get_selection_SQL(generateTimestamp));
    qDebug() << "Generated sql: " << sql;
    if (!query.exec(sql))
    {
        qDebug() << "Query Error: " << query.lastError().driverText();
        return;
    }
    if (query.first())
        num = query.value("row").toInt();
    if(num != 0)
        review_list = new Card *[num];

    sql = QString("SELECT * FROM card WHERE account = %1 ").arg(LoginInfo::getId());
    if(type == Today)
        sql.append(QString("AND next_review < %2 ORDER BY next_review ASC ").arg(generateTimestamp));
    if(type == Ramdom)
        sql.append(selectDate::get_selection_SQL(generateTimestamp));
    qDebug() << "Generated sql: " << sql;
    if (!query.exec(sql))
    {
        qDebug() << "Query Error: " << query.lastError().driverText();
        return;
    }
    for (int i = 0; query.next(); i++)
    {
        int cardType = query.value(1).toInt();
        switch (cardType)
        {
        case 0:
            review_list[i] = new Plain;
            break;
        case 1:
            review_list[i] = new Text;
            break;
        case 2:
            review_list[i] = new Word;
            break;
        case 3:
            review_list[i] = new Choices;
            break;
        default:
            return;
        }
        review_list[i]->set_id(query.value(0).toInt());
        review_list[i]->set_review_time(query.value(4).toInt());
        review_list[i]->set_ac_time(query.value(5).toInt());
        // review_list[i]->set_next_time(query.value(10).toLongLong());
        review_list[i]->set_title(query.value(3).toString());
        review_list[i]->set_prob(query.value(8).toString());
        review_list[i]->option(4, query.value(9).toString());
    }
}

// if the force quit is triggered
void reviewMain::exit() {
    qDebug() << "triggered force quit";
    forceQuitFlag = true;
}

// the random or costomized test
void reviewMain::on_Butstart_clicked()
{
    num = 0;
    currentCard = 0;
    selectDate* selectdate = new selectDate(this);
    connect(selectdate, SIGNAL(forceQuit()), this, SLOT(exit()));
    connect(selectdate, SIGNAL(forceQuit()), this, SLOT(close()));
    selectdate->exec();
    if (forceQuitFlag) return ;
    generate_review_list(Ramdom);
    if (num == 0)
    {
        QMessageBox::warning(this, "No cards to Review", "There are no cards available for reviewing\nMaybe try another option :O", QMessageBox::Ok);
        return ;
    }
    simpleReview *temp = new simpleReview(this);
    temp->init(review_list[0]);
    connect(temp, SIGNAL(finished()), this, SLOT(next_card()));
    // connect(temp, SIGNAL(forceQuit()), this, SLOT(close()));
    temp->setWindowTitle(QString("Review Cards %1/%2").arg(currentCard+1).arg(num));
    this->close();
    temp->show();
}

// the daily test
void reviewMain::on_ButToday_clicked()
{
    num = 0;
    currentCard = 0;
    generate_review_list(Today);
    if (num == 0)
    {
        QMessageBox::warning(this, "No cards to Review", "There are no cards available for reviewing\nMaybe try another option :O", QMessageBox::Ok);
        return ;
    }
    simpleReview *temp = new simpleReview(this);
    temp->init(review_list[0]);
    connect(temp, SIGNAL(finished()), this, SLOT(next_card()));
    // connect(temp, SIGNAL(forceQuit()), this, SLOT(close()));
    temp->setWindowTitle(QString("Review Cards %1/%2").arg(currentCard+1).arg(num));
    this->close();
    temp->show();
}

// record the current card state and switch to the next one
// note that the window is reopened
void reviewMain::next_card()
{
    int reviewTimes = review_list[currentCard]->get_review_time();
    int id = review_list[currentCard]->get_id();
    long nextReview;
    reviewTimes++;
    if(reviewTimes > 5) nextReview = generateTimestamp + 30 * 24 * 60 * 60;
    else nextReview = generateTimestamp + reviewTimes * 48 * 60 * 60;
    
    QSqlQuery update;
    QString sql = QString("UPDATE card SET review_times = %1, last_review = %2, next_review = %3 WHERE account = %4 AND id = %5")
                    .arg(reviewTimes)
                    .arg(generateTimestamp)
                    .arg(nextReview)
                    .arg(LoginInfo::getId())
                    .arg(id);
    qDebug() << "Generated sql: " << sql;
    if (!update.exec(sql))
    {
        qDebug() << "Query Error: " << update.lastError().driverText();
        return;
    }

    currentCard++;
    if (currentCard == num)
    {
        QMessageBox *temp = new QMessageBox;
        temp->addButton("OK", QMessageBox::AcceptRole);
        temp->setText("No more cards to review!");
        temp->setIcon(QMessageBox::Information);
        temp->show();
        this->close();
    }
    else
    {
        simpleReview *temp = new simpleReview(this);
        temp->init(review_list[currentCard]);
        connect(temp, SIGNAL(finished()), this, SLOT(next_card()));
        // connect(temp, SIGNAL(forceQuit()), this, SLOT(close()));
        temp->setWindowTitle(QString("Review Cards %1/%2").arg(currentCard+1).arg(num));
        temp->show();
    }
}
