#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QObject>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ChosenNum=0;
    DeckNum=0;
    rank=new Rank();

    ui->setupUi(this);
    scene = new Scene();

    scene->posCandidateArr[0]=ui->Btn_Candidate1->pos();
    scene->posCandidateArr[1]=ui->Btn_Candidate2->pos();
    scene->posCandidateArr[2]=ui->Btn_Candidate3->pos();
    scene->posCandidateArr[3]=ui->Btn_Candidate4->pos();
    scene->posCandidateArr[4]=ui->Btn_Candidate5->pos();
    scene->posCandidateArr[5]=ui->Btn_Candidate6->pos();
    scene->posCandidateArr[6]=ui->Btn_Candidate7->pos();
    scene->posCandidateArr[7]=ui->Btn_Candidate8->pos();

    scene->posCallLeftArr[0]=ui->Btn_CallL1->pos();
    scene->posCallLeftArr[1]=ui->Btn_CallL2->pos();
    scene->posCallLeftArr[2]=ui->Btn_CallL3->pos();
    scene->posCallRightArr[0]=ui->Btn_CallR1->pos();
    scene->posCallRightArr[1]=ui->Btn_CallR2->pos();
    scene->posCallRightArr[2]=ui->Btn_CallR3->pos();

    scene->posRankArr[0]=ui->Show_rank1->pos();
    scene->posRankArr[1]=ui->Show_rank2->pos();
    scene->posRankArr[2]=ui->Show_rank3->pos();

    ui->Show_Blood1->setStyleSheet("QProgressBar::chunk {background-color: #ff6347}");
    ui->Show_Blood2->setStyleSheet("QProgressBar::chunk {background-color: #ff6347}");

    ui->graphicsView->setScene(scene);
    scene->setSceneRect(0,0,SCENE_WIDTH,SCENE_HEIGHT); // change the value to fit
    ui->graphicsView->show();
    setScreenModeOne();

    connect(ui->Btn_Candidate1, SIGNAL(toggled(bool)), this, SLOT(setArmy1(bool)));
    connect(ui->Btn_Candidate2, SIGNAL(toggled(bool)), this, SLOT(setArmy2(bool)));
    connect(ui->Btn_Candidate3, SIGNAL(toggled(bool)), this, SLOT(setArmy3(bool)));
    connect(ui->Btn_Candidate4, SIGNAL(toggled(bool)), this, SLOT(setArmy4(bool)));
    connect(ui->Btn_Candidate5, SIGNAL(toggled(bool)), this, SLOT(setArmy5(bool)));
    connect(ui->Btn_Candidate6, SIGNAL(toggled(bool)), this, SLOT(setArmy6(bool)));
    connect(ui->Btn_Candidate7, SIGNAL(toggled(bool)), this, SLOT(setArmy7(bool)));
    connect(ui->Btn_Candidate8, SIGNAL(toggled(bool)), this, SLOT(setArmy8(bool)));

    connect(ui->Btn_Deck1, SIGNAL(toggled(bool)), this, SLOT(setDeck1(bool)));
    connect(ui->Btn_Deck2, SIGNAL(toggled(bool)), this, SLOT(setDeck2(bool)));
    connect(ui->Btn_Deck3, SIGNAL(toggled(bool)), this, SLOT(setDeck3(bool)));
    connect(ui->Btn_Deck4, SIGNAL(toggled(bool)), this, SLOT(setDeck4(bool)));
    connect(ui->Btn_Deck5, SIGNAL(toggled(bool)), this, SLOT(setDeck5(bool)));
    connect(ui->Btn_Deck6, SIGNAL(toggled(bool)), this, SLOT(setDeck6(bool)));
    connect(ui->Btn_Deck7, SIGNAL(toggled(bool)), this, SLOT(setDeck7(bool)));
    connect(ui->Btn_Deck8, SIGNAL(toggled(bool)), this, SLOT(setDeck8(bool)));

    connect(ui->Btn_CallR1, SIGNAL(clicked(bool)), this, SLOT(callRight1()));
    connect(ui->Btn_CallR2, SIGNAL(clicked(bool)), this, SLOT(callRight2()));
    connect(ui->Btn_CallR3, SIGNAL(clicked(bool)), this, SLOT(callRight3()));

    connect(ui->Btn_Start, SIGNAL(clicked(bool)), this, SLOT(setScreenModeTwo()));
    connect(ui->Btn_again, SIGNAL(clicked(bool)), this, SLOT(setScreenModeOne()));
    connect(ui->Btn_Rank, SIGNAL(toggled(bool)), this, SLOT(setScreenModeRank(bool)));
    connect(ui->Btn_Pause, SIGNAL(toggled(bool)), this, SLOT(ifPause(bool)));
    connect(ui->Btn_rolling, SIGNAL(clicked(bool)), this, SLOT(magic1()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete scene;
    delete rank;
}

void MainWindow::setBg()
{
    QImage bg;
    if (scene->screenMode==1) {           
       bg.load(":/bg1.png");
       bg = bg.scaled(SCENE_WIDTH,SCENE_HEIGHT);
       scene->setBackgroundBrush(bg);
       closeScreenModeTwo();
       closeScreenModeThree();
       closeScreenModeRank();

       ui->Btn_Deck1->setVisible(false);
       ui->Btn_Deck2->setVisible(false);
       ui->Btn_Deck3->setVisible(false);
       ui->Btn_Deck4->setVisible(false);
       ui->Btn_Deck5->setVisible(false);
       ui->Btn_Deck6->setVisible(false);
       ui->Btn_Deck7->setVisible(false);
       ui->Btn_Deck8->setVisible(false);
       ui->Btn_Deck1->setStyleSheet("QPushButton {background-color: white}");
       ui->Btn_Deck2->setStyleSheet("QPushButton {background-color: white}");
       ui->Btn_Deck3->setStyleSheet("QPushButton {background-color: white}");
       ui->Btn_Deck4->setStyleSheet("QPushButton {background-color: white}");
       ui->Btn_Deck5->setStyleSheet("QPushButton {background-color: white}");
       ui->Btn_Deck6->setStyleSheet("QPushButton {background-color: white}");
       ui->Btn_Deck7->setStyleSheet("QPushButton {background-color: white}");
       ui->Btn_Deck8->setStyleSheet("QPushButton {background-color: white}");

       ui->Btn_Candidate1->setVisible(true);
       ui->Btn_Candidate2->setVisible(true);
       ui->Btn_Candidate3->setVisible(true);
       ui->Btn_Candidate4->setVisible(true);
       ui->Btn_Candidate5->setVisible(true);
       ui->Btn_Candidate6->setVisible(true);
       ui->Btn_Candidate7->setVisible(true);
       ui->Btn_Candidate8->setVisible(true);
       ui->Btn_Candidate1->setStyleSheet("QPushButton {background-color: white}");
       ui->Btn_Candidate2->setStyleSheet("QPushButton {background-color: white}");
       ui->Btn_Candidate3->setStyleSheet("QPushButton {background-color: white}");
       ui->Btn_Candidate4->setStyleSheet("QPushButton {background-color: white}");
       ui->Btn_Candidate5->setStyleSheet("QPushButton {background-color: white}");
       ui->Btn_Candidate6->setStyleSheet("QPushButton {background-color: white}");
       ui->Btn_Candidate7->setStyleSheet("QPushButton {background-color: white}");
       ui->Btn_Candidate8->setStyleSheet("QPushButton {background-color: white}");

       ui->Btn_Start->setVisible(true);
       ui->Btn_Rank->setVisible(true);
       ui->Show_Name->setVisible(true);
       ui->Edit_Name->setVisible(true);

       scene->ScreenModeOne(); //Then "candidates" exist.
       ui->Btn_Deck1->setChecked(false);
       ui->Btn_Deck2->setChecked(false);
       ui->Btn_Deck3->setChecked(false);
       ui->Btn_Deck4->setChecked(false);
       ui->Btn_Deck5->setChecked(false);
       ui->Btn_Deck6->setChecked(false);
       ui->Btn_Deck7->setChecked(false);
       ui->Btn_Deck8->setChecked(false);

       ui->Btn_Candidate1->setChecked(false);
       ui->Btn_Candidate2->setChecked(false);
       ui->Btn_Candidate3->setChecked(false);
       ui->Btn_Candidate4->setChecked(false);
       ui->Btn_Candidate5->setChecked(false);
       ui->Btn_Candidate6->setChecked(false);
       ui->Btn_Candidate7->setChecked(false);
       ui->Btn_Candidate8->setChecked(false);
      }
    if (scene->screenMode==2) {
       bg.load(":/prairie.jpg");
       bg = bg.scaled(SCENE_WIDTH,SCENE_HEIGHT);
       scene->setBackgroundBrush(bg);
       closeScreenModeOne();
       closeScreenModeThree();
       closeScreenModeRank();

       ui->Btn_Pause->setVisible(true);

       ui->Show_AI->setVisible(true);
       ui->Show_player->setVisible(true);
       ui->Show_time->setVisible(true);
       ui->Show_timeMin->setVisible(true);
       ui->Show_timeSec->setVisible(true);
       ui->Show_timeColon->setVisible(true);
       ui->Show_Mana1->setVisible(true);
       ui->Show_Mana2->setVisible(true);
       ui->Show_MNum1->setVisible(true);
       ui->Show_MNum2->setVisible(true);
       ui->Show_Blood1->setVisible(true);
       ui->Show_Blood2->setVisible(true);

       /*AI*/
       ui->Btn_CallL1->setVisible(false);
       ui->Btn_CallL2->setVisible(false);
       ui->Btn_CallL3->setVisible(false);
       /*Player*/
       ui->Btn_CallR1->setVisible(true);
       ui->Btn_CallR2->setVisible(true);
       ui->Btn_CallR3->setVisible(true);
       ui->Btn_CallR1->setEnabled(false);
       ui->Btn_CallR2->setEnabled(false);
       ui->Btn_CallR3->setEnabled(false);

       scene->addCastle(battle->Build, battle->C_Build);

       scene->ScreenModeTwo(); //then "ready" will be create
       timerCountdown->start(1000);
       scene->ready(3);
      }
    if (scene->screenMode==3) {
        bg.load(":/bg3.png");
        bg = bg.scaled(SCENE_WIDTH,SCENE_HEIGHT);
        scene->setBackgroundBrush(bg);
        closeScreenModeOne();
        closeScreenModeTwo();
        closeScreenModeRank();

        ui->Btn_again->setVisible(true);
        ui->Show_winner->setVisible(true);
        ui->Show_judge->setVisible(true);

        scene->ScreenModeThree(); //screenMode3 is empty currently
      }
    if (scene->screenMode==4) {
        scene->setBackgroundBrush(Qt::white);
        closeScreenModeOne();
        closeScreenModeTwo();
        closeScreenModeThree();

        ui->Btn_Rank->setVisible(true);
        ui->Show_rank1->setVisible(true);
        ui->Show_rank2->setVisible(true);
        ui->Show_rank3->setVisible(true);

        scene->ScreenModeRank(); //screenMode3 is empty currently
      }
}

/********************************************************Army Slots*********************************************************/
void MainWindow::setArmy1(bool Press)
{
    if (Press==true) {
       ++ChosenNum;
       scene->CandidateArr[0]->Pick=true;
       ui->Btn_Candidate1->setStyleSheet("QPushButton {background-color: green}");
      }
    else {
       --ChosenNum;
       scene->CandidateArr[0]->Pick=false;
       ui->Btn_Candidate1->setStyleSheet("QPushButton {background-color: white}");
      }
    ifFullChosenNum();
}

void MainWindow::setArmy2(bool Press)
{
    if (Press==true) {
       ++ChosenNum;
       scene->CandidateArr[1]->Pick=true;
       ui->Btn_Candidate2->setStyleSheet("QPushButton {background-color: green}");
      }
    else {
       --ChosenNum;
       scene->CandidateArr[1]->Pick=false;
       ui->Btn_Candidate2->setStyleSheet("QPushButton {background-color: white}");
      }
    ifFullChosenNum();
}

void MainWindow::setArmy3(bool Press)
{
    if (Press==true) {
       ++ChosenNum;
       scene->CandidateArr[2]->Pick=true;
       ui->Btn_Candidate3->setStyleSheet("QPushButton {background-color: green}");
      }
    else {
       --ChosenNum;
       scene->CandidateArr[2]->Pick=false;
       ui->Btn_Candidate3->setStyleSheet("QPushButton {background-color: white}");
     }
    ifFullChosenNum();
}

void MainWindow::setArmy4(bool Press)
{
    if (Press==true) {
       ++ChosenNum;
       scene->CandidateArr[3]->Pick=true;
       ui->Btn_Candidate4->setStyleSheet("QPushButton {background-color: green}");
      }
    else {
       --ChosenNum;
       scene->CandidateArr[3]->Pick=false;
       ui->Btn_Candidate4->setStyleSheet("QPushButton {background-color: white}");
      }
    ifFullChosenNum();
}

void MainWindow::setArmy5(bool Press)
{
    if (Press==true) {
       ++ChosenNum;
       scene->CandidateArr[4]->Pick=true;
       ui->Btn_Candidate5->setStyleSheet("QPushButton {background-color: green}");
      }
    else {
       --ChosenNum;
       scene->CandidateArr[4]->Pick=false;
       ui->Btn_Candidate5->setStyleSheet("QPushButton {background-color: white}");
      }
    ifFullChosenNum();
}

void MainWindow::setArmy6(bool Press)
{
    if (Press==true) {
       ++ChosenNum;
       scene->CandidateArr[5]->Pick=true;
       ui->Btn_Candidate6->setStyleSheet("QPushButton {background-color: green}");
      }
    else {
       --ChosenNum;
       scene->CandidateArr[5]->Pick=false;
       ui->Btn_Candidate6->setStyleSheet("QPushButton {background-color: white}");
      }
    ifFullChosenNum();
}

void MainWindow::setArmy7(bool Press)
{
    if (Press==true) {
       ++ChosenNum;
       scene->CandidateArr[6]->Pick=true;
       ui->Btn_Candidate7->setStyleSheet("QPushButton {background-color: green}");
      }
    else {
       --ChosenNum;
       scene->CandidateArr[6]->Pick=false;
       ui->Btn_Candidate7->setStyleSheet("QPushButton {background-color: white}");
      }
    ifFullChosenNum();
}

void MainWindow::setArmy8(bool Press)
{
    if (Press==true) {
       ++ChosenNum;
       scene->CandidateArr[7]->Pick=true;
       ui->Btn_Candidate8->setStyleSheet("QPushButton {background-color: green}");
      }
    else {
       --ChosenNum;
       scene->CandidateArr[7]->Pick=false;
       ui->Btn_Candidate8->setStyleSheet("QPushButton {background-color: white}");
      }
    ifFullChosenNum();
}

/***************************************************Deck Slots*********************************************************/
void MainWindow::setDeck1(bool Press)
{
    if (Press==true) {
       ++DeckNum;
       scene->CandidateArr[0]->FirstDeck=true;
       ui->Btn_Deck1->setStyleSheet("QPushButton {background-color: yellow}");
      }
    else {
       --DeckNum;
       scene->CandidateArr[0]->FirstDeck=false;
       ui->Btn_Deck1->setStyleSheet("QPushButton {background-color: white}");
      }
    ifFullDeckNum();
}

void MainWindow::setDeck2(bool Press)
{
    if (Press==true) {
       ++DeckNum;
       scene->CandidateArr[1]->FirstDeck=true;
       ui->Btn_Deck2->setStyleSheet("QPushButton {background-color: yellow}");
      }
    else {
       --DeckNum;
       scene->CandidateArr[1]->FirstDeck=false;
       ui->Btn_Deck2->setStyleSheet("QPushButton {background-color: white}");
      }
    ifFullDeckNum();
}

void MainWindow::setDeck3(bool Press)
{
    if (Press==true) {
       ++DeckNum;
       scene->CandidateArr[2]->FirstDeck=true;
       ui->Btn_Deck3->setStyleSheet("QPushButton {background-color: yellow}");
      }
    else {
       --DeckNum;
       scene->CandidateArr[2]->FirstDeck=false;
       ui->Btn_Deck3->setStyleSheet("QPushButton {background-color: white}");
      }
    ifFullDeckNum();
}

void MainWindow::setDeck4(bool Press)
{
    if (Press==true) {
       ++DeckNum;
       scene->CandidateArr[3]->FirstDeck=true;
       ui->Btn_Deck4->setStyleSheet("QPushButton {background-color: yellow}");
      }
    else {
       --DeckNum;
       scene->CandidateArr[3]->FirstDeck=false;
       ui->Btn_Deck4->setStyleSheet("QPushButton {background-color: white}");
      }
    ifFullDeckNum();
}

void MainWindow::setDeck5(bool Press)
{
    if (Press==true) {
       ++DeckNum;
       scene->CandidateArr[4]->FirstDeck=true;
       ui->Btn_Deck5->setStyleSheet("QPushButton {background-color: yellow}");
      }
    else {
       --DeckNum;
       scene->CandidateArr[4]->FirstDeck=false;
       ui->Btn_Deck5->setStyleSheet("QPushButton {background-color: white}");
      }
    ifFullDeckNum();
}

void MainWindow::setDeck6(bool Press)
{
    if (Press==true) {
       ++DeckNum;
       scene->CandidateArr[5]->FirstDeck=true;
       ui->Btn_Deck6->setStyleSheet("QPushButton {background-color: yellow}");
      }
    else {
       --DeckNum;
       scene->CandidateArr[5]->FirstDeck=false;
       ui->Btn_Deck6->setStyleSheet("QPushButton {background-color: white}");
      }
    ifFullDeckNum();
}

void MainWindow::setDeck7(bool Press)
{
    if (Press==true) {
       ++DeckNum;
       scene->CandidateArr[6]->FirstDeck=true;
       ui->Btn_Deck7->setStyleSheet("QPushButton {background-color: yellow}");
      }
    else {
       --DeckNum;
       scene->CandidateArr[6]->FirstDeck=false;
       ui->Btn_Deck7->setStyleSheet("QPushButton {background-color: white}");
      }
    ifFullDeckNum();
}

void MainWindow::setDeck8(bool Press)
{
    if (Press==true) {
       ++DeckNum;
       scene->CandidateArr[7]->FirstDeck=true;
       ui->Btn_Deck8->setStyleSheet("QPushButton {background-color: yellow}");
      }
    else {
       --DeckNum;
       scene->CandidateArr[7]->FirstDeck=false;
       ui->Btn_Deck8->setStyleSheet("QPushButton {background-color: white}");
      }
    ifFullDeckNum();
}

/*****************************************************CAll-Slot******************************************************/

void MainWindow::callRight1()
{
    if (battle->mana<ManaCost[scene->Deck[0]-1])
        return;

    scene->Call=scene->Deck[0];
    scene->setDeck(0);

    battle->mana -= ManaCost[scene->Call-1];
    QString Smana;
    Smana.setNum(battle->mana);
    ui->Show_MNum2->setText(Smana);

    Minion* CH=battle->callMinion(scene->Call);
    scene->addMinion(CH);
    scene->setMinionPos(CH);    
}

void MainWindow::callRight2()
{
    if (battle->mana<ManaCost[scene->Deck[1]-1])
        return;

    scene->Call=scene->Deck[1];
    scene->setDeck(1);

    battle->mana -= ManaCost[scene->Call-1];
    QString Smana;
    Smana.setNum(battle->mana);
    ui->Show_MNum2->setText(Smana);

    Minion* CH=battle->callMinion(scene->Call);
    scene->addMinion(CH);
    scene->setMinionPos(CH);
}

void MainWindow::callRight3()
{
    if (battle->mana<ManaCost[scene->Deck[2]-1])
        return;

    scene->Call=scene->Deck[2];
    scene->setDeck(2);

    battle->mana -= ManaCost[scene->Call-1];
    QString Smana;
    Smana.setNum(battle->mana);
    ui->Show_MNum2->setText(Smana);

    Minion* CH=battle->callMinion(scene->Call);
    scene->addMinion(CH);
    scene->setMinionPos(CH);
}

/*****************************************************update-Slot******************************************************/

void MainWindow::updateBattle() //battle and ai response
{
    int i, j, VecSize;
    Minion* Ob;

    if (battle->time<=0 || battle->Build->hp<=0 || battle->C_Build->hp<=0) {
        timerCountdown->stop();
        timerDetect->stop();
        setScreenModeThree();
       }
    else {
        if (battle->mana==10)
           ui->Btn_rolling->setVisible(true);
        else
           ui->Btn_rolling->setVisible(false);

        for (i=0; i<DECKNUM; ++i) //ai response
            ai->Deck[i]=scene->C_Deck[i];
        scene->C_Call=ai->response(battle->C_mana);

        if (scene->C_Call!=0) {
           scene->setDeckcp(ai->Pick);

           battle->C_mana -= ManaCost[scene->C_Call-1];
           QString Smana;
           Smana.setNum(battle->C_mana);
           ui->Show_MNum1->setText(Smana);

           Minion* CH=battle->callMinioncp(scene->C_Call);
           scene->addMinion(CH);
           scene->setMinionPos(CH);
          }

        battle->Analyze();
        for (i=0; i<LOCATE_LEN; ++i) {
            VecSize=battle->location[i].size();
            for (j=0; j<VecSize; ++j) {
                Ob=battle->location[i].at(j);
                scene->setMinionAct(Ob);
                scene->setMinionPos(Ob);
               }
           }
        for (i=0; i<LOCATE_LEN; ++i) {
            VecSize=battle->C_location[i].size();
            for (j=0; j<VecSize; ++j) {
                Ob=battle->C_location[i].at(j);
                scene->setMinionAct(Ob);
                scene->setMinionPos(Ob);
               }
           }
        scene->setCastleAct(battle->Build);
        scene->setCastleAct(battle->C_Build);        
        ui->Show_Blood1->setValue(battle->C_Build->hp);
        ui->Show_Blood2->setValue(battle->Build->hp);
       }
}

void MainWindow::updateScene()
{
    battle->time -= 1;

    if (battle->time<=0)
        battle->time=0;
    else {
        if (battle->time>COUNTDOWN)
            scene->ready(battle->time-COUNTDOWN-1);
        else {
            if (battle->time==COUNTDOWN) {
                delete scene->Ready;
                scene->Ready=NULL;
                timerDetect->start(100);
                ui->Btn_CallR1->setEnabled(true);
                ui->Btn_CallR2->setEnabled(true);
                ui->Btn_CallR3->setEnabled(true);
                ui->Btn_Pause->setEnabled(true);
               }
            if (battle->time>0) {
                QString Smana;
                if (battle->mana<FULLMANA) {
                    battle->mana += 1;
                    Smana.setNum(battle->mana);
                    ui->Show_MNum2->setText(Smana);
                  }
                if (battle->C_mana<FULLMANA) {  //ai
                    battle->C_mana += 1;
                    Smana.setNum(battle->C_mana);
                    ui->Show_MNum1->setText(Smana);
                  }
                QString Stime;
                Stime.setNum(battle->time/60);
                ui->Show_timeMin->setText(Stime);
                Stime.setNum(battle->time%60);
                if (battle->time%60>=10)
                    ui->Show_timeSec->setText(Stime);
                else {
                    Stime.prepend("0");
                    ui->Show_timeSec->setText(Stime);
                  }
              }
          }
      }
}

/******************************************************Magic-Slot*******************************************************/
void MainWindow::magic1()
{
    battle->mana=0;
    battle->rolling();
    battle->roll->setAttribute(Qt::WA_NoSystemBackground);
    scene->addWidget(battle->roll);
}

/******************************************************setScreenMode-Slot*******************************************************/
void MainWindow::setScreenModeOne()
{
    int i, x, y, y_mod=70, Side=78;

    for (i=0; i<ARMYNUM; ++i) {
        x=scene->posCandidateArr[i].x();
        y=scene->posCandidateArr[i].y();
        IntroRange[i]=new MouseRange(x,y-y_mod,Side,Side);
        scene->addWidget(IntroRange[i]);
       }
    connect(IntroRange[0], SIGNAL(ifhover(bool)), scene, SLOT(chIntro1(bool)));
    connect(IntroRange[1], SIGNAL(ifhover(bool)), scene, SLOT(chIntro2(bool)));
    connect(IntroRange[2], SIGNAL(ifhover(bool)), scene, SLOT(chIntro3(bool)));
    connect(IntroRange[3], SIGNAL(ifhover(bool)), scene, SLOT(chIntro4(bool)));
    connect(IntroRange[4], SIGNAL(ifhover(bool)), scene, SLOT(chIntro5(bool)));
    connect(IntroRange[5], SIGNAL(ifhover(bool)), scene, SLOT(chIntro6(bool)));
    connect(IntroRange[6], SIGNAL(ifhover(bool)), scene, SLOT(chIntro7(bool)));
    connect(IntroRange[7], SIGNAL(ifhover(bool)), scene, SLOT(chIntro8(bool)));

    ui->Edit_Name->setPlainText("PLAYER");
    rank->read();

    ui->Btn_Rank->setText("RANK");

    scene->screenMode=1;
    setBg();
}

void MainWindow::setScreenModeTwo()
{
    if (DeckNum!=DECKNUM)
        return;

    int i, DeckNext=0, CoverNext=0;

    PlayerName=ui->Edit_Name->toPlainText();
    ui->Show_player->setText(PlayerName);

    for (i=0; i<ARMYNUM; ++i) {
        delete IntroRange[i];
        IntroRange[i]=NULL;
       }

    ui->Btn_Pause->setText("PAUSE");
    ui->Btn_Pause->setChecked(false);
    ui->Btn_Pause->setEnabled(false);

    timerDetect=new QTimer();
    timerCountdown=new QTimer();
    battle = new Battle();
    ai = new AI(ManaCost);

    ui->Show_Blood1->setRange(0,battle->C_Build->hp);
    ui->Show_Blood2->setRange(0,battle->Build->hp);
    ui->Show_Blood1->setValue(battle->C_Build->hp);
    ui->Show_Blood2->setValue(battle->Build->hp);

    QTimer::connect(timerDetect, SIGNAL(timeout()), this, SLOT(updateBattle()));
    QTimer::connect(timerCountdown, SIGNAL(timeout()), this, SLOT(updateScene()));

    /*Player*/
    for (i=0; i<ARMYNUM; ++i) {
        if (scene->CandidateArr[i]->Pick==true) {
           if (scene->CandidateArr[i]->FirstDeck==true) {
              scene->Deck[DeckNext]=i+1;
              ++DeckNext;
             }
           else {
              scene->Cover[CoverNext]=i+1;
              ++CoverNext;
             }
          }
       }
    /*AI*/
    for (i=0; i<DECKNUM; ++i)
        scene->C_Deck[i]=ai->Deck[i];
    for (i=0; i<COVERNUM; ++i)
        scene->C_Cover[i]=ai->Cover[i];

    QString Stime;
    battle->time=COUNTDOWN+4; //4 seconds for ready
    Stime.setNum((battle->time-4)/60);
    ui->Show_timeMin->setText(Stime);
    Stime.setNum((battle->time-4)%60);
    if ((battle->time-4)%60>=10)
        ui->Show_timeSec->setText(Stime);
    else {
        Stime.prepend("0");
        ui->Show_timeSec->setText(Stime);
      }

    QString Smana;
    Smana.setNum(battle->mana); //player
    ui->Show_MNum2->setText(Smana);
    Smana.setNum(battle->C_mana); //ai
    ui->Show_MNum1->setText(Smana);

    scene->screenMode=2;
    setBg();
}

void MainWindow::setScreenModeThree()
{
    battle->judge();

    QString winner;
    if (battle->winner==2) {
        winner=PlayerName;
        rank->write(PlayerName, battle->time);
       }
    if (battle->winner==1)
        winner="AI";
    if (battle->winner==3)
        winner="(Tie)";
    ui->Show_winner->setText(winner);

    delete timerDetect;
    delete timerCountdown;
    delete battle;
    delete ai;
    timerDetect=NULL;
    timerCountdown=NULL;
    battle=NULL;
    ai=NULL;

    scene->screenMode=3;
    setBg();
}

void MainWindow::setScreenModeRank(bool SeeTable)
{
    int i;

    if (SeeTable==true) {
       rank->read();
       scene->setRankTable(rank);
       ui->Btn_Rank->setText("Home");

       for (i=0; i<ARMYNUM; ++i) {
           delete IntroRange[i];
           IntroRange[i]=NULL;
          }

       scene->screenMode=4;
       setBg();
      }
    else {
       scene->deleteRankTable();
       setScreenModeOne();
      }
}

/****************************************Pause-slot*****************************************/

void MainWindow::ifPause(bool Press)
{
    int i, j, VecSize;
    Minion *Ob;

    if (Press==true) {
       timerCountdown->stop();
       timerDetect->stop();
       ui->Btn_Pause->setText("RESUME");
       ui->Show_pause->setVisible(true);

       ui->Btn_CallR1->setEnabled(false);
       ui->Btn_CallR2->setEnabled(false);
       ui->Btn_CallR3->setEnabled(false);       
       ui->Btn_rolling->setEnabled(false);

       for (i=0; i<LOCATE_LEN; ++i) {
           VecSize=battle->location[i].size();
           for (j=0; j<VecSize; ++j) {
               Ob=battle->location[i].at(j);
               Ob->MoveMovie->setPaused(true);
               Ob->ActMovie->setPaused(true);
              }
          }
       for (i=0; i<LOCATE_LEN; ++i) {
           VecSize=battle->C_location[i].size();
           for (j=0; j<VecSize; ++j) {
               Ob=battle->C_location[i].at(j);
               Ob->MoveMovie->setPaused(true);
               Ob->ActMovie->setPaused(true);
              }
          }
       battle->Build->RestMovie->setPaused(true);
       battle->Build->ActMovie->setPaused(true);
       battle->C_Build->RestMovie->setPaused(true);
       battle->C_Build->RestMovie->setPaused(true);
      }
    else {
       timerCountdown->start(1000);
       timerDetect->start(100);
       ui->Btn_Pause->setText("PAUSE");
       ui->Show_pause->setVisible(false);

       ui->Btn_CallR1->setEnabled(true);
       ui->Btn_CallR2->setEnabled(true);
       ui->Btn_CallR3->setEnabled(true);
       ui->Btn_rolling->setEnabled(true);

       for (i=0; i<LOCATE_LEN; ++i) {
           VecSize=battle->location[i].size();
           for (j=0; j<VecSize; ++j) {
               Ob=battle->location[i].at(j);
               Ob->MoveMovie->setPaused(false);
               Ob->ActMovie->setPaused(false);
              }
          }
       for (i=0; i<LOCATE_LEN; ++i) {
           VecSize=battle->C_location[i].size();
           for (j=0; j<VecSize; ++j) {
               Ob=battle->C_location[i].at(j);
               Ob->MoveMovie->setPaused(false);
               Ob->ActMovie->setPaused(false);
              }
          }
       battle->Build->RestMovie->setPaused(false);
       battle->Build->ActMovie->setPaused(false);
       battle->C_Build->RestMovie->setPaused(false);
       battle->C_Build->RestMovie->setPaused(false);
      }
}

/**********************************************Close Mode************************************************/

void MainWindow::closeScreenModeOne()
{
    ui->Btn_Candidate1->setVisible(false);
    ui->Btn_Candidate2->setVisible(false);
    ui->Btn_Candidate3->setVisible(false);
    ui->Btn_Candidate4->setVisible(false);
    ui->Btn_Candidate5->setVisible(false);
    ui->Btn_Candidate6->setVisible(false);
    ui->Btn_Candidate7->setVisible(false);
    ui->Btn_Candidate8->setVisible(false);

    ui->Btn_Deck1->setVisible(false);
    ui->Btn_Deck2->setVisible(false);
    ui->Btn_Deck3->setVisible(false);
    ui->Btn_Deck4->setVisible(false);
    ui->Btn_Deck5->setVisible(false);
    ui->Btn_Deck6->setVisible(false);
    ui->Btn_Deck7->setVisible(false);
    ui->Btn_Deck8->setVisible(false);

    ui->Btn_Start->setVisible(false);
    ui->Btn_Rank->setVisible(false);

    ui->Edit_Name->setVisible(false);
    ui->Show_Name->setVisible(false);
}

void MainWindow::closeScreenModeTwo()
{
    ui->Btn_CallL1->setVisible(false);
    ui->Btn_CallL2->setVisible(false);
    ui->Btn_CallL3->setVisible(false);
    ui->Btn_CallR1->setVisible(false);
    ui->Btn_CallR2->setVisible(false);
    ui->Btn_CallR3->setVisible(false);

    ui->Btn_Pause->setVisible(false);
    ui->Btn_rolling->setVisible(false);

    ui->Show_AI->setVisible(false);
    ui->Show_player->setVisible(false);
    ui->Show_time->setVisible(false);
    ui->Show_timeMin->setVisible(false);
    ui->Show_timeSec->setVisible(false);
    ui->Show_timeColon->setVisible(false);
    ui->Show_Mana1->setVisible(false);
    ui->Show_Mana2->setVisible(false);
    ui->Show_MNum1->setVisible(false);
    ui->Show_MNum2->setVisible(false);
    ui->Show_pause->setVisible(false);    
    ui->Show_Blood1->setVisible(false);
    ui->Show_Blood2->setVisible(false);
}

void MainWindow::closeScreenModeThree()
{
    ui->Btn_again->setVisible(false);

    ui->Show_judge->setVisible(false);
    ui->Show_winner->setVisible(false);
}

void MainWindow::closeScreenModeRank()
{
    ui->Btn_Rank->setVisible(false);

    ui->Show_rank1->setVisible(false);
    ui->Show_rank2->setVisible(false);
    ui->Show_rank3->setVisible(false);
}

/***********************************************************************************************************************/

void MainWindow::ifFullChosenNum()
{
    if (ChosenNum>=DECKNUM+COVERNUM) {
        if (ui->Btn_Candidate1->isChecked()==false)
            ui->Btn_Candidate1->setEnabled(false);
        if (ui->Btn_Candidate2->isChecked()==false)
            ui->Btn_Candidate2->setEnabled(false);
        if (ui->Btn_Candidate3->isChecked()==false)
            ui->Btn_Candidate3->setEnabled(false);
        if (ui->Btn_Candidate4->isChecked()==false)
            ui->Btn_Candidate4->setEnabled(false);
        if (ui->Btn_Candidate5->isChecked()==false)
            ui->Btn_Candidate5->setEnabled(false);
        if (ui->Btn_Candidate6->isChecked()==false)
            ui->Btn_Candidate6->setEnabled(false);
        if (ui->Btn_Candidate7->isChecked()==false)
            ui->Btn_Candidate7->setEnabled(false);
        if (ui->Btn_Candidate8->isChecked()==false)
            ui->Btn_Candidate8->setEnabled(false);

        if (scene->CandidateArr[0]->Pick==true)
            ui->Btn_Deck1->setVisible(true);
        if (scene->CandidateArr[1]->Pick==true)
            ui->Btn_Deck2->setVisible(true);
        if (scene->CandidateArr[2]->Pick==true)
            ui->Btn_Deck3->setVisible(true);
        if (scene->CandidateArr[3]->Pick==true)
            ui->Btn_Deck4->setVisible(true);
        if (scene->CandidateArr[4]->Pick==true)
            ui->Btn_Deck5->setVisible(true);
        if (scene->CandidateArr[5]->Pick==true)
            ui->Btn_Deck6->setVisible(true);
        if (scene->CandidateArr[6]->Pick==true)
            ui->Btn_Deck7->setVisible(true);
        if (scene->CandidateArr[7]->Pick==true)
            ui->Btn_Deck8->setVisible(true);
      }
    else {
        ui->Btn_Candidate1->setEnabled(true);
        ui->Btn_Candidate2->setEnabled(true);
        ui->Btn_Candidate3->setEnabled(true);
        ui->Btn_Candidate4->setEnabled(true);
        ui->Btn_Candidate5->setEnabled(true);
        ui->Btn_Candidate6->setEnabled(true);
        ui->Btn_Candidate7->setEnabled(true);
        ui->Btn_Candidate8->setEnabled(true);

        ui->Btn_Deck1->setVisible(false);
        ui->Btn_Deck2->setVisible(false);
        ui->Btn_Deck3->setVisible(false);
        ui->Btn_Deck4->setVisible(false);
        ui->Btn_Deck5->setVisible(false);
        ui->Btn_Deck6->setVisible(false);
        ui->Btn_Deck7->setVisible(false);
        ui->Btn_Deck8->setVisible(false);

        ui->Btn_Deck1->setChecked(false);
        ui->Btn_Deck2->setChecked(false);
        ui->Btn_Deck3->setChecked(false);
        ui->Btn_Deck4->setChecked(false);
        ui->Btn_Deck5->setChecked(false);
        ui->Btn_Deck6->setChecked(false);
        ui->Btn_Deck7->setChecked(false);
        ui->Btn_Deck8->setChecked(false);

        DeckNum=0;
    }
}

void MainWindow::ifFullDeckNum()
{
    if (DeckNum>=DECKNUM) {
        if (ui->Btn_Deck1->isChecked()==false)
            ui->Btn_Deck1->setEnabled(false);
        if (ui->Btn_Deck2->isChecked()==false)
            ui->Btn_Deck2->setEnabled(false);
        if (ui->Btn_Deck3->isChecked()==false)
            ui->Btn_Deck3->setEnabled(false);
        if (ui->Btn_Deck4->isChecked()==false)
            ui->Btn_Deck4->setEnabled(false);
        if (ui->Btn_Deck5->isChecked()==false)
            ui->Btn_Deck5->setEnabled(false);
        if (ui->Btn_Deck6->isChecked()==false)
            ui->Btn_Deck6->setEnabled(false);
        if (ui->Btn_Deck7->isChecked()==false)
            ui->Btn_Deck7->setEnabled(false);
        if (ui->Btn_Deck8->isChecked()==false)
            ui->Btn_Deck8->setEnabled(false);
      }
    else {
        ui->Btn_Deck1->setEnabled(true);
        ui->Btn_Deck2->setEnabled(true);
        ui->Btn_Deck3->setEnabled(true);
        ui->Btn_Deck4->setEnabled(true);
        ui->Btn_Deck5->setEnabled(true);
        ui->Btn_Deck6->setEnabled(true);
        ui->Btn_Deck7->setEnabled(true);
        ui->Btn_Deck8->setEnabled(true);
    }
}


