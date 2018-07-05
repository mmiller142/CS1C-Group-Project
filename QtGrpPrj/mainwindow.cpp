#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Canvas.h"
#include <QtWidgets>

MainWindow::MainWindow()//(QWidget *parent) :
//    QMainWindow(parent),
//    ui(new Ui::MainWindow)
{
    //ui->setupUi(this);
    canvas = new Canvas(this);
    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->setColumnStretch(0, 1);
    mainLayout->setColumnStretch(3, 1);
    mainLayout->addWidget(canvas, 0, 0, 1, 4);
    setLayout(mainLayout);
    setWindowTitle(tr("CS 1C Group Project - Team: C+++++"));
}

MainWindow::~MainWindow()
{
//    delete ui;
    delete canvas;
}
