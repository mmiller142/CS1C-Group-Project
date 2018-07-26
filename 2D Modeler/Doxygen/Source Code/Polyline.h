// Polyline.h
// CS-1C Summer 2018
// Team C+++++
// Group Project

#ifndef POLYLINE_H
#define POLYLINE_H

#include "Shape.h"

//! name spae myShapes.
namespace myShapes {

//! The Rectangle class.
/*!
* A Rectangle class used to represent a polyline object, derives from Shape.
*/
class Polyline : public Shape
{
public:
    //! Polyline constructor
    /*!
     * \brief Polyline constructor used to represent a polyline object.
     * \param id
     */
    Polyline(int id) : Shape(id){}

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
    virtual Shapes getShapeType() const {return polyline;}

private:

};
}

#endif // POLYLINE_H
