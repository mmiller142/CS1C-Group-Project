#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
class Canvas;
/*
namespace Ui {
class MainWindow;
}
*/
//class MainWindow : public QMainWindow
class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow();//(QWidget *parent = 0);
    ~MainWindow();

private:
    //Ui::MainWindow *ui;
    Canvas* canvas;
};

#endif // MAINWINDOW_H
