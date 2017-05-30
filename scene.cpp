#include "scene.h"

Scene::Scene()
{
    int i;

    Ready=NULL;
    Intro=NULL;
    for (i=0; i<ARMYNUM; ++i)
        CandidateArr[i]=NULL;
    for (i=0; i<DECKNUM; ++i)
        MinionArr[i]=NULL;
    for (i=0; i<DECKNUM; ++i)
        C_MinionArr[i]=NULL;
    for (i=0; i<RANKNUM; ++i)
        Namelb[i]=NULL;
    for (i=0; i<RANKNUM; ++i)
        Timelb[i]=NULL;
    for (i=0; i<RANKNUM; ++i)
        Ranklb[i]=NULL;

    pathCandidateArr[0]=":/normal.png";
    pathCandidateArr[1]=":/V.png";
    pathCandidateArr[2]=":/japan.png";
    pathCandidateArr[3]=":/bird.png";
    pathCandidateArr[4]=":/horse.png";
    pathCandidateArr[5]=":/dancer.png";
    pathCandidateArr[6]=":/fat.png";
    pathCandidateArr[7]=":/god.png";

    pathIntroArr[0]=":/Intro_norm.png";
    pathIntroArr[1]=":/Intro_V.png";
    pathIntroArr[2]=":/Intro_japan.png";
    pathIntroArr[3]=":/Intro_bird.png";
    pathIntroArr[4]=":/Intro_horse.png";
    pathIntroArr[5]=":/Intro_dancer.png";
    pathIntroArr[6]=":/Intro_fat.png";
    pathIntroArr[7]=":/Intro_god.png";

    pathReadyArr[0]=":/start.png";
    pathReadyArr[1]=":/1.png";
    pathReadyArr[2]=":/2.png";
    pathReadyArr[3]=":/3.png";

    pathMoveArr[0]=":/play_normalham.gif";
    pathMoveArr[1]=":/play_Vham.gif";
    pathMoveArr[2]=":/play_Japanham.gif";
    pathMoveArr[3]=":/play_birdham.gif";
    pathMoveArr[4]=":/play_horseham.gif";
    pathMoveArr[5]=":/play_dancerham.gif";
    pathMoveArr[6]=":/play_fatham.gif";
    pathMoveArr[7]=":/play_godham.gif";
    pathActArr[0]=":/play_normalact.gif";
    pathActArr[1]=":/play_Vact.gif";
    pathActArr[2]=":/play_Japanact.gif";
    pathActArr[3]=":/play_birdact.gif";
    pathActArr[4]=":/play_horseact.gif";
    pathActArr[5]=":/play_danceract.gif";
    pathActArr[6]=":/play_fatact.gif";
    pathActArr[7]=":/play_godact.gif";

    C_pathMoveArr[0]=":/ai_normalham.gif";
    C_pathMoveArr[1]=":/ai_Vham.gif";
    C_pathMoveArr[2]=":/ai_Japanham.gif";
    C_pathMoveArr[3]=":/ai_birdham.gif";
    C_pathMoveArr[4]=":/ai_horseham.gif";
    C_pathMoveArr[5]=":/ai_dancerham.gif";
    C_pathMoveArr[6]=":/ai_fatham.gif";
    C_pathMoveArr[7]=":/ai_godham.gif";
    C_pathActArr[0]=":/ai_normalact.gif";
    C_pathActArr[1]=":/ai_Vact.gif";
    C_pathActArr[2]=":/ai_Japanact.gif";
    C_pathActArr[3]=":/ai_birdact.gif";
    C_pathActArr[4]=":/ai_horseact.gif";
    C_pathActArr[5]=":/ai_danceract.gif";
    C_pathActArr[6]=":/ai_fatact.gif";
    C_pathActArr[7]=":/ai_godact.gif";
}

