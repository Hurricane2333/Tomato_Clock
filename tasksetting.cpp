#include "tasksetting.h"
#include "ui_tasksetting.h"

taskSetting::taskSetting(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::taskSetting)
{
    ui->setupUi(this);
}

taskSetting::~taskSetting()
{
    delete ui;
}

void taskSetting::on_taskSave_clicked()
{
    QDir taskDir(QDir::currentPath());
    if(!taskDir.exists("taskList"))
    {
        taskDir.mkdir("taskList");
    }

    //读取用户输入的文件
    QString taskName;
    QString workHours,workMinutes,workSeconds;
    QString breakHours,breakMinutes,breakSeconds;
    taskName = ui->taskName->text();
    workHours = ui->workH->text();
    if(workHours.isEmpty())
    {
        workHours = "0";
    }
    workHours += "\n";
    workMinutes = ui->workM->text();
    if(workMinutes.isEmpty())
    {
        workMinutes = "0";
    }
    workMinutes += "\n";
    workSeconds = ui->workS->text();
    if(workSeconds.isEmpty())
    {
        workSeconds = "0";
    }
    workSeconds += "\n";
    breakHours = ui->breakH->text();
    if(breakHours.isEmpty())
    {
        breakHours = "0";
    }
    breakHours += "\n";
    breakMinutes = ui->breakM->text();
    if(breakMinutes.isEmpty())
    {
        breakMinutes = "0";
    }
    breakMinutes += "\n";
    breakSeconds = ui->breakS->text();
    if(breakSeconds.isEmpty())
    {
        breakSeconds = "0";
    }
    breakSeconds += "\n";

    //保存记录任务数据
    taskFilePath = QCoreApplication::applicationDirPath() + "\\taskList\\" + taskName + ".task";
    QFile taskFile(taskFilePath);
    if(taskFile.open(QIODevice::WriteOnly|QIODevice::Text))
    {
        QByteArray workHoursB,workMinutesB,workSecondsB;
        workHoursB.append(workHours.toUtf8());
        taskFile.write(workHoursB);
        workMinutesB.append(workMinutes.toUtf8());
        taskFile.write(workMinutesB);
        workSecondsB.append(workSeconds.toUtf8());
        taskFile.write(workSecondsB);

        QByteArray breakHoursB,breakMinutesB,breakSecondsB;
        breakHoursB.append(breakHours.toUtf8());
        taskFile.write(breakHoursB);
        breakMinutesB.append(breakMinutes.toUtf8());
        taskFile.write(breakMinutesB);
        breakSecondsB.append(breakSeconds.toUtf8());
        taskFile.write(breakSecondsB);

        taskFile.close();
    }

    //更新任务列表
    taskListFilePath = QCoreApplication::applicationDirPath() + "\\taskList.json";
    QFile taskListFile(taskListFilePath);
    if(taskListFile.open(QIODevice::ReadWrite|QIODevice::Text))
    {
        QByteArray taskListData = taskListFile.readAll();
        QJsonDocument taskJson = QJsonDocument::fromJson(taskListData);
        QJsonArray taskArray = taskJson.array();

        if (!taskArray.contains(QJsonValue(taskName)))
        {
            QJsonValue taskValue = QJsonValue(taskName);
            taskArray.append(taskValue);
            taskJson.setArray(taskArray);
            taskListFile.resize(0);
            taskListFile.write(taskJson.toJson());
            taskListFile.close();
        }
    }

    //发送更新信号并关闭此界面
    emit finished();
    this->close();
}

void taskSetting::on_taskCancel_clicked()
{
    emit finished();
    this->close();
}

