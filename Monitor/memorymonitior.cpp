#include "memorymonitior.h"
#include "ui_memorymonitior.h"
#include <QProcess>
#include "util.h"
MemoryMonitior::MemoryMonitior(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MemoryMonitior)
{
    ui->setupUi(this);

    for (int i = 0; i < pointNumber; i++) {
        cpuPercents.append(0);
    }

    connect(&aniTimer, SIGNAL(timeout()), this, SLOT(render()));
//    aniTimer.start(30);

    connect(&timer,SIGNAL(timeout()),this,SLOT(update()));
    update();
    timer.start(2000);


}

MemoryMonitior::~MemoryMonitior()
{
    delete ui;
}

void MemoryMonitior::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setPen(QPen(QColor(0,255,0),4));
    painter.drawEllipse(50,40,100,100);//画圆
    painter.drawEllipse(46,36,108,108);//画圆


    painter.setPen(QPen(QColor(100,0,0),6));
    painter.drawArc(48,38,104,104,0,memoryUsePercent*360/100*16);
    QFont font=painter.font();
    font.setPointSize(20);
    painter.setFont(font);
    painter.drawText(76,100,QString::number(memoryUsePercent,'f',1));
    font.setPointSize(12);
    painter.setFont(font);
    painter.drawText(40,170,"内存:"+currentUse+"G/"+totalMemory+"G");
    if(swapTotal!=0)
        painter.drawText(40,200,"swap:"+QString::number((swapTotal-swapavilabel)/1048576.0f,'f',2)+"G/"+QString::number(swapTotal/1048576.0f,'f',2)+"G");
    else {
        painter.drawText(40,200,"交换内存未启用");
    }

    painter.translate(60, 100);
    painter.scale(1, -1);

    painter.setPen(QPen(QColor("#2CA7F8"), 2));
    painter.drawPath(cpuPath);
}

void MemoryMonitior::update()
{
    QProcess process;
    process.start("cat /proc/meminfo");
    process.waitForFinished();
    QByteArray output = process.readAllStandardOutput();
    QString s= output;
    QStringList list=s.split("\n");
    QRegExp regx(".*(\\d+)\\s");
    regx.indexIn(list[0]);
    int total=regx.cap(1).toInt();
    regx.indexIn(list[2]);
    int available=regx.cap(1).toInt();

    regx.indexIn(list[14]);
    swapTotal=regx.cap(1).toInt();
    regx.indexIn(list[15]);
    swapavilabel=regx.cap(1).toInt();

    currentUse=QString::number((total-available)/1024.0f/1024.0f,'f',2);
    totalMemory=QString::number(total/1024.0f/1024.0f,'f',2);
    memoryUsePercent=(total-available)*100.0f/total;
    updateStatus(memoryUsePercent);
}


void MemoryMonitior::render()
{
    if (animationIndex < animationFrames) {
        animationIndex++;

        repaint();
    } else {
        aniTimer.stop();
    }
}

void MemoryMonitior::updateStatus(double cpuPercent)
{
    cpuPercents.append(cpuPercent);
    if (cpuPercents.size() > pointNumber) {
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
        aniTimer.start(120);
    }

}
