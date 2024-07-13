#ifndef HISTORY_H
#define HISTORY_H

#include <QMainWindow>
#include <QtCharts>


namespace Ui {
class history;
}

class history : public QMainWindow
{
    Q_OBJECT

public:
    explicit history(QWidget *parent = nullptr);
    ~history();
    void initChart();
    QBarCategoryAxis* axisX = new QBarCategoryAxis();// QBarCategoryAxis类向图表的轴添加类别。
    QValueAxis* axisY = new QValueAxis();// 创建Y轴
    void paintEvent(QPaintEvent *event);

private:
    Ui::history *ui;
};

#endif // HISTORY_H
