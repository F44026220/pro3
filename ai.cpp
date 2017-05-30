#include "ai.h"

AI::AI(int *ManaCostInfo)
{
    int i, Candidate[ARMYNUM]={1,1,1,1,1,1,1,1}, Pick;

    for (i=0; i<ARMYNUM; ++i)
        ManaCost[i]=ManaCostInfo[i];

    for (i=0; i<DECKNUM; ++i) {
        srand(time(NULL));
        Pick=rand()%ARMYNUM;
        while (Candidate[Pick]==0) {
           Pick += 1;
           if (Pick>=8)
               Pick=0;
          }
        Deck[i]=Pick+1;
        Candidate[Pick]=0;
       }
    for (i=0; i<COVERNUM; ++i) {
        srand(time(NULL));
        Pick=rand()%ARMYNUM;
        while (Candidate[Pick]==0) {
           Pick += 1;
           if (Pick>=8)
               Pick=0;
          }
        Cover[i]=Pick+1;
        Candidate[Pick]=0;
       }
}

int AI::response(int CurrentMana)
{
    if (hold==false) {
        srand(time(NULL));
        Pick=rand()%DECKNUM;
        if (CurrentMana>=ManaCost[Deck[Pick]-1]) {
            hold=false;
            return Deck[Pick];
          }
        else {
           hold=true;
           return 0;
          }
      }
    else {
        if (CurrentMana>=ManaCost[Deck[Pick]-1]) {
            hold=false;
            return Deck[Pick];
          }
        else {
           hold=true;
           return 0;
          }
      }
}



