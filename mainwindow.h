#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QTimer>
#include "tasklist.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class mainWindow;
}
QT_END_NAMESPACE

class mainWindow : public QWidget
{
    Q_OBJECT

public:
    mainWindow(QWidget *parent = nullptr);
    ~mainWindow();

signals:
    void nextWork(QString work);

    void breakTime(QString work);

private slots:
    void on_workStartBtn_clicked();

    void on_workStopBtn_clicked();

    void on_workPassBtn_clicked();

    void on_workListSettingBtn_clicked();

    void on_historicalDataBtn_clicked();

    void on_lockBtn_clicked();

    void on_rewardBtn_clicked();

    void getWorkList(QStringList worksInfo,QStringList timesInfo);

    void TC_run(QString work);

    void TC_break(QString work);

    void workTimeOut();

    void breakTimeOut();

private:
    Ui::mainWindow *ui;
    QTimer *workTimer;
    QTimer *breakTimer;
    QStringList works;
    QStringList strTimes;
    QList<int> times;
    int workRank;
    int timeData[6];
};
#endif // MAINWINDOW_H
