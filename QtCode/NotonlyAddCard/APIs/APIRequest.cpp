#include "APIRequest.h"

QString translateDataHandler(QNetworkReply *response);
QList<QString> textRazorHandler(QNetworkReply *response, QString& text);

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

QList<QString> textRazorAPI(QString text)
{
    QNetworkRequest httpRequest;
    QNetworkAccessManager networkAccessManager;

    httpRequest.setRawHeader("Content-Type", "application/x-www-form-urlencoded");
    httpRequest.setRawHeader("X-TextRazor-Key", "c9cd30a5e5b83cdc80129910343644733ac4f781efc5e1d59191bb27");

    QUrlQuery params;
    params.addQueryItem("text", text);
    params.addQueryItem("extractors", "entities");

    QUrl url("http://api.textrazor.com/");
    url.setPath("/");
    httpRequest.setUrl(url);
    qDebug() << httpRequest.url();
    qDebug() << params.query();
    QNetworkReply *response = networkAccessManager.post(httpRequest, params.query().toUtf8());

    // 开启一个局部的事件循环，等待响应结束，退出
    QEventLoop eventLoop;
    QObject::connect(&networkAccessManager, &QNetworkAccessManager::finished, &eventLoop, &QEventLoop::quit);
    eventLoop.exec();

    // QString all = response->readAll();
    // qDebug() << all;
    return textRazorHandler(response, text);
}

QList<QString> textRazorHandler(QNetworkReply *response, QString& text)
{
    QString all = response->readAll();

    QJsonParseError err;
    QJsonDocument json_recv = QJsonDocument::fromJson(all.toUtf8(), &err);
    QList<QString> result;

    if (!json_recv.isNull())
    {
        QJsonObject obj = json_recv.object();
        if (all.contains("response"))
        {
            obj = obj.value("response").toObject(); //.value("entities").toObject();
            QJsonArray array = obj.value("entities").toArray();
            int length = 7;
            if(array.size() < 7) length = array.size();
            for(int i = 0; i < length; i++)
                if(text.contains(array[i].toObject().value("entityId").toString()))
                    result.append(array[i].toObject().value("entityId").toString());
        }
    }
    qDebug() << result;
    return result;
}
