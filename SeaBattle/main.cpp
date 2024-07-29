#include <iostream>
#include<iomanip>//setw
#include<windows.h>
#include <conio.h>//getch()
#include<stdlib.h>
#include<time.h>

using namespace std;
void moving(int xpos, int ypos)//для управления с клавы
{
    COORD scrn;

    HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);

    scrn.X = xpos; scrn.Y = ypos;

    SetConsoleCursorPosition(hOuput, scrn);
}
enum ConsoleColor //color
{
    Black,
    Blue,
    Green,
    Cyan,
    Red,
    Magenta,
    Brown,
    LightGray,
    DarkGray,
    LightBlue,
    LightGreen,
    LightCyan,
    LightRed,
    LightMagenta,
    Yellow,
    White
};
void SetColor(ConsoleColor text, ConsoleColor background)
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

const int Size = 10;// строки и ряды
const int CountersShip = 1;

class Map
{

public:

    int Life[Size][Size] = {};//выстрелы 
    int Ships[Size][Size] = {};//расположение короблей
    int Hits[Size] = {};     // жизнь коробля
    ~Map() {};
    Map() {
        for (int i = 0; i < Size; i++)
        {
            for (int j = 0; j < Size; j++)
            {
                Ships[i][j] = 0;
                Life[i][j] = 0;
            }
        }
        for (int i = 0; i < Size; i++) { Hits[i] = 0; }

    }
    void InstallationSips(int, int, int);//установка коробля
    int ExaminationShip(int&, int&, int&, int&);//проверка на соприкосновение
    void GetPlay(int* playrPositionX, int* playrPositionY, int* modbot, int* clonePlayrPositionX, int* clonePlayrPositionY)//авто выстрел
    {
        int x;// = rand() % 10;
        int y;// = rand() % 10;
        bool flag = 0;
        if (*modbot == 0)
            do
            {

                x = rand() % 10;
                y = rand() % 10;
                if (Life[x][y] != 1) // проверка: выбирал ли уже компьютер эти координаты
                {
                    Life[x][y] = 1;
                    flag = 1;
                    *playrPositionX = x;
                    *playrPositionY = y;
                }
            } while (flag == 0);
            if (*modbot == 2)
            {


            }
    }
    void SetLife(int positionX, int positionY) { Life[positionX][positionY] = 1; }//заносим в таблицу
    int GetLife(Map& name, int, int);//проверка на ход в туже клетку 

