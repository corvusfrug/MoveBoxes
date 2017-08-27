#include "field.h"
//#include <string>

using std::ifstream;
using std::ofstream;
using std::string;
Field::Field()
{
    input();
}
void Field::input()
{
     /*try{
    ifstream readF("map.txt");
        throw "FILE NOT OPEN!!!";
    }
    catch(string s) {cout << s << endl;};*/
    ifstream readF("map.txt");
    readF >> n >> m >> k;
    setlocale(LC_ALL, "Russian");
    end_game_flag=false;
    //cout << n <<" !!!! " << m << "  !! " << k << endl;
    boxes=new YellowBox* [k];
    boxInPosFlag = new bool [k];
    for(int i=0;i<k;++i) boxInPosFlag[i]=false;
    board = new Cell** [n];
    for(int i=0;i<n;++i)
        board[i]=new Cell* [m];

    string temp;
    int temp_int=0;
    getline(readF,temp);
    for(int i=0;i<n;i++)
    {
       getline(readF,temp);
       for(int j=0;j<m;j++)
       {
           if(temp[j]=='P')
           {
               board[i][j] = new PosOb(' ');
               pl = new Player(j,i);
           }
           else if(temp[j]=='Q')
                {
                    board[i][j] = new PosOb(' ');
                    board[i][j]->SetBoxHere(true);
                    boxes[temp_int++] = new YellowBox(j,i);
                }
                else board[i][j] = new PosOb(temp[j]);
       };
    };
}
Field::~Field()
{
    delGame();
}
void Field::delGame()
{
    for(int i=0;i<n;++i)
        delete board[i];
    delete board;
    for(int i=0;i<k;++i)
        delete boxes[i];
    delete boxes;
    delete pl;
}
void Field::Print()
{
    system("cls");
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
            if((i==pl->GetY())&&(j==pl->GetX())) pl->Print();
            else
            {
                bool temp_flag=false;
                for(int t=0;t<k;t++)
                  if((i==boxes[t]->GetY())&&(j==boxes[t]->GetX()))
                  {
                      boxes[t]->Print();
                      temp_flag=true;
                      break;
                  };
                  if(!temp_flag) board[i][j]->Print();
            }
        cout << endl;
    };
    cout << endl;
    cout << "���� ����: " << pl->GetScore() << endl;
}
bool Field::GetPosPasible(int x,int y)
{
    return board[y][x]->GetPasible();
}
int Field::GetN(){return n;}
int Field::GetM(){return m;}
int Field::GetK(){return k;}
bool Field::GetEGF(){return end_game_flag;}
void Field::Comand()
{
    int temp_comand = _getch();
    if(temp_comand==224) temp_comand = _getch();
    if(temp_comand==26) {ReversStep(); return;};
    if(temp_comand==27) {Outro(); return;};
    if(temp_comand==170||temp_comand==138||temp_comand==114||temp_comand==82)
    {
        delGame();
        input();
        return;
    };
    switch(temp_comand)
    {
    case 230: ;// UP
    case 119: ;// UP
    case 87:  ;// UP
    case 150: ;// UP
    case 72:
        if((board[pl->GetY()-1][pl->GetX()]->GetPasible()))          // ������ ���������?
        {
            if((board[pl->GetY()-1][pl->GetX()]->GetBoxHere()))      // ������� ���� ����?
            {
                if((board[pl->GetY()-2][pl->GetX()]->GetPasible())&& // ��� ����� ��������?
                   (pl->GetAzimut()=='U')&&                          // �������� � ������� �����?
                   (!board[pl->GetY()-2][pl->GetX()]->GetBoxHere())) // �� ���� ���� ������ ����?
                {
                    int j=0;
                    while(1)
                    {
                        if((pl->GetY()-1==boxes[j]->GetY())&&
                           (pl->GetX()==boxes[j]->GetX())) break;
                        j++;
                    };
                    cout << "�����!" << endl;
                    boxes[j]->BMove('U');
                    board[pl->GetY()-1][pl->GetX()]->SetBoxHere(false);
                    board[pl->GetY()-2][pl->GetX()]->SetBoxHere(true);
                    if(board[pl->GetY()-2][pl->GetX()]->GetImg()=='O') {boxes[j]->SetInPos(true);boxInPosFlag[j]=true;}
                        else {boxes[j]->SetInPos(false);boxInPosFlag[j]=false;};
                    Player* tempPlayer;//
                    tempPlayer = new Player(pl->GetX(),pl->GetY(),pl,pl->GetAzimut(),pl->GetScore(),pl->GetImg());//
                    pl=tempPlayer;//
                    pl->PMove('U');
                    //pl->PMove('U');
                } else if(pl->GetAzimut()=='U')
                            cout << "���� ��������!" << endl;
                        else {cout << "�����!" << endl;
                                Player* tempPlayer;//
                                tempPlayer = new Player(pl->GetX(),pl->GetY(),pl,pl->GetAzimut(),pl->GetScore(),pl->GetImg());//
                                pl=tempPlayer;//
                                pl->PMove('U');};
            } else {cout << "�����!" << endl;
                        Player* tempPlayer;//
                        tempPlayer = new Player(pl->GetX(),pl->GetY(),pl,pl->GetAzimut(),pl->GetScore(),pl->GetImg());//
                        pl=tempPlayer;//
                        pl->PMove('U');};
        } else if(pl->GetAzimut()=='U')
                    cout << "���� ��������!" << endl;
               else {cout << "�����!" << endl;
                        Player* tempPlayer;//
                        tempPlayer = new Player(pl->GetX(),pl->GetY(),pl,pl->GetAzimut(),pl->GetScore(),pl->GetImg());//
                        pl=tempPlayer;//
                        pl->PMove('U');};
        break;
    case 235: ;// DOWN
    case 115: ;// DOWN
    case 83:  ;// DOWN
    case 155: ;// DOWN
    case 80:
        if((board[pl->GetY()+1][pl->GetX()]->GetPasible()))          // ���� ���������?
        {
            if((board[pl->GetY()+1][pl->GetX()]->GetBoxHere()))      // ����� ���� ����?
            {
                if((board[pl->GetY()+2][pl->GetX()]->GetPasible())&& // ��� ����� ��������?
                   (pl->GetAzimut()=='D')&&                          // �������� � ������� �����?
                   (!board[pl->GetY()+2][pl->GetX()]->GetBoxHere())) // �� ���� ���� ������ ����?
                {
                    int j=0;
                    while(1)
                    {
                        if((pl->GetY()+1==boxes[j]->GetY())&&
                           (pl->GetX()==boxes[j]->GetX())) break;
                        j++;
                    };
                    cout << "����!" << endl;
                    boxes[j]->BMove('D');
                    board[pl->GetY()+1][pl->GetX()]->SetBoxHere(false);
                    board[pl->GetY()+2][pl->GetX()]->SetBoxHere(true);
                    if(board[pl->GetY()+2][pl->GetX()]->GetImg()=='O') {boxes[j]->SetInPos(true);boxInPosFlag[j]=true;}
                        else {boxes[j]->SetInPos(false);boxInPosFlag[j]=false;};
                            Player* tempPlayer;//
                            tempPlayer = new Player(pl->GetX(),pl->GetY(),pl,pl->GetAzimut(),pl->GetScore(),pl->GetImg());//
                            pl=tempPlayer;//
                            pl->PMove('D');
                    //pl->PMove('U');
                } else if(pl->GetAzimut()=='D')
                            cout << "���� ��������!" << endl;
                        else {cout << "����!" << endl;
                                Player* tempPlayer;//
                                tempPlayer = new Player(pl->GetX(),pl->GetY(),pl,pl->GetAzimut(),pl->GetScore(),pl->GetImg());//
                                pl=tempPlayer;//
                                pl->PMove('D');};
            } else {cout << "����!" << endl;
                        Player* tempPlayer;//
                        tempPlayer = new Player(pl->GetX(),pl->GetY(),pl,pl->GetAzimut(),pl->GetScore(),pl->GetImg());//
                        pl=tempPlayer;//
                        pl->PMove('D');};
        } else if(pl->GetAzimut()=='D')
                    cout << "���� ��������!" << endl;
               else {cout << "����!" << endl;
                        Player* tempPlayer;//
                        tempPlayer = new Player(pl->GetX(),pl->GetY(),pl,pl->GetAzimut(),pl->GetScore(),pl->GetImg());//
                        pl=tempPlayer;//
                        pl->PMove('D');};
        break;
    case 228: ;// LEFT
    case 97:  ;// LEFT
    case 65:  ;// LEFT
    case 148: ;// LEFT
    case 75:
        if((board[pl->GetY()][pl->GetX()-1]->GetPasible()))          // ����� ���������?
        {
            if((board[pl->GetY()][pl->GetX()-1]->GetBoxHere()))      // ����� ���� ����?
            {
                if((board[pl->GetY()][pl->GetX()-2]->GetPasible())&& // ��� ����� ��������?
                   (pl->GetAzimut()=='L')&&                          // �������� � ������� �����?
                   (!board[pl->GetY()][pl->GetX()-2]->GetBoxHere())) // �� ���� ���� ������ ����?
                {
                    int j=0;
                    while(1)
                    {
                        if((pl->GetY()==boxes[j]->GetY())&&
                           (pl->GetX()-1==boxes[j]->GetX())) break;
                        j++;
                    };
                    cout << "�����!" << endl;
                    boxes[j]->BMove('L');
                    board[pl->GetY()][pl->GetX()-1]->SetBoxHere(false);
                    board[pl->GetY()][pl->GetX()-2]->SetBoxHere(true);
                    if(board[pl->GetY()][pl->GetX()-2]->GetImg()=='O') {boxes[j]->SetInPos(true);boxInPosFlag[j]=true;}
                        else {boxes[j]->SetInPos(false);boxInPosFlag[j]=false;}
                            Player* tempPlayer;//
                            tempPlayer = new Player(pl->GetX(),pl->GetY(),pl,pl->GetAzimut(),pl->GetScore(),pl->GetImg());//
                            pl=tempPlayer;//
                            pl->PMove('L');
                    //pl->PMove('U');
                } else if(pl->GetAzimut()=='L')
                            cout << "���� ��������!" << endl;
                        else {cout << "�����!" << endl;
                                Player* tempPlayer;//
                                tempPlayer = new Player(pl->GetX(),pl->GetY(),pl,pl->GetAzimut(),pl->GetScore(),pl->GetImg());//
                                pl=tempPlayer;//
                                pl->PMove('L');};
            } else {cout << "�����!" << endl;
                            Player* tempPlayer;//
                            tempPlayer = new Player(pl->GetX(),pl->GetY(),pl,pl->GetAzimut(),pl->GetScore(),pl->GetImg());//
                            pl=tempPlayer;//
                            pl->PMove('L');};
        } else if(pl->GetAzimut()=='L')
                    cout << "���� ��������!" << endl;
               else {cout << "�����!" << endl;
                        Player* tempPlayer;//
                        tempPlayer = new Player(pl->GetX(),pl->GetY(),pl,pl->GetAzimut(),pl->GetScore(),pl->GetImg());//
                        pl=tempPlayer;//
                        pl->PMove('L');};
        break;
    case 162: ;// RIGHT
    case 100: ;// RIGHT
    case 68:  ;// RIGHT
    case 130: ;// RIGHT
    case 77:
        if((board[pl->GetY()][pl->GetX()+1]->GetPasible()))          // ������ ���������?
        {
            if((board[pl->GetY()][pl->GetX()+1]->GetBoxHere()))      // ������ ���� ����?
            {
                if((board[pl->GetY()][pl->GetX()+2]->GetPasible())&& // ��� ����� ��������?
                   (pl->GetAzimut()=='R')&&                          // �������� � ������� �����?
                   (!board[pl->GetY()][pl->GetX()+2]->GetBoxHere())) // �� ���� ���� ������ ����?
                {
                    int j=0;
                    while(1)
                    {
                        if((pl->GetY()==boxes[j]->GetY())&&
                           (pl->GetX()+1==boxes[j]->GetX())) break;
                        j++;
                    };
                    cout << "������!" << endl;
                    boxes[j]->BMove('R');
                    board[pl->GetY()][pl->GetX()+1]->SetBoxHere(false);
                    board[pl->GetY()][pl->GetX()+2]->SetBoxHere(true);
                    if(board[pl->GetY()][pl->GetX()+2]->GetImg()=='O') {boxes[j]->SetInPos(true);boxInPosFlag[j]=true;}
                        else {boxes[j]->SetInPos(false);boxInPosFlag[j]=false;}
                                Player* tempPlayer;//
                                tempPlayer = new Player(pl->GetX(),pl->GetY(),pl,pl->GetAzimut(),pl->GetScore(),pl->GetImg());//
                                pl=tempPlayer;//
                                pl->PMove('R');
                    //pl->PMove('U');
                } else if(pl->GetAzimut()=='R')
                            cout << "���� ��������!" << endl;
                        else {cout << "������!" << endl;
                                Player* tempPlayer;//
                                tempPlayer = new Player(pl->GetX(),pl->GetY(),pl,pl->GetAzimut(),pl->GetScore(),pl->GetImg());//
                                pl=tempPlayer;//
                                pl->PMove('R');};
            } else {cout << "������!" << endl;
                        Player* tempPlayer;//
                        tempPlayer = new Player(pl->GetX(),pl->GetY(),pl,pl->GetAzimut(),pl->GetScore(),pl->GetImg());//
                        pl=tempPlayer;//
                        pl->PMove('R');};
        } else if(pl->GetAzimut()=='R')
                    cout << "���� ��������!" << endl;
               else {cout << "������!" << endl;
                        Player* tempPlayer;//
                        tempPlayer = new Player(pl->GetX(),pl->GetY(),pl,pl->GetAzimut(),pl->GetScore(),pl->GetImg());//
                        pl=tempPlayer;//
                        pl->PMove('R');};
            break;
    default: cout << " ��???" << endl; break;
    };
    int j=0;
    for(int i=0;i<k;i++)
        if(boxInPosFlag[i]) j++;
    if(j==k) Outro();
   // pl->PMove();
}
void Field::Intro()
{
    cout << "\n\n\n\n\n\n\n\n\n\n\t\t\t\t���������";
    Sleep(3000); // DELLLLLL
}
void Field::Outro()
{
    Print();
    int j=0;
    for(int i=0;i<k;i++)
        if(boxInPosFlag[i]) j++;
    if(j==k)
    {
        cout << "����������! ��� ����� �� �����. �� ���������� c �������\n����� �������: "
             << pl->GetScore()
             <<"\n���������� ������!\n\n";
        ifstream readF("log.txt");
        int top[3];
        for(int i=0;i<3;i++)
            readF >> top[i];
        cout << "��� ������:\n";
        ofstream printF("log.txt");
        bool tempFlag=false;
        for(int i=0;i<3;i++)
        {
            cout << i+1 << ") ";
            if((pl->GetScore()<top[i])&&(!tempFlag))
            {
                cout << pl->GetScore() << " - ��� ��!\n";
                top[i]=pl->GetScore();
                tempFlag=true;
            } else cout  << top[i] << endl;
            printF << top[i] << " ";
        };
        cout << "����� \"R\" ����� ���������� ��� �����.";
        int temp_comand = _getch();
        if(temp_comand==170||temp_comand==138||temp_comand==114||temp_comand==82)
        {
            delGame();
            input();
        } else end_game_flag=true;
    }
    else {cout << "�� �������� ���� � ��� �� ������! ������!\n\n";end_game_flag=true;}

}
void Field::ReversStep()
{
    if(pl->prev!=NULL) pl=pl->prev; else {cout << "���  ������ ���!\n";Sleep(600);};
}
