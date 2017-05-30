#ifndef ARMY_H
#define ARMY_H

#include <QGraphicsPixmapItem>

class Army: public QGraphicsPixmapItem
{
    public:
        bool Pick;
        bool FirstDeck;

        Army();
};

#endif // ARMY_H
