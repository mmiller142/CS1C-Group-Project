// Polyline.h
// CS-1C Summer 2018
// Team C+++++
// Group Project

#ifndef TEXT_H
#define TEXT_H

#include "Shape.h"

namespace myShapes {

class Text : public Shape
{
public:
    Text(int id) : Shape(id){}
    virtual void paintEvent(QPaintEvent* event, QWidget* canvas);

private:

};
}

#endif // TEXT_H

