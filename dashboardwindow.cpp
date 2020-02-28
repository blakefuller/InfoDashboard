#include "dashboardwindow.h"
#include "ui_dashboardwindow.h"

#include <QFileDialog>
#include <iostream>
#include <QMessageBox>
#include <vector>

DashboardWindow::DashboardWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::DashboardWindow)
    , timer(new QTimer)
    , frameTimer(new QTimer)
    , toDoModel (new ToDoModel(this))
    , httpManager (new HttpManager)
{
    ui->setupUi(this);
    // points to do list to tableview
    ui->todolist->setModel(toDoModel);

    // connect clock
    connect(timer, SIGNAL(timeout()),
            this, SLOT(setCurrentTime()));
    setCurrentTime();
    timer->start(1000);

    // connect frame clock
    connect(frameTimer, SIGNAL(timeout()),
            this, SLOT(setFrameTime()));
    setFrameTime();
    frameTimer->start(10000);

    frameNum = 0;
    loadImage();
    ui->frameLabel->setPixmap(pics);



    //connecting HttpManager
    connect(httpManager, SIGNAL(WeatherJsonReady(QJsonObject *)),
            this, SLOT(processWeatherJson(QJsonObject *)));
}

DashboardWindow::~DashboardWindow()
{
    delete ui;
}

void DashboardWindow::setCurrentTime()
{
    QTime time = QTime::currentTime();


    QString hour = time.toString("hh");
    QString worldHour = time.toString("hh+7");  //shifted 8 hours for greenwich time
    QString minute = time.toString("mm");
    QString second = time.toString("ss");

    //current time
    ui->hourLCD->display(hour);
    ui->minuteLCD->display(minute);
    ui->secondLCD->display(second);

    //world time
    ui->worldHourLCD->display(worldHour);
    ui->worldMinuteLCD->display(minute);
    ui->worldSecondLCD->display(second);
}

void DashboardWindow::setFrameTime()
{
    if(frameNum < picNames.length())
        frameNum++;
    else
        frameNum = 0;

    loadImage();
    ui->frameLabel->setPixmap(pics);
}

void DashboardWindow::loadImage()
{
    picNames.prepend("19488752_1501993383192064_4566436695561068900_o.jpg");
    picNames.prepend("37185133_1890616464329752_8201941175058300928_o.jpg");
    picNames.prepend("37715743_1900109846713747_9207013816389337088_o.jpg");
    picNames.prepend("39347_101496846575065_5129752_n.jpg");
    picNames.prepend("418383_316157708442310_1953668505_n.jpg");
    picNames.prepend("423690_322467191144695_1612927000_n.jpg");

    QString picFile = picNames[frameNum];

    if(pics.load(picFile))
    {
        std::cout << "Image loaded!" << std::endl;
        pics = pics.scaled(ui->frameLabel->size(), Qt::KeepAspectRatioByExpanding);
    }
}


void DashboardWindow::on_actionOpen_to_do_list_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Open To-do List"),"",
                                                    tr("To-do List (*.csv);;All File (*)"));

    toDoModel->openFile(fileName);
}

void DashboardWindow::on_pushButton_clicked()
{
    QString zip = ui->zipCodeEdit->text();
    qDebug() << zip;
    httpManager->sendWeatherRequest(zip);
}

void DashboardWindow::processWeatherJson(QJsonObject *json)
{
    qDebug() << "Json ready";

    QString weather = json->value("weather").toArray()[0].toObject()["main"].toString();
    QString description = json->value("weather").toArray()[0].toObject()["description"].toString();
    double temp = json->value("main").toObject()["temp"].toDouble();
    double tempMin = json->value("main").toObject()["temp_min"].toDouble();
    double tempMax = json->value("main").toObject()["temp_max"].toDouble();

    qDebug() << weather;
    qDebug() << description;
    qDebug() << temp;
    qDebug() << tempMin;
    qDebug() << tempMax;
}
