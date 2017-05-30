#ifndef CASTLE_H
#define CASTLE_H

#include <QLabel>
#include <QMovie>

class Castle: public QLabel
{
public:
    Castle();
    ~Castle();

    int hp;
    bool Acting;
    bool LastActing;

    QMovie *RestMovie;
    QMovie *ActMovie;
};

#endif // CASTLE_H