    int replay(Map& name, int positionX, int positionY, bool* move)//повторный ход
    {
        if (name.Ships[positionX][positionY] >= 1)
        {

            return *move;// = *move;
        }

        *move = !(*move);
        return *move;

    }
    int victory(Map& name)//проверка на победителя
    {
        int flag = 0;
        for (int i = 0; i < 10; i++)
        {

            if (name.Hits[i] > 0) flag = 1;


            if (i == 9 && flag == 1)return flag;
            if (i == 9 && flag == 0)return flag;
        }

    }
};
void Position1(int*, int*, int*, int*);//для выстрела с клавиатуры
bool random() //определяем кто первый ходит
{
    if (rand() % 2 == 0)
        return true;
    else return false;
}
void FirstMove(int* flag, bool* move)//определяем кто первый ходит
{
    *flag = 1;
    *move = random();

}
int main()
{

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(NULL));
    char Pole[46]{ ' ',' ',' ','•',' ','-',' ','•',' ','-',' ','•',' ','-',' ','•',' ','-',' ','•',' ','-',' ','•',' ','-',' ','•',' ','-',' ','•',' ','-',' ','•',' ','-',' ','•',' ','-',' ','•' };
    char Pole2[50]{ ' ','%',' ', ' ', ' ','A',' ', ' ', ' ','B',' ', ' ', ' ','C',' ', ' ', ' ','D',' ', ' ', ' ','E',' ', ' ', ' ','F',' ', ' ', ' ','G',' ', ' ', ' ','H',' ', ' ', ' ','I',' ', ' ', ' ','J' };
    int  x = 5, y = 3, PositionX = 0, PositionY = 0;
    int PlayrPositionX = 0, PlayrPositionY = 0;
    int flag = 0;
    int BotMod = 0, ClonePlayrPositionX = 0, ClonePlayrPositionY = 0;
    bool Move = true;
    Map Player;
    Map Pc;
    Player.InstallationSips(4, 1, CountersShip);//установка кораблей 
    Pc.InstallationSips(4, 1, CountersShip);//установка кораблей

    do {
        system("cls");
        cout << string(20, ' ') << "ПОЛЕ PC" << string(40, ' ') << "ПОЛЕ ИГРОКА\n";
        cout << Pole2 << string(7, ' ') << Pole2 << "\n";
        cout << Pole << string(5, ' ') << Pole << "\n";
        for (int i = 0; i < Size; i++)//строки
        {

            cout << setw(2) << i << " ";//setw для цифры 10
            for (int j = 0; j < Size; j++)//ряды
            {
                if (Pc.Life[i][j] == 0) cout << "| " << "  ";//если нет выстрела в клетку
                else if (Pc.Life[i][j] == 1 && Pc.Ships[i][j] >= 1)//вход если есть корабль и выстрел в туже координату
                {
                    if (Pc.Hits[(Pc.Ships[i][j]) - 1] <= 0)//если уничтожен 
                    {
                        cout << "|";
                        SetColor(LightRed, Black);
                        cout << " Х" << " ";
                        SetColor(White, Black);
                    }
                    else// подбили
                    {
                        cout << "|";
                        SetColor(Yellow, Black);
                        cout << " Х" << " ";
                        SetColor(White, Black);
                    }

                }
                else if (Pc.Life[i][j] == 1 && Pc.Ships[i][j] == 0)//если выстрел мимо
                {
                    cout << "|";
                    SetColor(Brown, Black);
                    cout << " 0" << " ";
                    SetColor(White, Black);
                }

                if (j == 9) cout << "|";
                if (j == 9) {
                    cout << string(5, ' ') << setw(2) << i << " ";
                    for (int j = 0; j < Size; j++)
                    {
                        //
                        if (Player.Ships[i][j] == 0 && Player.Life[i][j] <= 0) cout << "| " << "  ";//если нет коробля
                        if (Player.Ships[i][j] >= 1 && Player.Life[i][j] <= 0)  cout << "| #" << " "; //есть корабль
                        if (Player.Life[i][j] >= 1 && Player.Ships[i][j] <= 0)//если выстрел мимо
                        {
                            cout << "|";
                            SetColor(Brown, Black);
                            cout << " 0" << " ";
                            SetColor(White, Black);
                        }
                        if (Player.Life[i][j] >= 1 && Player.Ships[i][j] >= 1)//вход если есть корабль и выстрел в туже координату
                        {
                            if (Player.Hits[(Player.Ships[i][j]) - 1] <= 0)//если уничтожен 
                            {
                                cout << "|";
                                SetColor(LightRed, Black);
                                cout << " Х" << " ";
                                SetColor(White, Black);
                            }
                            else// подбили
                            {
                                cout << "|";
                                SetColor(Yellow, Black);
                                cout << " Х" << " ";
                                SetColor(White, Black);
                            }

                        }

                        if (j == 9) cout << "|";
                    }
                }
            }
            cout << endl;
            cout << Pole << string(5, ' ') << Pole << "\n";
        }
        cout << "Произведите выстрел\n";
        if (flag == 0)FirstMove(&flag, &Move);
        if (Move == 1)
        {
            cout << "Выстрел делает Player\n";
            cout << "Для выхода нажмите Esc\n";
            cout << "ход осуществляется маленькими буквами w,a,s,d выстрел через пробел\n";
            do
            {
                moving(x, y);
                Position1(&x, &y, &PositionY, &PositionX);
            } while (Pc.GetLife(Pc, PositionX, PositionY) != 0);
            //Pc.GetPlay(&PositionX, &PositionY, &BotMod, & ClonePlayrPositionX, &ClonePlayrPositionY);// авто ход
            Pc.SetLife(PositionX, PositionY);// заносим значение
            Pc.replay(Pc, PositionX, PositionY, &Move);// для повторного хода
            if (Pc.Ships[PositionX][PositionY] >= 1)Pc.Hits[(Pc.Ships[PositionX][PositionY]) - 1]--;
            int Message = Pc.victory(Pc);
            if (Message == 0)
            {
                cout << "победил Pc\n";
                Sleep(3000);
                exit(0);
            }
        }
        else
        {
            cout << "Выстрел делает Pc\n";

            //Sleep(1000);
            Player.GetPlay(&PlayrPositionX, &PlayrPositionY, &BotMod, &ClonePlayrPositionX, &ClonePlayrPositionY);
            Player.replay(Player, PlayrPositionX, PlayrPositionY, &Move);//для повторного хода
            /*if (Player.Ships[PlayrPositionX][PlayrPositionY] >= 1)
            {
                //BotMod = 2;
                ClonePlayrPositionX = PlayrPositionX;
                ClonePlayrPositionY = PlayrPositionY;
            }*/
            if (Player.Ships[PlayrPositionX][PlayrPositionY] >= 1)Player.Hits[(Player.Ships[PlayrPositionX][PlayrPositionY]) - 1]--;
            int Message = Player.victory(Player);
            if (Message == 0)
            {
                cout << "победил Pc\n";
                Sleep(3000);
                exit(0);
            }
        }
    } while (true);

}

