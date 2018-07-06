// Text.cpp
// CS-1C Summer 2018
// Team C+++++
// Group Project

#include "Text.h"

using namespace myShapes;

/*******************************************************************************

    Text Class

*********************************************************************************/

void Text::paintEvent(QPaintEvent* /*event*/, QWidget* canvas)
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
