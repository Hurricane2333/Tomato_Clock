#ifndef GIFT_H
#define GIFT_H

#include <QWidget>
#include<QAction>
#include<vector>
#include<QString>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QSqlError>
#include"giftshop.h"
using namespace std;

namespace Ui {
class gift;
}

class gift : public QWidget
{
    Q_OBJECT

public:
    explicit gift(QWidget *parent = nullptr);
    ~gift();
    int money=1600;//原石
    giftshop* shopWindow=new giftshop;

    void paintEvent(QPaintEvent *event);
    //int getMoney();
    void updateMoney(int nowMoney);
    void init();

signals:
    void goback();

private slots:

    void on_Button1_clicked();//单抽

    void on_Button10_clicked();//十连

    void on_giftButton_clicked();//抽卡记录

    void on_getButton_clicked();//获取抽数

    void on_setButton_clicked();//皮肤设置

private:
    int bigGift;//出金抽数
    int smallGift;//出紫抽数
    int isLucky();//是否抽中：1出金，2出紫，3出蓝
    void showImage(int num);//抽卡
    Ui::gift *ui;
};

#endif // GIFT_H
