// Polyline.h
// CS-1C Summer 2018
// Team C+++++
// Group Project

#ifndef POLYGON_H
#define POLYGON_H

#include "Shape.h"

//! name spae myShapes.
namespace myShapes {

//! The Polygon class.
/*!
* A Polygon class  used to represent a Polygon object, derives from Shape.
*/
class Polygon : public Shape
{
public:
    //! Polygon constructor
    /*!
     * \brief polygon constructor used to represent a Polygon object.
     * \param id
     * \param isSquare
     */
    Polygon(int id) : Shape(id){}

    //! Mutator virtual method paintEvent
    /*!
     * \brief This methods sets the QPaint event.
     * \param event
     */
    virtual void paintEvent(QPaintEvent* event);

    //! Accessor method getShapeType
    /*!
     * \brief This methods returns the shape type as a shape object.
     */
    virtual Shapes getShapeType() const {return polygon;}

private:

};
}

#endif // POLYGON_H
