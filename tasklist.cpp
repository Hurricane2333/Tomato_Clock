#include "tasklist.h"
#include "ui_tasklist.h"

taskList::taskList(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::taskList)
{
    ui->setupUi(this);

    connect(ui->workListWgt->verticalScrollBar(),&QScrollBar::valueChanged,ui->workTimesWgt->verticalScrollBar(),&QScrollBar::setValue);
    connect(ui->workTimesWgt->verticalScrollBar(),&QScrollBar::valueChanged,ui->workListWgt->verticalScrollBar(),&QScrollBar::setValue);
    connect(ui->workListWgt->model(),&QAbstractItemModel::rowsInserted,this,&taskList::workAdded);
    connect(ui->workListWgt->model(),&QAbstractItemModel::rowsRemoved,this,&taskList::workAdded);
    connect(ui->rubbishWgt->model(),&QAbstractItemModel::rowsInserted,this,&taskList::workRemoved);
    ui->workTimesWgt->setColumnCount(1);

    QDir taskDir(QDir::currentPath());
    if(!taskDir.exists("taskList"))
    {
        taskDir.mkdir("taskList");
    }


    //显示任务列表
    taskListFilePath = QCoreApplication::applicationDirPath() + "\\taskList.json";
    QFile taskListFile(taskListFilePath);
    if (taskListFile.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        QByteArray taskListData = taskListFile.readAll();
        taskListFile.close();
        QJsonDocument taskJson = QJsonDocument::fromJson(taskListData);
        QJsonArray taskArray = taskJson.array();
        for(const QJsonValue& taskValue:taskArray)
        {
            QString taskName = taskValue.toString();
            ui->taskListWgt->addItem(taskName);
        }
    }
}

taskList::~taskList()
{
    delete ui;
}

void taskList::on_newTaskBtn_clicked()
{
    taskSetting *w = new taskSetting();
    connect(w,&taskSetting::finished,this,&taskList::reDisplay);
    w->show();
}

void taskList::on_clearTaskBtn_clicked()
{

}

void taskList::on_startWorkBtn_clicked()
{
    //传递执行列表并关闭窗口
    QStringList worksInfo;
    for(int i = 0;i < ui->workListWgt->count();i++)
    {
        worksInfo.append(ui->workListWgt->item(i)->text());
    }
    QStringList timesInfo;
    for(int i = 0;i < ui->workTimesWgt->rowCount();i++)
    {
        QString times;
        if(ui->workTimesWgt->item(i, 0)==nullptr)
        {
            times = "1";
        }
        else
        {
            times = ui->workTimesWgt->item(i, 0)->text();
        }
        timesInfo.append(times);
    }
    emit sendWorkList(worksInfo,timesInfo);
    this->close();
}

void taskList::on_clearWorkBtn_clicked()
{

}

void taskList::reDisplay()
{
    //添加任务后重新显示任务列表
    ui->taskListWgt->clear();
    taskListFilePath = QCoreApplication::applicationDirPath() + "\\taskList.json";
    QFile taskListFile(taskListFilePath);
    if (taskListFile.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        QByteArray taskListData = taskListFile.readAll();
        taskListFile.close();
        QJsonDocument taskJson = QJsonDocument::fromJson(taskListData);
        QJsonArray taskArray = taskJson.array();
        for(const QJsonValue& taskValue:taskArray)
        {
            QString taskName = taskValue.toString();
            ui->taskListWgt->addItem(taskName);
        }
    }
}

void taskList::workAdded(){
    //同步执行列表和执行轮次
    int newWorks = ui->workListWgt->count();
    ui->workTimesWgt->setRowCount(newWorks);
}

void taskList::workRemoved(){
    ui->rubbishWgt->clear();
}

