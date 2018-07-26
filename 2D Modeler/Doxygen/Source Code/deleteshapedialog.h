#ifndef DELETESHAPEDIALOG_H
#define DELETESHAPEDIALOG_H

#include <QDialog>

namespace Ui {
class DeleteShapeDialog;
}

class DeleteShapeDialog : public QDialog
{
    Q_OBJECT

public:
	//!DeleteShapeDialog constructor
	/*!
	 * \brief DeleteShapeDialog
	 * \param QWidget Object
	 */
    explicit DeleteShapeDialog(QWidget *parent = 0);

    //!DeleteShapeDialog destructor
    ~DeleteShapeDialog();

   //!Shape ID
   /*!
	* \brief ID selected to be deleted
	*/
    int selectedId;

    //!Shape Range
    void setRange(int min, int max);

public slots:
    //!Changing the selected Shape ID
    void selectedIdChanged();

private:
    //!Dialog for deleted shape
    Ui::DeleteShapeDialog *ui;
};


#endif //! DELETESHAPEDIALOG_H
