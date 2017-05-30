#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <vector>
#include <QMainWindow>
#include "scene.h"
#include "ai.h"
#include <QTimer>
#include "battle.h"
#include "mouserange.h"
#include "rank.h"

#define COUNTDOWN 180

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    int ChosenNum;
    int DeckNum;
    int ManaCost[ARMYNUM]={1,4,3,2,2,5,5,7};
    QString PlayerName;
    QTimer *timerDetect;
    QTimer *timerCountdown;
    Scene *scene;
    Battle *battle;
    AI *ai;
    Rank *rank;
    MouseRange *IntroRange[ARMYNUM];

    void setBg();
    void closeScreenModeOne();
    void closeScreenModeTwo();
    void closeScreenModeThree();
    void closeScreenModeRank();
    void ifFullChosenNum();
    void ifFullDeckNum();

public slots:
    void setArmy1(bool);
    void setArmy2(bool);
    void setArmy3(bool);
    void setArmy4(bool);
    void setArmy5(bool);
    void setArmy6(bool);
    void setArmy7(bool);
    void setArmy8(bool);

    void setDeck1(bool);
    void setDeck2(bool);
    void setDeck3(bool);
    void setDeck4(bool);
    void setDeck5(bool);
    void setDeck6(bool);
    void setDeck7(bool);
    void setDeck8(bool);

    void callRight1();
    void callRight2();
    void callRight3();

    void ifPause(bool);

    void updateBattle();
    void updateScene();

    void setScreenModeOne();
    void setScreenModeTwo();
    void setScreenModeThree();
    void setScreenModeRank(bool);

    void magic1();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
