#include "mainwindow.h"

#include <QApplication>
#include <QPixmap>
#include <QPalette>

#include <QtSql>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("laojk.club");   //数据库服务器IP
    db.setUserName("root");         //用户名
    db.setPassword("45922622qaz");  //密码
    db.setDatabaseName("Memorier"); //使用的数据库
    qDebug() << "Database Connecting";

    if (!db.open())                                     //打开数据库
        qDebug() << "ERROR: " << db.lastError().text(); //数据库打开失败

    w.show();
    return a.exec();
}
