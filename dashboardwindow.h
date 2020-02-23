#ifndef DASHBOARDWINDOW_H
#define DASHBOARDWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QTime>
#include "todomodel.h"
#include "httpmanager.h"

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

    void on_actionOpen_to_do_list_triggered();

private:
    Ui::DashboardWindow *ui;
    QTimer *timer;

    ToDoModel *toDoModel;
    HttpManager *httpManager;
};
#endif // DASHBOARDWINDOW_H
