#include "tasksetting.h"
#include "ui_tasksetting.h"
#include<QPainter>

tasksetting::tasksetting(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::tasksetting)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/res/tomato.png"));
}

tasksetting::~tasksetting()
{
    delete ui;
}

void tasksetting::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setOpacity(0.2);
    QPixmap backPic(":/res/42.png");
    QPixmap scaledPixmap = backPic.scaled(this->size(),Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation);
    painter.drawPixmap((this->size().width()-scaledPixmap.width())/2, 0 ,scaledPixmap);
        //通过计算使图片水平居中                       //图片置于顶端
}

void tasksetting::on_saveBtn_clicked()//保存按钮
{
    //将ui的lineEdit插入到数据库
    QString name = ui->nameLineEdit->text();
    QString grade = ui->gradeLineEdit->text();
    QString studyTime = ui->studyLineEdit->text();
    QString breakTime = ui->breakLineEdit->text();
    QString turn=ui->turnLineEdit->text();
    QSqlQuery query;
    QString sqlIn = QString("insert into task (name, grade, studyTime, breakTime,turn) "
                            "values ('%1', %2, %3, %4, %5);")
                        .arg(name)
                        .arg(grade.toInt())
                        .arg(studyTime.toInt())
                        .arg(breakTime.toInt())
                        .arg(turn);
    if (!query.exec(sqlIn))
    {
        qDebug() << "Error executing SQL query: " << query.lastError();
    }
    ui->nameLineEdit->clear();
    ui->gradeLineEdit->clear();
    ui->studyLineEdit->clear();
    ui->breakLineEdit->clear();
    ui->turnLineEdit->clear();
    this->close();
    emit taskAdded();
}

