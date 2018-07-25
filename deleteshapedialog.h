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
    explicit DeleteShapeDialog(QWidget *parent = 0);
    ~DeleteShapeDialog();

    int selectedId;

    void setRange(int min, int max);

public slots:
    void selectedIdChanged();

private:
    Ui::DeleteShapeDialog *ui;
};

#endif // DELETESHAPEDIALOG_H
