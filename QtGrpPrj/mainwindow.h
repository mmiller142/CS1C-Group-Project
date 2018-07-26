#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QMenuBar>
#include <QString>

class Canvas;
/*
namespace Ui {
class MainWindow;
}
*/
class MainWindow;


const int NUM_USERS = 2;

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow();//(QWidget *parent = 0);
    ~MainWindow();

    enum accessLevels { noAccess, guest, admin };
    typedef struct user{
        QString username;
        QString password;
        accessLevels accessLevel;
    } User;
    bool authenticateUser(User& loginUser);
    User& getUser() {return user;}

private slots:
    void addButtonClicked();
    void deleteButtonClicked();
    void report();
    void about();

private:
    //Ui::MainWindow *ui;
    Canvas* canvas;
    QPushButton* addButton;
    QPushButton* deleteButton;
    QMenuBar *menuBar;
    QMenu *fileMenu;
    QMenu *helpMenu;
    QMenu *reportMenu;
    QAction *exitAction;
    QAction *reportAction;
    QAction *aboutAction;
    void createMenu();
    User users[NUM_USERS];
    User user;
    //User login

};

#endif // MAINWINDOW_H
