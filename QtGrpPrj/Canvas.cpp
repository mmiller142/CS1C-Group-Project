#include "Canvas.h"
#include "Rectangle.h"
#include "Ellipse.h"
#include "Line.h"
#include "Polygon.h"
#include "Polyline.h"

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
    testRect->setPenColor(QColor("black"));
    testRect->setPenWidth(10);
    testRect->updateDimensions(dims);
    shapes.push_back(testRect);

    myShapes::Ellipse* testEll = new myShapes::Ellipse{2};
    dims[0] = 200;
    dims[1] = 200;
    dims[2] = 600;
    dims[3] = 400;

    testEll->updateDimensions(dims);
    testEll->setBrushColor(QColor("red"));
    testEll->setBrushStyle(Qt::SolidPattern);
    testEll->setPenColor(QColor("black"));
    testEll->setPenWidth(20);
    shapes.push_back(testEll);

    myShapes::Line* testLine = new myShapes::Line{3};
    testLine->updateDimensions(dims);
    testLine->setPenStyle(Qt::DashLine);
    testLine->setPenColor(QColor("blue"));
    testLine->setPenWidth(5);
    shapes.push_back(testLine);

    myShapes::Polyline* testPolyline = new myShapes::Polyline{4};
    dims[0] = 600;
    dims[1] = 400;
    dims[2] = 800;
    dims[3] = 200;
    dims.push_back(1000);
    dims.push_back(500);
    testPolyline->updateDimensions(dims);
    testPolyline->setPenStyle(Qt::DashDotLine);
    testPolyline->setPenColor(QColor("green"));
    testPolyline->setPenWidth(5);
    shapes.push_back(testPolyline);

    myShapes::Polygon* testPolygon = new myShapes::Polygon{4};
    dims[0] = 300;
    dims[1] = 100;
    dims[2] = 400;
    dims[3] = 100;
    dims[4] = 500;
    dims[5] = 200;
    testPolygon->updateDimensions(dims);
    testPolygon->setBrushColor(QColor("purple"));
    testPolygon->setBrushStyle(Qt::Dense5Pattern);
    testPolygon->setPenStyle(Qt::DashDotDotLine);
    testPolygon->setPenColor(QColor("orange"));
    testPolygon->setPenWidth(8);
    shapes.push_back(testPolygon);

    update();
}

Canvas::~Canvas()
{
    for(int i = 0; i < shapes.size(); i++)
        delete shapes[i];
}

void Canvas::paintEvent(QPaintEvent * event)
{
    QPainter painter(this);
    painter.setClipping(true);
    for(int i = 0; i < shapes.size(); i++)
    {
        myShapes::Shape* pShape = shapes[i];
        pShape->pPainter = &painter;
        pShape->paintEvent(event, this);
    }
}

QSize Canvas::minimumSizeHint() const
{
    return QSize(1000, 500);
}

QSize Canvas::sizeHint() const
{
    return QSize(1000, 500);
}
