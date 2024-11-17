#include "DrawHelpers.h"

void DrawHelpers::drawFirst(QPainter *painter, QRect *paintRect) {
    // X
    painter->save();
    auto pen = painter->pen();
    pen.setWidth(10);
    pen.setColor(Qt::red);
    painter->setPen(pen);

    painter->translate(paintRect->center());
    painter->rotate(45);
    auto len = qMin(paintRect->width() / 4, paintRect->height() / 4);
    painter->drawLine(QPoint(-len, 0), QPoint(len, 0));
    painter->drawLine(QPoint(0, -len), QPoint(0, len));

    painter->restore();
}

void DrawHelpers::drawSecond(QPainter *painter, QRect *paintRect) {
    // O
    painter->save();
    auto pen = painter->pen();
    pen.setWidth(10);
    pen.setColor(Qt::blue);
    painter->setPen(pen);

    auto radius = qMin(paintRect->width() / 4, paintRect->height() / 4);
    painter->drawEllipse(paintRect->center(), radius, radius);
    painter->restore();
}
