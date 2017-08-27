#include <iostream>
#include "field.h"

using std::cin;
using std::cout;
using std::endl;

int main(int argv, char* argc[])
{
    Field MyGame;
    MyGame.Intro();
    while(!MyGame.GetEGF())
    {
        MyGame.Print();
        MyGame.Comand();
        //Sleep(100); // DEL
    };
    return 0;
}
