#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "gamefield.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    setCentralWidget(new GameField(this));
    connect(ui->gameField, &GameField::sideChanged, ui->headerWidget, &HeaderWidget::setCurrentStepSide);
}

MainWindow::~MainWindow()
{
    delete ui;
}

