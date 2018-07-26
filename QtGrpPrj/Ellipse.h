// Ellipse.h
// CS-1C Summer 2018
// Team C+++++
// Group Project

#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "Shape.h"
namespace myShapes {

class Ellipse : public Shape //this is an example of inheritance as ellipse is derived from shape
{

public:
    Ellipse(int id, bool isCircle = false) : Shape(id), isCircle{isCircle} {}
    virtual void paintEvent(QPaintEvent* event);
    virtual Shapes getShapeType() const {return isCircle ? circle : ellipse;}

private:
    bool isCircle;
};

}
#endif //!ELLIPSE_H
