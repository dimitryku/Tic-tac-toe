#include "headerwidget.h"
#include "ui_headerwidget.h"

HeaderWidget::HeaderWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HeaderWidget)
{
    ui->setupUi(this);
    ui->firstLabel->setState(CellState::first);
    ui->secondLabel->setState(CellState::second);
    ui->currStepLabel->setState(CellState::first);
}

HeaderWidget::~HeaderWidget()
{
    delete ui;
}

void HeaderWidget::setCurrentStepSide(CellState state)
{
    ui->currStepLabel->setState(state);
}
