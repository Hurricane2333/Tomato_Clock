#include "mainwindow.h"
#include "./ui_mainwindow.h"

mainWindow::mainWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::mainWindow)
{
    ui->setupUi(this);

    workTimer = new QTimer();
    breakTimer = new QTimer();
    connect(workTimer,&QTimer::timeout,this,&mainWindow::workTimeOut);
    connect(breakTimer,&QTimer::timeout,this,&mainWindow::breakTimeOut);

    connect(this,&mainWindow::nextWork,this,&mainWindow::TC_run);
    connect(this,&mainWindow::breakTime,this,&mainWindow::TC_break);
}

mainWindow::~mainWindow()
{
    delete ui;
}

void mainWindow::on_workStartBtn_clicked()
{
    workRank = 0;
    emit nextWork(works[workRank]);
}

void mainWindow::on_workStopBtn_clicked()
{

}


void mainWindow::on_workPassBtn_clicked()
{

}

void mainWindow::on_workListSettingBtn_clicked()
{
    taskList *w = new taskList();
    w->show();
    connect(w,&taskList::sendWorkList,this,&mainWindow::getWorkList);
}


void mainWindow::on_historicalDataBtn_clicked()
{

}


void mainWindow::on_lockBtn_clicked()
{

}


void mainWindow::on_rewardBtn_clicked()
{

}

void mainWindow::getWorkList(QStringList worksInfo,QStringList timesInfo)
{
    works = worksInfo;
    strTimes = timesInfo;
    for(int i = 0;i < strTimes.size();i++)
    {
        QString numTimes = strTimes[i];
        times.append(numTimes.toInt());
    }
}

void mainWindow::TC_run(QString work)
{
    QString workPath = QCoreApplication::applicationDirPath() + "\\taskList\\" + work + ".task";
    QFile workFile(workPath);
    workFile.open(QIODevice::ReadOnly);
    QTextStream in(&workFile);
    for(int i = 0;i < 6;i++)
    {
        QString number = in.readLine();
        timeData[i] = number.toInt();
    }
    QString workDisplay = work + "\n正在进行";
    QTime showTime = QTime(timeData[0],timeData[1],timeData[2]);
    QString timeText = showTime.toString("hh:mm:ss");
    ui->timeDisplayLbl->setText(timeText);
    ui->workDisplayLbl->setText(workDisplay);
    ui->workDisplayLbl->setText(workDisplay);
    workTimer->start(1000);
}

void mainWindow::TC_break(QString work)
{
    QString workDisplay = work + "\n休息时间";
    QTime showTime = QTime(timeData[3],timeData[4],timeData[5]);
    QString timeText = showTime.toString("hh:mm:ss");
    ui->timeDisplayLbl->setText(timeText);
    ui->workDisplayLbl->setText(workDisplay);
    breakTimer->start(1000);
}

void mainWindow::workTimeOut()
{
    if(timeData[2] == 0)
    {
        if(timeData[1] == 0)
        {
            if(timeData[0] == 0)
            {
                workTimer->stop();
                emit breakTime(works[workRank]);
                return;
            }
            timeData[0]--;
            timeData[1] = 60;
        }
        timeData[1]--;
        timeData[2] = 60;
    }
    timeData[2]--;
    QTime showTime = QTime(timeData[0],timeData[1],timeData[2]);
    QString timeText = showTime.toString("hh:mm:ss");
    ui->timeDisplayLbl->setText(timeText);
}

void mainWindow::breakTimeOut()
{
    if(timeData[5] == 0)
    {
        if(timeData[4] == 0)
        {
            if(timeData[3] == 0)
            {
                breakTimer->stop();
                times[workRank]--;
                if(times[workRank] == 0)
                {
                    workRank++;
                    if(workRank >= works.size())
                        return;
                }
                emit nextWork(works[workRank]);
                return;
            }
            timeData[3]--;
            timeData[4] = 60;
        }
        timeData[4]--;
        timeData[5] = 60;
    }
    timeData[5]--;
    QTime showTime = QTime(timeData[3],timeData[4],timeData[5]);
    QString timeText = showTime.toString("hh:mm:ss");
    ui->timeDisplayLbl->setText(timeText);
}
