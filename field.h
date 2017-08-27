#ifndef FIELD_H
#define FIELD_H

#include "cell.h"
#include "PosOb.h"
#include "player.h"
#include "YellowBox.h"
#include <fstream>
#include <string>
#include <conio.h>


class Field
{
public:
    Field();
    ~Field();
    void Print();
    void Comand();
    bool GetPosPasible(int,int);
    int GetN();
    int GetM();
    int GetK();
    bool GetEGF();
    void Intro();
    void Outro();
    void ReversStep();
private:
    void input();
    void delGame();
    Cell ***board;
    int n,m,k; //Вертиаль, горизонталь, ящики
    Player *pl; // Игрок
    YellowBox **boxes; // Ящики
    bool end_game_flag;
    bool *boxInPosFlag;
};

#endif // FIELD_H
