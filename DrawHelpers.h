#ifndef DRAWHELPERS_H
#define DRAWHELPERS_H

#include "cellstate.h"

#include <QPainter>

namespace DrawHelpers {

    void drawFirst(QPainter* painter, QRect* paintRect);
    void drawSecond(QPainter* painter, QRect* paintRect);

}

#endif // DRAWHELPERS_H
