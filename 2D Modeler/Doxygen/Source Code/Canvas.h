#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include <QBrush>
#include <QPen>
#include <QPixmap>
#include "vector.h"
#include "Shape.h"

class Canvas : public QWidget
{
    Q_OBJECT

public:

	//!Canvas constructor
	/*!
	 * \brief Canvas
	 * \param QWidget Object
	 */
    explicit Canvas(QWidget *parent = nullptr);

    //!Canvas destructor
    ~Canvas();

    //!Object Minimum Size
    QSize minimumSizeHint() const;

    //!Object Size
    QSize sizeHint() const;

    //!The Report Dialog
	/*!
	 * \brief report
	 */
    void report();

    //!Deleting shape from the Canvas
	/*!
	 * \brief deleteShape
	 */
    void deleteShape();

protected:

    //!Handler to paint the shape to the supplied QPainted object
	/*!
	 * \brief paintEvent
	 * \param event QPaintEvent* not used
	 */
    void paintEvent(QPaintEvent *event) override;

signals:

public slots:

	//!Repainting the Canvas with new shape
	/*!
	 * \brief addShape
	 */
    void addShape();

private:

    //!Example of Composition, Canvas includes a vector object.
    myShapes::vector<myShapes::Shape*> shapes;

    //!Performs a test draw of the shapes defined in the shape.txt files
	/*!
	 * \brief testShapes
	 */
    void testShapes();

    //!Retrieve the next shape ID
	/*!
	 * \brief getNextId
	 * \return next shape ID
	 */
    int getNextId();

};

#endif //!CANVAS_H
