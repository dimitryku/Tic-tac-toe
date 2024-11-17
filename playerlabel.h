#ifndef PLAYERLABEL_H
#define PLAYERLABEL_H

#include "cellstate.h"

#include <QLabel>

class PlayerLabel : public QLabel
{
    Q_OBJECT
public:
    explicit PlayerLabel(QWidget *parent = nullptr);

    void setState(CellState newState);

signals:

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    CellState m_state;
};

#endif // PLAYERLABEL_H
