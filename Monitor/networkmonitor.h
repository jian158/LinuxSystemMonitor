#ifndef NETWORKMONITOR_H
#define NETWORKMONITOR_H

#include <QWidget>
#include <QTimer>
namespace Ui {
class NetWorkMonitor;
}

class NetWorkMonitor : public QWidget
{
    Q_OBJECT

public:
    explicit NetWorkMonitor(QWidget *parent = 0);
    ~NetWorkMonitor();
    void paintEvent(QPaintEvent *event);
    void updateStatus(long tRecvBytes, long tSentBytes, float tRecvKbs, float tSentKbs);
public slots:
    void update();

private:
    QTimer timer;
    Ui::NetWorkMonitor *ui;
    int uploadRenderMaxHeight = 10;
    int downloadRenderMaxHeight = 50;
    int pointsNumber = 34;
    QList<double> *downloadSpeeds;
    QList<double> *uploadSpeeds;
    QPainterPath downloadPath;
    QPainterPath uploadPath;

    double totalRecvKbs = 0;
    double totalSentKbs = 0;
    long long totalRecvBytes = 0;
    long long totalSentBytes = 0;

    long long preos_sum=0,preis_sum=0;

    int downloadWaveformsRenderOffsetX = 4;
    int downloadWaveformsRenderOffsetY = 156;
    int gridPaddingRight = 21;
    int gridPaddingTop = 10;

    int uploadWaveformsRenderOffsetY = -5;
};

#endif // NETWORKMONITOR_H
