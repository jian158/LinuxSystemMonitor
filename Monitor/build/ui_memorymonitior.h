/********************************************************************************
** Form generated from reading UI file 'memorymonitior.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MEMORYMONITIOR_H
#define UI_MEMORYMONITIOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MemoryMonitior
{
public:

    void setupUi(QWidget *MemoryMonitior)
    {
        if (MemoryMonitior->objectName().isEmpty())
            MemoryMonitior->setObjectName(QStringLiteral("MemoryMonitior"));
        MemoryMonitior->resize(400, 300);

        retranslateUi(MemoryMonitior);

        QMetaObject::connectSlotsByName(MemoryMonitior);
    } // setupUi

    void retranslateUi(QWidget *MemoryMonitior)
    {
        MemoryMonitior->setWindowTitle(QApplication::translate("MemoryMonitior", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class MemoryMonitior: public Ui_MemoryMonitior {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MEMORYMONITIOR_H
