#include "cell.h"
#include "DrawHelpers.h"

#include <QPainter>

Cell::Cell(QWidget *parent) : QWidget(parent)
{
}

void Cell::setState(CellState newState) {
    if(newState == m_state)
        return;
    m_state = newState;
    update();
}

CellState Cell::getState() const {
    return m_state;
}

void Cell::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    painter.setPen(Qt::lightGray);
    if (m_state == CellState::notReady)
        painter.setBrush(Qt::lightGray);
    else
        painter.setBrush(Qt::white);

    painter.drawRoundedRect(rect().adjusted(0, 0, -1, -1), 10, 10, Qt::RelativeSize);

    auto r = rect();

    if (m_state == CellState::first)
        DrawHelpers::drawFirst(&painter, &r);
    else if (m_state == CellState::second)
        DrawHelpers::drawSecond(&painter, &r);
}


void Cell::mousePressEvent(QMouseEvent *event)
{
    m_pressStarted = true;
}

void Cell::mouseReleaseEvent(QMouseEvent *event)
{
    if (m_pressStarted && m_state != CellState::notReady) {
        m_pressStarted = false;
        emit clicked();
    }
}
