// Shape.h
// CS-1C Summer 2018
// Team C+++++
// Group Project

#include "Shape.h"
#include <algorithm>
using namespace myShapes;

/*******************************************************************************

	Shape Class

*********************************************************************************/

void Shape::updateDimensions(const vector<int>& dims)
{
    this->dims = dims;
}

void Shape::setPenColor(QColor color)
{
    penColor = color;
}

void Shape::setPenWidth(int width)
{
    penWidth = width;
}

void Shape::setPenStyle(Qt::PenStyle penStyle)
{
    this->penStyle = penStyle;
}

void Shape::setPenCapStyle(Qt::PenCapStyle capStyle)
{
    penCapStyle = capStyle;
}

void Shape::setPenJoinStyle(Qt::PenJoinStyle joinStyle)
{
    penJoinStyle = joinStyle;
}

void  Shape::setBrushColor(QColor color)
{
    brushColor = color;
}

void  Shape::setBrushStyle(Qt::BrushStyle style)
{
    brushStyle = style;
}

const QPen& Shape::getPen()
{
    pen.setColor(penColor);
    pen.setCapStyle(penCapStyle);
    pen.setJoinStyle(penJoinStyle);
    pen.setStyle(penStyle);

    return pen;
}

const QBrush& Shape::getBrush()
{
    brush.setColor(brushColor);
    brush.setStyle(brushStyle);

    return brush;
}



