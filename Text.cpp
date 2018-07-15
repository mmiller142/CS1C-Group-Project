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
    int xCoordTL = dims[0];
    int yCoordTL = dims[1];
    QRect rect(xCoordTL, yCoordTL, dims[2], dims[3]);
    pPainter->setFont(getFont());
    pPainter->drawText(rect, alignment, QObject::tr(textString.c_str()));

    //draw the id
    QPoint topLeft(xCoordTL, yCoordTL);
    QPoint bottomRight(rect.bottomRight());
    topLeft.setY(bottomRight.y() + penWidth);
    bottomRight.setY(topLeft.y() + 20);
    QRect rectId(topLeft, bottomRight);
    drawId(rectId);
}

void Text::setTextString(std::string text)
{
    textString = text;
}

void Text::setAlignment(Qt::AlignmentFlag alignment)
{
    this->alignment = alignment;
}

void Text::setAlignment(std::string alignment)
{
    std::transform(alignment.begin(), alignment.end(), alignment.begin(), tolower);
    if(alignment == "alignleft")
        this->alignment = Qt::AlignLeft;
    else if(alignment == "alignright")
        this->alignment = Qt::AlignRight;
    else if(alignment == "aligncenter")
        this->alignment = Qt::AlignCenter;
    else
        this->alignment = Qt::AlignLeft;
}

void Text::setPointSize(int pointSize)
{
    this->pointSize = pointSize;
}

void Text::setPointSize(std::string pointSize)
{
    this->pointSize = stoi(pointSize);
}

void Text::setFontFamily(std::string fontFamily)
{
    this->fontFamily = fontFamily;
}

void Text::setfontStyle(QFont::Style style)
{
    fontStyle = style;
}

void Text::setfontStyle(std::string style)
{
    if("StyleNormal" == style)
        fontStyle = QFont::StyleNormal;
    else if("StyleItalic" == style)
        fontStyle = QFont::StyleItalic;
    else if("StyleOblique" == style)
        fontStyle = QFont::StyleOblique;
    else
        fontStyle = QFont::StyleNormal;
}

void Text::setFontWeight(QFont::Weight weight)
{
    fontWeight = weight;
}

void Text::setFontWeight(std::string weight)
{
    if("Normal" == weight)
        fontWeight = QFont::Normal;
    else if("Thin" == weight)
        fontWeight = QFont::Thin;
    else if("ExtraLight" == weight)
        fontWeight = QFont::ExtraLight;
    else if("Light" == weight)
        fontWeight = QFont::Light;
    else if("Medium" == weight)
        fontWeight = QFont::Medium;
    else if("DemiBold" == weight)
        fontWeight = QFont::DemiBold;
    else if("Bold" == weight)
        fontWeight = QFont::Bold;
    else if("ExtraBold" == weight)
        fontWeight = QFont::ExtraBold;
    else if("Black" == weight)
        fontWeight = QFont::Black;
    else
        fontWeight = QFont::Normal;
}

QFont Text::getFont()
{
    return QFont(QObject::tr(fontFamily.c_str()), pointSize, fontWeight, fontStyle);
}
