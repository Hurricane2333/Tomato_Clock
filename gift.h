#ifndef GIFT_H
#define GIFT_H

#include <QWidget>
#include<QAction>
#include<vector>
#include<QString>
using namespace std;

namespace Ui {
class gift;
}

struct History
{
    int num;//奖励类型
    string result;
    History(int num,string result)
        :num(num),result(result){}
    History()
        :num(0),result(""){}
};

class gift : public QWidget
{
    Q_OBJECT

public:
    explicit gift(QWidget *parent = nullptr);
    ~gift();
    QString up[9]={"001","002","003","004","005","006","007","008","009"};
    QString purple[19]={"01","02","03","04","05","06","07","08","09","010","011","012","013","014","015","016","017","018","019"};
    QString blue[6]={"1","2","3","4","5","6"};
    int money=1600;
    void paintEvent(QPaintEvent *event);

signals:
    void goback();

private slots:

    void on_Button1_clicked();//单抽

    void on_Button10_clicked();//十连

    void on_giftButton_clicked();//抽卡记录

    void on_getButton_clicked();//获取抽数

     void on_setButton_clicked();//皮肤设置

private:
    Ui::gift *ui;
    int bigGift=0;//出金抽数
    int smallGift=0;//出紫抽数
    vector<History>history;
    int isLucky();//是否抽中：1出金，2出紫，3出蓝
    void luckyTry();//单抽
    void showImage(int num);//抽卡图片
};

#endif // GIFT_H
