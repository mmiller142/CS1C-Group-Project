#include "deleteshapedialog.h"
#include "ui_deleteshapedialog.h"

DeleteShapeDialog::DeleteShapeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteShapeDialog),
    selectedId(-1)
{
    ui->setupUi(this);

    connect(ui->spinBox, SIGNAL(valueChanged(int)), this, SLOT(selectedIdChanged()));
}

DeleteShapeDialog::~DeleteShapeDialog()
{
    delete ui;
}

void DeleteShapeDialog::setRange(int min, int max)
{
    ui->spinBox->setRange(min, max);
}

void DeleteShapeDialog::selectedIdChanged()
{
    selectedId = ui->spinBox->value();
}
