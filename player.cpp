#include "player.h"

HANDLE hStdOut2 = GetStdHandle(STD_OUTPUT_HANDLE); // Для цвету

Player::Player(int _x,int _y, Player * _prev, char _azimut,int _score, char _img)
{
    img=_img;
    score=_score;
    x=_x;
    y=_y;
    prev = _prev;
    azimut=_azimut;
    passable=true;
}
Player::~Player(){}
void Player::PMove(char comand)
{
    if(azimut==comand)
        switch(comand)
        {
        case 'U': // UP
            y--;
            score++;
            break;
        case 'D': // DOWN
            y++;
            score++;
            break;
        case 'L': // LEFT
            x--;
            score++;
            break;
        case 'R': // RIGHT
            x++;
            score++;
            break;
        default: break;
        }
    else switch(comand)
        {
        case 'U': // UP
            azimut=comand;
            img=static_cast<char>(30);
            break;
        case 'D': // DOWN
            azimut=comand;
            img=static_cast<char>(31);
            break;
        case 'L': // LEFT
            azimut=comand;
            img=static_cast<char>(17);
            break;
        case 'R': // RIGHT
            azimut=comand;
            img=static_cast<char>(16);
            break;
        default: break;
        };
    //cout << "MOVE!!!\n";
}
int Player::GetX(){return x;}
int Player::GetY(){return y;}
char Player::GetAzimut(){return azimut;}
int Player::GetScore(){return score;}
void Player::Print()
{
    SetConsoleTextAttribute(hStdOut2,13);
    cout << img;
    SetConsoleTextAttribute(hStdOut2,7);
}
//Player* Player::GetPrev() {return prev;}
/*

Стрелочки:
Вверх  - 30
Вниз   - 31
Влево  - 17
Вправо - 16

*/
