// Shape.h
// CS-1C Summer 2018
// Team C+++++
// Group Project

#ifndef SHAPE_H
#define SHAPE_H

#include "vector.h"
#include <qpainter.h>
#include <QBrush>
#include <QPen>
#include <QPixmap>
#include <QWidget>

namespace myShapes {
class Shape
{

public:
    Shape(int id);
    virtual ~Shape() {}
    virtual void updateDimensions(const vector<int>& dims);
    virtual void paintEvent(QPaintEvent* event) = 0;

    void setPenColor(QColor color);
    void setPenColor(std::string color); //Takes a color name (e.g. black or blue, etc.)
    void setPenWidth(int width);
    void setPenWidth(std::string width); //converts string value to integer
    void setPenStyle(Qt::PenStyle penStyle);
    void setPenStyle(std::string penStyle); //converts string to penstyle enum
    void setPenCapStyle(Qt::PenCapStyle capStyle);
    void setPenCapStyle(std::string capStyle); //converts string to capstyle enum
    void setPenJoinStyle(Qt::PenJoinStyle joinStyle);
    void setPenJoinStyle(std::string joinStyle); //converts string to joinstyle enum
    void setBrushColor(QColor color);
    void setBrushColor(std::string color); //Takes a color name (e.g. black or blue, etc.)
    void setBrushStyle(Qt::BrushStyle style);
    void setBrushStyle(std::string style); //converts string to brushstyle enum

    static Shape* makeShape(std::string id, std::string shapeToMake);

    QPainter* pPainter;
private:
    int id;

    QPen pen;
    QColor penColor;
    int penWidth;
    Qt::PenStyle penStyle;
    Qt::PenCapStyle penCapStyle;
    Qt::PenJoinStyle penJoinStyle;

    QBrush brush;
    QColor brushColor;
    Qt::BrushStyle brushStyle;

protected:
    vector<int> dims; //shape dimensions

    const QPen& getPen();
    const QBrush& getBrush();

};


}

#endif //!SHAPE_H
