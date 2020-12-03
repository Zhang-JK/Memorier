#include "LoginInfo.h"
#include <QFile>
#include <QTextStream>
#include <QJsonObject>
#include <QJsonDocument>

bool LoginInfo::loginState = false;
int LoginInfo::id = 0;
QString LoginInfo::username = "";
QString LoginInfo::session = "";

// save the log info to the local file .session
void LoginInfo::saveLoginInfo()
{
    QFile file(".session");
    if (file.open(QFile::WriteOnly | QIODevice::Truncate))
    {
        QJsonObject logInfo;
        logInfo.insert("id", LoginInfo::id);
        logInfo.insert("username", LoginInfo::username);
        logInfo.insert("session", LoginInfo::session);
        QTextStream out(&file);
        out << QString(QJsonDocument(logInfo).toJson());
    }
}

// read the login info from the local file .session
void LoginInfo::readLoginInfo()
{
    QFile file(".session");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QByteArray data = file.readAll();
    file.close();

    QJsonParseError json_error;
    QJsonDocument jsonDoc(QJsonDocument::fromJson(data, &json_error));
    if(json_error.error != QJsonParseError::NoError) return ;

    QJsonObject obj = jsonDoc.object();
    if(obj.contains("id") && obj.contains("username") && obj.contains("session")) 
        {id = obj["id"].toInt(); username = obj["username"].toString(); session = obj["session"].toString(); loginState = true;}
    else return ;
}

// clean .session for safety
void LoginInfo::cleanLoginInfo() {
    id = 0; username = ""; session = ""; loginState = false;
    QFile file(".session");
    if (file.open(QFile::WriteOnly | QIODevice::Truncate))
    {
        QTextStream out(&file);
        out << "";
    }
}