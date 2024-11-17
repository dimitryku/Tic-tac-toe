#ifndef HEADERWIDGET_H
#define HEADERWIDGET_H

#include "cellstate.h"

#include <QWidget>

namespace Ui {
class HeaderWidget;
}

class HeaderWidget : public QWidget
{
    Q_OBJECT
public:
    explicit HeaderWidget(QWidget *parent = nullptr);
    ~HeaderWidget();

public slots:
    void setCurrentStepSide(CellState state);

private:
    Ui::HeaderWidget *ui;
};

#endif // HEADERWIDGET_H
