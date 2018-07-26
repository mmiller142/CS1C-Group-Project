// Shape.h
// CS-1C Summer 2018
// Team C+++++
// Group Project

#ifndef SHAPE_H
#define SHAPE_H

#include "vector.h"
#include <qpainter.h>
#include <QBrush>
#include <QPen>
#include <QPixmap>
#include <QWidget>

namespace myShapes {

//!Shape name strings
/*!
  Strings for each defined shape.
 */
const std::string SHAPE_NAMES[9] = {"none", "line", "polyline", "polygon", "rectangle", "square", "ellipse", "circle", "text" };

class Shape
{

public:
    //!Enumerated shapes
    enum Shapes {none, line, polyline, polygon, rectangle, square, ellipse, circle, text };

    //!Shape constructor
    /*!
     * \brief Shape
     * \param id
     */
    Shape(int id);

    //!Shape destructor (virtual!)
    virtual ~Shape() {}

    //!Mutator for shape dimensions
    /*!
     * \brief updateDimensions
     * \param dims vector of integers
     */
    virtual void updateDimensions(const vector<int>& dims);

    //!Mutator for shape dimensions,  this is an exmaple of a virtual function
    /*!
     * \brief updateDimensions
     * \param dims std::string that can be parsed to int
     */
    virtual void updateDimensions(const std::string dimStr);

    //!Handler to paint the shape to the supplied QPainted object
    /*!
     * \brief paintEvent
     * \param event QPaintEvent* not used
     */
    virtual void paintEvent(QPaintEvent* event) = 0;

    //!Pen color mutator
    /*!
     * \brief setPenColor
     * \param color std::string
     */
    void setPenColor(std::string color); //Takes a color name (e.g. black or blue, etc.)

    //!Pen width mutator
    /*!
     * \brief setPenWidth
     * \param width integer
     */
    void setPenWidth(int width);

    //!Pen width mutator
    /*!
     * \brief setPenWidth
     * \param width std::string
     */
    void setPenWidth(std::string width); //converts string value to integer

    //!Pen style mutator
    /*!
     * \brief setPenStyle
     * \param penStyle Qt::PenStyle
     */
    void setPenStyle(Qt::PenStyle penStyle);

    //!Pen style mutator
    /*!
     * \brief setPenStyle
     * \param penStyle std::string
     */
    void setPenStyle(std::string penStyle); //converts string to penstyle enum

    //!Pen cap style mutator
    /*!
     * \brief setPenCapStyle
     * \param capStyle Qt::PenCapStyle
     */
    void setPenCapStyle(Qt::PenCapStyle capStyle);
    //!Pen cap style mutator

    /*!
     * \brief setPenCapStyle
     * \param capStyle std::string
     */
    void setPenCapStyle(std::string capStyle); //converts string to capstyle enum

    //!Pen join style mutator
    /*!
     * \brief setPenJoinStyle
     * \param joinStyle Qt::PenJoinStyle
     */
    void setPenJoinStyle(Qt::PenJoinStyle joinStyle);

    //!Pen join style mutator
    /*!
     * \brief setPenJoinStyle
     * \param joinStyle std::string
     */
    void setPenJoinStyle(std::string joinStyle); //converts string to joinstyle enum

    //!Brush color mutator
    /*!
     * \brief setBrushColor
     * \param color std::string
     */
    void setBrushColor(std::string color); //Takes a color name (e.g. black or blue, etc.)

    //!Brush style mutator
    /*!
     * \brief setBrushColor
     * \param color Qt::BrushStyle
     */
    void setBrushStyle(Qt::BrushStyle style);

    //!Brush style mutator
    /*!
     * \brief setBrushColor
     * \param color std::string
     */
    void setBrushStyle(std::string style); //converts string to brushstyle enum

    //!New shape creator from string input
    /*!
     * \brief makeShape
     * \param id            std::string
     * \param shapeToMake   std::string
     * \return
     */
    static Shape* makeShape(std::string id, std::string shapeToMake);

    //!New shape creator from int and enum input
    /*!
     * \brief makeShape
     * \param id            int
     * \param shapeToMake   Shapes enum
     * \return
     */
    static Shape* makeShape(int id, Shapes shapeEnum);

    //!Id accessor
    /*!
     * \brief getId
     * \return shape id (int by value)
     */
    int getId() const {return id;}
    QPainter* pPainter;

    //!Shape data
    /*!
     * \brief getShapeData
     * \param shapeData QStringList reference, filled with data on return;
     */
    virtual void getShapeData(QStringList& shapeData) const;

    //!Shape type accessor
    /*!
     * \brief getShapeType
     * \return Shapes enum
     */
    virtual Shapes getShapeType() const {return none;}

    //!Shape name accessor
    /*!
     * \brief getShapeTypeString
     * \return Shape name std::string
     */
    virtual std::string getShapeTypeString() const {return SHAPE_NAMES[getShapeType()];}

    //!Shape name accessor
    /*!
     * \brief getPenStyleString
     * \return pen style std::string
     */
    std::string getPenStyleString() const;

    //!Shape name accessor
    /*!
     * \brief getPenCapString
     * \return pen cap style std::string
     */
    std::string getPenCapString() const;

    //!Shape name accessor
    /*!
     * \brief getPenJoinString
     * \return pen join style std::string
     */
    std::string getPenJoinString() const;

    //!Shape name accessor
    /*!
     * \brief getBrushStyleString
     * \return brush style std::string
     */
    std::string getBrushStyleString() const;

private:

    //!Pen for linework
    /*!
     * \brief pen for drawing linear objects and outlines
     */
    QPen pen;
    Qt::PenStyle penStyle;
    Qt::PenCapStyle penCapStyle;
    Qt::PenJoinStyle penJoinStyle;

    //!Brush for fills
    /*!
     * \brief brush for fills inside closed objects
     */
    QBrush brush;
    std::string brushColor;
    Qt::BrushStyle brushStyle;

protected:
    //!Shape id
    /*!
     * \brief unique id assigned to each shape
     */
    int id;

    std::string penColor;

    //!dimension vector
    /*!
     * \brief dims, vector for storing the shapes dimension integers
     */
    vector<int> dims; //shape dimensions

    //!Retreive the pen object
    /*!
     * \brief getPen
     * \return QPen object with current pen settings applied
     */
    const QPen& getPen();

    //!Retreive the brush object
    /*!
     * \brief getBrush
     * \return QBrush object with current brush settings applied
     */
    const QBrush& getBrush();
    void drawId(QRect rect);
    int penWidth;

};


}

#endif //!SHAPE_H
