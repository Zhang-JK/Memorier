#include "mainwindow.h"
#include "libwindow.h"
#include "LoginInfo.h"

#include <QApplication>
#include <QPixmap>
#include <QPalette>
#include <QObject>
#include <QMessageBox>

#include <QtSql>

#include "main.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    LibWindow lw;

    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QMYSQL");
    // delete the database info if you want to share the code!
    db.setHostName(DATABASE_URL);   //数据库服务器IP
    db.setUserName(DATABASE_USER);         //用户名
    db.setPassword(DATABASE_PASSWORD);  //密码
    db.setDatabaseName(DATABASE_NAME); //使用的数据库
    // delete the database info if you want to share the code!
    qDebug() << "Database Connecting...";

    if (!db.open())
    {
        qDebug() << "Database Connection Failed!";
        qDebug() << "ERROR: " << db.lastError().text(); //数据库打开失败
        QMessageBox::warning(nullptr, "Database Fail to Connect", "Please check your network connection and make sure you have QMYSQL driver ready!\nError: "+db.lastError().text(), QMessageBox::Close);
        return 0;
    }
    else
    {
        qDebug() << "Database Connected!";
        w.show();
        lw.hide();
        QObject::connect(&w, SIGNAL(libStart()), &lw, SLOT(show()));
        return a.exec();
    }

}
