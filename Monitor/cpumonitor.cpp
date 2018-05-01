#include "cpumonitor.h"
#include "ui_cpumonitor.h"
#include <QProcess>
#include <QPainter>
#include <QtMath>
#include <QDebug>
#include "util.h"
CPUMonitor::CPUMonitor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CPUMonitor)
{
    ui->setupUi(this);

    for (int i = 0; i < 24; i++) {
        cpuPercents.append(0);
    }

    connect(&aniTimer, SIGNAL(timeout()), this, SLOT(render()));
    aniTimer.start(30);

    connect(&timer,SIGNAL(timeout()),this,SLOT(update()));
    timer.start(2000);


}

CPUMonitor::~CPUMonitor()
{
    delete ui;
}

void CPUMonitor::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setPen(QPen(QColor(0,255,0),2));
    painter.drawArc(30,30,140,140,310*16,16*280);

    painter.drawArc(24,24,152,152,310*16,16*280);

    QFont font=painter.font();
    font.setPointSize(20);
    painter.setFont(font);

    double percent = (cpuPercents.at(cpuPercents.size() - 2) + ((1 - qCos(3.14* (animationIndex / animationFrames) )) / 2)
                      *
                      (cpuPercents.last() - cpuPercents.at(cpuPercents.size() - 2)));

    QString s_Percent=QString::number(percent,'f',1);

    painter.drawText(s_Percent.length()>3?70:78,170,s_Percent);


    painter.setPen(QPen(QColor(255,255,0),6));
    int startle=280*percent/100;
    painter.drawArc(27,27,146,146,(230-startle)*16,16*(startle));




    painter.translate(40, 100);
    painter.scale(1, -1);

    painter.setPen(QPen(QColor("#2CA7F8"), 2));
    painter.drawPath(cpuPath);
}

void CPUMonitor::updateStatus(double cpuPercent)
{
    cpuPercents.append(cpuPercent);
    if (cpuPercents.size() > 24) {
        cpuPercents.pop_front();
    }

    QList<QPointF> points;

    double cpuMaxHeight = 0;
    for (int i = 0; i < cpuPercents.size(); i++) {
        if (cpuPercents.at(i) > cpuMaxHeight) {
            cpuMaxHeight = cpuPercents.at(i);
        }
    }

    for (int i = 0; i < cpuPercents.size(); i++) {
        if (cpuMaxHeight < cpuRenderMaxHeight) {
            points.append(QPointF(i * 5, cpuPercents.at(i)));
        } else {
            points.append(QPointF(i * 5, cpuPercents.at(i) * cpuRenderMaxHeight / cpuMaxHeight));
        }
    }
    cpuPath =Util::generateSmoothCurve(points);

    if (cpuPercents.last() != cpuPercents.at(cpuPercents.size() - 2)) {
        animationIndex = 0;
        aniTimer.start(30);
    }

}



void CPUMonitor::update()
{
    QProcess process;
    process.start("cat /proc/stat");
    process.waitForFinished();
    QByteArray output = process.readAllStandardOutput();
    QString s= output;
    s=s.left(s.indexOf("\n"));
    QStringList list=s.split(" ");
    long long workTime=list[1].toLongLong()+list[2].toLongLong()+list[3].toLongLong();
    long long totalTime=list[1].toLongLong()+list[2].toLongLong()+list[3].toLongLong()+list[4].toLongLong()+list[5].toLongLong()+list[6].toLongLong()+list[7].toLongLong()+list[8].toLongLong();

    updateStatus((workTime-preWorkTime)*100.0/(totalTime-preTotalTime));
    preWorkTime=workTime;
    preTotalTime=totalTime;
}

void CPUMonitor::render()
{
    if (animationIndex < animationFrames) {
        animationIndex++;

        repaint();
    } else {
        aniTimer.stop();
    }
}
