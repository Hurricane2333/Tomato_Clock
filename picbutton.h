#ifndef PICBUTTON_H
#define PICBUTTON_H

#include <QPushButton>

class picbutton : public QPushButton
{
    Q_OBJECT
public:

    picbutton(QString normalImg);

    QString normalImgPath;


signals:

public slots:

};

#endif // PICBUTTON_H
