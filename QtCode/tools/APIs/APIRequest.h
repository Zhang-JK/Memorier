#ifndef API_REQUEST
#define API_REQUEST

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrlQuery>

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

#include <QEventLoop>
#include <QString>

// call the translate API for auto translating
QString translateAPI(QString text, QString target = "en", QString source = "zh");
// QString translateDataHandler(QNetworkReply *response);

// call the key word extract API for auto selecting
QList<QString> textRazorAPI(QString text);
// QList<QString> textRazorHandler(QNetworkReply *response);

#endif