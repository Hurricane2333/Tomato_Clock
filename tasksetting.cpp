#include "tasksetting.h"
#include "ui_tasksetting.h"

tasksetting::tasksetting(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::tasksetting)
{
    ui->setupUi(this);
}

tasksetting::~tasksetting()
{
    delete ui;
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
    this->close(); // 关闭窗口
    emit taskAdded(); // 发送信号
}

