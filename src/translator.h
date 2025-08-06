#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include <QNetworkAccessManager>
#include <QNetworkReply>

#include <QObject>

#include <QCoreApplication>
#include <QDir>

class translator : public QObject
{
    Q_OBJECT
public:
    explicit translator(QObject* parent = nullptr);

    QString translate(const QString& text);

    void loadAPIAndFolderKeys();
    void saveAPIAndFolderKeys(QString APIKey, QString folderKey);

    bool checkSecretFile();

private:
    QNetworkAccessManager* manager;

    QString apiKey_ = "";
    QString folderId_ = "";

    const QString targetLang_ = "ru";

    QString appDir = QCoreApplication::applicationDirPath();
    QString filePath = QDir(appDir).filePath("secret/keys.txt");
};

#endif // TRANSLATOR_H
