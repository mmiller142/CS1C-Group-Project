#include "formaddshape.h"
#include "Rectangle.h"
#include "Ellipse.h"
#include "Line.h"
#include "Polygon.h"
#include "Polyline.h"
#include "Text.h"
#include <QtWidgets>
#include <QString>

using namespace myShapes;

FormAddShape::FormAddShape(QWidget *parent, int id) : QDialog(parent), pShape{nullptr}, id{id}
{
    //buttonOk = new QPushButton(tr("Ok"), this);

    shapeComboBox = new QComboBox;
    shapeComboBox->addItem(tr("Select Shape"), Shape::none);
    shapeComboBox->addItem(tr("Polygon"), Shape::polygon);
    shapeComboBox->addItem(tr("Rectangle"), Shape::rectangle);
    shapeComboBox->addItem(tr("Square"), Shape::square);
    shapeComboBox->addItem(tr("Ellipse"), Shape::ellipse);
    shapeComboBox->addItem(tr("Circle"), Shape::circle);
    shapeComboBox->addItem(tr("Line"), Shape::line);
    shapeComboBox->addItem(tr("Polyline"), Shape::polyline);
    shapeComboBox->addItem(tr("Text"), Shape::text);

    shapeLabel = new QLabel(tr("&Shape:"));
    shapeLabel->setBuddy(shapeComboBox);

    shapeDimensionEdit = new QLineEdit();
    shapeDimensionLabel = new QLabel(tr("Shape &Dimensions:"));
    shapeDimensionLabel->setBuddy(shapeDimensionEdit);

    //Create controls for standard shapes and text
    setupShapeControls();
    setupTextControls();

    //Add Ok and Cancel buttons
    buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);

    connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
    connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));

    //Connect signals to slots (user actions to handlers)
    connect(shapeComboBox, SIGNAL(activated(int)), this, SLOT(shapeChanged()));
    connect(shapeDimensionEdit, SIGNAL(editingFinished()), this, SLOT(dimChanged()));
    connect(penColorEdit, SIGNAL(activated(int)), this, SLOT(penChanged()));
    connect(penWidthSpinBox, SIGNAL(valueChanged(int)), this, SLOT(penChanged()));
    connect(penCapComboBox, SIGNAL(activated(int)), this, SLOT(penChanged()));
    connect(penJoinComboBox, SIGNAL(activated(int)), this, SLOT(penChanged()));
    connect(penStyleComboBox, SIGNAL(activated(int)), this, SLOT(penChanged()));
    connect(brushColorEdit, SIGNAL(activated(int)), this, SLOT(brushColorChanged()));
    connect(brushStyleComboBox, SIGNAL(activated(int)), this, SLOT(brushStyleChanged()));

    //Build layout
    QGridLayout *mainLayout = new QGridLayout;

    mainLayout->setColumnStretch(0, 1);
    mainLayout->setColumnStretch(3, 1);
    mainLayout->setColumnMinimumWidth(0, 100);
    mainLayout->setColumnMinimumWidth(1, 215);
    mainLayout->setColumnMinimumWidth(2, 100);
    mainLayout->setColumnMinimumWidth(3, 215);
    mainLayout->addWidget(shapeLabel, 2, 0, Qt::AlignRight);
    mainLayout->addWidget(shapeComboBox, 2, 1);
    mainLayout->addWidget(shapeDimensionLabel, 2, 2, Qt::AlignRight);
    mainLayout->addWidget(shapeDimensionEdit, 2, 3);
    mainLayout->addWidget(penColorLabel, 3, 0, Qt::AlignRight);
    mainLayout->addWidget(penColorEdit, 3, 1);
    mainLayout->addWidget(penWidthLabel, 3, 2, Qt::AlignRight);
    mainLayout->addWidget(penWidthSpinBox, 3, 3);
    mainLayout->addWidget(penCapLabel, 4, 0, Qt::AlignRight);
    mainLayout->addWidget(penCapComboBox, 4, 1);
    mainLayout->addWidget(penJoinLabel, 4, 2, Qt::AlignRight);
    mainLayout->addWidget(penJoinComboBox, 4, 3);
    mainLayout->addWidget(penStyleLabel, 5, 0, Qt::AlignRight);
    mainLayout->addWidget(penStyleComboBox, 5, 1);
    mainLayout->addWidget(brushColorLabel, 6, 0, Qt::AlignRight);
    mainLayout->addWidget(brushColorEdit, 6, 1);
    mainLayout->addWidget(brushStyleLabel, 6, 2, Qt::AlignRight);
    mainLayout->addWidget(brushStyleComboBox, 6, 3);


    mainLayout->addWidget(buttonBox,7,0,2,5,Qt::AlignRight);
    setLayout(mainLayout);
    setWindowTitle(tr("CS 1C Group Project - Add Shape Form"));
    showControls(false);

}

