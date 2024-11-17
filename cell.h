#ifndef CELL_H
#define CELL_H

#include "cellstate.h"

#include <QWidget>

class Cell : public QWidget
{
    Q_OBJECT
public:
    explicit Cell(QWidget *parent = nullptr);

    void setState(CellState newState);
    CellState getState() const;

signals:
    void clicked();

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    CellState m_state = CellState::ready;
    bool m_pressStarted = false;
};

#endif // CELL_H
