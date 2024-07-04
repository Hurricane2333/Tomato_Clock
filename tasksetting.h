#ifndef TASKSETTING_H
#define TASKSETTING_H

#include <QWidget>
#include <QFile>
#include <QDir>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonValue>

namespace Ui {
class taskSetting;
}

class taskSetting : public QWidget
{
    Q_OBJECT

public:
    explicit taskSetting(QWidget *parent = nullptr);
    ~taskSetting();

signals:
    void finished();

private slots:
    void on_taskSave_clicked();

    void on_taskCancel_clicked();

private:
    Ui::taskSetting *ui;
    QString taskName;
    QString taskFilePath;
    QString taskListFilePath;
    QDir taskDir;
};

#endif // TASKSETTING_H
