/********************************************************************************
** Form generated from reading UI file 'tasksetting.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASKSETTING_H
#define UI_TASKSETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_taskSetting
{
public:
    QLineEdit *taskName;
    QLineEdit *workH;
    QLineEdit *workM;
    QLineEdit *workS;
    QLineEdit *taskDifficulty;
    QPushButton *taskSave;
    QPushButton *taskCancel;
    QLineEdit *breakH;
    QLineEdit *breakM;
    QLineEdit *breakS;
    QLabel *taskNameLbl;
    QLabel *difficultyLbl;
    QLabel *workTimeLbl;
    QLabel *breakTimeLbl;
    QLabel *workHourLbl;
    QLabel *breakHourLbl;
    QLabel *workMinuteLbl;
    QLabel *breakMinuteLbl;
    QLabel *workSecondLbl;
    QLabel *breakSecondLbl;

    void setupUi(QWidget *taskSetting)
    {
        if (taskSetting->objectName().isEmpty())
            taskSetting->setObjectName("taskSetting");
        taskSetting->resize(538, 406);
        taskName = new QLineEdit(taskSetting);
        taskName->setObjectName("taskName");
        taskName->setGeometry(QRect(100, 60, 113, 25));
        workH = new QLineEdit(taskSetting);
        workH->setObjectName("workH");
        workH->setGeometry(QRect(80, 150, 113, 25));
        workM = new QLineEdit(taskSetting);
        workM->setObjectName("workM");
        workM->setGeometry(QRect(240, 150, 113, 25));
        workS = new QLineEdit(taskSetting);
        workS->setObjectName("workS");
        workS->setGeometry(QRect(390, 150, 113, 25));
        taskDifficulty = new QLineEdit(taskSetting);
        taskDifficulty->setObjectName("taskDifficulty");
        taskDifficulty->setGeometry(QRect(330, 60, 113, 25));
        taskSave = new QPushButton(taskSetting);
        taskSave->setObjectName("taskSave");
        taskSave->setGeometry(QRect(110, 250, 93, 28));
        taskCancel = new QPushButton(taskSetting);
        taskCancel->setObjectName("taskCancel");
        taskCancel->setGeometry(QRect(300, 250, 93, 28));
        breakH = new QLineEdit(taskSetting);
        breakH->setObjectName("breakH");
        breakH->setGeometry(QRect(80, 190, 113, 25));
        breakM = new QLineEdit(taskSetting);
        breakM->setObjectName("breakM");
        breakM->setGeometry(QRect(240, 200, 113, 25));
        breakS = new QLineEdit(taskSetting);
        breakS->setObjectName("breakS");
        breakS->setGeometry(QRect(380, 200, 113, 25));
        taskNameLbl = new QLabel(taskSetting);
        taskNameLbl->setObjectName("taskNameLbl");
        taskNameLbl->setGeometry(QRect(110, 40, 69, 19));
        difficultyLbl = new QLabel(taskSetting);
        difficultyLbl->setObjectName("difficultyLbl");
        difficultyLbl->setGeometry(QRect(350, 40, 69, 19));
        workTimeLbl = new QLabel(taskSetting);
        workTimeLbl->setObjectName("workTimeLbl");
        workTimeLbl->setGeometry(QRect(10, 150, 69, 19));
        breakTimeLbl = new QLabel(taskSetting);
        breakTimeLbl->setObjectName("breakTimeLbl");
        breakTimeLbl->setGeometry(QRect(10, 190, 69, 19));
        workHourLbl = new QLabel(taskSetting);
        workHourLbl->setObjectName("workHourLbl");
        workHourLbl->setGeometry(QRect(200, 150, 21, 21));
        breakHourLbl = new QLabel(taskSetting);
        breakHourLbl->setObjectName("breakHourLbl");
        breakHourLbl->setGeometry(QRect(200, 190, 21, 21));
        workMinuteLbl = new QLabel(taskSetting);
        workMinuteLbl->setObjectName("workMinuteLbl");
        workMinuteLbl->setGeometry(QRect(360, 150, 21, 21));
        breakMinuteLbl = new QLabel(taskSetting);
        breakMinuteLbl->setObjectName("breakMinuteLbl");
        breakMinuteLbl->setGeometry(QRect(360, 200, 21, 21));
        workSecondLbl = new QLabel(taskSetting);
        workSecondLbl->setObjectName("workSecondLbl");
        workSecondLbl->setGeometry(QRect(510, 150, 21, 21));
        breakSecondLbl = new QLabel(taskSetting);
        breakSecondLbl->setObjectName("breakSecondLbl");
        breakSecondLbl->setGeometry(QRect(510, 200, 21, 21));

        retranslateUi(taskSetting);

        QMetaObject::connectSlotsByName(taskSetting);
    } // setupUi

    void retranslateUi(QWidget *taskSetting)
    {
        taskSetting->setWindowTitle(QCoreApplication::translate("taskSetting", "Form", nullptr));
        taskSave->setText(QCoreApplication::translate("taskSetting", "\347\241\256\345\256\232", nullptr));
        taskCancel->setText(QCoreApplication::translate("taskSetting", "\345\217\226\346\266\210", nullptr));
        taskNameLbl->setText(QCoreApplication::translate("taskSetting", "\344\273\273\345\212\241\345\220\215\347\247\260", nullptr));
        difficultyLbl->setText(QCoreApplication::translate("taskSetting", "\351\232\276\345\272\246", nullptr));
        workTimeLbl->setText(QCoreApplication::translate("taskSetting", "\345\267\245\344\275\234\346\227\266\351\227\264", nullptr));
        breakTimeLbl->setText(QCoreApplication::translate("taskSetting", "\344\274\221\346\201\257\346\227\266\351\227\264", nullptr));
        workHourLbl->setText(QCoreApplication::translate("taskSetting", "h", nullptr));
        breakHourLbl->setText(QCoreApplication::translate("taskSetting", "h", nullptr));
        workMinuteLbl->setText(QCoreApplication::translate("taskSetting", "m", nullptr));
        breakMinuteLbl->setText(QCoreApplication::translate("taskSetting", "m", nullptr));
        workSecondLbl->setText(QCoreApplication::translate("taskSetting", "s", nullptr));
        breakSecondLbl->setText(QCoreApplication::translate("taskSetting", "s", nullptr));
    } // retranslateUi

};

namespace Ui {
    class taskSetting: public Ui_taskSetting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASKSETTING_H
