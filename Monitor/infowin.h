#ifndef INFOWIN_H
#define INFOWIN_H

#include <QWidget>
#include <QLabel>
namespace Ui {
class InfoWin;
}

class InfoWin : public QWidget
{
    Q_OBJECT

public:
    explicit InfoWin(QWidget *parent = 0);
    void update();
    ~InfoWin();

private:
    Ui::InfoWin *ui;
    QLabel hostName,version,startTime,totalTime,cpu;
};

#endif // INFOWIN_H
