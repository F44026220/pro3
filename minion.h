#ifndef MINION_H
#define MINION_H

#include <QLabel>
#include <QMovie>
#include <QVector>
#include <QProgressBar>

class Minion: public QLabel
{
public:
    int WhichCh;
    int hp;
    int DisFromHome; //distance between home and the current position.
    int group;

    bool LastActing;
    bool Acting;

    QMovie *MoveMovie;
    QMovie *ActMovie;
    QProgressBar *Blood;

    Minion(int);
    ~Minion();
};

#endif //MINION_H
