// Rectangle.h
// CS-1C Summer 2018
// Team C+++++
// Group Project

#include "Rectangle.h"

using namespace myShapes;

/*******************************************************************************

	Rectangle Class

*********************************************************************************/

void Rectangle::paintEvent(QPaintEvent* /*event*/, QWidget* canvas)
{
    const int size = dims.size();
    if(4 > size)
        return;//not enough ints to define 2 points

    pPainter->setPen(getPen());
    pPainter->setBrush(getBrush());
    QPoint topLeft(dims[0], dims[1]);
    QPoint bottomRight(dims[2], dims[3]);
    QRect rect(topLeft, bottomRight);

    pPainter->drawRect(rect);
}

