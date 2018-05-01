#include "mainwindow.h"
#include <QApplication>
#include <QProcess>
#include <QDebug>
#include <infowin.h>
int main(int argc, char *argv[])
{
    QApplication a(argc,argv);

    MainWindow mainWindow;
    mainWindow.show();
    return a.exec();
//    InfoWin info;
//    info.update();
//    QString s="Inactive:        1772444 kB";
//    QRegExp regx(".*(\\d+)\\s");
//    regx.indexIn(s);
//    qDebug()<<regx.cap(1);
//    s="Inactive(file):  1145508 kB";
//    regx.indexIn(s);
//    qDebug()<<regx.cap(1);
}
