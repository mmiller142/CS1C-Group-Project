// Ellipse.h
// CS-1C Summer 2018
// Team C+++++
// Group Project

#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "Shape.h"
namespace myShapes {

class Ellipse : public Shape //!Example of inheritance as Ellipse is derived from Shape
{

public:
	//!Ellipse constructor
	/*!
	 * \brief Ellipse
	 * \param id
	 * \param isCircle
	 */
    Ellipse(int id, bool isCircle = false) : Shape(id), isCircle{isCircle} {}

    //!Handler to paint the shape to the supplied QPainted object
	/*!
	 * \brief paintEvent
	 * \param event QPaintEvent* not used
	 */
    virtual void paintEvent(QPaintEvent* event);

    //!Shape type accessor
	/*!
	 * \brief getShapeType
	 * \return circle or ellipse enum
	 */
    virtual Shapes getShapeType() const {return isCircle ? circle : ellipse;}

private:
    //!Bool that determines if the shape is a circle or not
    bool isCircle;
};

}

#endif //!ELLIPSE_H
