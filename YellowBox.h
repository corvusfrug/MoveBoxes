#ifndef YELLOWBOX_H
#define YELLOWBOX_H

#include "PosOb.h"

//HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE); // Для цвету

class YellowBox : public PosOb
{
public:
    YellowBox(int,int,YellowBox* _prev = NULL);
    ~YellowBox();
    void Print();
    void BMove(char);
    int GetX();
    int GetY();
    bool GetInPos();
    void SetInPos(bool);
    YellowBox* GetPrev();
private:
    int x,y;
    bool inPos;
    YellowBox* prev;

};

#endif // YELLOWBOX_H
