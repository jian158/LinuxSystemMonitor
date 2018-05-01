#ifndef PROCESSMONITOR_H
#define PROCESSMONITOR_H

#include <QWidget>
#include <QTimer>
#include <QTableView>
#include <QStandardItemModel>
#include <QLineEdit>
#include <QMenu>
namespace Ui {
class ProcessMonitor;
}

class Listitem
{
public:
    QString pid,comm,rss,ppid,pri,state;
    double cpu;
};

class ProcessMonitor : public QWidget
{
    Q_OBJECT

public:
    static int sortMode;
    explicit ProcessMonitor(QWidget *parent = 0);
    ~ProcessMonitor();
    void paintEvent(QPaintEvent *event);
    void createContextMenu();
    void resizeEvent(QResizeEvent *event);
private:
    void getMemory(int pid);


public slots:
    void onItemClick(const QModelIndex& index);
    void onEndActionClick(bool);
    void onContextMenu(const QPoint&p);
    void update();
    void onColumnClick(int col);
private:
    QMenu *menu;
    QTimer timer;
    Ui::ProcessMonitor *ui;
    QTableView *listview;
    QString currentPid="";
    QStandardItemModel *model;
//    ProcessListView *listview;
    QMap<QString,long long> preWorkTimes;
//    long long preWorkTime=0;
    long long preTotalTime=0;
    QLineEdit *lineEdit;
    bool showMenu=false;

};



#endif // PROCESSMONITOR_H
