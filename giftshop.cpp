#include "giftshop.h"
#include "ui_giftshop.h"
#include"mainwindow.h"

giftShop::giftShop(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::giftShop)
{
    ui->setupUi(this);
}

void giftShop::onSkinButtonClicked()
{

}

giftShop::~giftShop()
{
    delete ui;
}
