#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Canvas.h"
#include <QtWidgets>
#include "formaddshape.h"

MainWindow::MainWindow()//(QWidget *parent) :
//    QMainWindow(parent),
//    ui(new Ui::MainWindow)
{
    //ui->setupUi(this);
    canvas = new Canvas(this);
    addButton = new QPushButton(tr("Add Shape"), this);
    connect(addButton,SIGNAL(clicked(bool)), this, SLOT(addButtonClicked()));
    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->setColumnStretch(0, 1);
    mainLayout->setColumnStretch(3, 1);
    mainLayout->addWidget(canvas, 0, 0, 1, 4);
    mainLayout->addWidget(addButton, 1, 0);
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
}

void MainWindow::addButtonClicked()
{
    canvas->addShape();
}

void MainWindow::createMenu()
{
    menuBar = new QMenuBar;

    fileMenu = new QMenu(tr("&File"), this);
    exitAction = fileMenu->addAction(tr("E&xit"));
    menuBar->addMenu(fileMenu);

    connect(exitAction, SIGNAL(triggered()), this, SLOT(close()));
}
