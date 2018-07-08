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
    const int size = dims.size();
    if(4 > size)
        return;//not enough ints to define a minimum of 2 points

    pPainter->setPen(getPen());
    pPainter->setBrush(getBrush());

    QPoint* points = new QPoint[size / 2]{};
    for(int i = 0; i < size / 2; i++)
        points[i] = QPoint(dims[i * 2], dims[(i * 2) + 1]);

    pPainter->drawPolyline(points, size / 2);
}
