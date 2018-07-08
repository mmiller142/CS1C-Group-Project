// Shape.h
// CS-1C Summer 2018
// Team C+++++
// Group Project

#include "Shape.h"
#include "Ellipse.h"
#include "Line.h"
#include "Polygon.h"
#include "Polyline.h"
#include "Rectangle.h"
#include "Text.h"
#include <algorithm>
using namespace myShapes;

/*******************************************************************************

	Shape Class

*********************************************************************************/
Shape::Shape(int id) : id(id)
{
    penWidth = 5;
    penStyle = Qt::SolidLine;
    penCapStyle = Qt::FlatCap;
    penJoinStyle = Qt::MiterJoin;
    penColor = QColor("black");
}


void Shape::updateDimensions(const vector<int>& dims)
{
    this->dims = dims;
}

void Shape::setPenColor(QColor color)
{
    penColor = color;
}

void Shape::setPenColor(std::string color)
{
    penColor = QColor(color.c_str());
}

void Shape::setPenWidth(int width)
{
    penWidth = width;
}

void Shape::setPenWidth(std::string width)
{
    penWidth = stoi(width);
}

void Shape::setPenStyle(Qt::PenStyle penStyle)
{
    this->penStyle = penStyle;
}

void Shape::setPenStyle(std::string penStyle)
{
    if(penStyle == "DashLine")
        this->penStyle = Qt::DashLine;

    else if(penStyle == "DotLine")
        this->penStyle = Qt::DotLine;

    else if(penStyle == "DashDotLine")
        this->penStyle = Qt::DashDotLine;

    else if(penStyle == "DashDotDotLine")
        this->penStyle = Qt::DashDotDotLine;

    else
        this->penStyle = Qt::SolidLine;

}

void Shape::setPenCapStyle(Qt::PenCapStyle capStyle)
{
    penCapStyle = capStyle;
}

void Shape::setPenCapStyle(std::string capStyle)
{

    if(capStyle == "SquareCap")
        penCapStyle = Qt::SquareCap;

    else if(capStyle == "FlatCap")
        penCapStyle = Qt::FlatCap;

    else
        penCapStyle = Qt::RoundCap;

}

void Shape::setPenJoinStyle(Qt::PenJoinStyle joinStyle)
{
    penJoinStyle = joinStyle;
}

void Shape::setPenJoinStyle(std::string joinStyle)
{

    if(joinStyle == "RoundJoin")
        penJoinStyle = Qt::RoundJoin;

    else if(joinStyle == "BevelJoin")
        penJoinStyle = Qt::BevelJoin;

    else
        penJoinStyle = Qt::MiterJoin;

}

void  Shape::setBrushColor(QColor color)
{
    brushColor = color;
}

void Shape::setBrushColor(std::string color)
{
    brushColor = QColor(color.c_str());
}

void  Shape::setBrushStyle(Qt::BrushStyle style)
{
    brushStyle = style;
}

void Shape::setBrushStyle(std::string style)
{

    if(style == "SolidPattern")
        brushStyle = Qt::SolidPattern;

    else if(style == "HorPattern")
        brushStyle = Qt::HorPattern;

    else if(style == "VerPattern")
        brushStyle = Qt::VerPattern;

    else if(style == "BDiagPattern")
        brushStyle = Qt::BDiagPattern;

    else if(style == "FDiagPattern")
        brushStyle = Qt::FDiagPattern;

    else if(style == "DiagCrossPattern")
        brushStyle = Qt::DiagCrossPattern;

    else if(style == "Dense1Pattern")
        brushStyle = Qt::Dense1Pattern;

    else if(style == "Dense2Pattern")
        brushStyle = Qt::Dense2Pattern;

    else if(style == "Dense3Pattern")
        brushStyle = Qt::Dense3Pattern;

    else if(style == "Dense4Pattern")
        brushStyle = Qt::Dense4Pattern;

    else if(style == "Dense5Pattern")
        brushStyle = Qt::Dense5Pattern;

    else if(style == "Dense6Pattern")
        brushStyle = Qt::Dense6Pattern;

    else if(style == "Dense7Pattern")
        brushStyle = Qt::Dense7Pattern;

    else
        brushStyle = Qt::NoBrush;

}

const QPen& Shape::getPen()
{
    pen.setWidth(penWidth);
    pen.setColor(penColor);
    pen.setCapStyle(penCapStyle);
    pen.setJoinStyle(penJoinStyle);
    pen.setStyle(penStyle);
    //pen = QPen(penColor, penWidth, penStyle, penCapStyle, penJoinStyle);
    return pen;
}

const QBrush& Shape::getBrush()
{
    brush.setColor(brushColor);
    brush.setStyle(brushStyle);

    return brush;
}

Shape* Shape::makeShape(std::string idStr, std::string shapeToMake)
{
    int id = stoi(idStr);
    std::transform(shapeToMake.begin(), shapeToMake.end(), shapeToMake.begin(), toupper);

    Shape* pShape = nullptr;

    if(shapeToMake == "LINE")
        pShape = new Line(id);

    else if(shapeToMake == "POLYLINE")
        pShape = new Polyline(id);

    else if(shapeToMake == "ELLIPSE")
        pShape = new Ellipse(id);

    else if(shapeToMake == "CIRCLE")
        pShape = new Ellipse(id, true);

    else if(shapeToMake == "RECTANGLE")
        pShape = new Rectangle(id);

    else if(shapeToMake == "SQUARE")
        pShape = new Rectangle(id, true);

    else if(shapeToMake == "POLYGON")
        pShape = new Polygon(id);

    else if(shapeToMake == "TEXT")
        pShape = new Text(id);

    return pShape;
}
