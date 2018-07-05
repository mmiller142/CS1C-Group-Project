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
    Rectangle(int id) : Shape(id){}
    virtual void paintEvent(QPaintEvent* event, QWidget* canvas);

private:
};
}
#endif //!RECTANGLE_H