FormAddShape::~FormAddShape()
{
    delete shapeLabel;
    delete penColorLabel;
    delete penWidthLabel;
    delete penStyleLabel;
    delete penCapLabel;
    delete penJoinLabel;
    delete brushStyleLabel;
    delete brushColorLabel;
    delete shapeDimensionLabel;
    delete shapeComboBox;
    delete penStyleComboBox;
    delete penCapComboBox;
    delete penJoinComboBox;
    delete brushStyleComboBox;
    delete brushColorEdit;
    delete penColorEdit;
    delete shapeDimensionEdit;
    delete penWidthSpinBox;
    delete buttonBox;

    //delete text controls
    delete alignmentLabel;
    delete alignmentComboBox;
    delete fontFamilyLabel;
    delete fontFamilyComboBox;
    delete fontStyleLabel;
    delete fontStyleComboBox;
    delete fontWeightLabel;
    delete fontWeightComboBox;
    delete textStringLabel;
    delete textStringEdit;


}

void FormAddShape::shapeChanged()
{
    bool shapeExists = nullptr != pShape;
    bool shapeWasText = false;
    if(shapeExists)
        shapeWasText = myShapes::Shape::text == pShape->getShapeType();

    delete pShape;
    pShape = nullptr;
    if(Shape::none != shapeComboBox->currentData())
        pShape = myShapes::Shape::makeShape(id, Shape::Shapes(shapeComboBox->currentData().toInt()));

    showControls(nullptr != pShape);

    if(shapeWasText && myShapes::Shape::text != pShape->getShapeType())
        showStandardControls(true);//switch controls back to standard shapes
    else if(!shapeWasText && myShapes::Shape::text == pShape->getShapeType())
        showStandardControls(false);//switch controls back to text shapes
}

void FormAddShape::dimChanged()
{
    if(nullptr == pShape)
        return;

    pShape->updateDimensions(shapeDimensionEdit->text().toStdString());
}

void FormAddShape::brushStyleChanged()
{
    if(nullptr == pShape)
        return;

    Qt::BrushStyle style = Qt::BrushStyle(brushStyleComboBox->currentData().toInt());

    pShape->setBrushStyle(style);
}

void FormAddShape::brushColorChanged()
{
    if(nullptr == pShape)
        return;
    pShape->setBrushColor(brushColorEdit->currentText().toStdString());
}

void FormAddShape::penChanged()
{
    if(nullptr == pShape)
        return;
    pShape->setPenColor(penColorEdit->currentText().toStdString());

    int width = penWidthSpinBox->value();
    if(myShapes::Shape::text != pShape->getShapeType())
    {
        pShape->setPenWidth(width);

        Qt::PenStyle style = Qt::PenStyle(penStyleComboBox->currentData().toInt());
        pShape->setPenStyle(style);

        Qt::PenCapStyle cap = Qt::PenCapStyle(penCapComboBox->currentData().toInt());
        pShape->setPenCapStyle(cap);

        Qt::PenJoinStyle join = Qt::PenJoinStyle(penJoinComboBox->currentData().toInt());
        pShape->setPenJoinStyle(join);
    }
    else
    {
        Text* pText = dynamic_cast<Text*>(pShape);
        pText->setPointSize(width);
    }

}

