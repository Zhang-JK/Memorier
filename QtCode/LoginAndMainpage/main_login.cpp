#include "mainwindow.h"
#include "LoginInfo.h"

#include <QApplication>
#include <QPixmap>
#include <QPalette>

#include <QtSql>

// This file is used to test login function, not useful in the project

// int main(int argc, char *argv[])
// {
//     QApplication a(argc, argv);
//     MainWindow w;

//     QSqlDatabase db;
//     db = QSqlDatabase::addDatabase("QMYSQL");
//     db.setHostName("laojk.club");   //数据库服务器IP
//     db.setUserName("root");         //用户名
//     db.setPassword("45922622qaz");  //密码
//     db.setDatabaseName("Memorier"); //使用的数据库
//     qDebug() << "Database Connecting";

//     if (!db.open())
//     {
//         qDebug() << "ERROR: " << db.lastError().text(); //数据库打开失败
//     }
//     else
//     {
//         w.show();
//     }

//     return a.exec();
// }
