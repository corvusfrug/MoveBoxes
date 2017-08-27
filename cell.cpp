#include "cell.h"


Cell::Cell()
{
    img=' ';
    //boxHere=false;
}
Cell::Cell(char x)
{
    img=x;
}
Cell::~Cell(){}
void Cell::Print()
{
    cout << img;
}
char Cell::GetImg(){return img;}
bool Cell::GetPasible(){return true;}
bool Cell::GetBoxHere(){return true;}
void Cell::SetBoxHere(bool b){}
