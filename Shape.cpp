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
    brushColor = QColor("white");
    brushStyle = Qt::SolidPattern;
}


void Shape::updateDimensions(const vector<int>& dims)
{
    this->dims = dims;
}

void Shape::updateDimensions(const std::string dimStr)
{
    std::string subDim = "";
    vector<int> newDims;
    //parse dimStr for integers
    int len = dimStr.length();
    for(int i = 0; i < len; i++)
    {
        char c = dimStr[i];
        if(c < '0' || c > '9')//negative numbers are not allowed
        {
            if(0 < subDim.length())
            {
                newDims.push_back(stoi(subDim));
                subDim.clear();
            }
        }
        else
            subDim += c;

    }
    if(0 < subDim.length())
        newDims.push_back(stoi(subDim));

    dims = newDims;
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
    std::transform(shapeToMake.begin(), shapeToMake.end(), shapeToMake.begin(), tolower);
    int index = 0;
    for(; index < 9; index++)
    {
        if(shapeToMake == SHAPE_NAMES[index])
            break;
    }
    if(9 == index)
        return nullptr;

    return makeShape(id, static_cast<Shapes>(index));
}


Shape* Shape::makeShape(int id, Shapes shapeEnum)
{
    switch (shapeEnum) {
    case line:
       return new Line(id);
    case polyline:
       return new Polyline(id);
    case polygon:
       return new Polygon(id);
    case ellipse:
       return new Ellipse(id);
    case circle:
       return new Ellipse(id, true);
    case rectangle:
       return new Rectangle(id);
    case square:
       return new Rectangle(id, true);
    case text:
       return new Text(id);
    default:
       return nullptr;
    }
}

void Shape::drawId(QRect rect)
{

    QPen tPen = getPen();
    tPen.setColor(QColor("black"));
    pPainter->setPen(tPen);
    pPainter->setFont(QFont(QObject::tr("arial"), 15, QFont::Bold));
    pPainter->drawText(rect, Qt::AlignHCenter, QObject::tr(std::to_string(id).c_str()));

}
