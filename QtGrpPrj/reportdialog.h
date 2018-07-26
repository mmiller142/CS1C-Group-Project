#ifndef REPORTDIALOG_H
#define REPORTDIALOG_H

#include <QDialog>
#include "vector.h"
#include "Shape.h"

namespace Ui {
class ReportDialog;
}

class ReportDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ReportDialog(myShapes::vector<myShapes::Shape*>& pShapes, QWidget *parent = 0);
    ~ReportDialog();

private:
    Ui::ReportDialog *ui;
    myShapes::vector<myShapes::Shape*>& shapes;
    void buildTable();
    void addShape(int row);
};

#endif // REPORTDIALOG_H
