// Ellipse.h
// CS-1C Summer 2018
// Team C+++++
// Group Project

#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "Shape.h"
namespace myShapes {

class Ellipse : public Shape
{

public:
    Ellipse(int id) : Shape(id){}
    virtual void paintEvent(QPaintEvent* event, QWidget* canvas);

private:

};

}
#endif //!ELLIPSE_H
