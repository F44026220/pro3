#include "rolling.h"

Rolling::Rolling()
{
    QPixmap pic;

    Timer=new QTimer();
    QTimer::connect(Timer, SIGNAL(timeout()), this, SLOT(update()));

    ActMovie=new QMovie();
    pic.load(":/rolling.gif");
    width=pic.width();
    height=pic.height();
    ActMovie->setFileName(":/rolling.gif");
    ActMovie->setScaledSize(QSize(width,height));

    y_pos=600-height;
    x_pos=1300;
    this->setGeometry(x_pos, y_pos, width+2, height+2);

    this->setAttribute(Qt::WA_NoSystemBackground);
    this->setMovie(ActMovie);
    ActMovie->start();

    Timer->start(100);
}

Rolling::~Rolling()
{
    delete Timer;
}

void Rolling::update()
{
    x_pos -= 130;
    if (x_pos+width<=0) {
       Timer->stop();
       emit rollAct(200);
      }

    this->setGeometry(x_pos, y_pos, width+2, height+2);
}
