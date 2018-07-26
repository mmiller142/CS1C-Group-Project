#ifndef TEXT_H
#define TEXT_H

#include "Shape.h"
//! name space myShapes.
namespace myShapes {

//! The Text class.
/*!
* Text class, used for displaying text on the Qt Canvas.
*/
class Text : public Shape
{
public:
    //! Text constructor
    /*!
     * \brief Text Constructor
     * \param id
     */
    Text(int id) : Shape(id), textString{""}, alignment{Qt::AlignLeft}, pointSize{10},
        fontFamily{"Arial"}, fontStyle{QFont::StyleNormal}, fontWeight{QFont::Normal}{}


    //! paintEvent method
    /*!
     * \brief Method used to send event to Qt widget for updating paint events.
     * \param event.
     */
    virtual void paintEvent(QPaintEvent* event);

    //!Mutator setting the Text String
    /*!
     * \brief setTextString, sets the string to be display in Qt Widget.
     * \param text
     */
    void setTextString(std::string text);

    //!Mutator setting the text Alignment
    /*!
     * \brief setAlignment, sets Qt::AlignmentFlag.
     * \param Qt::AlignmentFlag alignment
     */
    void setAlignment(Qt::AlignmentFlag alignment);

    //!Mutator setting the text Alignment
    /*!
     * \brief setAlignment, sets alignment string.
     * \param std::string alignment
     */
    void setAlignment(std::string alignment);

    //!Mutator for setPointSize
    /*!
     * \brief setPointSize, sets the size of rasterized points.
     * \param int pointSize
     */
    void setPointSize(int pointSize);

    //!Mutator for setting the Point Size
    /*!
     * \brief setPointSize, sets the size of rasterized points.
     * \param std::string pointSize
     */
    void setPointSize(std::string pointSize);

    //!Mutator for setting the Font family
    /*!
     * \brief setFontFamily, method use to set the Font Family to use for text.
     * \param std::string fontFamily
     */
    void setFontFamily(std::string fontFamily);

    //!Mutator for setting the font style
    /*!
     * \brief setfontStyle, method use to set the Font Style to use for text.
     * \param QFont::Style style
     */
    void setfontStyle(QFont::Style style);

    //!Mutator for setting the font style
    /*!
     * \brief setfontStyle, method use to set the Font Style to use for text
     * \param std::string style)s
     */
    void setfontStyle(std::string style);

    //!Mutator for setting the Font Weight
    /*!
     * \brief setFontWeight, method the sets QFont::Weight.
     * \param QFont::Weight weight
     */
    void setFontWeight(QFont::Weight weight);

    //!Mutator for setting Font Weigth
    /*!
     * \brief setFontWeight, method the sets string::weight
     * \param std::string weight
     */
    void setFontWeight(std::string weight);

    //! Accessor for getting shape data.
    /*!
     * \brief virtual method getShapeData, method used to get shape data from QString List.
     * \param shapeData
     */
    virtual void getShapeData(QStringList& shapeData) const;

    //! Accessor for getting the shape type
    /*!
     * \brief virtual method getShapeType,method used to get the type of shape.
     */
    virtual Shapes getShapeType() const {return text;}

    //! Accessor for getting the Font style as a string
    /*!
     * \brief getFontStyleString, method used to get the font style as a string.
     * \return std::string
     */
    std::string getFontStyleString() const;

    //! Accessor for getting the Font Weight as a string
    /*!
     * \brief getFontWeightString, method used to get the Font Weight as a standard string.
     * \return std::string
     */
    std::string getFontWeightString() const;

    //! Accessor for getting the Alignment String.
    /*!
     * \brief getAlignmentString, method used for gettig the alignment string.
     * \return std::string
     */
    std::string getAlignmentString() const;

private:
    std::string textString;         /*!< Text to display */
    Qt::AlignmentFlag alignment;    /*!< alignment flag */
    int pointSize;                  /*!< the size of the point */
    std::string fontFamily;         /*!< the font family */
    QFont::Style fontStyle;         /*!< the font style to use */
    QFont::Weight fontWeight;       /*!< the fontWeight */

    //! Accessor for getting the font.
    /*!
     * \brief getFont, method used for getting the font.
     * \return QFont
     */
    QFont getFont();
};
}

#endif // TEXT_H
