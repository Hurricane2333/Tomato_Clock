#include "widget.h"
#include "ui_widget.h"
#include"gift.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->giftWindow = new gift;
    connect(giftWindow,&gift::goback,this,[=](){
        giftWindow->close();
        this->show();
    });

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    giftWindow->show();
}

