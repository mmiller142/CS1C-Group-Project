// Line.h
// CS-1C Summer 2018
// Team C+++++
// Group Project

#include "Line.h"

using namespace myShapes;

/*******************************************************************************

    Line Class

*********************************************************************************/

void Line::paintEvent(QPaintEvent* /*event*/)
{
    if(nullptr == pPainter)
        return;

    const int size = dims.size();
    if(4 > size)
        return;//not enough ints to define 2 points

    pPainter->setPen(getPen());
    pPainter->setBrush(getBrush());
    QPoint start(dims[0], dims[1]);
    QPoint end(dims[2], dims[3]);
    pPainter->drawLine(start, end);

    //draw the id
    int topX = (start.x() < end.x() ? start.x() : end.x());
    int bottomX = (start.x() > end.x() ? start.x() : end.x());
    int topY = (start.y() > end.y() ? start.y() : end.y());
    QPoint topLeft(topX + penWidth, topY);
    QPoint bottomRight(bottomX, topY + 20);
    QRect rectId(topLeft, bottomRight);
    drawId(rectId);
}
