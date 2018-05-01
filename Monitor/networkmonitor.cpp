#include "networkmonitor.h"
#include "ui_networkmonitor.h"
#include "util.h"
#include <QProcess>
#include <QStringList>
NetWorkMonitor::NetWorkMonitor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NetWorkMonitor)
{
    ui->setupUi(this);
    downloadSpeeds = new QList<double>();
    for (int i = 0; i < pointsNumber; i++) {
        downloadSpeeds->append(0);
    }

    uploadSpeeds = new QList<double>();
    for (int i = 0; i < pointsNumber; i++) {
        uploadSpeeds->append(0);
    }
    update();
    connect(&timer,SIGNAL(timeout()),this,SLOT(update()));
    timer.start(1000);
}

NetWorkMonitor::~NetWorkMonitor()
{
    delete ui;
}

void NetWorkMonitor::updateStatus(long tRecvBytes, long tSentBytes, float tRecvKbs, float tSentKbs)
{
    totalRecvBytes = tRecvBytes;
    totalSentBytes = tSentBytes;
    totalRecvKbs = tRecvKbs;
    totalSentKbs = tSentKbs;

    // Init download path.
    downloadSpeeds->append(totalRecvKbs);

    if (downloadSpeeds->size() > pointsNumber) {
        downloadSpeeds->pop_front();
    }

    QList<QPointF> downloadPoints;

    double downloadMaxHeight = 0;
    for (int i = 0; i < downloadSpeeds->size(); i++) {
        if (downloadSpeeds->at(i) > downloadMaxHeight) {
            downloadMaxHeight = downloadSpeeds->at(i);
        }
    }

    for (int i = 0; i < downloadSpeeds->size(); i++) {
        if (downloadMaxHeight < downloadRenderMaxHeight) {
            downloadPoints.append(QPointF(i * 5, downloadSpeeds->at(i)));
        } else {
            downloadPoints.append(QPointF(i * 5, downloadSpeeds->at(i) * downloadRenderMaxHeight / downloadMaxHeight));
        }
    }

    downloadPath = Util::generateSmoothCurve(downloadPoints);

    // Init upload path.
    uploadSpeeds->append(totalSentKbs);

    if (uploadSpeeds->size() > pointsNumber) {
        uploadSpeeds->pop_front();
    }

    QList<QPointF> uploadPoints;

    double uploadMaxHeight = 0;
    for (int i = 0; i < uploadSpeeds->size(); i++) {
        if (uploadSpeeds->at(i) > uploadMaxHeight) {
            uploadMaxHeight = uploadSpeeds->at(i);
        }
    }

    for (int i = 0; i < uploadSpeeds->size(); i++) {
        if (uploadMaxHeight < uploadRenderMaxHeight) {
            uploadPoints.append(QPointF(i * 5, uploadSpeeds->at(i)));
        } else {
            uploadPoints.append(QPointF(i * 5, uploadSpeeds->at(i) * uploadRenderMaxHeight / uploadMaxHeight));
        }
    }

    uploadPath = Util::generateSmoothCurve(uploadPoints);

    repaint();
}

void NetWorkMonitor::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);


    int penSize = 1;
    int gridX = 20;
    int gridY = 20;
    int gridWidth = 180;
    int gridHeight = 80;

    QPainterPath framePath;
    framePath.addRect(QRect(gridX, gridY, gridWidth, gridHeight));
    painter.drawPath(framePath);


    QPen gridPen;
    QVector<qreal> dashes;
    qreal space = 3;
    dashes << 5 << space;
    painter.setOpacity(0.5);
    gridPen.setColor(QColor("#111122"));
    gridPen.setWidth(0.5);
    gridPen.setDashPattern(dashes);
    painter.setPen(gridPen);

    int gridLineX = gridX;
    while (gridLineX < gridX + gridWidth - 20) {
        gridLineX += 20;
        painter.drawLine(gridLineX, gridY + 1, gridLineX, gridY + gridHeight - 1);
    }
    int gridLineY = gridY;
    while (gridLineY < gridY + gridHeight - 20) {
        gridLineY += 20;
        painter.drawLine(gridX + 1, gridLineY, gridX + gridWidth - 1, gridLineY);
    }

    //↑000.00 B\n↓000
    QFont font=painter.font();
    font.setPointSize(16);
    painter.setFont(font);
    painter.setPen(QPen(QColor("#ff00ff"), 4));
    painter.drawText(20,128,"↓"+Util::formatByteCount(totalRecvKbs));

    painter.setPen(QPen(QColor("#00ffff"), 4));
    painter.drawText(110,128," ↑"+Util::formatByteCount(totalSentKbs));


    painter.setOpacity(1);


    painter.translate(30, 80);
    painter.scale(1, -1);

    qreal devicePixelRatio = qApp->devicePixelRatio();
    qreal networkCurveWidth = 1.6;
    if (devicePixelRatio > 1) {
        networkCurveWidth = 2;
    }


    painter.setPen(QPen(QColor("#ff00ff"), 2));
    painter.setBrush(QBrush());
    painter.drawPath(downloadPath);



    painter.translate(0, 10);
    painter.scale(1, -1);

    painter.setPen(QPen(QColor("#00ffff"), 2));
    painter.setBrush(QBrush());
    painter.drawPath(uploadPath);



}

#include <QDebug>

void NetWorkMonitor::update()
{
    QProcess process;
    process.start("cat /proc/net/dev");
    process.waitForFinished();
    QByteArray output = process.readAllStandardOutput();
    QString s= output;
    QStringList lines=s.split("\n");
    long long os_sum=0,is_sum=0;
    int i=2;
    while (i<lines.length()){
      QStringList line=lines[i++].split(QRegExp("\\s{1,}"), QString::SkipEmptyParts);
      if(line.length()<9)
          break;
      os_sum+=line[9].toLongLong();
      is_sum+=line[1].toLongLong();
    }
    if(preis_sum==0)
        updateStatus(is_sum,os_sum,0,0);
    else {
        updateStatus(is_sum,os_sum,(is_sum-preis_sum),(os_sum-preos_sum));
    }
    preis_sum=is_sum;
    preos_sum=os_sum;
}
