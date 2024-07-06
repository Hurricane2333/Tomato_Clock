#ifndef GIFTSHOP_H
#define GIFTSHOP_H

#include <QWidget>
#include "picbutton.h"

namespace Ui {
class giftShop;
}

class giftShop : public QWidget
{
    Q_OBJECT

public:
    explicit giftShop(QWidget *parent = nullptr);
    ~giftShop();

private slots:
    void onSkinButtonClicked();

private:
    Ui::giftShop *ui;
};

#endif // GIFTSHOP_H
