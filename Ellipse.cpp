// Ellipse.h
// CS-1C Summer 2018
// Team C+++++
// Group Project

#include "Ellipse.h"

using namespace myShapes;

/*******************************************************************************

	Ellipse Class

*********************************************************************************/

void Ellipse::paintEvent(QPaintEvent* /*event*/)
{
    const int size = dims.size();
    if(4 > size)
        return;//not enough ints to define 2 points

    pPainter->setPen(getPen());
    pPainter->setBrush(getBrush());
    int xCoordTL = dims[0];
    int yCoordTL = dims[1];

    //Set bounding box corners
    QPoint topLeft(xCoordTL, yCoordTL);
    QPoint bottomRight;
    if(isCircle)
    {
        int diameter = dims[2];
        bottomRight.setX(xCoordTL + diameter);
        bottomRight.setY(yCoordTL + diameter);
    }
    else
    {
        int width = dims[2];
        int height = dims[3];
        bottomRight.setX(xCoordTL + width);
        bottomRight.setY(yCoordTL + height);
    }
    QRect rect(topLeft, bottomRight);
    pPainter->drawEllipse(rect);
}
