#ifndef BATTLE_H
#define BATTLE_H

#include <QObject>
#include <QVector>
#include "minion.h"
#include "castle.h"
#include "rolling.h"

#define LOCATE_LEN 1100
#define ARMYNUM 8
#define FULLMANA 10
#define UNIT 10

class Battle: public QObject
{
    Q_OBJECT

public:
    int mana;
    int C_mana;
    int winner;  //1 for left; 2 for right; 3 for tie.
    int time;
    int Attack[ARMYNUM]={4,8,8,6,6,12,4,15}; //per 0.1s
    int SeeRange[ARMYNUM]={6*UNIT,4*UNIT,16*UNIT,12*UNIT,4*UNIT,6*UNIT,4*UNIT,6*UNIT};
    int Speed[ARMYNUM]={6,8,6,8,10,6,6,8}; //per 0.1s
    int castleAttack=5;
    int castleSeeRange=5*UNIT;

    Battle();
    ~Battle();
    Minion* callMinion(int);
    Minion* callMinioncp(int);
    void Analyze();
    void judge();
    Minion* ifSeeEnemy(int, int);
    Minion* ifSeeEnemycp(int, int);
    void rolling();

    Castle *Build;
    Castle *C_Build;
    QVector<Minion*> location[LOCATE_LEN];
    QVector<Minion*> C_location[LOCATE_LEN];
    Rolling *roll;

public slots:
    void rollAttack(int);
};

#endif // BATTLE_H