void Map::InstallationSips(int Deck, int Shipp, int CountersShip)
{
    if (Deck == 0)return;
    bool Flag1 = false;
    int Col, Row, Row2 = 0, Col2 = 0;// , d = CountersShip;



    for (int k = 0; k < Shipp; k++)
    {

        do
        {
            int direction = 1 + rand() % 2; // выбираем направление



            Col = rand() % 10; // случайным образом определяются координаты
            Row = rand() % 10;
            Col2 = Col;
            Row2 = Row;


            //int e = 0;
            if (direction == 1)
            {
                do
                {
                    Row = rand() % 10;

                } while (Row + Deck > Size);//проверка рандом + количество палуб
                Row2 = Row + Deck - 1;
            }
            else
            {
                do
                {
                    Col = rand() % 10;

                } while (Col + Deck > Size);
                Col2 = Col + Deck - 1;
            }

            Flag1 = ExaminationShip(Col, Row, Col2, Row2);
            if (Flag1 == true)//continue;
                //else
            {
                for (int i = Col; i <= Col2; i++)
                {
                    for (int j = Row; j <= Row2; j++)
                    {
                        Ships[i][j] = CountersShip;
                    }
                }
                Hits[CountersShip - 1] = Deck;
                CountersShip++;
            }


        } while (Flag1 != true); // конец while
    }

    Map::InstallationSips(Deck - 1, Shipp + 1, CountersShip);
}

int Map::ExaminationShip(int& col, int& row, int& col2, int& row2)
{

    for (int i = col - 1; i <= col2 + 1; i++)//проверяем с -1 строки до +1
    {
        for (int j = row - 1; j <= row2 + 1; j++)//проверяем с -1 стоблца до +1 столбца
        {
            if (Ships[i][j] >= 1)  return false;

        }
    }
    return true;



}

void Position1(int* x1, int* y2, int* positionX, int* positionY)
{

    int x = *x1, y = *y2;


    while (true)
    {
        int ch = _getch();


        switch (ch)
        {
        case 27:

            exit(0);
            break;
        case 100:

            if (x < 40)
            {
                x = x + 4;
                moving(x, y);
            }
            break;
        case 97:

            if (x > 5)
            {
                x = x - 4;
                moving(x, y);
            }
            break;
        case 119:

            if (y > 3)
            {
                y = y - 2;
                moving(x, y);
            }
            break;
        case 115:

            if (y < 20)
            {
                y = y + 2;
                moving(x, y);
            }
            break;
        }
        if (ch == 32)
        {
            *x1 = x;
            *y2 = y;
            *positionX = (x - 5) / 4;
            *positionY = (y - 3) / 2;
            break;
        }
    }


}
int Map::GetLife(Map& name, int I, int J)
{
    if (name.Life[I][J] == 1)return 1;
    return 0;
}