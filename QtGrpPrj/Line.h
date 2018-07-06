// Line.h
// CS-1C Summer 2018
// Team C+++++
// Group Project

#ifndef LINE_H
#define LINE_H

#include "Shape.h"
namespace myShapes {

class Line : public Shape
{
public:
    Line(int id) : Shape(id){}
    virtual void paintEvent(QPaintEvent* event, QWidget* canvas);

private:

};
}

#endif // LINE_H
