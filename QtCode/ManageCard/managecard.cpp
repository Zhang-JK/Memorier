#include "LoginInfo.h"
#include "managecard.h"
#include "ui_managecard.h"

#include <QtSql>
#include <QMessageBox>
#include <QElapsedTimer>

ManageCard::ManageCard(QWidget *parent) : QMainWindow(parent),
                                          ui(new Ui::ManageCard)
{
    ui->setupUi(this);

    connect(ui->search, SIGNAL(clicked()), this, SLOT(setCostumRows()));
    connect(ui->editCard, SIGNAL(clicked()), this, SLOT(editRow()));
    connect(ui->deleteCard, SIGNAL(clicked()), this, SLOT(deleteRow()));
    connect(ui->tableInfo, SIGNAL(itemSelectionChanged()), this, SLOT(selectOnTable()));
    connect(ui->back, SIGNAL(clicked()), this, SLOT(close()));

    labCellIndex = new QLabel("", this);
    labCellIndex->setMinimumWidth(250);
    ui->statusBar->addWidget(labCellIndex); //加到状态栏

    QTableWidgetItem *headerItem;
    QStringList headerText;
    headerText << "Id"
               << "Type"
               << "Create time"
               << "Review time"
               << "Title";                                 //表头标题用QStringList来表示
    ui->tableInfo->setColumnCount(headerText.count());     //列数设置为与 headerText的行数相等
    for (int i = 0; i < ui->tableInfo->columnCount(); i++) //列编号从0开始
    {
        headerItem = new QTableWidgetItem(headerText.at(i)); //新建一个QTableWidgetItem， headerText.at(i)获取headerText的i行字符串
        QFont font = headerItem->font();                     //获取原有字体设置
        font.setBold(true);                                  //设置为粗体
        font.setPointSize(15);                               //字体大小
        // headerItem->setTextColor(Qt::red);//字体颜色
        headerItem->setFont(font);                             //设置字体
        ui->tableInfo->setHorizontalHeaderItem(i, headerItem); //设置表头单元格的Item
    }
    ui->tableInfo->verticalHeader()->hide();
    ui->tableInfo->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->tableInfo->horizontalHeader()->setSectionResizeMode(4, QHeaderView::Stretch);
    ui->tableInfo->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableInfo->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableInfo->setSelectionBehavior(QAbstractItemView::SelectRows);

    setRows(-1, "");
}

void ManageCard::setRows(int type, QString title)
{
    ui->tableInfo->clearContents();

    QSqlQuery query;
    int row = 0;
    //初始化行数
    QString sql = QString("SELECT COUNT(*) AS `row` FROM card WHERE account = %1").arg(LoginInfo::getId());
    if (type != -1)
        sql.append(QString(" AND `type` = %1").arg(type));
    if (title != "")
        sql.append((" AND title LIKE '%" + title + "%'"));

    // query.exec(sql);
    qDebug() << "Generated sql: " << sql;
    if (!query.exec(sql))
    {
        qDebug() << "Query Error: " << query.lastError().driverText();
        return;
    }
    if (query.first())
    {
        row = query.value("row").toInt();
        ui->tableInfo->setRowCount(row);
    }
    ui->tableInfo->setColumnCount(5);

    //状态栏
    labCellIndex->setText(row > 1 ? QString("Total Cards: %1").arg(row) : QString("Total Card: %1").arg(row));

    //将数据库中的数据写入表格
    QStringList typeList = {"Plain Text", "Hollow Text", "Word", "Mult Choice"};
    sql = QString("SELECT * FROM card WHERE account = %1").arg(LoginInfo::getId());
    if (type != -1)
        sql.append(QString(" AND `type` = %1").arg(type));
    if (title != "")
        sql.append((" AND title LIKE '%" + title + "%'"));

    query.exec(sql);
    for (int i = 0; query.next(); i++)
    {
        QDateTime timestamp;
        ui->tableInfo->setItem(i, 0, new QTableWidgetItem(query.value(0).toString()));
        ui->tableInfo->setItem(i, 1, new QTableWidgetItem(typeList.at(query.value(1).toInt())));
        timestamp.setTime_t(query.value(6).toUInt());
        ui->tableInfo->setItem(i, 2, new QTableWidgetItem(timestamp.toString("yyyy-MM-dd hh:mm")));
        ui->tableInfo->setItem(i, 3, new QTableWidgetItem(query.value(4).toString()));
        ui->tableInfo->setItem(i, 4, new QTableWidgetItem(query.value(3).toString()));
    }
}

void ManageCard::setCostumRows()
{
    int type = ui->typeSelect->currentIndex() - 1;
    QString title = ui->titleSelect->text();
    setRows(type, title);
}

void ManageCard::deleteRow()
{
    if (selectedId == -1)
    {
        QMessageBox::warning(this, "Warning", "No card has been selected, please select a card first!", QMessageBox::Ok);
        return;
    }
    if (QMessageBox::question(this, "Delete Card", QString("Are you sure to Delete this card?\nId:\t%1\nTitle:\t%2\nThis operation is NOT reversible!").arg(selectedId).arg(selectedTitle), QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes)
    {
        QSqlQuery deleteCard;
        QString sql = QString("DELETE FROM card WHERE account = %1 AND id = %2").arg(LoginInfo::getId()).arg(selectedId);
        if (!deleteCard.exec(sql))
        {
            qDebug() << "Query Error: " << deleteCard.lastError().driverText();
            QMessageBox::warning(this, "Failed", deleteCard.lastError().driverText(), QMessageBox::Ok);
            return;
        }
        setCostumRows();
    }
}

void ManageCard::editRow()
{
    QMessageBox::warning(this, "没写", "是真的妹写", QMessageBox::No);
}

void ManageCard::selectOnTable()
{
    QList<QTableWidgetItem *> items = ui->tableInfo->selectedItems();
    if (items.count() == 0)
    {
        ui->cardIndicator->setText("No card has been chosen");
        selectedId = -1;
        selectedTitle = "";
        return;
    }
    QTableWidgetItem *item = items.at(0);
    QString text = item->text();
    item = items.at(4);
    QString title = item->text();
    selectedId = text.toInt();
    selectedTitle = title;
    ui->cardIndicator->setText("Chosen Card Id: " + text);
}

ManageCard::~ManageCard()
{
    delete ui;
}
