#ifndef MOUSERANGE_H
#define MOUSERANGE_H

#include <QWidget>

class MouseRange: public QWidget
{
    Q_OBJECT

public:
    MouseRange(int, int, int, int);
    virtual void enterEvent(QEvent *e);
    virtual void leaveEvent(QEvent *e);

signals:
    void ifhover(bool);
};

#endif // MOUSERANGE_H
