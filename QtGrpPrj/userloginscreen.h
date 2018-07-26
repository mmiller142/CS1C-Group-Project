#ifndef USERLOGINSCREEN_H
#define USERLOGINSCREEN_H
#include "mainwindow.h"
#include <QWidget>
#include <QDialog>
#include <QDialogButtonBox>
#include <QLineEdit>
#include <QLabel>

class UserLoginScreen : public QDialog
{
public:
    UserLoginScreen(MainWindow* pMainWindow, MainWindow::User& user);
    MainWindow::User& user;
    MainWindow* pMainWindow;
public slots:
    virtual void accept();

private:
    QLabel *nameLabel;
    QLabel *passLabel;
    QLineEdit *nameEdit;
    QLineEdit *passEdit;
    QDialogButtonBox *buttonBox;
    QLabel *logoLabel;
};

#endif // USERLOGINSCREEN_H
