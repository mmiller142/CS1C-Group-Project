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
    QPainter painter(canvas);

    setPenColor(QColor("black"));
    painter.setPen(getPen());
    painter.setBrush(getBrush());
    QPoint topLeft(dims[0], dims[1]);
    QPoint bottomRight(dims[2], dims[3]);
    QRect rect(topLeft, bottomRight);

    painter.drawRect(rect);
}

