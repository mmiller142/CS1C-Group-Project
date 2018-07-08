// Polyline.h
// CS-1C Summer 2018
// Team C+++++
// Group Project

#ifndef TEXT_H
#define TEXT_H

#include "Shape.h"

namespace myShapes {

class Text : public Shape
{
public:
    Text(int id) : Shape(id), textString{""}, alignment{Qt::AlignLeft}, pointSize{10},
        fontFamily{"Arial"}, fontStyle{QFont::StyleNormal}, fontWeight{QFont::Normal}{}

    virtual void paintEvent(QPaintEvent* event);
    void setTextString(std::string text);
    void setAlignment(int alignment);
    void setPointSize(int pointSize);
    void setFontFamily(std::string fontFamily);
    void setfontStyle(QFont::Style style);
    void setFontWeight(QFont::Weight weight);

private:
    std::string textString;
    int alignment;
    int pointSize;
    std::string fontFamily;
    QFont::Style fontStyle;
    QFont::Weight fontWeight;

    QFont getFont();
};
}

#endif // TEXT_H

