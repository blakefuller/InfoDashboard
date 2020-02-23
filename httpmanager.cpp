#include "httpmanager.h"

HttpManager::HttpManager(QObject *parent) :
    QObject(parent),
    weatherAPIManager(new QNetworkAccessManager)
{

}

HttpManager::~HttpManager()
{
    delete weatherAPIManager;
}

void HttpManager::sendWeatherRequest(QString zip)
{
    QNetworkRequest request;

    QString address = "http://api.openweathermap.org/data/2.5/weather?zip="
                      + zip + ",us&units=imperial&appid=b06ccb2acf7eda5f16dc87809eda5deb";

    request.setUrl(QUrl(address));
    weatherAPIManager->get(request);
    qDebug() << "Weather Request Sent to Address " << request.url();
}

void HttpManager::WeatherDownloadedHandler(QNetworkReply *reply)
{
    qDebug() << "Weather Reply has arrived";
    if(reply->error())
    {
        qDebug() << reply->errorString();
        return;
    }
    qDebug() << "Download was successful";

    QString answer = reply->readAll();
    reply->deleteLater();

    QJsonDocument jsonResponse = QJsonDocument::fromJson(answer.toUtf8());
    QJsonObject *jsonObj = new QJsonObject(jsonResponse.object());

    emit WeatherJsonReady(jsonObj);
}

void HttpManager::processWeatherJson(QJsonObject *json)
{
    qDebug() << json->value("weather");
}
