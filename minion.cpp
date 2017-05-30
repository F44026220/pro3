#include "minion.h"

Minion::Minion(int ch)
{
    WhichCh=ch;
    DisFromHome=0;
    Acting=false;

    MoveMovie=new QMovie();
    ActMovie=new QMovie();

    Blood=new QProgressBar();

    switch (ch) {
    case 1:
        hp=500;
        break;
    case 2:
        hp=800;
        break;
    case 3:
        hp=400;
        break;
    case 4:
        hp=400;
        break;
    case 5:
        hp=800;
        break;
    case 6:
        hp=600;
        break;
    case 7:
        hp=3000;
        break;
    case 8:
        hp=1500;
        break;
    }

    Blood->setRange(0,hp);
    Blood->setValue(hp);
    Blood->setStyleSheet("QProgressBar::chunk {background-color: #ff6347}");
    Blood->setTextVisible(false);
}

Minion::~Minion()
{
    delete MoveMovie;
    delete ActMovie;
    delete Blood;
}




