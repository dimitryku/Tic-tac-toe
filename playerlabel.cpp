#include "playerlabel.h"
#include "DrawHelpers.h"

PlayerLabel::PlayerLabel(QWidget *parent)
    : QLabel(parent)
{

}

void PlayerLabel::setState(CellState newState) {
    m_state = newState;
    update();
}


void PlayerLabel::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QRect r = rect();

    if (m_state == CellState::first)
        DrawHelpers::drawFirst(&painter, &r);
    else if (m_state == CellState::second)
        DrawHelpers::drawSecond(&painter, &r);
    else
        QLabel::paintEvent(event);
}
