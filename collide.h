#ifndef COLLIDE_H
#define COLLIDE_H

#include <QtMath>
#include<QPoint>

inline bool collide(QPoint point1, int radius1, QPoint point2, int radius2)
{
    const int dx = point1.x() - point2.x();
    const int dy = point1.y() - point2.y();
    const int dis = qSqrt(dx * dx + dy * dy);

    if (dis <= radius1 + radius2)
    return true;

    return false;
}

#endif // COLLIDE_H
