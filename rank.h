#ifndef RANK_H
#define RANK_H

#include <QString>
#include <QTextStream>
#include <QFile>
#include <iostream>

#define RANKNUM 10

class Rank
{
public:
    Rank();
    void write(QString, int);
    void read();

    QFile rankFile;
    QTextStream out;
    QTextStream in;

    int PlayerNum;
    QString Name[RANKNUM];
    int Time[RANKNUM];
};

#endif // RANK_H
