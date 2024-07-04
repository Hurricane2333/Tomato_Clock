/********************************************************************************
** Form generated from reading UI file 'tasklist.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASKLIST_H
#define UI_TASKLIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_taskList
{
public:
    QPushButton *newTaskBtn;
    QListWidget *taskListWgt;
    QLabel *taskListLbl;
    QPushButton *startWorkBtn;
    QLabel *workListLbl;
    QPushButton *clearTaskBtn;
    QPushButton *clearWorkBtn;
    QLabel *workTimesLbl;
    QListWidget *workListWgt;
    QTableWidget *workTimesWgt;
    QListWidget *rubbishWgt;

    void setupUi(QWidget *taskList)
    {
        if (taskList->objectName().isEmpty())
            taskList->setObjectName("taskList");
        taskList->resize(818, 639);
        newTaskBtn = new QPushButton(taskList);
        newTaskBtn->setObjectName("newTaskBtn");
        newTaskBtn->setGeometry(QRect(70, 140, 93, 28));
        taskListWgt = new QListWidget(taskList);
        taskListWgt->setObjectName("taskListWgt");
        taskListWgt->setGeometry(QRect(80, 230, 256, 192));
        taskListWgt->setDragDropOverwriteMode(false);
        taskListWgt->setDragDropMode(QAbstractItemView::DragDropMode::DragOnly);
        taskListWgt->setDefaultDropAction(Qt::DropAction::CopyAction);
        taskListWgt->setSortingEnabled(true);
        taskListLbl = new QLabel(taskList);
        taskListLbl->setObjectName("taskListLbl");
        taskListLbl->setGeometry(QRect(160, 200, 69, 19));
        startWorkBtn = new QPushButton(taskList);
        startWorkBtn->setObjectName("startWorkBtn");
        startWorkBtn->setGeometry(QRect(420, 140, 93, 28));
        workListLbl = new QLabel(taskList);
        workListLbl->setObjectName("workListLbl");
        workListLbl->setGeometry(QRect(480, 210, 69, 19));
        clearTaskBtn = new QPushButton(taskList);
        clearTaskBtn->setObjectName("clearTaskBtn");
        clearTaskBtn->setGeometry(QRect(210, 140, 111, 28));
        clearWorkBtn = new QPushButton(taskList);
        clearWorkBtn->setObjectName("clearWorkBtn");
        clearWorkBtn->setGeometry(QRect(560, 140, 111, 28));
        workTimesLbl = new QLabel(taskList);
        workTimesLbl->setObjectName("workTimesLbl");
        workTimesLbl->setGeometry(QRect(600, 210, 69, 19));
        workListWgt = new QListWidget(taskList);
        workListWgt->setObjectName("workListWgt");
        workListWgt->setGeometry(QRect(430, 230, 169, 192));
        workListWgt->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
        workListWgt->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAsNeeded);
        workListWgt->setDragDropMode(QAbstractItemView::DragDropMode::DragDrop);
        workListWgt->setDefaultDropAction(Qt::DropAction::MoveAction);
        workListWgt->setGridSize(QSize(0, 20));
        workTimesWgt = new QTableWidget(taskList);
        workTimesWgt->setObjectName("workTimesWgt");
        workTimesWgt->setGeometry(QRect(600, 230, 71, 192));
        workTimesWgt->horizontalHeader()->setVisible(false);
        workTimesWgt->horizontalHeader()->setMinimumSectionSize(40);
        workTimesWgt->horizontalHeader()->setDefaultSectionSize(40);
        workTimesWgt->horizontalHeader()->setHighlightSections(true);
        workTimesWgt->verticalHeader()->setVisible(false);
        workTimesWgt->verticalHeader()->setMinimumSectionSize(20);
        workTimesWgt->verticalHeader()->setDefaultSectionSize(20);
        rubbishWgt = new QListWidget(taskList);
        rubbishWgt->setObjectName("rubbishWgt");
        rubbishWgt->setGeometry(QRect(470, 480, 161, 101));
        rubbishWgt->setDragDropMode(QAbstractItemView::DragDropMode::DropOnly);
        rubbishWgt->setDefaultDropAction(Qt::DropAction::MoveAction);

        retranslateUi(taskList);

        QMetaObject::connectSlotsByName(taskList);
    } // setupUi

    void retranslateUi(QWidget *taskList)
    {
        taskList->setWindowTitle(QCoreApplication::translate("taskList", "Form", nullptr));
        newTaskBtn->setText(QCoreApplication::translate("taskList", "\346\226\260\345\273\272\344\273\273\345\212\241", nullptr));
        taskListLbl->setText(QCoreApplication::translate("taskList", "\347\216\260\346\234\211\344\273\273\345\212\241", nullptr));
        startWorkBtn->setText(QCoreApplication::translate("taskList", "\344\273\273\345\212\241\345\274\200\345\247\213", nullptr));
        workListLbl->setText(QCoreApplication::translate("taskList", "\346\211\247\350\241\214\345\210\227\350\241\250", nullptr));
        clearTaskBtn->setText(QCoreApplication::translate("taskList", "\346\270\205\347\251\272\344\273\273\345\212\241\345\210\227\350\241\250", nullptr));
        clearWorkBtn->setText(QCoreApplication::translate("taskList", "\346\270\205\347\251\272\346\211\247\350\241\214\345\210\227\350\241\250", nullptr));
        workTimesLbl->setText(QCoreApplication::translate("taskList", "\346\211\247\350\241\214\346\254\241\346\225\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class taskList: public Ui_taskList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASKLIST_H
