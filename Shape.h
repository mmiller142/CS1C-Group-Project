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

const std::string SHAPE_NAMES[9] = {"none", "line", "polyline", "polygon", "rectangle", "square", "ellipse", "circle", "text" };

class Shape
{

public:
    enum Shapes {none, line, polyline, polygon, rectangle, square, ellipse, circle, text };
    Shape(int id);
    virtual ~Shape() {}
    virtual void updateDimensions(const vector<int>& dims);
    virtual void updateDimensions(const std::string dimStr);
    virtual void paintEvent(QPaintEvent* event) = 0;

    //void setPenColor(QColor color);
    void setPenColor(std::string color); //Takes a color name (e.g. black or blue, etc.)
    void setPenWidth(int width);
    void setPenWidth(std::string width); //converts string value to integer
    void setPenStyle(Qt::PenStyle penStyle);
    void setPenStyle(std::string penStyle); //converts string to penstyle enum
    void setPenCapStyle(Qt::PenCapStyle capStyle);
    void setPenCapStyle(std::string capStyle); //converts string to capstyle enum
    void setPenJoinStyle(Qt::PenJoinStyle joinStyle);
    void setPenJoinStyle(std::string joinStyle); //converts string to joinstyle enum
    //void setBrushColor(QColor color);
    void setBrushColor(std::string color); //Takes a color name (e.g. black or blue, etc.)
    void setBrushStyle(Qt::BrushStyle style);
    void setBrushStyle(std::string style); //converts string to brushstyle enum

    static Shape* makeShape(std::string id, std::string shapeToMake);
    static Shape* makeShape(int id, Shapes shapeEnum);
    int getId() const {return id;}
    QPainter* pPainter;

    virtual void getShapeData(QStringList& shapeData) const;
    virtual Shapes getShapeType() const {return none;}
    virtual std::string getShapeTypeString() const {return SHAPE_NAMES[getShapeType()];}

    std::string getPenStyleString() const;
    std::string getPenCapString() const;
    std::string getPenJoinString() const;
    std::string getBrushStyleString() const;

private:

    QPen pen;
    Qt::PenStyle penStyle;
    Qt::PenCapStyle penCapStyle;
    Qt::PenJoinStyle penJoinStyle;

    QBrush brush;
    std::string brushColor;
    Qt::BrushStyle brushStyle;

protected:
    int id;
    std::string penColor;
    vector<int> dims; //shape dimensions

    const QPen& getPen();
    const QBrush& getBrush();
    void drawId(QRect rect);
    int penWidth;

};


}

#endif //!SHAPE_H
