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

QString translateAPI(QString text, QString target = "zh", QString source = "en");
QString translateDataHandler(QNetworkReply *response);

#endif
