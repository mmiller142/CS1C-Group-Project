#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Canvas.h"
#include <QtWidgets>
#include "formaddshape.h"
#include "userloginscreen.h"
#include "ui_about.h"

MainWindow::MainWindow()//(QWidget *parent) :
//    QMainWindow(parent),
//    ui(new Ui::MainWindow)
    :canvas(nullptr), menuBar(nullptr), fileMenu(nullptr)
{
    //ui->setupUi(this);

    //add guest access
    MainWindow::users[0].username = tr("guest");
    MainWindow::users[0].password = tr("guest");
    MainWindow::users[0].accessLevel = MainWindow::guest;

    //add admin access
    users[1].username = tr("admin");
    users[1].password = tr("admin");
    users[1].accessLevel = MainWindow::admin;


    canvas = new Canvas(this);
    addButton = new QPushButton(tr("&Add Shape"), this);
    connect(addButton,SIGNAL(clicked(bool)), this, SLOT(addButtonClicked()));

    deleteButton = new QPushButton(tr("&Delete Shape"), this);
    connect(deleteButton,SIGNAL(clicked(bool)), this, SLOT(deleteButtonClicked()));

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->setColumnStretch(0, 1);
    mainLayout->setColumnStretch(3, 1);
    mainLayout->addWidget(canvas, 0, 0, 1, 4);
    mainLayout->addWidget(addButton, 1, 1, 1, 1);
    mainLayout->addWidget(deleteButton, 1, 2, 1, 1);
    createMenu();
    mainLayout->setMenuBar(menuBar);
    setLayout(mainLayout);
    setWindowTitle(tr("CS 1C Group Project - Team: C+++++"));
}

MainWindow::~MainWindow()
{
//    delete ui;
    delete canvas;
    delete menuBar;
    delete fileMenu;
    delete reportMenu;
    delete addButton;
    delete deleteButton;
}

void MainWindow::addButtonClicked()
{
    canvas->addShape();
}

void MainWindow::deleteButtonClicked()
{
    canvas->deleteShape();
}

void MainWindow::createMenu()
{
    menuBar = new QMenuBar;

    fileMenu = new QMenu(tr("&File"), this);
    exitAction = fileMenu->addAction(tr("E&xit"));
    menuBar->addMenu(fileMenu);

    reportMenu = new QMenu(tr("&Report"), this);
    reportAction = reportMenu->addAction(tr("&Shape List"));
    menuBar->addMenu(reportMenu);

    helpMenu = new QMenu(tr("&Help"), this);
    aboutAction = helpMenu->addAction(tr("&About"));
    menuBar->addMenu(helpMenu);

    connect(exitAction, SIGNAL(triggered()), this, SLOT(close()));
    connect(reportAction, SIGNAL(triggered()), this, SLOT(report()));
    connect(aboutAction, SIGNAL(triggered()), this, SLOT(about()));
}

bool MainWindow::authenticateUser(User& loginUser)
{
    for(int i = 0; i < NUM_USERS; i++)
    {
        if(users[i].username == loginUser.username &&
                users[i].password == loginUser.password)
        {
            loginUser.accessLevel = users[i].accessLevel;
            addButton->setEnabled(user.accessLevel > accessLevels::guest);
            deleteButton->setEnabled(user.accessLevel > accessLevels::guest);
            return true;
        }
    }
    return false;
}

void MainWindow::report()
{
    canvas->report();
}

void MainWindow::about()
{
    QDialog* pWidget = new QDialog{};
    Ui::about about;
    about.setupUi(pWidget);

    QPixmap logo("C++ Logo.jpg");
    about.label_3->setPixmap(logo);
    pWidget->exec();

    delete pWidget;
}