void FormAddShape::showControls(bool show)
{
    shapeDimensionLabel->setEnabled(show);
    shapeDimensionEdit->setEnabled(show);
    penColorLabel->setEnabled(show);
    penColorEdit->setEnabled(show);
    penWidthLabel->setEnabled(show);
    penWidthSpinBox->setEnabled(show);
    penStyleLabel->setEnabled(show);
    penStyleComboBox->setEnabled(show);
    penCapLabel->setEnabled(show);
    penCapComboBox->setEnabled(show);
    penJoinLabel->setEnabled(show);
    penJoinComboBox->setEnabled(show);
    penJoinComboBox->setEnabled(show);

    //Show brush options for non-linear shapes
    Shape::Shapes selectedShape = Shape::Shapes(shapeComboBox->currentData().toInt());
    if(selectedShape == Shape::Shapes::line || selectedShape == Shape::Shapes::polyline)
    {
        brushStyleLabel->setEnabled(false);
        brushStyleComboBox->setEnabled(false);
        brushColorLabel->setEnabled(false);
        brushColorEdit->setEnabled(false);
    }
    else
    {
        brushStyleLabel->setEnabled(show);
        brushStyleComboBox->setEnabled(show);
        brushColorLabel->setEnabled(show);
        brushColorEdit->setEnabled(show);
    }
}

void FormAddShape::showStandardControls(bool show)
{
    //If show is true than text shape controls need to be removed from the layout
    //and replaced with standard shape controls
    //If show is false than the standard shape controls need to be removed from the
    //layout and the text shape controls added.

    penColorLabel->setText(show ? "Pen &Color:" : "Text &Color");
    penWidthLabel->setText(show ? "Pen &Width:" : "Font &Height:");
    int minWidth = (show ? 0 : 5);
    int maxWidth = (show ? 20 : 100);
    penWidthSpinBox->setRange(minWidth, maxWidth);
    penWidthSpinBox->setSpecialValueText(tr(show ? "0 (cosmetic pen)" : ""));


    QGridLayout* mainLayout = dynamic_cast<QGridLayout*>(this->layout());
    mainLayout->removeWidget(show ? alignmentLabel : penCapLabel);
    mainLayout->removeWidget(show ? alignmentComboBox : penCapComboBox);
    mainLayout->removeWidget(show ? fontFamilyLabel : penJoinLabel);
    mainLayout->removeWidget(show ? fontFamilyComboBox: penJoinComboBox);
    mainLayout->removeWidget(show ? fontStyleLabel : penStyleLabel);
    mainLayout->removeWidget(show ? fontStyleComboBox : penStyleComboBox);
    mainLayout->removeWidget(show ? fontWeightLabel: brushStyleLabel);
    mainLayout->removeWidget(show ? fontWeightComboBox: brushStyleComboBox);
    mainLayout->removeWidget(show ? textStringLabel: brushColorLabel);
    if(show)
        mainLayout->removeWidget(textStringEdit);
    else
        mainLayout->removeWidget(brushColorEdit);

    mainLayout->addWidget((!show ? alignmentLabel : penCapLabel), 4, 0, Qt::AlignRight);
    mainLayout->addWidget(!show ? alignmentComboBox : penCapComboBox, 4, 1);
    mainLayout->addWidget(!show ? fontFamilyLabel : penJoinLabel, 4, 2, Qt::AlignRight);
    mainLayout->addWidget(!show ? fontFamilyComboBox : penJoinComboBox, 4, 3);
    mainLayout->addWidget(!show ? fontStyleLabel : penStyleLabel, 5, 0, Qt::AlignRight);
    mainLayout->addWidget(!show ? fontStyleComboBox : penStyleComboBox, 5, 1);
    mainLayout->addWidget(!show ? fontWeightLabel : brushStyleLabel, 5, 2, Qt::AlignRight);
    mainLayout->addWidget(!show ? fontWeightComboBox : brushStyleComboBox, 5, 3);
    mainLayout->addWidget(!show ? textStringLabel : brushColorLabel, 6, 0, Qt::AlignRight);
    if(show)
        mainLayout->addWidget(brushColorEdit, 6, 1);
    else
        mainLayout->addWidget(textStringEdit, 6, 1, 1, 3, Qt::AlignLeft);


    //set the visibility states
    penCapLabel->setHidden(!show);
    penCapComboBox->setHidden(!show);
    penJoinLabel->setHidden(!show);
    penJoinComboBox->setHidden(!show);
    penStyleLabel->setHidden(!show);
    penStyleComboBox->setHidden(!show);
    brushStyleLabel->setHidden(!show);
    brushStyleComboBox->setHidden(!show);
    brushColorLabel->setHidden(!show);
    brushColorEdit->setHidden(!show);

    alignmentLabel->setHidden(show);
    alignmentComboBox->setHidden(show);
    fontFamilyLabel->setHidden(show);
    fontFamilyComboBox->setHidden(show);
    fontStyleLabel->setHidden(show);
    fontStyleComboBox->setHidden(show);
    fontWeightLabel->setHidden(show);
    fontWeightComboBox->setHidden(show);
    textStringLabel->setHidden(show);
    textStringEdit->setHidden(show);

}