Scene::~Scene()
{
    int i;

    delete Ready;
    delete Intro;
    for (i=0; i<ARMYNUM; ++i)
        delete CandidateArr[i];
    for (i=0; i<DECKNUM; ++i)
        delete MinionArr[i];
    for (i=0; i<DECKNUM; ++i)
        delete C_MinionArr[i];
    for (i=0; i<RANKNUM; ++i)
        delete Namelb[i];
    for (i=0; i<RANKNUM; ++i)
        delete Timelb[i];
    for (i=0; i<RANKNUM; ++i)
        delete Ranklb[i];
}

void Scene::ScreenModeOne()
{
    int i, y_mod=75, Side=78;
    QPixmap man;

    for (i=0; i<ARMYNUM; ++i) {
        CandidateArr[i]=new Army();
        man.load(pathCandidateArr[i]);
        man = man.scaled(Side,Side);
        CandidateArr[i]->setPixmap(man);
        CandidateArr[i]->setPos(posCandidateArr[i].x(),posCandidateArr[i].y()-y_mod);
        this->addItem(CandidateArr[i]);

        CandidateArr[i]->Pick=false;
        CandidateArr[i]->FirstDeck=false;
       }   
}

void Scene::ScreenModeTwo()
{
    int i, y_mod=75, Side=78;
    QPixmap man;

    for (i=0; i<ARMYNUM; ++i) {
        delete CandidateArr[i];
        CandidateArr[i]=NULL;
       }
    delete Intro;
    Intro=NULL;

    Ready=new QGraphicsPixmapItem();
    this->addItem(Ready);

    /*AI*/
    for (i=0; i<DECKNUM; ++i) {
        C_MinionArr[i]=new QGraphicsPixmapItem();
        man.load(pathCandidateArr[C_Deck[i]-1]);
        man = man.scaled(Side,Side);
        C_MinionArr[i]->setPixmap(man);
        C_MinionArr[i]->setPos(posCallLeftArr[i].x(),posCallLeftArr[i].y()-y_mod);
        this->addItem(C_MinionArr[i]);
       }
    /*Player*/
    for (i=0; i<DECKNUM; ++i) {
        MinionArr[i]=new QGraphicsPixmapItem();
        man.load(pathCandidateArr[Deck[i]-1]);
        man = man.scaled(Side,Side);
        MinionArr[i]->setPixmap(man);
        MinionArr[i]->setPos(posCallRightArr[i].x(),posCallRightArr[i].y()-y_mod);
        this->addItem(MinionArr[i]);
       }
}

void Scene::ScreenModeThree()
{
    int i;

    for (i=0; i<DECKNUM; ++i) {
        delete MinionArr[i];
        MinionArr[i]=NULL;
       }
    for (i=0; i<DECKNUM; ++i) {
        delete C_MinionArr[i];
        C_MinionArr[i]=NULL;
       }
}

void Scene::ScreenModeRank()
{
    int i, bias=35, gap=5, width=100, height=30;
    int x_rank=posRankArr[0].x(), x_name=posRankArr[1].x(), x_time=posRankArr[2].x();
    int y_start=posRankArr[0].y();
    QFont font;

    for (i=0; i<ARMYNUM; ++i) {
        delete CandidateArr[i];
        CandidateArr[i]=NULL;
       }

    for (i=0; i<RANKNUM; ++i) {
        if (Ranklb[i]!=NULL) {
           Ranklb[i]->setGeometry(x_rank, y_start+bias+i*(gap+height), width, height);
           font=Ranklb[i]->font();
           font.setPixelSize(20);
           Ranklb[i]->setFont(font);
           this->addWidget(Ranklb[i]);
          }
        if (Namelb[i]!=NULL) {
           Namelb[i]->setGeometry(x_name, y_start+bias+i*(gap+height), width, height);
           font=Namelb[i]->font();
           font.setPixelSize(20);
           Namelb[i]->setFont(font);
           this->addWidget(Namelb[i]);
          }
        if (Timelb[i]!=NULL) {
           Timelb[i]->setGeometry(x_time, y_start+bias+i*(gap+height), width, height);
           font=Timelb[i]->font();
           font.setPixelSize(20);
           Timelb[i]->setFont(font);
           this->addWidget(Timelb[i]);
          }
       }
}

