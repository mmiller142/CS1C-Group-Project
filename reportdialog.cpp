#include "reportdialog.h"
#include "ui_reportdialog.h"
#include "QTableWidgetItem"

ReportDialog::ReportDialog(myShapes::vector<myShapes::Shape*>& shapes, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ReportDialog),
    shapes(shapes)
{
    ui->setupUi(this);
    buildTable();
}

ReportDialog::~ReportDialog()
{
    delete ui;
}

void ReportDialog::buildTable()
{

    QStringList headings{tr("ID"), tr("Shape"), tr("Dimensions"), tr("Pen Color"), tr("Width"), tr("Style"), tr("Cap"), tr("Join"), tr("Brush Color"), tr("Style")};
    ui->tableWidget->setColumnCount(headings.count());
    ui->tableWidget->setRowCount(shapes.size());
    ui->tableWidget->setHorizontalHeaderLabels(headings);
    ui->tableWidget->setColumnWidth(0, 20);
    ui->tableWidget->setColumnWidth(1, 70);
    ui->tableWidget->setColumnWidth(2, 180);
    ui->tableWidget->setColumnWidth(3, 60);
    ui->tableWidget->setColumnWidth(4, 50);
    ui->tableWidget->setColumnWidth(5, 100);

    ui->gridLayout->setColumnStretch(0, 1);
    ui->gridLayout->addWidget(ui->tableWidget, 0, 0, 10, 20, Qt::AlignHCenter | Qt::AlignVCenter);
    ui->gridLayout->addWidget(ui->buttonBox, 12, 20, 1, 4, Qt::AlignRight);

    //Add Shape data
    for(int i = 0; i < shapes.size(); i++)
        addShape(i);

}

void ReportDialog::addShape(int row)
{
    myShapes::Shape *pShape = shapes[row];
    QStringList shapeData;
    pShape->getShapeData(shapeData);
    int count = shapeData.count();
    for(int i = 0; i < count; i++)
    {
        QTableWidgetItem* item = new QTableWidgetItem(shapeData[i]);
        ui->tableWidget->setItem(row, i, item);
    }
}
