#include "testmain.h"
#include "ui_testmain.h"
#include "LoginInfo.h"
#include "selectdate.h"
#include <QtSql>
#include <QMessageBox>

testMain::testMain(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::testMain)
{
    ui->setupUi(this);
    this->setWindowTitle("Ready to test..");

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
        ui->TxtInfo->setText((num_all == 0) ? ("You do not have any cards!") : (QString("You have %1 card(s) in total!").arg(num_all)));
    }

    generateTimestamp = QDateTime::currentDateTime().toSecsSinceEpoch();
    sql = QString("SELECT COUNT(*) AS `row` FROM card WHERE account = %1 AND next_test < %2").arg(LoginInfo::getId()).arg(generateTimestamp);
    qDebug() << "Generated sql: " << sql;
    if (!query.exec(sql))
    {
        qDebug() << "Query Error: " << query.lastError().driverText();
        return;
    }
    if (query.first())
    {
        int num_today = query.value("row").toInt();
        ui->TxtTest->setText((num_today == 0) ? ("Today's test has finished!") : (QString("You have %1 card(s) to test today!").arg(num_today)));
    }
}

testMain::~testMain()
{
    delete [] testlist;
    delete ui;
}

void testMain::generate_testlist(TestType type)
{
    num = 0;
    currentCard = 0;
    QSqlQuery query;
    QString sql = QString("SELECT COUNT(*) AS `row` FROM card WHERE account = %1 ").arg(LoginInfo::getId());
    if(type == Today)
        sql.append(QString("AND next_test < %1").arg(generateTimestamp));
    if(type == Self)
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
        testlist = new Card *[num];

    sql = QString("SELECT * FROM card WHERE account = %1 ").arg(LoginInfo::getId());
    if(type == Today)
        sql.append(QString("AND next_test < %2 ORDER BY next_test ASC ").arg(generateTimestamp));
    if(type == Self)
        sql.append("ORDER BY RAND()");
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
            testlist[i] = new Plain;
            break;
        case 1:
            testlist[i] = new Text;
            break;
        case 2:
            testlist[i] = new Word;
            break;
        case 3:
            testlist[i] = new Choices;
            break;
        default:
            return;
        }
        testlist[i]->set_id(query.value(0).toInt());
        testlist[i]->set_review_time(query.value(4).toInt());
        testlist[i]->set_ac_time(query.value(5).toInt());
        testlist[i]->set_title(query.value(3).toString());
        testlist[i]->set_prob(query.value(8).toString());
        testlist[i]->option(4, query.value(9).toString());
    }
}

void testMain::display_test(Card* card)
{
    simpleTest *temp = new simpleTest(this);
    temp->init(card);
    connect(temp, SIGNAL(finished()), this, SLOT(next_card()));
    temp->setWindowTitle(QString("Review Cards %1/%2").arg(currentCard+1).arg(num));
    temp->show();
}

void testMain::on_ButSelf_clicked()
{
    currentCard = 0;
    selectDate* selectdate = new selectDate(this);
    selectdate->exec();
    generate_testlist(Self);
    if (num == 0)
    {
        QMessageBox::warning(this, "No cards to Review", "There are no cards available for reviewing\nMaybe try another option :O", QMessageBox::Ok);
        return ;
    }
    this->close();
    display_test(testlist[0]);
}

void testMain::on_ButToday_clicked()
{
    currentCard = 0;
    generate_testlist(Today);
    if (num == 0)
    {
        QMessageBox::warning(this, "No cards to Review", "There are no cards available for reviewing\nMaybe try another option :O", QMessageBox::Ok);
        return ;
    }
    this->close();
    display_test(testlist[0]);
}

void testMain::next_card()
{
    int next_test = testlist[currentCard]->get_nextTest();
    int ac_time = testlist[currentCard]->get_ac_time();
    int id = testlist[currentCard]->get_id();
    int review_time = testlist[currentCard]->get_review_time();
    QSqlQuery update;
    QString sql = QString("UPDATE card SET review_times = %1, ac_time = %2, last_review = %3, next_test = %4 WHERE account = %5 AND id = %6")
                    .arg(review_time)
                    .arg(ac_time)
                    .arg(generateTimestamp)
                    .arg(next_test)
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
        display_test(testlist[currentCard]);
    }
}
