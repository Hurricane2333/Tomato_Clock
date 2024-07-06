#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPainter>
#include<QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new QTimer;
    ui->Timer->setDigitCount(5);
    ui->Timer->setLineWidth(0);
    ui->Timer->setSegmentStyle(QLCDNumber::Filled);
    timer->setInterval(1000);

    //建立数据库
    basedb=QSqlDatabase::addDatabase("QSQLITE");
    basedb.setDatabaseName("compary.db");
    if(!basedb.open())
    {
        qDebug()<<"open error";
    }
    QSqlQuery query(basedb);
    //任务名称，难度等级，学习时间，休息时间
    QString sqlCreateTable=QString("create table if not exists task"
                                     "(id integer primary key autoincrement,"
                                     "name varchar(20),"
                                     "grade int,"
                                     "studyTime int,"
                                     "breakTime int);");

    if(!query.exec(sqlCreateTable))
    {
        qDebug()<<"Error falied to open"<<basedb.lastError();
    }
    //manageWindow->db=basedb
    InitTime();
    connect(manageWindow, &manage::saved, this, &MainWindow::InitTime);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setOpacity(0.6);
    painter.drawPixmap(0,0,1260,707,QPixmap(":/res/2.png"));
}


void MainWindow::on_rewardBtn_clicked()
{
    giftWindow->show();
}

void MainWindow::InitTime()
{
    QSqlQuery query(basedb);
    QString sqlSelect = QString("select * from task;");//查询
    if(!query.exec(sqlSelect))
    {
        qDebug()<<"select error in mainWindow";
    }
    if(query.next())
    {
    studyTime=query.value("studyTime").toInt();
    breakTime=query.value("breakTime").toInt();
    }
    if(studyTime)
        time.setHMS(0,studyTime,0);
    else
        time.setHMS(0,25,0);
    ui->Timer->display(time.toString("mm:ss"));
    ui->Timer->setStyleSheet ("color:red");
}

void MainWindow::updateTime()
{
    time = time.addSecs(-1);
    ui->Timer->display(time.toString("mm:ss"));
    if(time.minute() == 0  && time.second() == 0 && tomato_num==1)
    {
        //休息完毕
        giftWindow->money+=800;//第一阶段送5发
        tomato_num = 0;
        InitTime();
        timer->stop();
        state = 0;
    }
    if(time.minute() == 0  && time.second() == 0 && tomato_num==0)
    {
        //进入休息
        tomato_num = 1;
        if(breakTime)
            time.setHMS(0,breakTime,0);
        else
            time.setHMS(0,5,0);
        ui->Timer->setStyleSheet ("color:green");
    }
}


void MainWindow::on_startBtn_clicked()
{
    if(state==0)
    {
    disconnect(timer, SIGNAL(timeout()), this, SLOT(updateTime()));
    timer->start();
    connect(timer,SIGNAL(timeout()),this,SLOT(updateTime()));
    state=1;
    }
}


void MainWindow::on_pauseBtn_clicked()
{    
    timer->stop();
    state=0;
}


void MainWindow::on_stopBtn_clicked()
{    
    timer->stop();
    InitTime();
    state=0;
}


void MainWindow::on_manageBtn_clicked()//设置按钮
{
    manageWindow->show();
    manageWindow->updateWindow();
}

