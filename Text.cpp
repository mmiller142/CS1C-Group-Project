// Text.cpp
// CS-1C Summer 2018
// Team C+++++
// Group Project

#include "Text.h"
#include <QPainter>

using namespace myShapes;

/*******************************************************************************

    Text Class

*********************************************************************************/

void Text::paintEvent(QPaintEvent* /*event*/)
{
    const int size = dims.size();
    if(4 > size)
        return;//not enough ints to define 2 points

    pPainter->setPen(getPen());
    pPainter->setBrush(getBrush());
    QRect rect(dims[0], dims[1], dims[2], dims[3]);
    pPainter->setFont(getFont());
    pPainter->drawText(rect, alignment, QObject::tr(textString.c_str()));
}

void Text::setTextString(std::string text)
{
    textString = text;
}

void Text::setAlignment(int alignment)
{
    this->alignment = alignment;
}

void Text::setPointSize(int pointSize)
{
    this->pointSize = pointSize;
}

void Text::setFontFamily(std::string fontFamily)
{
    this->fontFamily = fontFamily;
}

void Text::setfontStyle(QFont::Style style)
{
    fontStyle = style;
}

void Text::setFontWeight(QFont::Weight weight)
{
    fontWeight = weight;
}

QFont Text::getFont()
{
    return QFont(QObject::tr(fontFamily.c_str()), pointSize, fontWeight, fontStyle);
}
