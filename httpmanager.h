#ifndef HTTPMANAGER_H
#define HTTPMANAGER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

class HttpManager : public QObject
{
    Q_OBJECT
public:
    explicit HttpManager(QObject *parent = nullptr);
    ~HttpManager();

    void sendWeatherRequest(QString zip);

signals:
    void WeatherJsonReady(QJsonObject *json);

private slots:
    void WeatherDownloadedHandler(QNetworkReply *reply);

private:
    QNetworkAccessManager *weatherAPIManager;
};

#endif // HTTPMANAGER_H
