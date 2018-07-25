// Polyline.h
// CS-1C Summer 2018
// Team C+++++
// Group Project

#include "Polyline.h"

using namespace myShapes;

/*******************************************************************************

    Polyline Class

*********************************************************************************/

void Polyline::paintEvent(QPaintEvent* /*event*/)
{
    if(nullptr == pPainter)
        return;

    const int size = dims.size();
    if(4 > size)
        return;//not enough ints to define a minimum of 2 points

    pPainter->setPen(getPen());
    pPainter->setBrush(getBrush());

    QPoint left(1000,500);
    QPoint right(0,0);


    QPoint* points = new QPoint[size / 2]{};
    for(int i = 0; i < size / 2; i++)
    {
        QPoint pt(dims[i * 2], dims[(i * 2) + 1]);
        points[i] = pt;

        //adjust id rect, when complete it will bound the shape
        if(pt.x() < left.x())
            left.setX(pt.x());
        if(pt.y() < left.y())
            left.setY(pt.y());
        if(pt.x() > right.x())
            right.setX(pt.x());
        if(pt.y() > right.y())
            right.setY(pt.y());
    }

    pPainter->drawPolyline(points, size / 2);

    //draw the id
    left.setY(right.y() + penWidth);
    right.setY(left.y() + 20);
    QRect rectId(left, right);
    drawId(rectId);
}
