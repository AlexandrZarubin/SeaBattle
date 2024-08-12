#include "Map.h"

void Map::Print()
{
    std::cout << std::string(20, ' ') << "ПОЛЕ PC\n";
    std::cout << " %   A   B   C   D   E   F   G   H   I   J\n";
    for (int i = 1; i < 11 ; i++)//строки
    {

        std::cout <<Pole1<<"\n";
        std::cout << std::setw(2) << i << " ";//setw для цифры 10
        for (int j = 1; j < 12; j++)//ряды
        {
            std::cout << "| " << "  ";
           
        }
        std::cout << std::endl;
       

    }
        std::cout << Pole1;
        
}
