#include "castle.h"

Castle::Castle()
{
    hp=5000;
    Acting=false;

    RestMovie=new QMovie();
    ActMovie=new QMovie();
}

Castle::~Castle()
{
    delete RestMovie;
    delete ActMovie;
}

