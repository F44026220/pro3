#ifndef SCENE_H
#define SCENE_H

#include <QString>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QLabel>
#include <QVector>
#include "army.h"
#include "castle.h"
#include "minion.h"
#include <ctime>
#include "rank.h"

#define ARMYNUM 8
#define DECKNUM 3
#define COVERNUM 3
#define SCENE_WIDTH 1300
#define SCENE_HEIGHT 700

class Scene: public QGraphicsScene
{
    Q_OBJECT

 public:
    Scene();
    ~Scene();
    void ScreenModeOne();
    void ScreenModeTwo();
    void ScreenModeThree();
    void ScreenModeRank();
    void setDeck(int);
    void setDeckcp(int);
    void ready(int);
    void addCastle(Castle* &, Castle* &);
    void addMinion(Minion* &);
    void setMinionPos(Minion* &);
    void setMinionAct(Minion* &);
    void setCastleAct(Castle* &);
    void setRankTable(Rank* &);
    void deleteRankTable();

    int screenMode; //represents that we are in which mode.
    int Deck[DECKNUM]; /*characters who are ready for assignment*/
    int Cover[DECKNUM]; /*characters who don't appear*/
    int C_Deck[COVERNUM];
    int C_Cover[COVERNUM];
    int Call, C_Call;

    Army *CandidateArr[ARMYNUM];
    QGraphicsPixmapItem *Intro;
    QGraphicsPixmapItem *MinionArr[DECKNUM];
    QGraphicsPixmapItem *C_MinionArr[DECKNUM];
    QGraphicsPixmapItem *Ready;
    QLabel *Namelb[RANKNUM];
    QLabel *Timelb[RANKNUM];
    QLabel *Ranklb[RANKNUM];

    /*Btn sites for minion-chosen page(screenMode=1)*/
    QPoint posCandidateArr[ARMYNUM];
    /*Btn sites for game page(screenMode=2)*/
    QPoint posCallLeftArr[DECKNUM];
    QPoint posCallRightArr[DECKNUM];
    /*label sites for rank page(screenMode=4)*/
    QPoint posRankArr[3];
    /*Paths of pictures*/
    QString pathCandidateArr[ARMYNUM];
    QString pathIntroArr[ARMYNUM];
    QString pathReadyArr[4];
    /*Paths of pictures(GIF)*/
    QString pathMoveArr[ARMYNUM];
    QString C_pathMoveArr[ARMYNUM];
    QString pathActArr[ARMYNUM];
    QString C_pathActArr[ARMYNUM];

 public slots:
    void chIntro1(bool);
    void chIntro2(bool);
    void chIntro3(bool);
    void chIntro4(bool);
    void chIntro5(bool);
    void chIntro6(bool);
    void chIntro7(bool);
    void chIntro8(bool);
};

#endif // SCENE_H
