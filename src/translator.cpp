#include "translator.h"

#include <QNetworkReply>
#include <QSslConfiguration>

#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

#include <QEventLoop>

#include <QFile>
#include <QTextStream>
#include <iostream>

translator::translator(QObject *parent)
    : QObject(parent)
    , manager(new QNetworkAccessManager(this))
{
    manager->setCache(nullptr);
}

QString translator::translate(const QString &text)
{
    if (apiKey_.size() == 0 || folderId_.size() == 0) {
        loadAPIAndFolderKeys();
    }

    // 1. Подготовка запроса
    QUrl url("https://translate.api.cloud.yandex.net/translate/v2/translate");
    QNetworkRequest request(url);

    // 2. Настройки безопасности
    QSslConfiguration sslConfig = request.sslConfiguration();
    sslConfig.setProtocol(QSsl::TlsV1_2OrLater);
    request.setSslConfiguration(sslConfig);

    // 3. Заголовки
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader("Authorization", QString("Api-Key %1").arg(apiKey_).toUtf8());

    // 4. Тело запроса
    QJsonObject requestBody;
    requestBody["folderId"] = folderId_;
    requestBody["texts"] = QJsonArray{text};
    requestBody["targetLanguageCode"] = getTargetLang();
    requestBody["sourceLanguageCode"] = getSourceLang();

    // 5. Отправка запроса
    QNetworkReply *reply = manager->post(request, QJsonDocument(requestBody).toJson());

    // 6. Ожидание ответа
    QEventLoop loop;
    connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();

    // 7. Обработка ответа
    QString result;
    if (reply->error() == QNetworkReply::NoError) {
        QJsonDocument doc = QJsonDocument::fromJson(reply->readAll());
        if (doc.object().contains("translations")) {
            result = doc.object()["translations"].toArray()[0].toObject()["text"].toString();
        }
    }

    // 8. Очистка
    reply->deleteLater();
    return result.isEmpty() ? "Translation error" : result;
}

void translator::loadAPIAndFolderKeys()
{
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly)) {
        std::cerr << "Failed to open file for reading";
    }
    for (int count_line = 0; count_line < 2; count_line++) {
        QByteArray line = file.readLine();
        if (line.contains("APIKey:")) {
            apiKey_ = QString::fromUtf8(line.mid(7).trimmed());
        } else {
            folderId_ = QString::fromUtf8(line.mid(10).trimmed());
        }
    }
    file.close();
}

void translator::saveAPIAndFolderKeys(QString APIKey, QString folderKey)
{
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text | QIODevice::ReadWrite)) {
        qDebug() << "Failed to open file for writing";
        return;
    }
    QTextStream stream(&file);
    stream << "APIKey: " << APIKey << Qt::endl;
    stream << "FolderId: " << folderKey << Qt::endl;
    file.close();
}

bool translator::checkSecretFile()
{
    QFile file(filePath);

    if (!file.exists()) {
        qDebug() << "Config file does not exist";
        return false;
    }

    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "Failed to open file for reading";
        return false;
    }

    bool isEmpty = file.size() == 0;
    file.close();

    if (isEmpty) {
        qDebug() << "Config file is empty";
        return false;
    }

    return true;
}

void translator::clearKeysFile()
{
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
        qDebug() << "Failed to clear file:" << file.errorString();
        return;
    }
    file.close();
}

void translator::setSourceLang(QString sourceLang)
{
    sourceLang_ = sourceLang;
}

void translator::setTargetLang(QString targetLang)
{
    targetLang_ = targetLang;
}
