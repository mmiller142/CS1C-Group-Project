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
    enum Shape { Line, Polyline, Polygon, Rect, Ellipse, Text };

    explicit Canvas(QWidget *parent = nullptr);
    ~Canvas();
    QSize minimumSizeHint() const;
    QSize sizeHint() const;

protected:
    void paintEvent(QPaintEvent *event) override;

signals:

public slots:

private:
    vector<myShapes::Shape*> shapes;
};

#endif // CANVAS_H
