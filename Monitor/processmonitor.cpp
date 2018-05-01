#include "processmonitor.h"
#include "ui_processmonitor.h"
#include <QProcess>
#include <QHBoxLayout>
#include<QDebug>
#include <QPainter>
#include <QDir>
int ProcessMonitor::sortMode=1;
ProcessMonitor::ProcessMonitor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProcessMonitor)
{
    ui->setupUi(this);
//    listview=new ProcessListView(this);
    listview=new QTableView;
    QFont font=this->font();
    font.setPointSize(14);
    listview->setFont(font);
    QVBoxLayout *hbox=new QVBoxLayout;
    lineEdit=new QLineEdit;
    lineEdit->setPlaceholderText("输入名称/PID/PPID/状态");
    createContextMenu();
    hbox->addWidget(listview);
    hbox->addWidget(lineEdit);
//    hbox->setStretch(0,9);
//    hbox->setStretch(1,9);
    model=new QStandardItemModel;
    model->setHorizontalHeaderItem(0,new QStandardItem("名称"));
    model->setHorizontalHeaderItem(1,new QStandardItem("CPU"));
    model->setHorizontalHeaderItem(2,new QStandardItem("内存"));
    model->setHorizontalHeaderItem(3,new QStandardItem("PID"));
    model->setHorizontalHeaderItem(4,new QStandardItem("PPID"));
    model->setHorizontalHeaderItem(5,new QStandardItem("优先级"));
    model->setHorizontalHeaderItem(6,new QStandardItem("状态"));

    listview->horizontalHeader()->setStretchLastSection(true);
//    listview->horizontalHeader()->setMinimumSectionSize(100);
    listview->setModel(model);
    listview->setColumnWidth(0,360);
    listview->setSelectionBehavior(QAbstractItemView::SelectRows);
    listview->verticalHeader()->hide();
//    listview->setSortingEnabled(true);

    //DescendingOrder
    listview->horizontalHeader()->setSortIndicator(1,Qt::DescendingOrder);
    listview->horizontalHeader()->setSortIndicatorShown(true);

    setLayout(hbox);
    hbox->setContentsMargins(0,20,0,20);
    this->update();
    connect(&timer,SIGNAL(timeout()),this,SLOT(update()));
    timer.start(2000);

    connect(listview->horizontalHeader(),SIGNAL(sectionClicked(int)),this,SLOT(onColumnClick(int)));
    connect(listview,SIGNAL(clicked(QModelIndex)),this,SLOT(onItemClick(QModelIndex)));
    connect(listview,SIGNAL(customContextMenuRequested(QPoint)),this,SLOT(onContextMenu(QPoint)));

}

ProcessMonitor::~ProcessMonitor()
{
    delete menu;
    delete model;
    delete listview;
    delete ui;
}

void ProcessMonitor::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QFont font=painter.font();
    font.setPointSize(14);
    painter.setFont(font);
    painter.fillRect(rect(),Qt::white);
}

void ProcessMonitor::createContextMenu()
{
    menu=new QMenu(this);
    QFont font=this->font();
    font.setPointSize(14);
    menu->setFont(font);
    QAction *endAction=new QAction("end",0);
    menu->addAction(endAction);
    setContextMenuPolicy(Qt::CustomContextMenu);
    connect(this,SIGNAL(customContextMenuRequested(QPoint)),this,SLOT(onContextMenu(QPoint)));
    connect(endAction,SIGNAL(triggered(bool)),this,SLOT(onEndActionClick(bool)));

}

void ProcessMonitor::resizeEvent(QResizeEvent *event)
{

}

void ProcessMonitor::getMemory(int pid)
{

}

void ProcessMonitor::onItemClick(const QModelIndex &index)
{
    QModelIndex i=model->index(index.row(),3);
    currentPid=i.data().toString();
}
#include <signal.h>
void ProcessMonitor::onEndActionClick(bool)
{
    kill(currentPid.toInt(),SIGKILL);
}
#include <QMessageBox>
void ProcessMonitor::onContextMenu(const QPoint &p)
{
//    currentPid=(model->index(listview->indexAt(p).row()-2,3).data()).toInt();
//    qDebug()<<currentPid;
    menu->move(QCursor::pos());
    menu->show();
}

