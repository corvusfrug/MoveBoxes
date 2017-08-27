#ifndef CELL_H
#define CELL_H

#include <iostream>
using std::cin;
using std::cout;
using std::endl;


class Cell
{
    public:
        Cell();
        Cell(char);
        virtual ~Cell();
        virtual void Print();
        virtual char GetImg();
        virtual bool GetPasible();
        virtual bool GetBoxHere();
        virtual void SetBoxHere(bool);
    protected:
        char img;
        //bool boxHere;
};

#endif // CELL_H
