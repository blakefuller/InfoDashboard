#ifndef DASHBOARDWINDOW_H
#define DASHBOARDWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QTime>
#include <QPixmap>
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

private slots:
    void setCurrentTime();
    void setFrameTime();
    void loadImage();

    void on_actionOpen_to_do_list_triggered();

    void on_pushButton_clicked();

    void processWeatherJson(QJsonObject *json);

private:
    Ui::DashboardWindow *ui;
    QTimer *timer;
    QTimer *frameTimer;
    int frameNum;
    QVector<QString> picNames;

    QPixmap pics;

    ToDoModel *toDoModel;
    HttpManager *httpManager;
};
#endif // DASHBOARDWINDOW_H
