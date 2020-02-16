#ifndef DASHBOARDWINDOW_H
#define DASHBOARDWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class DashboardWindow; }
QT_END_NAMESPACE

class DashboardWindow : public QMainWindow
{
    Q_OBJECT

public:
    DashboardWindow(QWidget *parent = nullptr);
    ~DashboardWindow();

private:
    Ui::DashboardWindow *ui;
};
#endif // DASHBOARDWINDOW_H
