/********************************************************************************
** Form generated from reading UI file 'networkmonitor.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NETWORKMONITOR_H
#define UI_NETWORKMONITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NetWorkMonitor
{
public:

    void setupUi(QWidget *NetWorkMonitor)
    {
        if (NetWorkMonitor->objectName().isEmpty())
            NetWorkMonitor->setObjectName(QStringLiteral("NetWorkMonitor"));
        NetWorkMonitor->resize(346, 178);

        retranslateUi(NetWorkMonitor);

        QMetaObject::connectSlotsByName(NetWorkMonitor);
    } // setupUi

    void retranslateUi(QWidget *NetWorkMonitor)
    {
        NetWorkMonitor->setWindowTitle(QApplication::translate("NetWorkMonitor", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class NetWorkMonitor: public Ui_NetWorkMonitor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NETWORKMONITOR_H