void FormAddShape::setupShapeControls()
{
    penWidthSpinBox = new QSpinBox;
    penWidthSpinBox->setRange(0, 20);
    penWidthSpinBox->setValue(5);
    penWidthSpinBox->setSpecialValueText(tr("0 (cosmetic pen)"));

    penWidthLabel = new QLabel(tr("Pen &Width:"));
    penWidthLabel->setBuddy(penWidthSpinBox);

    penStyleComboBox = new QComboBox;
    penStyleComboBox->addItem(tr("SolidLine"), static_cast<int>(Qt::SolidLine));
    penStyleComboBox->addItem(tr("DashLine"), static_cast<int>(Qt::DashLine));
    penStyleComboBox->addItem(tr("DotLine"), static_cast<int>(Qt::DotLine));
    penStyleComboBox->addItem(tr("DashDotLine"), static_cast<int>(Qt::DashDotLine));
    penStyleComboBox->addItem(tr("DashDotDotLine"), static_cast<int>(Qt::DashDotDotLine));
    penStyleComboBox->addItem(tr("NoPen"), static_cast<int>(Qt::NoPen));

    penStyleLabel = new QLabel(tr("&Pen Style:"));
    penStyleLabel->setBuddy(penStyleComboBox);

    penColorEdit = new QComboBox();
    penColorEdit->addItems(QColor::colorNames());
    penColorLabel = new QLabel(tr("Pen &Color:"));
    penColorLabel->setBuddy(penColorEdit);

    penCapComboBox = new QComboBox;
    penCapComboBox->addItem(tr("FlatCap"), Qt::FlatCap);
    penCapComboBox->addItem(tr("SquareCap"), Qt::SquareCap);
    penCapComboBox->addItem(tr("RoundCap"), Qt::RoundCap);

    penCapLabel = new QLabel(tr("Pen &Cap:"));
    penCapLabel->setBuddy(penCapComboBox);

    penJoinComboBox = new QComboBox;
    penJoinComboBox->addItem(tr("MiterJoin"), Qt::MiterJoin);
    penJoinComboBox->addItem(tr("BevelJoin"), Qt::BevelJoin);
    penJoinComboBox->addItem(tr("RoundJoin"), Qt::RoundJoin);

    penJoinLabel = new QLabel(tr("Pen &Join:"));
    penJoinLabel->setBuddy(penJoinComboBox);

    brushColorEdit = new QComboBox();
    brushColorEdit->addItems(QColor::colorNames());
    brushColorLabel = new QLabel(tr("&Brush Color:"));
    brushColorLabel->setBuddy(brushColorEdit);

    brushStyleComboBox = new QComboBox;
    brushStyleComboBox->addItem(tr("SolidPattern"), static_cast<int>(Qt::SolidPattern));
    brushStyleComboBox->addItem(tr("HorPattern"), static_cast<int>(Qt::HorPattern));
    brushStyleComboBox->addItem(tr("VerPattern"), static_cast<int>(Qt::VerPattern));
    brushStyleComboBox->addItem(tr("CrossPattern"), static_cast<int>(Qt::CrossPattern));
    brushStyleComboBox->addItem(tr("BDiagPattern"), static_cast<int>(Qt::BDiagPattern));
    brushStyleComboBox->addItem(tr("FDiagPattern"), static_cast<int>(Qt::FDiagPattern));
    brushStyleComboBox->addItem(tr("DiagCrossPattern"), static_cast<int>(Qt::DiagCrossPattern));
    brushStyleComboBox->addItem(tr("Dense1"), static_cast<int>(Qt::Dense1Pattern));
    brushStyleComboBox->addItem(tr("Dense2"), static_cast<int>(Qt::Dense2Pattern));
    brushStyleComboBox->addItem(tr("Dense3"), static_cast<int>(Qt::Dense3Pattern));
    brushStyleComboBox->addItem(tr("Dense4"), static_cast<int>(Qt::Dense4Pattern));
    brushStyleComboBox->addItem(tr("Dense5"), static_cast<int>(Qt::Dense5Pattern));
    brushStyleComboBox->addItem(tr("Dense6"), static_cast<int>(Qt::Dense6Pattern));
    brushStyleComboBox->addItem(tr("Dense7"), static_cast<int>(Qt::Dense7Pattern));
    brushStyleComboBox->addItem(tr("NoBrush"), static_cast<int>(Qt::NoBrush));

    brushStyleLabel = new QLabel(tr("&Brush:"));
    brushStyleLabel->setBuddy(brushStyleComboBox);

}

