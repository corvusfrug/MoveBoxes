#include "YellowBox.h"

HANDLE hStdOut3 = GetStdHandle(STD_OUTPUT_HANDLE); // Äëÿ öâåòó

YellowBox::YellowBox(int _x,int _y,YellowBox* _prev)
{
    img='Q';
    x=_x;
    y=_y;
    prev = _prev;
    inPos=false;
    passable=true;
}
YellowBox::~YellowBox(){}
void YellowBox::Print()
{
    if(inPos) SetConsoleTextAttribute(hStdOut3,4);
        else SetConsoleTextAttribute(hStdOut3,14);
    cout << img;
    SetConsoleTextAttribute(hStdOut3,7);
}
void YellowBox::BMove(char comand)
{
        switch(comand)
        {
        case 'U': // UP
            y--;
            //return true;
            break;
        case 'D': // DOWN
            y++;
            break;
        case 'L': // LEFT
            x--;
            break;
        case 'R': // RIGHT
            x++;
            break;
        default: break;
        }

    cout << "ÒÎËÊÀÅÌ ßÙÈÊ!!!\n";
}
int YellowBox::GetX(){return x;}
int YellowBox::GetY(){return y;}
bool YellowBox::GetInPos() {return inPos;}
void YellowBox::SetInPos(bool b) {inPos=b;}
YellowBox* YellowBox::GetPrev() {return prev;}
