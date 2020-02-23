#include "dashboardwindow.h"
#include "ui_dashboardwindow.h"

DashboardWindow::DashboardWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::DashboardWindow),
    timer(new QTimer)
{
    ui->setupUi(this);

    connect(timer, SIGNAL(timeout()),
            this, SLOT(setCurrentTime()));

    setCurrentTime();
    timer->start(1000);
}

DashboardWindow::~DashboardWindow()
{
    delete ui;
}

void DashboardWindow::setCurrentTime()
{
    QTime time = QTime::currentTime();

    QString hour = time.toString("hh");
    QString minute = time.toString("mm");
    QString second = time.toString("ss");

    //current time
    ui->hourLCD->display(hour);
    ui->minuteLCD->display(minute);
    ui->secondLCD->display(second);

    //shifted 8 hours for greenwich time
    timezone = greenwich;
    ui->worldHourLCD->display(hour+timezone);
    ui->worldMinuteLCD->display(minute);
    ui->worldSecondLCD->display(second);
}

