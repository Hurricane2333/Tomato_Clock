
#include "history.h"
#include "ui_history.h"
#include<QDate>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QSqlError>
#include<QGridLayout>



history::history(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::history)
{
    ui->setupUi(this);
    QChart* chart = ui->chartView->chart();
    //添加x轴和y轴
    chart->addAxis(axisX, Qt::AlignBottom);
    chart->addAxis(axisY, Qt::AlignLeft);
    axisX->setTitleText("日期");// 设置X轴标题
    axisY->setRange(0, 24);// 设置Y轴范围
    axisY->setTitleText("学习时间/30min");// 设置Y轴标题

}

history::~history()
{
    delete ui;
}

void history::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setOpacity(0.6);
    QPixmap backPic(":/res/42.png");
    QPixmap scaledPixmap = backPic.scaled(this->size(),Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation);
    painter.drawPixmap((this->size().width()-scaledPixmap.width())/2, 0 ,scaledPixmap);
        //通过计算使图片水平居中                       //图片置于顶端
}

void history::initChart()
{
    QFont font;
    font.setFamily("Arial"); //设置字体家族为Arial
    font.setPointSize(14); //设置字体大小为14
    font.setBold(true); //设置字体加粗
    ui->textEdit->setFont(font);

    //查询最后一条记录
    QSqlQuery query;
    QString sqlSelect = QString("select * from history order by id desc limit 1;");
    if(!query.exec(sqlSelect))
    {
        qDebug()<<"select error in history";
    }
    if(query.next())
    {
    ui->textEdit->setText("今日学习："+query.value("studyTime").toString()+"分钟"
                          +"\n任务开始次数："+query.value("startNum").toString()
                          +"\n任务暂停次数："+query.value("pauseNum").toString()
                          +"\n提前结束次数："+query.value("stopNum").toString()
                          +"\n创建任务个数："+query.value("createNum").toString()
                          +"\n完成任务个数："+query.value("finishNum").toString()
                          );
    }



    QChart* chart = ui->chartView->chart();
    QBarSet* set0 = new QBarSet("");
    QStringList categories;// X轴分类

    //避免重复加载统计图
    if (chart->series().count() > 0) {
        chart->removeSeries(chart->series().first());
    }
    if (axisX->categories().count() > 0) {
        axisX->clear();
    }

    //显示最新7条记录
    sqlSelect = QString("select * from history order by id desc limit 7;");
    if(!query.exec(sqlSelect))
    {
        qDebug()<<"select error in history";
    }

    //为每一个条形添加数据
    while(query.next())
    {
        QString date=query.value("date").toString();
        int time=query.value("studyTime").toInt();
        *set0<<time/30;//将学习时间（分钟）取整转换为0.5h
        categories<<date;
    }

    axisX->append(categories);

    QBarSeries* series = new QBarSeries();
    series->append(set0);
    //显示数据标签
    series->setLabelsVisible(true);

    chart->addSeries(series);// 将创建好的条形图series添加进chart中
    chart->setTitle("番茄历史记录");//设置标题
    chart->setAnimationOptions(QChart::SeriesAnimations);  //设置图表变化时的动画效果


    series->attachAxis(axisX);//将axis指定的轴附着到series。
    series->attachAxis(axisY);


    chart->legend()->setVisible(true);//设置图例是否可见
    chart->legend()->setAlignment(Qt::AlignRight); //设置图例显示的位置
    ui->chartView->setRenderHint(QPainter::Antialiasing);  //设置抗锯齿


}
