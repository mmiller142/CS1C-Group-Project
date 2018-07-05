#include "Canvas.h"
#include "Rectangle.h"

Canvas::Canvas(QWidget *parent) : QWidget(parent)
{
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);

    //test shape
    myShapes::Rectangle* testRect = new myShapes::Rectangle{1};
    vector<int> dims;
    dims.push_back(100);
    dims.push_back(100);
    dims.push_back(200);
    dims.push_back(200);
    testRect->updateDimensions(dims);
    shapes.push_back(testRect);
    update();
}

Canvas::~Canvas()
{
    delete shapes[0];
}

void Canvas::paintEvent(QPaintEvent * event)
{
    for(int i = 0; i < shapes.size(); i++)
        shapes[i]->paintEvent(event, this);
}

QSize Canvas::minimumSizeHint() const
{
    return QSize(1000, 500);
}
//! [1]

//! [2]
QSize Canvas::sizeHint() const
{
    return QSize(1000, 500);
}
