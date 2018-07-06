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
    void updateDimensions(const vector<int>& dims);
    virtual void paintEvent(QPaintEvent* event, QWidget* canvas) = 0;

    void setPenColor(QColor color);
    void setPenWidth(int width);
    void setPenStyle(Qt::PenStyle penStyle);
    void setPenCapStyle(Qt::PenCapStyle capStyle);
    void setPenJoinStyle(Qt::PenJoinStyle joinStyle);
    void setBrushColor(QColor color);
    void setBrushStyle(Qt::BrushStyle style);
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
