#ifndef CPUMONITOR_H
#define CPUMONITOR_H

#include <QWidget>
#include <QTimer>
namespace Ui {
class CPUMonitor;
}

class CPUMonitor : public QWidget
{
    Q_OBJECT

public:
    explicit CPUMonitor(QWidget *parent = 0);
    ~CPUMonitor();
    void paintEvent(QPaintEvent *event);
private:
    void updateStatus(double cpuPercent);

public slots:
    void update();
    void render();
private:
    QTimer timer;
    QTimer aniTimer;
    QPainterPath cpuPath;
    Ui::CPUMonitor *ui;
    QList<double> cpuPercents;
    int animationIndex = 0;
    double animationFrames = 20;
    int cpuRenderMaxHeight = 45;
    long long preWorkTime=0;
    long long preTotalTime=0;

};

#endif // CPUMONITOR_H
