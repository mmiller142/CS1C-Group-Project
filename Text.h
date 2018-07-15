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
    void setAlignment(Qt::AlignmentFlag alignment);
    void setAlignment(std::string alignment);
    void setPointSize(int pointSize);
    void setPointSize(std::string pointSize);
    void setFontFamily(std::string fontFamily);
    void setfontStyle(QFont::Style style);
    void setfontStyle(std::string style);
    void setFontWeight(QFont::Weight weight);
    void setFontWeight(std::string weight);

private:
    std::string textString;
    Qt::AlignmentFlag alignment;
    int pointSize;
    std::string fontFamily;
    QFont::Style fontStyle;
    QFont::Weight fontWeight;

    QFont getFont();
};
}

#endif // TEXT_H

