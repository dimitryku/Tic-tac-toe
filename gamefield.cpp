#include "gamefield.h"
#include "cell.h"

#include <QGridLayout>
#include <QDialog>

GameField::GameField(QWidget *parent)
    : QWidget(parent)
{
    auto* gLayout = new QGridLayout(this);
    for (int i = 0; i < 9; ++i) {
        m_cells.append(new Cell(this));
        gLayout->addWidget(m_cells.last(), i / 3, i % 3);
        connect(m_cells.last(), &Cell::clicked, this, &GameField::onCellClick);
    }
}

void GameField::onCellClick()
{
    auto* widget = static_cast<Cell*>(sender());
    if (!widget)
        return;

    if (widget->getState() == CellState::ready) {
       widget->setState(m_nextPlayer);
       m_nextPlayer = m_nextPlayer == CellState::first ? CellState::second : CellState::first;
       emit sideChanged(m_nextPlayer);
    }

    auto winState = checkFinished();
    if (winState == CellState::first || winState == CellState::second) {
        resetField();
        return;
    }

    m_cellQueue.append(widget);
    if (m_cellQueue.size() > 6) {
        auto* cell = m_cellQueue.dequeue();
        cell->setState(CellState::ready);
    }

    if (m_cellQueue.size() == 6) {
        auto* cell = m_cellQueue.head();
        cell->setState(CellState::notReady);
    }
}

CellState GameField::checkFinished()
{
    for (int i = 0; i < 3; ++i) {
        if (m_cells[i * 3]->getState() == m_cells[i * 3 + 1]->getState() && m_cells[i * 3 + 1]->getState() == m_cells[i * 3 + 2]->getState()
                && (m_cells[i * 3]->getState() == CellState::first || m_cells[i * 3]->getState() == CellState::second))
            return m_cells[i * 3]->getState();

        if (m_cells[i]->getState() == m_cells[i + 3]->getState() && m_cells[i + 3]->getState() == m_cells[i + 6]->getState()
                && (m_cells[i]->getState() == CellState::first || m_cells[i]->getState() == CellState::second))
            return m_cells[i]->getState();
    }

    if (m_cells[0]->getState() == m_cells[4]->getState() && m_cells[4]->getState() == m_cells[8]->getState()
            && (m_cells[0]->getState() == CellState::first || m_cells[0]->getState() == CellState::second))
        return m_cells[0]->getState();

    if (m_cells[6]->getState() == m_cells[4]->getState() && m_cells[4]->getState() == m_cells[2]->getState()
            && (m_cells[2]->getState() == CellState::first || m_cells[2]->getState() == CellState::second))
        return m_cells[2]->getState();

    return CellState::ready;
}

void GameField::resetField()
{
    m_cellQueue.clear();

    for(int i = 0; i < m_cells.size(); ++i)
        m_cells[i]->setState(CellState::ready);
}
