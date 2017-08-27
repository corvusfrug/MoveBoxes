#ifndef PLAYER_H
#define PLAYER_H

#include "PosOb.h"

class Player : public PosOb
{
public:
    Player(int,int,Player* _prev = NULL, char _azimut='U',int _score=0, char _img = static_cast<char>(30));
    ~Player();
    void PMove(char);
    int GetX();
    int GetY();
    int GetScore();
    char GetAzimut();
    void Print();
    //Player* GetPrev();
    Player *prev;

private:
    int x,y;
    char azimut;
    int score;
    //Player *prev;
};

#endif // PLAYER_H
