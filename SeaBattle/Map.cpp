#include "Map.h"

void Map::Print()
{
    //std::cout << std::string(20, ' ') << "���� PC" << std::string(43, ' ') << "���� PC\n";
    //std::cout << " %   A   B   C   D   E   F   G   H   I   J" << std::string(5, ' ') << "   %   A   B   C   D   E   F   G   H   I   J\n";;
    //for (int i = 1; i < 11 ; i++)//������
    //{

    //    std::cout <<Pole1<<std::string(5,' ') <<Pole1<< "\n";// ����� �����������
    //    std::cout << std::setw(2) << i << " ";//setw ��� ����� 10
    //    for (int j = 1; j < 12; j++)// �������
    //    {
    //        std::cout << "| " << "  ";
    //        if (j == 10) std::cout << "|";
    //        if (j == 10) 
    //        {
    //            std::cout << std::string(5, ' ');// ������ ����� ������
    //            // ����� ������ � ���������� ���� ��
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
    std::cout << std::string(20, ' ') << "���� ������" << std::string(43, ' ') << "���� ��\n";
    std::cout << ABC << std::string(12, ' ') <<ABC<<"\n";

    for (int i = 0; i < 10; i++) // ������
    {
        // ����� �����������
        std::cout << Line << std::string(10, ' ') << Line<<"\n";

        // ����� ������ � ���������� ���� ������
        std::cout << std::setw(2) << i + 1 << " "; // setw ��� ������������ ����� 10
        for (int j = 0; j < 10; j++) // �������
        {
            std::cout << "| " << PolePc1[i][j] << " ";//PolePc1[i][j] �������
        }
        std::cout << "|";

        // ������ ����� ������
        std::cout << std::string(10, ' ');

        // ����� ������ � ���������� ���� ��
        std::cout << std::setw(2) << i + 1 << " ";
        for (int j = 0; j < 10; j++) // �������
        {
            std::cout << "| " << PolePc[i][j] << " ";//PolePc1[i][j] �������
        }
        std::cout << "|";

        std::cout << std::endl;
    }

        // ������ ����� �����������
        std::cout << Line << std::string(10, ' ') << Line<<"\n";
    
}
