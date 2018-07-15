#include "formaddshape.h"
#include "Rectangle.h"
#include "Ellipse.h"
#include "Line.h"
#include "Polygon.h"
#include "Polyline.h"
#include "Text.h"
#include <QtWidgets>
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

    penColorEdit = new QLineEdit();
    penColorEdit->setText(tr("black"));
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

    brushColorEdit = new QLineEdit();
    brushColorEdit->setText(tr("white"));
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


    //Connect signals to slots (user actions to handlers)
    connect(shapeComboBox, SIGNAL(activated(int)), this, SLOT(shapeChanged()));
    connect(shapeDimensionEdit, SIGNAL(editingFinished()), this, SLOT(dimChanged()));
    connect(penColorEdit, SIGNAL(editingFinished()), this, SLOT(penChanged()));
    connect(penWidthSpinBox, SIGNAL(valueChanged(int)), this, SLOT(penChanged()));
    connect(penCapComboBox, SIGNAL(activated(int)), this, SLOT(penChanged()));
    connect(penJoinComboBox, SIGNAL(activated(int)), this, SLOT(penChanged()));
    connect(penStyleComboBox, SIGNAL(activated(int)), this, SLOT(penChanged()));
    connect(brushColorEdit, SIGNAL(editingFinished()), this, SLOT(brushColorChanged()));
    connect(brushStyleComboBox, SIGNAL(activated(int)), this, SLOT(brushStyleChanged()));

    QGridLayout *mainLayout = new QGridLayout;

    mainLayout->setColumnStretch(0, 1);
    mainLayout->setColumnStretch(3, 1);
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

    buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);

    connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
    connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));

    mainLayout->addWidget(buttonBox,7,0,2,5,Qt::AlignRight);
    setLayout(mainLayout);
    setWindowTitle(tr("CS 1C Group Project - Add Shape Form"));
    showControls(false);

}

void FormAddShape::shapeChanged()
{
    delete pShape;
    pShape = nullptr;
    if(Shape::none != shapeComboBox->currentData())
        pShape = myShapes::Shape::makeShape(id, Shape::Shapes(shapeComboBox->currentData().toInt()));

    showControls(nullptr != pShape);
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

    pShape->setBrushColor(QColor(brushColorEdit->text()));
}

void FormAddShape::penChanged()
{
    if(nullptr == pShape)
        return;
    pShape->setPenColor(QColor(penColorEdit->text()));

    int width = penWidthSpinBox->value();
    pShape->setPenWidth(width);

    Qt::PenStyle style = Qt::PenStyle(penStyleComboBox->currentData().toInt());
    pShape->setPenStyle(style);

    Qt::PenCapStyle cap = Qt::PenCapStyle(penCapComboBox->currentData().toInt());
    pShape->setPenCapStyle(cap);

    Qt::PenJoinStyle join = Qt::PenJoinStyle(penJoinComboBox->currentData().toInt());
    pShape->setPenJoinStyle(join);

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

