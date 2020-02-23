#ifndef DASHBOARDWINDOW_H
#define DASHBOARDWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QTime>

QT_BEGIN_NAMESPACE
namespace Ui { class DashboardWindow; }
QT_END_NAMESPACE

class DashboardWindow : public QMainWindow
{
    Q_OBJECT

public:
    DashboardWindow(QWidget *parent = nullptr);
    ~DashboardWindow();

    //ideally, a table of timezones
    int greenwich = 8;

private slots:
    void setCurrentTime();

private:
    Ui::DashboardWindow *ui;
    QTimer *timer;

};
#endif // DASHBOARDWINDOW_H
