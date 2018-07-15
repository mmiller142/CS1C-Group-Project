#ifndef FORMADDSHAPE_H
#define FORMADDSHAPE_H

#include <QWidget>
#include <QDialog>
#include <QDialogButtonBox>
#include <QLineEdit>
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
protected:

private:
    QPushButton* buttonOk;
    QLabel *shapeLabel;
    QLabel *penColorLabel;
    QLabel *penWidthLabel;
    QLabel *penStyleLabel;
    QLabel *penCapLabel;
    QLabel *penJoinLabel;
    QLabel *brushStyleLabel;
    QLabel *brushColorLabel;
    QLabel *shapeDimensionLabel;
    QComboBox *shapeComboBox;
    QComboBox *penStyleComboBox;
    QComboBox *penCapComboBox;
    QComboBox *penJoinComboBox;
    QComboBox *brushStyleComboBox;
    QLineEdit *brushColorEdit;
    QLineEdit *penColorEdit;
    QLineEdit *shapeDimensionEdit;
    QSpinBox *penWidthSpinBox;
    QDialogButtonBox *buttonBox;
    int id;

    void showControls(bool show);

};
}

#endif // FORMADDSHAPE_H

