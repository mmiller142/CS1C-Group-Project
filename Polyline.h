// Polyline.h
// CS-1C Summer 2018
// Team C+++++
// Group Project

#ifndef POLYLINE_H
#define POLYLINE_H


#include "Shape.h"
namespace myShapes {

class Polyline : public Shape
{
public:
    Polyline(int id) : Shape(id){}
    virtual void paintEvent(QPaintEvent* event);

private:

};
}

#endif // POLYLINE_H