void Scene::setDeck(int pos)
{
    int Side=78, Insert;
    QPixmap man;

    srand(time(NULL));
    Insert=rand()%COVERNUM;

    Deck[pos]=Cover[Insert];
    Cover[Insert]=Call;

    man.load(pathCandidateArr[Deck[pos]-1]);
    man = man.scaled(Side,Side);
    MinionArr[pos]->setPixmap(man);
}

void Scene::setDeckcp(int pos)
{
    int Side=78, Insert;
    QPixmap man;

    srand(time(NULL));
    Insert=rand()%COVERNUM;

    C_Deck[pos]=C_Cover[Insert];
    C_Cover[Insert]=C_Call;

    man.load(pathCandidateArr[C_Deck[pos]-1]);
    man = man.scaled(Side,Side);
    C_MinionArr[pos]->setPixmap(man);
}

void Scene::ready(int i)
{
    int width, height;
    QPixmap pic;

    pic.load(pathReadyArr[i]);
    width=pic.width();
    height=pic.height();
    Ready->setPixmap(pic);
    Ready->setPos(SCENE_WIDTH/2-width/2,SCENE_HEIGHT/2-height/2);
}

void Scene::addMinion(Minion* & CH)
{
    int width, height;
    QPixmap pic;

    if (CH->group==1) { //ai
        pic.load(C_pathMoveArr[CH->WhichCh-1]);
        width=pic.width()/3;
        height=pic.height()/3;
        CH->MoveMovie->setFileName(C_pathMoveArr[CH->WhichCh-1]);
        CH->MoveMovie->setScaledSize(QSize(width,height));

        pic.load(C_pathActArr[CH->WhichCh-1]);
        width=pic.width()/3;
        height=pic.height()/3;
        CH->ActMovie->setFileName(C_pathActArr[CH->WhichCh-1]);
        CH->ActMovie->setScaledSize(QSize(width,height));
      }
    else { //player
        pic.load(pathMoveArr[CH->WhichCh-1]);
        width=pic.width()/3;
        height=pic.height()/3;
        CH->MoveMovie->setFileName(pathMoveArr[CH->WhichCh-1]);
        CH->MoveMovie->setScaledSize(QSize(width,height));

        pic.load(pathActArr[CH->WhichCh-1]);
        width=pic.width()/3;
        height=pic.height()/3;
        CH->ActMovie->setFileName(pathActArr[CH->WhichCh-1]);
        CH->ActMovie->setScaledSize(QSize(width,height));
      }

    CH->setAttribute(Qt::WA_NoSystemBackground);
    CH->setMovie(CH->MoveMovie);
    CH->MoveMovie->start();

    this->addWidget(CH);
    this->addWidget(CH->Blood);
}

void Scene::setMinionPos(Minion* & CH)
{
    int start_x=100, pos_y=600, width, height;
    int BW=128, BH=18;
    QPixmap pic;

    if (CH->group==1) { //ai
       if (CH->Acting==false)
          pic.load(C_pathMoveArr[CH->WhichCh-1]);
       else
          pic.load(C_pathActArr[CH->WhichCh-1]);
       width=pic.width()/3;
       height=pic.height()/3;
       CH->setGeometry(start_x + CH->DisFromHome - width/2, pos_y - height, width+2, height+2);
       CH->Blood->setGeometry(start_x + CH->DisFromHome - BW/2, pos_y - height - BH - 20, BW, BH);
      }
    else { //player
       if (CH->Acting==false)
          pic.load(pathMoveArr[CH->WhichCh-1]);
       else
          pic.load(pathActArr[CH->WhichCh-1]);
       width=pic.width()/3;
       height=pic.height()/3;
       CH->setGeometry(SCENE_WIDTH - start_x - CH->DisFromHome - width/2, pos_y - height, width+2, height+2);
       CH->Blood->setGeometry(SCENE_WIDTH - start_x - CH->DisFromHome - BW/2, pos_y - height - BH - 20, BW, BH);
      }
}

