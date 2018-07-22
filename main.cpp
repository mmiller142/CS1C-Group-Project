#include "mainwindow.h"
#include <QApplication>
#include "userloginscreen.h"
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //Show login screen
    UserLoginScreen uLogin{&w, w.getUser()};
    int result = uLogin.exec();
    if(QDialog::Accepted != result)
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Login canceled");
        msgBox.setText("Closing program!     ");
        msgBox.exec();
        a.quit();
    }
    else
        w.show();

    return a.exec();
}
