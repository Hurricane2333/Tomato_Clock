/********************************************************************************
** Form generated from reading UI file 'cleartaskwarning.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLEARTASKWARNING_H
#define UI_CLEARTASKWARNING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_clearTaskWarning
{
public:

    void setupUi(QWidget *clearTaskWarning)
    {
        if (clearTaskWarning->objectName().isEmpty())
            clearTaskWarning->setObjectName("clearTaskWarning");
        clearTaskWarning->resize(400, 300);

        retranslateUi(clearTaskWarning);

        QMetaObject::connectSlotsByName(clearTaskWarning);
    } // setupUi

    void retranslateUi(QWidget *clearTaskWarning)
    {
        clearTaskWarning->setWindowTitle(QCoreApplication::translate("clearTaskWarning", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class clearTaskWarning: public Ui_clearTaskWarning {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLEARTASKWARNING_H
