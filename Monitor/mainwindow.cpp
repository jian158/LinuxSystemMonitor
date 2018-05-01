#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "memorymonitior.h"
#include "cpumonitor.h"
#include "networkmonitor.h"
#include "processmonitor.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("系统监视器");
    QHBoxLayout *mainBox=new QHBoxLayout;
    ui->centralWidget->setLayout(mainBox);

    QVBoxLayout *hbox=new QVBoxLayout;
    hbox->addWidget(new CPUMonitor);
    hbox->addWidget(new MemoryMonitior);
    hbox->addWidget(new NetWorkMonitor);

    QHBoxLayout *layout=new QHBoxLayout;

    layout->addWidget(new ProcessMonitor);

    mainBox->addLayout(hbox);
    mainBox->addLayout(layout);
    mainBox->setStretch(0,1);
    mainBox->setStretch(1,4);

    ui->menuBar->setStyleSheet("background:white");
    time=new QLabel("694");
    QFont font=this->font();
    font.setPointSize(14);
    setFont(font);
    ui->statusBar->addPermanentWidget(time);
    updateTime();
    connect(&timer,SIGNAL(timeout()),this,SLOT(updateTime()));
    timer.start(1000);
//    ui->statusBar->setToolTip("738");
//    mainBox->addStretch(1);

}


void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.fillRect(rect(),Qt::white);
}

void MainWindow::resizeEvent(QResizeEvent *event)
{

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_action_triggered()
{
    infoWin.show();
}

void MainWindow::updateTime()
{
    QDateTime time=QDateTime::currentDateTime();
    this->time->setText(time.toString("yyyy-MM-dd hh:mm:ss"));
}


void MainWindow::on_action_2_triggered()
{
    system("/home/wei/Qt/Monitor/cmd/power.sh");
//    QProcess *process=new QProcess;
//    process->start("sh :/new/prefix1/cmd/power.sh");
//    process->waitForFinished();
//    QProcess::execute("echo '1234'|sudo -S shutdown -h now");
//    qDebug()<<process->readAll();
}
