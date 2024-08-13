#include "Map.h"

void Map::Print()
{
    //std::cout << std::string(20, ' ') << "ПОЛЕ PC" << std::string(43, ' ') << "ПОЛЕ PC\n";
    //std::cout << " %   A   B   C   D   E   F   G   H   I   J" << std::string(5, ' ') << "   %   A   B   C   D   E   F   G   H   I   J\n";;
    //for (int i = 1; i < 11 ; i++)//строки
    //{

    //    std::cout <<Pole1<<std::string(5,' ') <<Pole1<< "\n";// Линия разделителя
    //    std::cout << std::setw(2) << i << " ";//setw для цифры 10
    //    for (int j = 1; j < 12; j++)// столбцы
    //    {
    //        std::cout << "| " << "  ";
    //        if (j == 10) std::cout << "|";
    //        if (j == 10) 
    //        {
    //            std::cout << std::string(5, ' ');// Пробел между полями
    //            // Номер строки и содержимое поля ПК
    //            std::cout << std::setw(2) << i << " ";
    //            for (int j = 1; j < 11; j++)
    //            {
    //                std::cout << "| " << "  ";
    //               
    //            }
    //        }
    //    }
    //    std::cout << std::endl;
    //   

    //}
    //    std::cout <<Pole1<<std::string(5,' ') <<Pole1<< "\n";
    std::cout << std::string(20, ' ') << "ПОЛЕ ИГРОКА" << std::string(43, ' ') << "ПОЛЕ ПК\n";
    std::cout << ABC << std::string(12, ' ') <<ABC<<"\n";

    for (int i = 0; i < 10; i++) // строки
    {
        // Линия разделителя
        std::cout << Line << std::string(10, ' ') << Line<<"\n";

        // Номер строки и содержимое поля игрока
        std::cout << std::setw(2) << i + 1 << " "; // setw для выравнивания цифры 10
        for (int j = 0; j < 10; j++) // столбцы
        {
            std::cout << "| " << PolePc1[i][j] << " ";//PolePc1[i][j] затычка
        }
        std::cout << "|";

        // Пробел между полями
        std::cout << std::string(10, ' ');

        // Номер строки и содержимое поля ПК
        std::cout << std::setw(2) << i + 1 << " ";
        for (int j = 0; j < 10; j++) // столбцы
        {
            std::cout << "| " << PolePc[i][j] << " ";//PolePc1[i][j] затычка
        }
        std::cout << "|";

        std::cout << std::endl;
    }

        // Нижняя линия разделителя
        std::cout << Line << std::string(10, ' ') << Line<<"\n";
    
}
