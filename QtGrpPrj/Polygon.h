// Polyline.h
// CS-1C Summer 2018
// Team C+++++
// Group Project

#ifndef POLYGON_H
#define POLYGON_H

#include "Shape.h"

namespace myShapes {

class Polygon : public Shape
{
public:
    Polygon(int id) : Shape(id){}
    virtual void paintEvent(QPaintEvent* event, QWidget* canvas);

private:

};
}

#endif // POLYGON_H

