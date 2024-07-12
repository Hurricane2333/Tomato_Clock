#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"history.h"
#include<QTime>
#include<QTimer>
#include"gift.h"
#include"manage.h"
#include"tasksetting.h"
#include"lockscreen.h"
#include"musicplayer.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    //void paintEvent(QPaintEvent *event)；
    void changeBackground(QString name);
    void clockIn();
    void updateHistory(int studyTime,int startNum,int pauseNum ,int stopNum ,int createNum ,int finishNum );//更新当天的history数据表

signals:
    void display(QPixmap pic);
    void locked(QTime time,int num,QString now,QString next,int nowNum,int nextNum);

private slots:

    void updateTime();

    void InitTime();

    void nextTask();

    void addMoney(int tomato);//任务奖励

    void subMoney(int tomato);//扣钱

    void on_rewardBtn_clicked();

    void on_startBtn_clicked();

    void on_pauseBtn_clicked();

    void on_stopBtn_clicked();

    void on_manageBtn_clicked();

    void on_closeBtn_clicked();

    void on_clockBtn_clicked();

    void on_historyBtn_clicked();

private:
    Ui::MainWindow *ui;
    QString currentBackground=":/res/42.png";//背景图片,默认为番茄娘
    manage* manageWindow=new manage;
    gift*giftWindow=NULL;
    int state=0; //时钟状态
    int tomato_num=0; //番茄计数，轮流工作休息
    int studyTime=0;//学习时间
    int breakTime=0;//休息时间
    int turn=0;//任务轮次

    QString nowWork;
    QString nextWork;
    int nowNum;
    int nextNum;
    lockScreen *w;
    bool isLock=false;

    int startNum=0;//开始次数
    int pauseNum=0;//暂停次数
    int stopNum=0;//提前结束次数

    QTimer *timer;
    QTime time;
    QSqlDatabase basedb; // 数据库连接对象

    history* historyWindow=new history;

    musicplayer mp;//音乐播放器

};
#endif // MAINWINDOW_H
