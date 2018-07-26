// Rectangle.h
// CS-1C Summer 2018
// Team C+++++
// Group Project

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"
namespace myShapes {
class Rectangle : public Shape
{

public:
    Rectangle(int id, bool isSquare = false) : Shape(id), isSquare{isSquare} {}
    virtual void paintEvent(QPaintEvent* event);
    virtual Shapes getShapeType() const {return isSquare ? square : rectangle;}

private:
    bool isSquare;
};
}
#endif //!RECTANGLE_H