bool compare(const Listitem& i1,const Listitem &i2){
    bool b;
    switch (ProcessMonitor::sortMode) {
    case 0:
        b=i2.comm.compare(i1.comm,Qt::CaseInsensitive)>0;
        break;
    case 1:
        b=i1.cpu>i2.cpu;
        break;
    case 2:
        b=i1.rss.toInt()>i2.rss.toInt();
        break;
    case 3:
        b=i1.pid.toInt()>i2.pid.toInt();
        break;
    case 4:
        b=i1.ppid.toInt()>i2.ppid.toInt();
        break;
    case 5:
        b=i1.pri.toInt()>i2.pri.toInt();
        break;
    default:
        b=i1.rss.toInt()>i2.rss.toInt();
        break;
    }
    return b;
}



void ProcessMonitor::update()
{
    if(showMenu)
        return;
//    if(listview->isScroll())
//        return;

//    listview->clear();

    QProcess process;
    process.start("cat /proc/stat");
    process.waitForFinished();
    QByteArray output = process.readAllStandardOutput();
    QString s= output;
    s=s.left(s.indexOf("\n"));
    QStringList list=s.split(" ");
//    long long workTime=list[1].toLongLong()+list[2].toLongLong()+list[3].toLongLong();
    long long totalTime=list[1].toLongLong()+list[2].toLongLong()+list[3].toLongLong()+list[4].toLongLong()+list[5].toLongLong()+list[6].toLongLong()+list[7].toLongLong()+list[8].toLongLong();
    long long _cpu=0;
    QDir dir("/proc");
    QStringList dirs=dir.entryList();
    QVector<Listitem> items;
    if(lineEdit->text().length()>0){
        int count=model->rowCount();
        for (int var = 0; var < count; ++var) {
            model->removeRow(0);
        }
    }

    foreach (QString s, dirs) {
        if(s.at(0).isDigit()){
            QFile file("/proc/"+s+"/stat");
            if(file.open(QIODevice::ReadOnly)){
                Listitem item;
                QStringList list=(QString(file.readAll())).split(" ");
                item.pid=s;
                item.comm=list[1].mid(1,list[1].length()-2);
                item.state=list[2];
                item.ppid=list[3];
                _cpu=list[13].toLongLong()+list[14].toLongLong()+list[15].toLongLong()+list[16].toLongLong();
                item.pri=list[17];
                item.rss=list[23];
                file.close();


                if(preWorkTimes.contains(item.pid))
                    item.cpu=(_cpu-preWorkTimes[item.pid])*100.0/(totalTime-preTotalTime);
                else
                    item.cpu=(_cpu)*100.0/(totalTime-preTotalTime);
                preWorkTimes[item.pid]=_cpu;

//                if(lineEdit->text().length()>0&&item.state=="S"){
//                    if(item.comm.indexOf(lineEdit->text())>-1||item.pid==lineEdit->text()||item.ppid==lineEdit->text())
//                        items.push_back(item);
//                }
//                else if(item.state=="S")
//                    items.push_back(item);
                if(lineEdit->text().length()>0){
                    if(item.comm.indexOf(lineEdit->text())>-1||item.pid==lineEdit->text()||item.ppid==lineEdit->text()||item.state==lineEdit->text())
                        items.push_back(item);
                }
                else
                    items.push_back(item);

                file.close();
//                listview->append("",item.pid,item.comm,QString::number(item.cpu,'f',2),QString::number(item.rss.toInt()/1024.0,'f',2)+"MB",item.ppid,item.pri);
            }
        }
    }
    qSort(items.begin(),items.end(),compare);


    int i;
    for (i = 0; i< items.size(); ++i) {
        model->setItem(i,0,new QStandardItem(items[i].comm));
        model->setItem(i,1,new QStandardItem(QString::number(items[i].cpu,'f',1)));
        model->setItem(i,2,new QStandardItem(QString::number(items[i].rss.toInt()/1024.0,'f',1)+"MB"));
        model->setItem(i,3,new QStandardItem(items[i].pid));
        model->setItem(i,4,new QStandardItem(items[i].ppid));
        model->setItem(i,5,new QStandardItem(items[i].pri));
        model->setItem(i,6,new QStandardItem(items[i].state));
        if(items[i].pid==currentPid){
            listview->selectRow(i);
        }
    }

    for (int row=i;i<model->rowCount();i++) {
        model->removeRow(row);
    }


//    listview->resizeColumnsToContents();




//    foreach (Listitem item, items) {
//        listview->append("",item.pid,item.comm,QString::number(item.cpu,'f',1),QString::number(item.rss.toInt()/1024.0,'f',1)+"MB",item.ppid,item.pri);
//    }

    preTotalTime=totalTime;
//    listview->setvalue();
    repaint();
}

void ProcessMonitor::onColumnClick(int col)
{
    sortMode=col;
}
