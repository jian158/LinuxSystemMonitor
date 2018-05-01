#ifndef MEMORYMONITIOR_H
#define MEMORYMONITIOR_H

#include <QWidget>
#include <QtCore>
#include <QtGui>
namespace Ui {
class MemoryMonitior;
}

class MemoryMonitior : public QWidget
{
    Q_OBJECT

public:
    explicit MemoryMonitior(QWidget *parent = 0);
    ~MemoryMonitior();
    void paintEvent(QPaintEvent *event);

private:
    void updateStatus(double cpuPercent);

public slots:
    void update();
    void render();
private:
    QTimer timer;
    QTimer aniTimer;
    float  memoryUsePercent=50.0f;
    QString  totalMemory="8.0";
    QString currentUse="4.0";
    float swapTotal=0,swapavilabel=0;
    Ui::MemoryMonitior *ui;

    QList<double> cpuPercents;
    int animationIndex = 0;
    double animationFrames = 20;
    int cpuRenderMaxHeight = 30;
    const int pointNumber=16;
    QPainterPath cpuPath;
};

#endif // MEMORYMONITIOR_H
