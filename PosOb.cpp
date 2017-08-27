#include "PosOb.h"
//#include <Windows.h>

HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE); // Для цвету

PosOb::PosOb()
{
    img=' ';
    passable=true;
    boxHere=false;
}
bool PosOb::GetPasible(){return passable;}
PosOb::PosOb(char x)
{
    img=x;
    boxHere=false;
    switch(x)
    {
        case ' ': passable=true; break;
        case 'X': passable=false; break;
        case 'T': passable=false; break;
        case 'W': passable=false; break;
        case 'O': passable=true; break;
        //case 'P': passable=true; break;
        //case 'Q': passable=true; break;
        default : passable=false; break;
    };
}
void PosOb::Print()
{
    SetConsoleTextAttribute(hStdOut,5);
    if(img=='T') SetConsoleTextAttribute(hStdOut,2);
    if(img=='O') SetConsoleTextAttribute(hStdOut,4);
    if(img=='W') SetConsoleTextAttribute(hStdOut,9);
    if(img=='Q') SetConsoleTextAttribute(hStdOut,14);
    if(img=='P') SetConsoleTextAttribute(hStdOut,13);
    if(img=='X') SetConsoleTextAttribute(hStdOut,7);
    //if(img==' ') cout << boxHere; else cout << img;
    cout << img;
    SetConsoleTextAttribute(hStdOut,7);
}
bool PosOb::GetBoxHere(){return boxHere;}
void PosOb::SetBoxHere(bool b){boxHere=b;}
PosOb::~PosOb(){}
