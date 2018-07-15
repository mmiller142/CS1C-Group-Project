#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QMenuBar>
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

private slots:
    void addButtonClicked();

private:
    //Ui::MainWindow *ui;
    Canvas* canvas;
    QPushButton* addButton;
    QMenuBar *menuBar;
    QMenu *fileMenu;
    QAction *exitAction;
    void createMenu();
    bool isGuest;
};

#endif // MAINWINDOW_H
