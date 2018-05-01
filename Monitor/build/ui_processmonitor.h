/********************************************************************************
** Form generated from reading UI file 'processmonitor.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROCESSMONITOR_H
#define UI_PROCESSMONITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProcessMonitor
{
public:

    void setupUi(QWidget *ProcessMonitor)
    {
        if (ProcessMonitor->objectName().isEmpty())
            ProcessMonitor->setObjectName(QStringLiteral("ProcessMonitor"));
        ProcessMonitor->resize(349, 260);

        retranslateUi(ProcessMonitor);

        QMetaObject::connectSlotsByName(ProcessMonitor);
    } // setupUi

    void retranslateUi(QWidget *ProcessMonitor)
    {
        ProcessMonitor->setWindowTitle(QApplication::translate("ProcessMonitor", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class ProcessMonitor: public Ui_ProcessMonitor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROCESSMONITOR_H
