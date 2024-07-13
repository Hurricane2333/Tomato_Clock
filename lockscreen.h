#ifndef LOCKSCREEN_H
#define LOCKSCREEN_H

#include <QWidget>
#include <QMessageBox>
#include <QPainter>
#include <QTime>

QT_BEGIN_NAMESPACE
namespace Ui {
class lockScreen;
}
QT_END_NAMESPACE

class lockScreen : public QWidget
{
    Q_OBJECT

public:
    lockScreen(QWidget *parent = nullptr);
    ~lockScreen();
    void paintEvent(QPaintEvent *event);
    bool eventFilter(QObject *obj, QEvent *event);
    QPixmap backPic;

public slots:
    void updateTime(QTime time,int num,QString nowWork,QString nextWork,int nowNum,int nextNum);

private:
    Ui::lockScreen *ui;
    QFont form;

private slots:
    void on_pushButton_clicked();

    void on_unlockBtn_clicked();

};
#endif // LOCKSCREEN_H
