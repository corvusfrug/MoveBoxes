#ifndef POSOB_H
#define POSOB_H

#include <Windows.h>
#include "cell.h"
//#include "field.h"

//HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE); // Для цвету

class PosOb : public Cell
{
public:
    PosOb();
    PosOb(char);
    virtual void Print();
    ~PosOb();
    bool GetPasible();
    bool GetBoxHere();
    void SetBoxHere(bool);
    //friend class Field;
protected:
    bool passable;
    bool boxHere;
};

#endif // POSOB_H
