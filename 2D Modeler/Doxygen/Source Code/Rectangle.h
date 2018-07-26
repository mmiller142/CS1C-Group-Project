// Rectangle.h
// CS-1C Summer 2018
// Team C+++++
// Group Project

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

//! name spae myShapes.
namespace myShapes {

//! The Rectangle class.
/*!
* A Rectangle class used to represent a rectangle object, derives from Shape.
*/
class Rectangle : public Shape
{

public:

    //! Rectangle constructor
    /*!
     * \brief Rectangle constructor used to represent a rectangle object.
     * \param id
     * \param isSquare
     */
    Rectangle(int id, bool isSquare = false) : Shape(id), isSquare{isSquare} {}

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
    virtual Shapes getShapeType() const {return isSquare ? square : rectangle;}

private:
    bool isSquare; /*!< boolean value, whether this is a square */
};
}
#endif //!RECTANGLE_H
