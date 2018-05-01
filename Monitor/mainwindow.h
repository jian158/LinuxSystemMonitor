#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QtWidgets>
#include <QtCore>
#include "infowin.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event);
    ~MainWindow();

private slots:
    void on_action_triggered();
    void updateTime();
    void on_action_2_triggered();

    
private:
    Ui::MainWindow *ui;
    InfoWin infoWin;
    QTimer timer;
    QLabel *time;
};

#endif // MAINWINDOW_H