void Scene::setMinionAct(Minion* & CH)
{
    if (CH->Acting==true && CH->Acting != CH->LastActing) {
        CH->MoveMovie->stop();
        CH->setMovie(CH->ActMovie);
        CH->ActMovie->start();
      }
    if (CH->Acting==false && CH->Acting != CH->LastActing) {
        CH->ActMovie->stop();
        CH->setMovie(CH->MoveMovie);
        CH->MoveMovie->start();
      }
}

void Scene::setCastleAct(Castle* & Build)
{
    if (Build->Acting==true && Build->Acting != Build->LastActing) {
        Build->RestMovie->stop();
        Build->setMovie(Build->ActMovie);
        Build->ActMovie->start();
      }
    if (Build->Acting==false && Build->Acting != Build->LastActing) {
        Build->ActMovie->stop();
        Build->setMovie(Build->RestMovie);
        Build->RestMovie->start();
      }
}

void Scene::addCastle(Castle* & Build, Castle* & C_Build) //1 for ai; 2 for player.
{
    int SideBuildH=200, SideBuildW=100, pos_x=50, pos_y=400;

    Build->RestMovie->setFileName(":/play_cas.gif");
    Build->ActMovie->setFileName(":/play_cas_act.gif");
    C_Build->RestMovie->setFileName(":/ai_cas.gif");
    C_Build->ActMovie->setFileName(":/ai_cas_act.gif");
    Build->RestMovie->setScaledSize(QSize(SideBuildW,SideBuildH));
    Build->ActMovie->setScaledSize(QSize(SideBuildW,SideBuildH));
    C_Build->RestMovie->setScaledSize(QSize(SideBuildW,SideBuildH));
    C_Build->ActMovie->setScaledSize(QSize(SideBuildW,SideBuildH));

    Build->setAttribute(Qt::WA_NoSystemBackground);
    C_Build->setAttribute(Qt::WA_NoSystemBackground);
    Build->setMovie(Build->RestMovie);
    C_Build->setMovie(C_Build->RestMovie);
    Build->RestMovie->start();
    C_Build->RestMovie->start();

    Build->setGeometry(SCENE_WIDTH-pos_x-SideBuildW, pos_y, SideBuildW+2, SideBuildH+2);
    C_Build->setGeometry(pos_x, pos_y, SideBuildW+2, SideBuildH+2);

    this->addWidget(Build);
    this->addWidget(C_Build);
}

void Scene::setRankTable(Rank* & rank)
{
    int i;
    QString STime_min, STime_sec, SRank;

    for (i=0; i<rank->PlayerNum; ++i) {
        Namelb[i]=new QLabel();
        Namelb[i]->setText(rank->Name[i]);
       }
    for (i=0; i<rank->PlayerNum; ++i) {
        Timelb[i]=new QLabel();
        STime_min.setNum(rank->Time[i]/60);
        STime_sec.setNum(rank->Time[i]%60);
        if (rank->Time[i]%60<10)
           STime_sec.prepend("0");
        Timelb[i]->setText('0'+STime_min+':'+STime_sec);
       }
    for (i=0; i<rank->PlayerNum; ++i) {
        Ranklb[i]=new QLabel();
        SRank.setNum(i+1);
        Ranklb[i]->setText(SRank);
       }
}

