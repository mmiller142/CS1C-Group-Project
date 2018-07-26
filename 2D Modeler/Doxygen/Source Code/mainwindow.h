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
	//!MainWindow constructor
	/*!
	 * \brief MainWindow
	 */
    explicit MainWindow();//(QWidget *parent = 0);

    //!MainWindow destructor
    ~MainWindow();

    //!Enumerated Access Levels
    enum accessLevels { noAccess, guest, admin };

    //!User Login Info
    typedef struct user{
        QString username;
        QString password;
        accessLevels accessLevel;
    } User;
    //!User Authentication
	/*!
	 * \brief authanticating user login
	 */
    bool authenticateUser(User& loginUser);

    //!Returning User
    User& getUser() {return user;}

private slots:
	//!Calling Add Shape
    void addButtonClicked();
    //!Calling Delete Shape
    void deleteButtonClicked();
    //!Calls Canvas Report
    void report();
    //!About Page
    void about();

private:
    //Ui::MainWindow *ui;

    //!Main Window Actions
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

};

#endif //! MAINWINDOW_H
