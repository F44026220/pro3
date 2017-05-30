#ifndef ROLLING_H
#define ROLLING_H

#include <QLabel>
#include <QMovie>
#include <QTimer>

class Rolling: public QLabel
{
    Q_OBJECT

public:
    Rolling();
    ~Rolling();

    QTimer *Timer;
    int x_pos, y_pos;
    int width, height;
    QMovie *ActMovie;

signals:
    void rollAct(int);

public slots:
    void update();
};

#endif // ROLLING_H
