#include "Canvas.h"
#include "Rectangle.h"
#include "Ellipse.h"
#include "Line.h"
#include "Polygon.h"
#include "Polyline.h"
#include "Text.h"
#include "formaddshape.h"
#include "parser.h"

using namespace myShapes;

Canvas::Canvas(QWidget *parent) : QWidget(parent)
{
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
    //testShapes();
    parser(&shapes);
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
        pShape->paintEvent(event);
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

void Canvas::addShape()
{
    int newId = getNextId();
    myShapes::FormAddShape* pFormAddShape = new myShapes::FormAddShape{this, newId};
    pFormAddShape->exec();
    int result = pFormAddShape->result();
    if(QDialog::Accepted == result)
    {
        shapes.push_back(pFormAddShape->pShape);
    }
    else
        delete pFormAddShape->pShape;

    delete pFormAddShape;

    update();//repaint the canvas
}

//Performs a test draw of the shapes defined in the shape.txt files
void Canvas::testShapes()
{
    std::string penColor = "blue";
    std::string lineStyle = "DashDotDotLine";
    std::string capStyle = "RoundCap";
    std::string joinStyle = "RoundJoin";
    std::string brushColor = "red";
    std::string brushStyle = "VerPattern";

    //test shapes
    myShapes::Rectangle* testRect = dynamic_cast<myShapes::Rectangle*>(myShapes::Shape::makeShape("4", "Rectangle"));
    //set the dimensions (top x, left y, width, height of rectangle)
    vector<int> dims;
    dims.push_back(20);
    dims.push_back(200);
    dims.push_back(170);
    dims.push_back(100);
    penColor = "blue";
    lineStyle = "DashLine";
    capStyle = "RoundCap";
    joinStyle = "RoundJoin";
    brushColor = "red";
    brushStyle = "VerPattern";
    testRect->setPenColor(penColor);
    testRect->setPenWidth(0);
    testRect->setPenStyle(lineStyle);
    testRect->setPenCapStyle(capStyle);
    testRect->setPenJoinStyle(joinStyle);
    testRect->setBrushColor(brushColor);
    testRect->setBrushStyle(brushStyle);
    testRect->updateDimensions(dims);
    shapes.push_back(testRect);

    myShapes::Rectangle* testSquare = dynamic_cast<myShapes::Rectangle*>(myShapes::Shape::makeShape("5", "Square"));
    //set the dimensions (top x, left y, side)
    dims[0] = 250;
    dims[1] = 150;
    dims[2] = 200;
    penColor = "red";
    lineStyle = "SolidLine";
    capStyle = "RoundCap";
    joinStyle = "RoundJoin";
    brushColor = "blue";
    brushStyle = "HorPattern";
    testSquare->setPenColor(penColor);
    testSquare->setPenWidth(0);
    testSquare->setPenStyle(lineStyle);
    testSquare->setPenCapStyle(capStyle);
    testSquare->setPenJoinStyle(joinStyle);
    testSquare->setBrushColor(brushColor);
    testSquare->setBrushStyle(brushStyle);
    testSquare->updateDimensions(dims);
    shapes.push_back(testSquare);

    myShapes::Ellipse* testEll = dynamic_cast<myShapes::Ellipse*>(myShapes::Shape::makeShape("6", "Ellipse"));
    //set the dimensions (top x, left y, width, height of bounding rectangle)
    dims[0] = 520;
    dims[1] = 200;
    dims[2] = 170;
    dims[3] = 100;
    penColor = "black";
    lineStyle = "SolidLine";
    capStyle = "FlatCap";
    joinStyle = "MiterJoin";
    brushColor = "white";
    brushStyle = "NoBrush";
    testEll->setPenColor(penColor);
    testEll->setPenWidth(12);
    testEll->setPenStyle(lineStyle);
    testEll->setPenCapStyle(capStyle);
    testEll->setPenJoinStyle(joinStyle);
    testEll->setBrushColor(brushColor);
    testEll->setBrushStyle(brushStyle);
    testEll->updateDimensions(dims);
    shapes.push_back(testEll);

    myShapes::Ellipse* testCircle = dynamic_cast<myShapes::Ellipse*>(myShapes::Shape::makeShape("7", "Circle"));
    //set the dimensions (top x, left y, side of bounding rectangle)
    dims[0] = 750;
    dims[1] = 150;
    dims[2] = 200;
    penColor = "black";
    lineStyle = "SolidLine";
    capStyle = "FlatCap";
    joinStyle = "MiterJoin";
    brushColor = "magenta";
    brushStyle = "SolidPattern";
    testCircle->setPenColor(penColor);
    testCircle->setPenWidth(12);
    testCircle->setPenStyle(lineStyle);
    testCircle->setPenCapStyle(capStyle);
    testCircle->setPenJoinStyle(joinStyle);
    testCircle->setBrushColor(brushColor);
    testCircle->setBrushStyle(brushStyle);
    testCircle->updateDimensions(dims);
    shapes.push_back(testCircle);

    myShapes::Line* testLine = dynamic_cast<myShapes::Line*>(myShapes::Shape::makeShape("1", "Line"));
    //Start x & y, end x & y
    dims[0] = 20;
    dims[1] = 90;
    dims[2] = 100;
    dims[3] = 20;
    testLine->updateDimensions(dims);
    lineStyle = "DashDotLine";
    testLine->setPenStyle(lineStyle);
    capStyle = "FlatCap";
    testLine->setPenCapStyle(capStyle);
    testLine->setPenColor(QColor("blue"));
    joinStyle = "MiterJoin";
    testLine->setPenJoinStyle(joinStyle);
    testLine->setPenWidth(2);
    shapes.push_back(testLine);

    myShapes::Polyline* testPolyline = dynamic_cast<myShapes::Polyline*>(myShapes::Shape::makeShape("2", "Polyline"));
    //Start x & y, end x & y ... n end x & y
    dims[0] = 460;
    dims[1] = 90;
    dims[2] = 470;
    dims[3] = 20;
    dims.push_back(530);
    dims.push_back(40);
    dims.push_back(540);
    dims.push_back(80);
    testPolyline->updateDimensions(dims);
    lineStyle = "SolidLine";
    testLine->setPenStyle(lineStyle);
    testPolyline->setPenColor(QColor("green"));
    testPolyline->setPenWidth(6);
    joinStyle = "MiterJoin";
    testLine->setPenJoinStyle(joinStyle);
    capStyle = "FlatCap";
    testLine->setPenCapStyle(capStyle);
    shapes.push_back(testPolyline);

    myShapes::Polygon* testPolygon = dynamic_cast<myShapes::Polygon*>(myShapes::Shape::makeShape("3", "Polygon"));
    //Start x & y, end x & y ... n end x & y
    dims[0] = 900;
    dims[1] = 90;
    dims[2] = 910;
    dims[3] = 20;
    dims[4] = 970;
    dims[5] = 40;
    dims[6] = 980;
    dims[7] = 80;
    testPolygon->updateDimensions(dims);
    testPolygon->setBrushColor(std::string("yellow"));
    testPolygon->setBrushStyle(std::string("SolidPattern"));
    testPolygon->setPenStyle(Qt::DashDotDotLine);
    testPolygon->setPenColor(std::string("cyan"));
    testPolygon->setPenWidth(6);
    shapes.push_back(testPolygon);

    myShapes::Text* testText = dynamic_cast<myShapes::Text*>(myShapes::Shape::makeShape("8", "text"));
    //set the dimensions (top x, left y, width, height of bounding rectangle)
    dims[0] = 250;
    dims[2] = 425;
    dims[3] = 500;
    dims[4] = 50;
    testText->updateDimensions(dims);
    testText->setTextString("Class Project 2 - 2D Graphics Modeler");
    testText->setPenColor(std::string("blue"));
    testText->setAlignment(Qt::AlignCenter);
    testText->setPointSize(10);
    testText->setFontFamily(std::string("Purisa"));
    testText->setfontStyle("StyleOblique");
    testText->setFontWeight("ExtraBold");
    shapes.push_back(testText);

}

int Canvas::getNextId()
{
    int nextId = -1;

    int size = shapes.size();
    for(int i = 0; i < size; i ++)
    {
        int shapeId = shapes[i]->getId();
        if(shapeId > nextId)
            nextId = shapeId;
    }

    return nextId;
}
