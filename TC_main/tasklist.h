#ifndef TASKLIST_H
#define TASKLIST_H

#include <QWidget>
#include <QFile>
#include <QDir>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonValue>
#include <QListWidgetItem>
#include <QScrollBar>
#include "tasksetting.h"

namespace Ui {
class taskList;
}

class taskList : public QWidget
{
    Q_OBJECT

public:
    explicit taskList(QWidget *parent = nullptr);
    ~taskList();

signals:
    void sendWorkList(QStringList worksInfo,QStringList timesInfo);

private slots:
    void on_newTaskBtn_clicked();

    void on_clearTaskBtn_clicked();

    void on_startWorkBtn_clicked();

    void on_clearWorkBtn_clicked();

    void reDisplay();

    void workAdded();

    void workRemoved();

private:
    Ui::taskList *ui;
    QString taskListFilePath;

};

#endif // TASKLIST_H
