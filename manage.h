#ifndef MANAGE_H
#define MANAGE_H

#include <QWidget>
#include"tasksetting.h"
#include"taskform.h"

namespace Ui {
class manage;
}

class manage : public QWidget
{
    Q_OBJECT

public:
    explicit manage(QWidget *parent = nullptr);
    ~manage();
    void updateWindow();//更新ui
    tasksetting*taskWindow=new tasksetting;
    //QSqlDatabase db; // 声明数据库连接对象

signals:
    void saved();

private slots:
    void on_accountBtn_clicked();

    void on_addTaskBtn_clicked();

    void on_saveBtn_clicked();

private:
    Ui::manage *ui;
};

#endif // MANAGE_H
