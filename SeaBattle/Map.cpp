#include "Map.h"

void Map::Print()
{
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
