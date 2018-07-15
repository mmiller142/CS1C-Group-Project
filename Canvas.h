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

    explicit Canvas(QWidget *parent = nullptr);
    ~Canvas();
    QSize minimumSizeHint() const;
    QSize sizeHint() const;

protected:
    void paintEvent(QPaintEvent *event) override;

signals:

public slots:
    void addShape();

private:
    myShapes::vector<myShapes::Shape*> shapes;
    void testShapes();
    int getNextId();

};

#endif // CANVAS_H
