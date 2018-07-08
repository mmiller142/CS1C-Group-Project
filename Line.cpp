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
    const int size = dims.size();
    if(4 > size)
        return;//not enough ints to define 2 points

    pPainter->setPen(getPen());
    pPainter->setBrush(getBrush());
    QPoint start(dims[0], dims[1]);
    QPoint end(dims[2], dims[3]);
    pPainter->drawLine(start, end);
}
