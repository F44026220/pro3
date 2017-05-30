#ifndef BTN_H
#define BTN_H
#include <QPushButton>


class Btn: public QPushButton
{
public:
    Btn();
    virtual void enterEvent(QEvent *e);
    virtual void leaveEvent(QEvent *e);

signals:
    void hover();
    void outBtn();
};
#endif // BTN_H
