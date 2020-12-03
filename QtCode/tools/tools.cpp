#include <tools.h>

#include <QtSql>

// generate a random string of certain length, will be used in salt and session
QString getRandomString(int length)
{
    qsrand(QDateTime::currentMSecsSinceEpoch());

    const char ch[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
    int size = sizeof(ch);

    char *str = new char[length + 1];

    int num = 0;
    for (int i = 0; i < length; ++i)
    {
        num = qrand() % (size - 1);
        str[i] = ch[num];
    }

    QString res(str);
    qDebug() << "Generated random string: " << res;
    return res;
}

// add log to the database
bool InsertLog(int id, QString recording) {
    QSqlQuery insert;
    QString sqlInsLog = QString("INSERT INTO account_log SET account_id=%1, log_time='%2', recording='%3'")
                            .arg(id)
                            .arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"))
                            .arg(recording);
    qDebug() << "Generated sql: " << sqlInsLog;
    if (!insert.exec(sqlInsLog)){
        qDebug() << "Query Error: " << insert.lastError().driverText();
        return false;
    }
    return true;
}