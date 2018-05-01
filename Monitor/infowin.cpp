#include "infowin.h"
#include "ui_infowin.h"
#include <QVBoxLayout>
#include <QProcess>
#include <QDebug>
#include <QDateTime>
InfoWin::InfoWin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InfoWin)
{
    ui->setupUi(this);
    QFont font=this->font();
    font.setPointSize(14);
    setFont(font);
    QVBoxLayout *layout=new QVBoxLayout;
    //QLabel hostName,version,startTime,totalTime,cpu,cpuFrequent;
    layout->addWidget(&hostName);
    layout->addWidget(&version);
    layout->addWidget(&startTime);
//    layout->addWidget(&totalTime);
    layout->addWidget(&cpu);
    this->setLayout(layout);
    update();
}

void InfoWin::update()
{
    QProcess *process=new QProcess;

    process->start("cat /etc/hostname\ncat /proc/version\ncat /proc/uptime");
    process->waitForFinished();
//    process.start("cat /proc/version");
//    process.start("cat /proc/uptime");
//    process.start("cat /proc/cpuinfo | grep name | cut -f2 -d: | uniq");

    QByteArray output = process->readAllStandardOutput();
    QString s= output;
//    qDebug()<<s;
    QStringList list=s.split("\n");
    hostName.setText("主机名:"+list[0]);
    version.setText("版本信息:"+list[1]);

    quint64 start1=QDateTime::currentDateTime().toMSecsSinceEpoch();
    double start2=list[2].split(" ")[0].toDouble()*1000;
    quint64 start=start1-(quint64)start2;
//    qDebug()<<"s:"<<start1;
//    qDebug()<<"start2"<<start;
    QDateTime time=QDateTime::fromMSecsSinceEpoch(start);
    startTime.setText("开机时间:"+time.toString("yyyy-MM-dd hh:mm:ss"));
    process->kill();
    process->deleteLater();
    process=new QProcess;
    process->start("cat /proc/cpuinfo");
    process->waitForFinished();
    output=process->readAllStandardOutput();
    s=output;
    QRegExp regx("(model name\t:)(.*)\n");
    regx.setMinimal(true);
    s.indexOf(regx);
    cpu.setText("CPU信息:"+regx.cap(2).split("\n")[0]);
    process->deleteLater();
}

InfoWin::~InfoWin()
{
    delete ui;
}
