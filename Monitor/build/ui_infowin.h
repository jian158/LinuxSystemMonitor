/********************************************************************************
** Form generated from reading UI file 'infowin.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFOWIN_H
#define UI_INFOWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InfoWin
{
public:

    void setupUi(QWidget *InfoWin)
    {
        if (InfoWin->objectName().isEmpty())
            InfoWin->setObjectName(QStringLiteral("InfoWin"));
        InfoWin->resize(747, 527);

        retranslateUi(InfoWin);

        QMetaObject::connectSlotsByName(InfoWin);
    } // setupUi

    void retranslateUi(QWidget *InfoWin)
    {
        InfoWin->setWindowTitle(QApplication::translate("InfoWin", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class InfoWin: public Ui_InfoWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFOWIN_H
