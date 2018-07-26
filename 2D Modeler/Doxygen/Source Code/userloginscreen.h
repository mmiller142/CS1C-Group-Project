#ifndef USERLOGINSCREEN_H
#define USERLOGINSCREEN_H
#include "mainwindow.h"
#include <QWidget>
#include <QDialog>
#include <QDialogButtonBox>
#include <QLineEdit>
#include <QLabel>

//!  UserLoginScreen class.
/*!
  This is the UserLoginScreen class, it inherits from QDialog.
*/
class UserLoginScreen : public QDialog
{
public:
    /*!
	* default UserLoginScreen constructor
	*/
    UserLoginScreen(MainWindow* pMainWindow, MainWindow::User& user);
    MainWindow::User& user; /*!< a user */
    MainWindow* pMainWindow; /*!< main window */
public slots:
    /*!
    * virtual method accept.
    */
    virtual void accept();

private:
    QLabel *nameLabel; /*!< QLabel widget for user name. */
    QLabel *passLabel; /*!< QLabel widget for user password. */
    QLineEdit *nameEdit; /*!< QLineEdit widget for user name input(text). */
    QLineEdit *passEdit; /*!< QLineEdit widget for user password input(text). */
    QDialogButtonBox *buttonBox; /*!< QDialogButtonBoxt widget for presenting button. */
    QLabel *logoLabel;  /*!< QLabel widget for displaying group Logo. */
};

#endif // USERLOGINSCREEN_H
