// Rectangle.h
// CS-1C Summer 2018
// Team C+++++
// Group Project

#include "Rectangle.h"

using namespace myShapes;

/*******************************************************************************

	Rectangle Class

*********************************************************************************/

void Rectangle::paintEvent(QPaintEvent* /*event*/)
{
    if(nullptr == pPainter)
        return;

    const int size = dims.size();
    if((3 > size && isSquare) || (4 > size && !isSquare))
        return;//not enough ints to define 2 points

    pPainter->setPen(getPen());
    pPainter->setBrush(getBrush());

    //Set bounding box corners
    QPoint topLeft;
    QPoint bottomRight;
    if(isSquare)
    {
        topLeft.setX(dims[0]);
        topLeft.setY(dims[1]);

        bottomRight.setX(dims[0] + dims[2]);
        bottomRight.setY(dims[1] + dims[2]);
    }
    else
    {
        topLeft.setX(dims[0]);
        topLeft.setY(dims[1]);
        bottomRight.setX(dims[0] + dims[2]);
        bottomRight.setY(dims[1] + dims[3]);
    }
    QRect rect(topLeft, bottomRight);

    pPainter->drawRect(rect);

    //draw the id
    topLeft.setY(bottomRight.y() + penWidth);
    bottomRight.setY(topLeft.y() + 20);
    QRect rectId(topLeft, bottomRight);
    drawId(rectId);
}

