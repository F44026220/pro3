#include "mouserange.h"

MouseRange::MouseRange(int x, int y, int w, int h)
{
    setGeometry(x,y,w,h);
    setMouseTracking(true);
}

void MouseRange::enterEvent(QEvent *e)
{
    emit ifhover(true);

    QWidget::enterEvent(e);
}

void MouseRange::leaveEvent(QEvent *e)
{
    emit ifhover(false);

    QWidget::leaveEvent(e);
}



