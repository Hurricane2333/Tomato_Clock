#include "lockscreen.h"
#include "ui_lockscreen.h"

lockScreen::lockScreen(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::lockScreen)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/res/tomato.png"));

    //全屏
    this->setWindowFlags(Qt::Window);
    this->setWindowState(Qt::WindowFullScreen);

    //事件过滤器
    ui->backGround->installEventFilter(this);
    ui->Timer->installEventFilter(this);
    ui->nowLbl->installEventFilter(this);
    ui->nextLbl->installEventFilter(this);

    this->setMouseTracking(true);
    ui->backGround->setMouseTracking(true);
    ui->Timer->setMouseTracking(true);
    ui->nowLbl->setMouseTracking(true);
    ui->nextLbl->setMouseTracking(true);

    this->setFocusPolicy(Qt::StrongFocus);
    ui->backGround->setFocusPolicy(Qt::StrongFocus);
    ui->Timer->setFocusPolicy(Qt::StrongFocus);
    ui->nowLbl->setFocusPolicy(Qt::StrongFocus);
    ui->nextLbl->setFocusPolicy(Qt::StrongFocus);

    form.setFamily("Arial"); // 设置字体家族为Arial
    form.setPointSize(20); // 设置字体大小为20
    form.setBold(true); // 设置字体加粗

}

lockScreen::~lockScreen()
{
    delete ui;
}

void lockScreen::on_pushButton_clicked()
{
    QMessageBox::information(this,"12","123");
}

bool lockScreen::eventFilter(QObject *obj,QEvent *event)
{
    switch (event->type())
    {
    //发现鼠标或键盘事件
    case QEvent::MouseButtonPress:
    case QEvent::MouseButtonRelease:
    case QEvent::MouseButtonDblClick:
    case QEvent::Wheel:
    case QEvent::KeyPress:
    case QEvent::KeyRelease:
        QMessageBox::warning(this, "警告", "请不要分心");
        return true;
        break;
    default:
        return QWidget::eventFilter(obj, event);
    }
}

void lockScreen::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setOpacity(0.6);

    QSize screenSize = this->size();
    QPixmap picture = backPic.scaled(screenSize.width(), screenSize.height(), Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation);
    painter.drawPixmap((screenSize.width()-picture.width())/2,(screenSize.height()-picture.height())/2,picture);

    ui->backGround->setGeometry(0,0,screenSize.width(),screenSize.height());
    ui->unlockBtn->setGeometry(screenSize.width()-25,10,15,15);
    ui->Timer->setGeometry(screenSize.width()/2-200,screenSize.height()/2-300,400,200);
    ui->nowLbl->setGeometry(screenSize.width()/2-500,screenSize.height()/2-300,200,200);
    ui->nextLbl->setGeometry(screenSize.width()/2+300,screenSize.height()/2-300,200,200);

    ui->nowLbl->setStyleSheet("background-color: rgba(255, 255, 255, 100);");
    ui->nextLbl->setStyleSheet("background-color: rgba(255, 255, 255, 100);");

}


void lockScreen::on_unlockBtn_clicked()
{
    QMessageBox warning1(this);
    warning1.setWindowTitle("提示");
    warning1.setText("您一定是误触的吧 :)");
    warning1.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    warning1.setDefaultButton(QMessageBox::Yes);
    if (warning1.exec() == QMessageBox::No)
    {
        QMessageBox warning2(this);
        warning2.setWindowTitle("声明");
        warning2.setText("请您专心地工作！ :|");
        warning2.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        warning2.setDefaultButton(QMessageBox::Yes);
        if (warning2.exec() == QMessageBox::No)
        {
            QMessageBox warning3(this);
            warning3.setWindowTitle("警告");
            warning3.setText("真的要前功尽弃？ :(");
            warning3.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
            warning3.setDefaultButton(QMessageBox::No);
            if (warning3.exec() == QMessageBox::Yes)
            {
                this->close();
                return;
            }
        }
    }
}

void lockScreen::updateTime(QTime time,int num,QString nowWork,QString nextWork,int nowNum,int nextNum)
{
    ui->Timer->display(time.toString("mm:ss"));
    if(num==2)
    {

    }
    else if(num==0)
    {
        ui->Timer->setStyleSheet ("color:red");
    }
    else if(num==1)
    {
        ui->Timer->setStyleSheet ("color:green");
    }

    ui->nowLbl->setFont(form);
    ui->nextLbl->setFont(form);

    ui->nowLbl->setText("当前任务：\n"+nowWork+"\n剩余轮次："+QString::number(nowNum));
    if(nextNum==0)
    {
        ui->nextLbl->clear();
    }
    else
    {
        ui->nextLbl->setText("下一项任务：\n"+nextWork+"\n剩余轮次："+QString::number(nextNum));
    }

}
