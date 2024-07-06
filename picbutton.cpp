#include "picbutton.h"
#include<QPropertyAnimation>
#include<QAbstractAnimation>

picbutton::picbutton(QString normalImg)
{
    this->normalImgPath=normalImg;

    QPixmap pix;
    pix.load(normalImg);

    this->setFixedSize(pix.width(),pix.height());
    this->setStyleSheet("QPushButton{border:0px;}");
    this->setIcon(pix);
    this->setIconSize(QSize(1260,840));

}
