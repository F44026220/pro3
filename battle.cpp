#include "battle.h"
#include <iostream>

Battle::Battle()
{
    mana=FULLMANA;
    C_mana=FULLMANA;

    roll=NULL;

    Build=new Castle();
    C_Build=new Castle();
}

Battle::~Battle()
{
    int i, j, VecSize;

    for (i=0; i<LOCATE_LEN; ++i) {
        VecSize=location[i].size();
        for (j=0; j<VecSize; ++j)
            delete location[i].at(j);
       }
    for (i=0; i<LOCATE_LEN; ++i) {
        VecSize=C_location[i].size();
        for (j=0; j<VecSize; ++j)
            delete C_location[i].at(j);
       }

    delete roll;
    delete Build;
    delete C_Build;
}

Minion* Battle::callMinion(int WhichMinion)
{
    Minion *CH=new Minion(WhichMinion);
    CH->group=2;
    location[LOCATE_LEN-1].push_back(CH);

    return CH;
}

Minion* Battle::callMinioncp(int WhichMinion)
{
    Minion *CH=new Minion(WhichMinion);
    CH->group=1;
    C_location[0].push_back(CH);

    return CH;
}

void Battle::Analyze()
{
    int i, j, VecSize;
    Minion *Ob, *Enemy;   
    QVector<Minion*> Buf_location[LOCATE_LEN];
    QVector<Minion*> Buf_C_location[LOCATE_LEN];

    for (i=0; i<LOCATE_LEN; ++i) { //if Minions see Enemy (player)
        VecSize=location[i].size();
        for (j=0; j<VecSize; ++j) {
            Ob=location[i].at(j);
            Ob->LastActing=Ob->Acting;
            Enemy=ifSeeEnemy(SeeRange[Ob->WhichCh-1], Ob->DisFromHome);
            if (Enemy==NULL) {
               if (LOCATE_LEN-1 - Ob->DisFromHome <= SeeRange[Ob->WhichCh-1]) { //See castle
                   Ob->Acting=true;
                   C_Build->hp -= Attack[Ob->WhichCh-1];
                  }
               else {
                  Ob->Acting=false;
                  Ob->DisFromHome += Speed[Ob->WhichCh-1];
                 }
              }
            else {
                Ob->Acting=true;
                Enemy->hp -= Attack[Ob->WhichCh-1];
              }
           }
       }
    Build->LastActing=Build->Acting;
    Enemy=ifSeeEnemy(castleSeeRange, 0); //if the castle sees Enemy (player)
    if (Enemy==NULL)
       Build->Acting=false;
    else {
       Build->Acting=true;
       Enemy->hp -= castleAttack;
      }

    for (i=LOCATE_LEN-1; i>=0; --i) { //if Minions see Enemy (ai)
        VecSize=C_location[i].size();
        for (j=0; j<VecSize; ++j) {
            Ob=C_location[i].at(j);
            Ob->LastActing=Ob->Acting;
            Enemy=ifSeeEnemycp(SeeRange[Ob->WhichCh-1], Ob->DisFromHome);
            if (Enemy==NULL) {
               if (LOCATE_LEN-1 - Ob->DisFromHome <= SeeRange[Ob->WhichCh-1]) { //See castle
                   Ob->Acting=true;
                   Build->hp -= Attack[Ob->WhichCh-1];
                  }
               else {
                  Ob->Acting=false;
                  Ob->DisFromHome += Speed[Ob->WhichCh-1];
                 }
              }
            else {
                Ob->Acting=true;
                Enemy->hp -= Attack[Ob->WhichCh-1];
              }
           }
       }
    C_Build->LastActing=C_Build->Acting;
    Enemy=ifSeeEnemycp(castleSeeRange, 0); //if the castle sees Enemy (ai)
    if (Enemy==NULL)
       C_Build->Acting=false;
    else {
       C_Build->Acting=true;
       Enemy->hp -= castleAttack;
      }

    /*assign the position inside the Buf and clear the corpse*/
    for (i=0; i<LOCATE_LEN; ++i) {
        VecSize=location[i].size();
        for (j=0; j<VecSize; ++j) {
            Ob=location[i].at(j);
            if (Ob->hp>0) {
               Buf_location[LOCATE_LEN-1 - Ob->DisFromHome].push_back(Ob);
               Ob->Blood->setValue(Ob->hp);
              }
            else {
               delete Ob;
               location[i][j]=NULL;
              }
           }
       }
    for (i=LOCATE_LEN-1; i>=0; --i) {
        VecSize=C_location[i].size();
        for (j=0; j<VecSize; ++j) {
            Ob=C_location[i].at(j);
            if (Ob->hp>0) {
               Buf_C_location[Ob->DisFromHome].push_back(Ob);
               Ob->Blood->setValue(Ob->hp);
              }
            else {
               delete Ob;
               C_location[i][j]=NULL;
              }
           }
       }

    /*reassign to locaion and C_location*/
    for (i=0; i<LOCATE_LEN; ++i) {
        location[i]=Buf_location[i];
        location[i].squeeze();
       }
    for (i=0; i<LOCATE_LEN; ++i) {
        C_location[i]=Buf_C_location[i];
        C_location[i].squeeze();
       }
}

void Battle::judge()
{
    if (Build->hp>C_Build->hp)
        winner=2;
    if (Build->hp<C_Build->hp)
        winner=1;
    if (Build->hp==C_Build->hp)
        winner=3;
}

Minion* Battle::ifSeeEnemy(int SeeRange, int Dfromhome)
{
    int CurrentSee, Obloc, Count=1;

    Obloc = LOCATE_LEN-1 - Dfromhome;
    CurrentSee= Obloc - 1;
    while (Count<=SeeRange && C_location[CurrentSee].size()==0 && CurrentSee>=0) {
        CurrentSee -= 1;
        ++Count;
       }
    if (Count>SeeRange || CurrentSee<0)
        return NULL; //No enemy
    else
        return C_location[CurrentSee].first();
}

Minion* Battle::ifSeeEnemycp(int SeeRange, int Dfromhome)
{
    int CurrentSee, Obloc, Count=1;

    Obloc = Dfromhome;
    CurrentSee= Obloc + 1;
    while (Count<=SeeRange && location[CurrentSee].size()==0 && CurrentSee<=LOCATE_LEN-1) {
        CurrentSee += 1;
        ++Count;
       }
    if (Count>SeeRange || CurrentSee>LOCATE_LEN-1)
        return NULL; //No enemy
    else
        return location[CurrentSee].first();
}

void Battle::rolling()
{
    roll=new Rolling();
    connect(roll, SIGNAL(rollAct(int)), this, SLOT(rollAttack(int)));
}

void Battle::rollAttack(int Attack)
{
    int i, j, VecSize;
    Minion *Enemy;

    for (i=0; i<LOCATE_LEN; ++i) {
        VecSize=C_location[i].size();
        for (j=0; j<VecSize; ++j) {
            Enemy=C_location[i].at(j);
            Enemy->hp -= Attack;
           }
       }

    delete roll;
    roll=NULL;
}



