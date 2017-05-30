#ifndef AI_H
#define AI_H

#include <ctime>
#include <cstdbool>
#include <iostream>

#define DECKNUM 3
#define COVERNUM 3
#define ARMYNUM 8
#define UNIT 10

class AI
{
public:
    int Deck[DECKNUM];
    int Cover[COVERNUM];
    int Pick;
    int ManaCost[ARMYNUM];

    bool hold;  //waiting for mana increasing

    AI(int*);
    int response(int);
};

#endif // AI_H
