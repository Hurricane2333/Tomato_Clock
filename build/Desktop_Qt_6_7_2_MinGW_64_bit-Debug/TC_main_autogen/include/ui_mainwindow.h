/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainWindow
{
public:
    QLabel *workDisplayLbl;
    QLabel *timeDisplayLbl;
    QPushButton *workStartBtn;
    QPushButton *workStopBtn;
    QPushButton *workPassBtn;
    QPushButton *workListSettingBtn;
    QPushButton *historicalDataBtn;
    QPushButton *lockBtn;
    QPushButton *rewardBtn;

    void setupUi(QWidget *mainWindow)
    {
        if (mainWindow->objectName().isEmpty())
            mainWindow->setObjectName("mainWindow");
        mainWindow->resize(800, 600);
        workDisplayLbl = new QLabel(mainWindow);
        workDisplayLbl->setObjectName("workDisplayLbl");
        workDisplayLbl->setGeometry(QRect(240, 180, 69, 19));
        timeDisplayLbl = new QLabel(mainWindow);
        timeDisplayLbl->setObjectName("timeDisplayLbl");
        timeDisplayLbl->setGeometry(QRect(400, 180, 69, 19));
        workStartBtn = new QPushButton(mainWindow);
        workStartBtn->setObjectName("workStartBtn");
        workStartBtn->setGeometry(QRect(190, 280, 93, 28));
        workStopBtn = new QPushButton(mainWindow);
        workStopBtn->setObjectName("workStopBtn");
        workStopBtn->setGeometry(QRect(320, 280, 93, 28));
        workPassBtn = new QPushButton(mainWindow);
        workPassBtn->setObjectName("workPassBtn");
        workPassBtn->setGeometry(QRect(460, 280, 93, 28));
        workListSettingBtn = new QPushButton(mainWindow);
        workListSettingBtn->setObjectName("workListSettingBtn");
        workListSettingBtn->setGeometry(QRect(50, 180, 93, 28));
        historicalDataBtn = new QPushButton(mainWindow);
        historicalDataBtn->setObjectName("historicalDataBtn");
        historicalDataBtn->setGeometry(QRect(50, 260, 93, 28));
        lockBtn = new QPushButton(mainWindow);
        lockBtn->setObjectName("lockBtn");
        lockBtn->setGeometry(QRect(600, 180, 93, 28));
        rewardBtn = new QPushButton(mainWindow);
        rewardBtn->setObjectName("rewardBtn");
        rewardBtn->setGeometry(QRect(600, 280, 93, 28));

        retranslateUi(mainWindow);

        QMetaObject::connectSlotsByName(mainWindow);
    } // setupUi

    void retranslateUi(QWidget *mainWindow)
    {
        mainWindow->setWindowTitle(QCoreApplication::translate("mainWindow", "mainWindow", nullptr));
        workDisplayLbl->setText(QCoreApplication::translate("mainWindow", "\345\275\223\345\211\215\344\273\273\345\212\241", nullptr));
        timeDisplayLbl->setText(QCoreApplication::translate("mainWindow", "00:00:00", nullptr));
        workStartBtn->setText(QCoreApplication::translate("mainWindow", "\345\274\200\345\247\213", nullptr));
        workStopBtn->setText(QCoreApplication::translate("mainWindow", "\346\232\202\345\201\234", nullptr));
        workPassBtn->setText(QCoreApplication::translate("mainWindow", "\344\270\213\344\270\200\351\241\271", nullptr));
        workListSettingBtn->setText(QCoreApplication::translate("mainWindow", "\344\273\273\345\212\241\350\256\276\347\275\256", nullptr));
        historicalDataBtn->setText(QCoreApplication::translate("mainWindow", "\346\225\260\346\215\256\350\256\260\345\275\225", nullptr));
        lockBtn->setText(QCoreApplication::translate("mainWindow", "\351\227\255\345\205\263", nullptr));
        rewardBtn->setText(QCoreApplication::translate("mainWindow", "\346\212\275\345\215\241", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mainWindow: public Ui_mainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
