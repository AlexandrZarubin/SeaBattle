#pragma once
#include"Functions.h"
class Map
{
	const std::string Line = "   Х - Х - Х - Х - Х - Х - Х - Х - Х - Х - Х";
	const std::string ABC= " %   A   B   C   D   E   F   G   H   I   J";
	int PolePc[10][10]{};//затычка
	int PolePc1[10][10]{};//затычка
public:
	void Print();
};

