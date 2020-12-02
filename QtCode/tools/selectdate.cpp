#include "selectdate.h"
#include "ui_selectdate.h"

#include <QMessageBox>

selectDate::selectDate(QWidget *parent) : QDialog(parent),
                                          ui(new Ui::selectDate)
{
    ui->setupUi(this);
    this->setWindowTitle("Choose range..");

    selection = "-1.";

    ui->dateBox->addItem("Today");
    ui->dateBox->addItem("Yesterday");
    ui->dateBox->addItem("3 days");
    ui->dateBox->addItem("7 days");
    ui->dateBox->addItem("14 days");
    ui->dateBox->addItem("30 days");
    ui->dateBox->addItem("All");

    check[0] = ui->CheckPlain;
    check[1] = ui->CheckText;
    check[2] = ui->CheckWord;
    check[3] = ui->CheckChoices;

    for (int i = 0; i < 4; i++)
        connect(check[i], SIGNAL(clicked()), this, SLOT(check_selection_all()));
    /*
    connect(ui->CheckPlain, SIGNAL(stateChanged()), this, SLOT(check_selection_all()));
    connect(ui->CheckText, SIGNAL(stateChanged()), this, SLOT(check_selection_all()));
    connect(ui->CheckWord, SIGNAL(stateChanged()), this, SLOT(check_selection_all()));
    connect(ui->CheckChoices, SIGNAL(stateChanged()), this, SLOT(check_selection_all()));
    */
}

selectDate::~selectDate()
{
    delete ui;
}

QString selectDate::selection = "-1.";

void selectDate::on_Butfinish_clicked()
{
    selection = QString::number(transform_days[ui->dateBox->currentIndex()]);
    for (int i = 0; i < 4; ++i)
    {
        if (check[i]->isChecked())
            selection = selection + "+" + QString::number(i);
    }
    selection = selection + ".";
    if (!selection.contains("+"))
    {
        QMessageBox::warning(this, "No type selected", "Please at least select one type!", QMessageBox::Ok);
        return ;
    }
    forceQuitFlag = false;
    this->close();
}

void selectDate::on_CheckAll_clicked()
{
    for (int i = 0; i < 4; i++)
        check[i]->setCheckState(ui->CheckAll->checkState());
}

void selectDate::check_selection_all()
{
    bool allchecked = 1;
    for (int i = 0; i < 4; i++)
        allchecked &= check[i]->isChecked();
    ui->CheckAll->setCheckState((allchecked == 1 ? Qt::Checked : Qt::Unchecked));
}

QString selectDate::get_selection_SQL(long timestamp)
{
    int i = 0;
    QString str = selection;
    QString sql = "";
    while (str[i] != '+' && str[i] != '.')
        i++;
    int t = str.left(i).toInt();
    if (t > -1)
    {
        t = timestamp - t * 86400;
        sql.append(QString("AND create_time > %1 ").arg(t));
    }
    str.remove(0, i + 1);

    if (str.length())
    {
        sql = sql + "AND (";
        int flag = 0;
        while (str.length())
        {
            i = 0;
            while (str[i] != '+' && str[i] != '.')
                i++;
            t = str.left(i).toInt();
            if (flag)
                sql = sql + "OR ";
            else
                flag = 1;
            sql.append(QString("type = %1 ").arg(t));
            str.remove(0, i + 1);
        }
        sql.append(QString(")"));
    }
    return sql;
}

void selectDate::closeEvent(QCloseEvent *event)
{
    if (forceQuitFlag)
        emit forceQuit();
}