void FormAddShape::setupTextControls()
{
    alignmentComboBox = new QComboBox;
    alignmentComboBox->addItem(tr("Left"), static_cast<int>(Qt::AlignLeft));
    alignmentComboBox->addItem(tr("Right"), static_cast<int>(Qt::AlignRight));
    alignmentComboBox->addItem(tr("Center"), static_cast<int>(Qt::AlignCenter));

    alignmentLabel = new QLabel(tr("&Alignment:"));
    alignmentLabel->setBuddy(alignmentComboBox);

    fontFamilyComboBox = new QFontComboBox;

    fontFamilyLabel = new QLabel(tr("&Font Family:"));
    fontFamilyLabel->setBuddy(fontFamilyComboBox);

    fontStyleComboBox = new QComboBox;
    fontStyleComboBox->addItem(tr("StyleNormal"), static_cast<int>(QFont::StyleNormal));
    fontStyleComboBox->addItem(tr("StyleItalic"), static_cast<int>(QFont::StyleItalic));
    fontStyleComboBox->addItem(tr("StyleOblique"), static_cast<int>(QFont::StyleOblique));

    fontStyleLabel = new QLabel(tr("Font &Style:"));
    fontStyleLabel->setBuddy(fontStyleComboBox);

    fontWeightComboBox = new QComboBox;
    fontWeightComboBox->addItem(tr("StyleNormal"), static_cast<int>(QFont::Normal));
    fontWeightComboBox->addItem(tr("Thin"), static_cast<int>(QFont::Thin));
    fontWeightComboBox->addItem(tr("ExtraLight"), static_cast<int>(QFont::ExtraLight));
    fontWeightComboBox->addItem(tr("Light"), static_cast<int>(QFont::Light));
    fontWeightComboBox->addItem(tr("Medium"), static_cast<int>(QFont::Medium));
    fontWeightComboBox->addItem(tr("DemiBold"), static_cast<int>(QFont::DemiBold));
    fontWeightComboBox->addItem(tr("Bold"), static_cast<int>(QFont::Bold));
    fontWeightComboBox->addItem(tr("ExtraBold"), static_cast<int>(QFont::ExtraBold));
    fontWeightComboBox->addItem(tr("Black"), static_cast<int>(QFont::Black));

    fontWeightLabel = new QLabel(tr("Font &Weight:"));
    fontWeightLabel->setBuddy(fontWeightComboBox);

    textStringEdit = new QLineEdit;
    textStringEdit->setMinimumWidth(215);

    textStringLabel = new QLabel(tr("&Text String:"));
    textStringLabel->setBuddy(textStringEdit);

    connect(alignmentComboBox, SIGNAL(activated(int)), this, SLOT(textChanged()));
    connect(fontFamilyComboBox, SIGNAL(activated(int)), this, SLOT(textChanged()));
    connect(fontStyleComboBox, SIGNAL(activated(int)), this, SLOT(textChanged()));
    connect(fontWeightComboBox, SIGNAL(activated(int)), this, SLOT(textChanged()));
    connect(textStringEdit, SIGNAL(editingFinished()), this, SLOT(textChanged()));
}

void FormAddShape::textChanged()
{
    if(myShapes::Shape::text != pShape->getShapeType())
        return;
    Text* pText = dynamic_cast<Text*>(pShape);

    pText->setAlignment((Qt::AlignmentFlag)alignmentComboBox->currentData().toInt());
    pText->setFontFamily(fontFamilyComboBox->currentText().toStdString());
    pText->setfontStyle((QFont::Style)fontStyleComboBox->currentData().toInt());
    pText->setFontWeight((QFont::Weight)fontWeightComboBox->currentData().toInt());
    pText->setTextString(textStringEdit->text().toStdString());
}
