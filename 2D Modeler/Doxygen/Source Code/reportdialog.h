#ifndef REPORTDIALOG_H
#define REPORTDIALOG_H

#include <QDialog>
#include "vector.h"
#include "Shape.h"

//! name spae Ui.
namespace Ui {

class ReportDialog;
}

//! Class ReportDialog
/*!
  Strings for each defined shape.
 */
class ReportDialog : public QDialog
{
    Q_OBJECT

public:
    //! ReportDialog constructor
    /*!
     * \brief Shape
     * \param pShapes
     * \param parent
     */
    explicit ReportDialog(myShapes::vector<myShapes::Shape*>& pShapes, QWidget *parent = 0);

    //!Shape destructor (virtual!)
    ~ReportDialog();

private:
    Ui::ReportDialog *ui;   /*!< Qt dialog for Shapes report */
    myShapes::vector<myShapes::Shape*>& shapes; /*!< vector of all shapes */

    //! buildTable method
    /*!
     * \brief This methods builds the shapes table for displaying on Qt Dialog.
     */
    void buildTable();

    //! addShape method.
    /*!
     * \brief Method used to add shape to ui->tableWidget.
     * \param row
     */
    void addShape(int row);
};

#endif // REPORTDIALOG_H
