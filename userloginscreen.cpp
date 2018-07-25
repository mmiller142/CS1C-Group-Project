#include "userloginscreen.h"
#include <QMessageBox>
#include <QtWidgets>

UserLoginScreen::UserLoginScreen(MainWindow* pMainWindow, MainWindow::User& user)
    : pMainWindow{pMainWindow},  user{user}
{

    nameEdit = new QLineEdit();
    nameLabel = new QLabel(tr("Username:"));
    nameLabel->setBuddy(nameEdit);
    passEdit = new QLineEdit();
    passLabel = new QLabel(tr("Password:"));
    passLabel->setBuddy(passEdit);

    connect(nameEdit, SIGNAL(editingFinished()), this, SLOT(nameChanged()));
    connect(passEdit, SIGNAL(editingFinished()), this, SLOT(passChanged()));

    QPixmap logo("C++ Logo.jpg");
    logoLabel = new QLabel();
    logoLabel->setPixmap(logo);

    QGridLayout *mainLayout = new QGridLayout;

    //mainLayout->setColumnStretch(0, 1);
    mainLayout->addWidget(logoLabel, 0, 0, 3, 3, Qt::AlignLeft);
    mainLayout->addWidget(nameLabel, 5, 0, Qt::AlignRight);
    mainLayout->addWidget(nameEdit, 5, 1);
    mainLayout->addWidget(passLabel, 6, 0, Qt::AlignRight);
    mainLayout->addWidget(passEdit, 6, 1);

    buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);

    connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
    connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));

    mainLayout->addWidget(buttonBox,8,0,2,5,Qt::AlignRight);
    setLayout(mainLayout);
    setWindowTitle(tr("User Login"));
}

void UserLoginScreen::accept()
{
    user.username = nameEdit->text();
    user.password = passEdit->text();

    if(pMainWindow->authenticateUser(user))
        QDialog::accept();
    else {
        QMessageBox msgBox;
        msgBox.setWindowTitle("ACCESS DENIED!");
        msgBox.setText("Invalid username or password");
        msgBox.exec();
    }
}
