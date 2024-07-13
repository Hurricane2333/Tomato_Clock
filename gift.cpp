#include "gift.h"
#include "ui_gift.h"
#include"picbutton.h"
#include <QSqlQuery>
#include<QDebug>
#include<QDial>
#include <QCoreApplication>
#include <QPixmap>
#include <QTime>
#include<QPainter>
#include <QRandomGenerator>
#include <QApplication>
#include <QLabel>
#include <QImage>
#include <QDialog>
#include <QListView>
#include<QVBoxLayout>
#include <QTextEdit>
#include<QMessageBox>

gift::gift(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::gift)
{
    ui->setupUi(this);
    init();
}

gift::~gift()
{
    delete ui;
}

void gift::init()
{
    // 查询数据库中是否存在user记录,进行初始化
    QSqlQuery query;
    QString curuser="select * from user";
    if (query.exec(curuser)&&query.next())
    {
        money=query.value("money").toInt();
        bigGift=query.value("bigGift").toInt();
        smallGift=query.value("smallGift").toInt();
    }
    else
    {
        // 数据库中不存在money记录，插入一条新记录
        QString sqlIn = QString("insert into user (money,bigGift,smallGift) "
                                "values (%1,%2,%3);")
                            .arg(1600)
                            .arg(0)
                            .arg(0);
        if (!query.exec(sqlIn))
        {
            qDebug() << "Error executing SQL user query";
        }
    }
}

void gift::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,1260,840,QPixmap(":/res/gift.jpg"));
    painter.drawPixmap(1070,40,51,51,QPixmap(":/res/yuans.png"));
}

int gift::isLucky( )
{
    money-=160;
    int luckyNum=QRandomGenerator::global()->bounded(1,10000);
    smallGift++;
    bigGift++;
    updateMoney(money);
    int num=60;
    if(bigGift>=64)
    {
        num=60+600*(bigGift-64);//概率增加
    }
    if(luckyNum<=num)//出金
    {
        bigGift=0;//清空保底
        smallGift++;
        return 1;
    }
    else if(luckyNum<=num+325||smallGift>=10)//出紫
    {
        smallGift=0;//紫色保底清零
        return 2;
    }
    return 3;
}

void gift::showImage(int num)//展示抽卡图片
{
    // 创建一个QPixmap从文件路径加载图片
    QString filePath;
    int luckyNum=QRandomGenerator::global()->bounded(0,100);
    switch(num) {
    case 1:
        filePath = ":/res/00"+QString::number(luckyNum%3+1)+".png"; //
        break;
    case 2:
        filePath = ":/res/0"+QString::number(luckyNum%16+1)+".png"; //
        break;
    case 3:
        filePath = ":/res/"+QString::number(luckyNum%69+1)+".png"; //
        break;
    }

    //向数据库插入抽卡结果
    QSqlQuery query;
    QString sqlIn = QString("insert into gift (name) "
                            "values ('%1');")
                        .arg(filePath);
    if (!query.exec(sqlIn))
    {
        qDebug() << "Error executing SQL gift query";
    }

    // 创建一个新的 picbutton 对象并设置图片
    picbutton *btn_picb=new picbutton(filePath,1260,707);
    btn_picb->setParent(this);

    // 设置图片的初始位置和大小
    btn_picb->move(this->width()/2 - btn_picb->width()/2, this->height()/2 - btn_picb->height()/2);
    btn_picb->show();

    // 连接信号和槽函数
    connect(btn_picb, &picbutton::clicked, btn_picb, &picbutton::hide);
}

void gift::on_Button1_clicked()//单抽
{
    if(money<160)
    {
        qInfo()<<"您的原石不够了喵";
        QDialog *dialog = new QDialog(this);
        QTextEdit *textEdit = new QTextEdit(dialog);
        textEdit->append("您的原石不够了喵");
        // 设置对话框的布局
        QVBoxLayout *layout = new QVBoxLayout(dialog);
        layout->addWidget(textEdit);
        // 显示对话框
        dialog->setLayout(layout);
        dialog->exec();
        return;
    }
    showImage(isLucky());
}


void gift::on_Button10_clicked()//十连
{
    if(money<1600)
    {
        qInfo()<<"您的原石不够了喵";
        QDialog *dialog = new QDialog(this);
        QTextEdit *textEdit = new QTextEdit(dialog);
        textEdit->append("您的原石不够了喵");
        // 设置对话框的布局
        QVBoxLayout *layout = new QVBoxLayout(dialog);
        layout->addWidget(textEdit);
        // 显示对话框
        dialog->setLayout(layout);
        dialog->exec();
        return;
    }
    for(int i=0;i<10;i++)
        showImage(isLucky());
}



void gift::on_giftButton_clicked()//奖励记录
{
    // 隐藏所有图片
    for (auto btn : this->findChildren<picbutton*>()) {
        btn->hide();
    }

    // 创建一个新的窗口来显示历史抽卡记录
    QDialog *dialog = new QDialog(this);
    dialog->setWindowTitle("历史抽卡记录");

    // 创建一个文本编辑器来显示历史记录
    QTextEdit *textEdit = new QTextEdit(dialog);

    // 设置文本编辑器的字体
    QFont font = textEdit->font();
    font.setPointSize(12);
    textEdit->setFont(font);

    QSqlQuery query;
    QString sqlSelect = QString("select * from gift;");//查询
    if(!query.exec(sqlSelect))
    {
        qDebug()<<"select error in gift";
    }
    while(query.next())
    {
        QString name=query.value("name").toString();
        textEdit->append(name);
    }

    // 设置对话框的布局
    QVBoxLayout *layout = new QVBoxLayout(dialog);
    layout->addWidget(textEdit);

    // 显示对话框
    dialog->setLayout(layout);
    dialog->exec();
}

void gift::updateMoney(int nowMoney)
{
    //修改数据库中的money与ui界面
    QSqlQuery query;
    QString sqlUpdate =QString("update user set money=%1,bigGift=%2,smallGift=%3 where id = %4;")
                            .arg(nowMoney)
                            .arg(bigGift)
                            .arg(smallGift)
                            .arg(1);
    if(!query.exec(sqlUpdate))
    {
        qDebug()<<"error in update money";
    }

    QString str = QString::number(nowMoney);
    ui->label->setText(str);
}


void gift::on_getButton_clicked() //获取抽数
{

    QString message = "打卡一次:160原石\n"
                      "每学习1分钟:10原石\n"
                      "每完成一个学习任务(学习总时间>=25):160原石\n"
                      "闭关完成一个任务:200原石";
    QMessageBox::information(this, "抽卡详情", message);
}


void gift::on_setButton_clicked()
{
    shopWindow->updateShop();
    shopWindow->show();
}

