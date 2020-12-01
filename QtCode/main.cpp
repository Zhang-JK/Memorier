#include "mainwindow.h"
#include "libwindow.h"
#include "LoginInfo.h"

#include <QApplication>
#include <QPixmap>
#include <QPalette>
#include <QObject>
#include <QMessageBox>

#include <QtSql>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    LibWindow lw;

    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("laojk.club");   //数据库服务器IP
    db.setUserName("root");         //用户名
    db.setPassword("45922622qaz");  //密码
    db.setDatabaseName("Memorier"); //使用的数据库
    qDebug() << "Database Connecting...";

    if (!db.open())
    {
        qDebug() << "Database Connection Failed!";
        qDebug() << "ERROR: " << db.lastError().text(); //数据库打开失败
        QMessageBox::warning(nullptr, "Database Fail to Connect", "Please check your network connection and make sure you have QMYSQL driver ready!\nError: "+db.lastError().text(), QMessageBox::Close);
    }
    else
    {
        qDebug() << "Database Connected!";
        w.show();
        lw.hide();
        QObject::connect(&w, SIGNAL(libStart()), &lw, SLOT(show()));
    }

    return a.exec();
}