void Scene::deleteRankTable()
{
    int i;

    for (i=0; i<RANKNUM; ++i) {
        delete Namelb[i];
        Namelb[i]=NULL;
       }
    for (i=0; i<RANKNUM; ++i) {
        delete Timelb[i];
        Timelb[i]=NULL;
       }
    for (i=0; i<RANKNUM; ++i) {
        delete Ranklb[i];
        Ranklb[i]=NULL;
       }
}


/****************************************Intro-slot*********************************************/
void Scene::chIntro1(bool show)
{
    int x=600, y=100, Side=450;
    QPixmap man;

    if (show==true) {
        Intro=new QGraphicsPixmapItem();
        man.load(pathIntroArr[0]);
        man = man.scaled(Side,Side);
        Intro->setPixmap(man);
        Intro->setPos(x,y);
        this->addItem(Intro);
       }
     else
       {
        delete Intro;
        Intro=NULL;
       }
}

void Scene::chIntro2(bool show)
{
    int x=600, y=100, Side=450;
    QPixmap man;

    if (show==true) {
        Intro=new QGraphicsPixmapItem();
        man.load(pathIntroArr[1]);
        man = man.scaled(Side,Side);
        Intro->setPixmap(man);
        Intro->setPos(x,y);
        this->addItem(Intro);
       }
     else
       {
        delete Intro;
        Intro=NULL;
       }
}

void Scene::chIntro3(bool show)
{
    int x=600, y=100, Side=450;
    QPixmap man;

    if (show==true) {
        Intro=new QGraphicsPixmapItem();
        man.load(pathIntroArr[2]);
        man = man.scaled(Side,Side);
        Intro->setPixmap(man);
        Intro->setPos(x,y);
        this->addItem(Intro);
       }
     else
       {
        delete Intro;
        Intro=NULL;
       }
}

void Scene::chIntro4(bool show)
{
    int x=600, y=100, Side=450;
    QPixmap man;

    if (show==true) {
        Intro=new QGraphicsPixmapItem();
        man.load(pathIntroArr[3]);
        man = man.scaled(Side,Side);
        Intro->setPixmap(man);
        Intro->setPos(x,y);
        this->addItem(Intro);
       }
     else
       {
        delete Intro;
        Intro=NULL;
       }
}

void Scene::chIntro5(bool show)
{
    int x=600, y=100, Side=450;
    QPixmap man;

    if (show==true) {
        Intro=new QGraphicsPixmapItem();
        man.load(pathIntroArr[4]);
        man = man.scaled(Side,Side);
        Intro->setPixmap(man);
        Intro->setPos(x,y);
        this->addItem(Intro);
       }
     else
       {
        delete Intro;
        Intro=NULL;
       }
}

void Scene::chIntro6(bool show)
{
    int x=600, y=100, Side=450;
    QPixmap man;

    if (show==true) {
        Intro=new QGraphicsPixmapItem();
        man.load(pathIntroArr[5]);
        man = man.scaled(Side,Side);
        Intro->setPixmap(man);
        Intro->setPos(x,y);
        this->addItem(Intro);
       }
     else
       {
        delete Intro;
        Intro=NULL;
       }
}

void Scene::chIntro7(bool show)
{
    int x=600, y=100, Side=450;
    QPixmap man;

    if (show==true) {
        Intro=new QGraphicsPixmapItem();
        man.load(pathIntroArr[6]);
        man = man.scaled(Side,Side);
        Intro->setPixmap(man);
        Intro->setPos(x,y);
        this->addItem(Intro);
       }
     else
       {
        delete Intro;
        Intro=NULL;
       }
}

void Scene::chIntro8(bool show)
{
    int x=600, y=100, Side=450;
    QPixmap man;

    if (show==true) {
        Intro=new QGraphicsPixmapItem();
        man.load(pathIntroArr[7]);
        man = man.scaled(Side,Side);
        Intro->setPixmap(man);
        Intro->setPos(x,y);
        this->addItem(Intro);
       }
     else
       {
        delete Intro;
        Intro=NULL;
       }
}















