#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPainter>
#include<QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //初始化番茄钟
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

    //创建任务表 task
    //任务名称，难度等级，学习时间，休息时间
    QString taskTable=QString("create table if not exists task"
                                     "(id integer primary key autoincrement,"
                                     "name varchar(20),"
                                     "grade int,"
                                     "studyTime int,"
                                     "breakTime int,"
                                     "turn int);");
    if(!query.exec(taskTable))
    {
        qDebug()<<"Error falied to open task"<<basedb.lastError();
    }

    //创建抽卡记录表 gift
    //抽卡图片名称
    QString giftTable=QString("create table if not exists gift"
                                     "(id integer primary key autoincrement,"
                                     "name varchar(70));");
    if(!query.exec(giftTable))
    {
        qDebug()<<"Error falied to open gift"<<basedb.lastError();
    }

    //创建背景图片表skin
    //背景图片名称
    QString skin=QString("create table if not exists skin"
                                "(id integer primary key autoincrement,"
                                "name varchar(70));");
    if(!query.exec(skin))
    {
        qDebug()<<"Error falied to open skin"<<basedb.lastError();
    }

    //创建用户数据表 user
    //账号、密码、原石、大小保底等 //目前只有原石,大小保底
    QString userTable=QString("create table if not exists user"
                                "(id integer primary key autoincrement,"
                                "money int,"
                                "bigGift int,"
                                "smallGift int);");
    if(!query.exec(userTable))
    {
        qDebug()<<"Error falied to open user"<<basedb.lastError();
    }

    //创建历史任务表
    //日期，学习时间，启动计时次数，暂停次数，提前结束次数，创建任务次数，完成任务次数
    QString hisTable=QString("create table if not exists history"
                               "(id integer primary key autoincrement,"
                               "date varchar(20),"
                               "studyTime int,"
                               "startNum int,"
                               "pauseNum int,"
                               "stopNum int,"
                               "createNum int,"
                               "finishNum int);");
    if(!query.exec(hisTable))
    {
        qDebug()<<"Error falied to open history"<<basedb.lastError();
    }


    //查询数据库初始化背景

    QString curskin="select name from skin";
    if (query.exec(curskin) && query.next())
    {
        currentBackground=query.value("name").toString();
    }
    else
    {
        // 数据库中不存在skin记录，插入一条新记录
        QString sqlIn = QString("insert into skin (name) "
                                "values ('%1');")
                            .arg(":/res/42.png");
        if (!query.exec(sqlIn))
        {
            qDebug() << "Error executing SQL skin query: " << query.lastError();
        }
    }

    changeBackground(currentBackground);
    //创建皮肤设置的连接
    giftWindow=new gift;
    connect(giftWindow->shopWindow, &giftshop::changeBackgroundRequested, this, &MainWindow::changeBackground);


    InitTime();
    //创建任务列表的连接
    connect(manageWindow, &manage::saved, this, &MainWindow::InitTime);

    //锁屏
    w = new lockScreen;
    connect(this,&MainWindow::locked,w,&lockScreen::updateTime);

    //更新历史记录

    connect(manageWindow->taskWindow, &tasksetting::taskAdded, this, [this]() {
        updateHistory(0,0,0,0,1,0);
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}

/*
void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setOpacity(0.6);
    QPixmap backPic(":/res/42.png");
    QPixmap scaledPixmap = backPic.scaled(this->size(),Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation);
    painter.drawPixmap((this->size().width()-scaledPixmap.width())/2, 0 ,scaledPixmap);
                       //通过计算使图片水平居中                       //图片置于顶端
}
*/

void MainWindow::clockIn()
{
    QDate currentDate = QDate::currentDate();
    QString date = currentDate.toString("yyyy-MM-dd");

    QSqlQuery query;
    // 检查数据库中是否存在当前日期的记录
    QString sql = QString("select * from history where date = '%1'").arg(date);
    query.exec(sql);

    // 如果没有记录，则插入一条新记录
    if (!query.next()) {
        QString Sqlin = QString("INSERT INTO history (date, studyTime, startNum, pauseNum, stopNum, createNum, finishNum)"
                                " VALUES ('%1', 0, 0, 0, 0, 0, 0)")
                            .arg(date);

        if(!query.exec(Sqlin))
        {
            qDebug()<<"insert error in update history";
        }
    }
}

void MainWindow::updateHistory(int studyTime,int startNum,int pauseNum ,int stopNum ,int createNum ,int finishNum)
{
    QDate currentDate = QDate::currentDate();
    QString date = currentDate.toString("yyyy-MM-dd");

    QSqlQuery query;
    // 更新数据库中日期为当前日期的数据
    QString sqlUpdate = QString("update history set"
                                " studyTime = studyTime + %1, startNum = startNum + %2, pauseNum = pauseNum + %3, stopNum = stopNum + %4, createNum = createNum + %5, finishNum = finishNum + %6"
                                " where date = '%7'")
                            .arg(studyTime).arg(startNum).arg(pauseNum).arg(stopNum).arg(createNum).arg(finishNum).arg(date);
    if(!query.exec(sqlUpdate))
    {
        qDebug()<<"update error in update history";
    };
}

void MainWindow::changeBackground(QString name)//改变背景图片
{
    //更新数据库中的背景图片名
    QSqlQuery query;
    QString sqlUpdate =QString("update skin set name='%1' where id = %2;")
                            .arg(name)
                            .arg(1);
    if(!query.exec(sqlUpdate))
    {
        qDebug()<<"error in update skin";
    }

    currentBackground = name;
    QPixmap pixmap(name);
    QPixmap scaledPixmap = pixmap.scaled(this->size(),Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation);
    // 创建一个目标设备，用于绘制背景图片
    QPixmap target(scaledPixmap.size());
    target.fill(Qt::white); // 设置目标设备为白色

    // 创建一个QPainter对象，用于在目标设备上绘制
    QPainter painter(&target);
    painter.setOpacity(0.8); //设置透明度
    // 在目标设备上绘制背景图片
    painter.drawPixmap((this->size().width()-scaledPixmap.width())/2, 0, scaledPixmap);//水平居中

    // 创建一个QPalette对象，并将具有透明度的背景图片分配给窗口背景色
    QPalette palette;
    palette.setBrush(QPalette::Window, QBrush(target));
    // 将QPalette应用于MainWindow窗口
    this->setPalette(palette);
}

void MainWindow::on_rewardBtn_clicked()
{
    giftWindow->updateMoney(giftWindow->money);
    giftWindow->show();
}

void MainWindow::InitTime()
{
    QSqlQuery query;
    QString sqlSelect = QString("select * from task;");//查询
    if(query.exec(sqlSelect)&&query.next())
    {
        studyTime=query.value("studyTime").toInt();
        breakTime=query.value("breakTime").toInt();
        turn=query.value("turn").toInt();

        QFont font;
        font.setFamily("Arial"); // 设置字体家族为Arial
        font.setPointSize(14); // 设置字体大小为14
        font.setBold(true); // 设置字体加粗

        nowWork = query.value("name").toString();
        nowNum = turn;
        ui->nowEdit->setFont(font);
        ui->nowEdit->setText("当前任务："+nowWork+"\n剩余轮次："+QString::number(nowNum));
        //显示下一项任务
        if(query.next())
        {
            nextWork = query.value("name").toString();
            nextNum = query.value("turn").toInt();
            ui->nextEdit->setFont(font);
            ui->nextEdit->setText("下一项任务："+nextWork+"\n剩余轮次："+QString::number(nextNum));
        }
        else
        {
            nextWork = "";
            nextNum = 0;
            ui->nextEdit->clear();
        }
    }
    else
    {
        // 数据库中不存在task记录，插入一条新记录
        QString sqlIn = QString("insert into task (name, grade, studyTime, breakTime,turn) "
                                "values ('%1', %2, %3, %4, %5);")
                            .arg("默认任务")
                            .arg(1)
                            .arg(25)
                            .arg(5)
                            .arg(1);
        if (!query.exec(sqlIn))
        {
            qDebug() << "error in inserting original task";
        }
        manageWindow->updateWindow();
        InitTime();
    }

    //设置计时器格式
    time.setHMS(0,studyTime,0);
    ui->Timer->display(time.toString("mm:ss"));
    ui->Timer->setStyleSheet ("color:red");

    emit locked(time,0,nowWork,nextWork,nowNum,nextNum);

}

void MainWindow::updateTime()
{
    time = time.addSecs(-1);
    ui->Timer->display(time.toString("mm:ss"));

    //在秒数为0的学习模式下时，studyTime+1
    //这样点击stopBtn时会亏损时间
    if (time.second() == 0&&tomato_num==0)
    {
        updateHistory(1, 0, 0, 0, 0, 0);
    }

    emit locked(time,2,nowWork,nextWork,nowNum,nextNum);
    //学习时间与休息时间轮流进行
    if(time.minute() == 0  && time.second() == 0 && tomato_num==1&&turn>0)
    {
        //进入学习
        turn--;
        QSqlQuery query;
        QString sqlSelect = QString("select * from task;");//查询
        if(query.exec(sqlSelect)&&query.next())
        {
            //更新第一条任务
            int id=query.value("id").toInt();
            QString sqlUpdate = QString("update task set tuen = %1 where id = %2;")
                                    .arg(turn)
                                    .arg(id);
            if(!query.exec(sqlUpdate))
            {
                qDebug()<<"error in update turn";
            }
        }

        if(turn==0)//任务结束
        {
            nextTask();
        }
        tomato_num = 0;
        InitTime();
        state = 0;
    }
    if(time.minute() == 0  && time.second() == 0 && tomato_num==0)
    {
        //进入休息
        tomato_num = 1;
        time.setHMS(0,breakTime,0);

        ui->Timer->setStyleSheet ("color:green");
        state=0;

        //锁定界面不应该在休息时出现
        //emit locked(time,1,nowWork,nextWork,nowNum,nextNum);
        w->close();
    }
}

void MainWindow::nextTask()
{
    updateHistory(0, 0, 0, 0, 0, 1);
    //进行下一项任务
    timer->stop();
    QSqlQuery query;
    QString sqlSelect = QString("select * from task;");//查询
    if(query.exec(sqlSelect)&&query.next())
    {
        //删除第一条任务
        int id=query.value("id").toInt();
        QString sqlDe=QString("delete from task where id=%1;").arg(id);
        if(!query.exec(sqlDe))
        {
            qDebug()<<"delete error";
        }
    }
    InitTime();
    state=0;
}

void MainWindow::addMoney(int tomato)//任务奖励
{
    giftWindow->money+=tomato;
    giftWindow->updateMoney(giftWindow->money);
}


void MainWindow::subMoney(int tomato)//扣钱
{
    giftWindow->money-=tomato;
    giftWindow->updateMoney(giftWindow->money);
}


void MainWindow::on_startBtn_clicked()
{
    //开始计时
    if(state==0)
    {
        //开始次数加1
        updateHistory(0,1,0,0,0,0);

        addMoney(160);
        disconnect(timer, SIGNAL(timeout()), this, SLOT(updateTime()));
        timer->start();
        connect(timer,SIGNAL(timeout()),this,SLOT(updateTime()));
        state=1;
    }
    if(isLock)
    {
        w = new lockScreen();
        connect(this,&MainWindow::locked,w,&lockScreen::updateTime);
        QPixmap backPic(currentBackground);
        w->backPic = backPic;
        w->show();
        emit locked(time,0,nowWork,nextWork,nowNum,nextNum);
        qDebug()<<nowWork;
    }
    timer->start(1000);
}


void MainWindow::on_pauseBtn_clicked()
{
    if(state==1)
    {
    updateHistory(0,0,1,0,0,0);
    timer->stop();
    state=0;
    }
}


void MainWindow::on_stopBtn_clicked()
{

    updateHistory(0,0,0,1,0,-1);
    nextTask();
    //进行番茄历史记录和原石操作

}


void MainWindow::on_manageBtn_clicked()//设置按钮
{
    manageWindow->show();
    manageWindow->updateWindow();
}


void MainWindow::on_closeBtn_clicked()
{
    if(ui->closeBtn->isChecked())
    {
        isLock = true;
    }
    else
    {
        isLock = false;
    }
}


void MainWindow::on_clockBtn_clicked()
{
    clockIn();
}


void MainWindow::on_historyBtn_clicked()
{
    historyWindow->initChart();
    historyWindow->show();
}

