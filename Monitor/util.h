#ifndef UTIL_H
#define UTIL_H
#include <QPainter>
#include <QList>

class Util
{
public:
    Util();
    static QPainterPath generateSmoothCurve(const QList<QPointF> &points);
    static void calculateFirstControlPoints(double *&result, const double *rhs, int n);
    static void calculateControlPoints(const QList<QPointF> &knots, QList<QPointF> *firstControlPoints, QList<QPointF> *secondControlPoints);
    static QString formatBandwidth(unsigned long v);
    static QString formatByteCount(unsigned long v);
    static QString formatUnitSize(double v, const char** orders, int nb_orders);
};

#endif // UTIL_H
