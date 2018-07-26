#ifndef FORMADDSHAPE_H
#define FORMADDSHAPE_H

#include <QWidget>
#include <QDialog>
#include <QDialogButtonBox>
#include <QLineEdit>
#include <QFontComboBox>
#include "Shape.h"

class QComboBox;
class QLabel;
class QSpinBox;
class QPushButton;

namespace myShapes {

class FormAddShape : public QDialog
{
    Q_OBJECT
public:
    explicit FormAddShape(QWidget *parent = nullptr, int id = 0);
    ~FormAddShape();
   // QSize minimumSizeHint() const override;
   // QSize sizeHint() const override;
    Shape* pShape;
//    QDialog::DialogCode result;
public slots:
//    void accept();

signals:

public slots:
    void shapeChanged();
    void brushStyleChanged();
    void brushColorChanged();
    void penChanged();
    void dimChanged();
    void textChanged();
protected:

private:

    QLabel *shapeLabel;
    QLabel *shapeDimensionLabel;
    QLabel *penColorLabel;
    QLabel *penWidthLabel;
    QLabel *penStyleLabel;
    QLabel *penCapLabel;
    QLabel *penJoinLabel;
    QLabel *brushStyleLabel;
    QLabel *brushColorLabel;
    QComboBox *shapeComboBox;
    QComboBox *penStyleComboBox;
    QComboBox *penCapComboBox;
    QComboBox *penJoinComboBox;
    QComboBox *brushStyleComboBox;
    QComboBox *brushColorEdit;
    QComboBox *penColorEdit;
    QLineEdit *shapeDimensionEdit;
    QSpinBox *penWidthSpinBox;
    QDialogButtonBox *buttonBox;
    int id;

    //text controls
    QLabel *alignmentLabel;
    QLabel *fontFamilyLabel;
    QLabel *fontStyleLabel;
    QLabel *fontWeightLabel;
    QLabel *textStringLabel;
    QComboBox *alignmentComboBox;
    QFontComboBox *fontFamilyComboBox;
    QComboBox *fontStyleComboBox;
    QComboBox *fontWeightComboBox;
    QLineEdit *textStringEdit;

    void showControls(bool show);
    void showStandardControls(bool show);

    void setupShapeControls();
    void setupTextControls();

};
}

#endif // FORMADDSHAPE_H

