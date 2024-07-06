#include "gift.h"
#include "ui_gift.h"
#include"picbutton.h"
#include"giftshop.h"
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

gift::gift(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::gift)
{
    ui->setupUi(this);
    QString str = QString::number(money);
    ui->lineEdit->setText(str);
}

gift::~gift()
{
    delete ui;
}

void gift::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,1260,840,QPixmap(":/res/gift.jpg"));
}

int gift::isLucky( )
{
    money-=160;
    int luckyNum=QRandomGenerator::global()->bounded(1,10000);
    smallGift++;
    bigGift++;
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

void gift::showImage(int num)
{
    // 创建一个QPixmap从文件路径加载图片
    QString filePath;
    int luckyNum=QRandomGenerator::global()->bounded(0,100);
    switch(num) {
    case 1:
        filePath = ":/res/"+up[luckyNum%9]+".png"; //
        break;
    case 2:
        filePath = ":/res/"+purple[luckyNum%19]+".png"; //
        break;
    case 3:
        filePath = ":/res/"+blue[luckyNum%6]+".png"; //
        break;
    }

    // 创建一个新的 picbutton 对象并设置图片
    picbutton *btn_picb=new picbutton(filePath);
    btn_picb->setParent(this);

    // 设置图片的初始位置和大小
    btn_picb->move(this->width()/2 - btn_picb->width()/2, this->height()/2 - btn_picb->height()/2);
    btn_picb->show();

    // 连接信号和槽函数
    connect(btn_picb, &picbutton::clicked, btn_picb, &picbutton::hide);
}

void gift::luckyTry()//单抽
{
    string Result;
    int Num=isLucky();
    switch(Num)
    {
    case 1:
        qInfo()<<"出金 "<<bigGift;
        Result="出金";
        break;
    case 2:
        qInfo()<<"出紫 "<<bigGift;
        Result="出紫";
        break;
    case 3:
        qInfo()<<"出蓝 "<<bigGift;
        Result="出蓝";
        break;
    default:
        return;
    }
    History h(Num,Result);
    history.push_back(h);
    // 显示图片
    showImage(Num);
    //显示原石
    QString str = QString::number(money);
    ui->lineEdit->setText(str);
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
    luckyTry();
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
    for (int i = 0; i < 10; i++)
    {
        luckyTry();
    }
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

    // 将历史记录添加到模型中
    for (int i = 0; i < history.size(); i++) {
        switch(history[i].num)
        {
        case 1:
            textEdit->append("<font color=\"gold\">金色</font>");
            break;
        case 2:
            textEdit->append("<font color=\"purple\">紫色</font>");
            break;
        case 3:
            textEdit->append("<font color=\"blue\">蓝色</font>");
            break;
        }
    }

    // 设置对话框的布局
    QVBoxLayout *layout = new QVBoxLayout(dialog);
    layout->addWidget(textEdit);

    // 显示对话框
    dialog->setLayout(layout);
    dialog->exec();
}

void gift::on_getButton_clicked() //获取抽数
{
    money+=1600;
    QString str = QString::number(money);
    ui->lineEdit->setText(str);
}


void gift::on_setButton_clicked()
{
    giftShop *shop = new giftShop;
    shop->show();
}

