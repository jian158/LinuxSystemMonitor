/********************************************************************************
** Form generated from reading UI file 'cpumonitor.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CPUMONITOR_H
#define UI_CPUMONITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CPUMonitor
{
public:
    QLabel *label;

    void setupUi(QWidget *CPUMonitor)
    {
        if (CPUMonitor->objectName().isEmpty())
            CPUMonitor->setObjectName(QStringLiteral("CPUMonitor"));
        CPUMonitor->resize(400, 300);
        label = new QLabel(CPUMonitor);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(80, 180, 61, 21));
        QFont font;
        font.setPointSize(16);
        label->setFont(font);

        retranslateUi(CPUMonitor);

        QMetaObject::connectSlotsByName(CPUMonitor);
    } // setupUi

    void retranslateUi(QWidget *CPUMonitor)
    {
        CPUMonitor->setWindowTitle(QApplication::translate("CPUMonitor", "Form", 0));
        label->setText(QApplication::translate("CPUMonitor", "CPU", 0));
    } // retranslateUi

};

namespace Ui {
    class CPUMonitor: public Ui_CPUMonitor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CPUMONITOR_H
