#include "APIRequest.h"

QString translateAPI(QString text, QString target, QString source)
{
    QString requestUrl = "https://v1.alapi.cn/api/fanyi";
    QUrl url(requestUrl);

    QUrlQuery data;
    data.addQueryItem("q", text);
    data.addQueryItem("from", source);
    data.addQueryItem("to", target);
    url.setQuery(data);

    // 构造请求
    QNetworkRequest request;
    request.setUrl(url);
    QNetworkAccessManager manager;

    // 发送请求
    qDebug() << request.url();
    QNetworkReply *response = manager.get(request);

    // 开启一个局部的事件循环，等待响应结束，退出
    QEventLoop eventLoop;
    QObject::connect(&manager, &QNetworkAccessManager::finished, &eventLoop, &QEventLoop::quit);
    eventLoop.exec();

    // 获取响应信息
    return translateDataHandler(response);
}

QString translateDataHandler(QNetworkReply *response)
{
    QString all = response->readAll();
    // qDebug() << all;

    QJsonParseError err;
    QJsonDocument json_recv = QJsonDocument::fromJson(all.toUtf8(), &err);
    QString translateResult = "";

    if (!json_recv.isNull())
    {
        QJsonObject all = json_recv.object();
        if (all.contains("data"))
        {
            QJsonArray result = all.value("data").toObject().value("trans_result").toArray();
            // qDebug() << result;
            // QJsonObject test4 = result.at(0).toObject();
            // QJsonValue test5 = test4.value("dst");
            translateResult = result.at(0).toObject().value("dst").toString();
        }
    }

    return translateResult;
}