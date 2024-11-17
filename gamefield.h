#ifndef GAMEFIELD_H
#define GAMEFIELD_H

#include "cellstate.h"

#include <QWidget>
#include <QQueue>

class Cell;

class GameField : public QWidget
{
    Q_OBJECT
public:
    explicit GameField(QWidget *parent = nullptr);

private slots:
    void onCellClick();

signals:
    void sideChanged(CellState state);
    void sideWin(CellState state);

private:
    QVector<Cell*> m_cells;
    CellState m_nextPlayer = CellState::first;


    CellState checkFinished();
    void resetField();

    QQueue<Cell*> m_cellQueue;

};

#endif // GAMEFIELD_H
