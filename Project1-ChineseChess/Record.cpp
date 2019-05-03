#include "Record.h"
#include <Windows.h>
#include <iostream>

vector<int> Record::chessTypeData;
vector<struct position> Record::fromPos;
vector<struct position> Record::toPos;
short leftStart = 7, topStart = 4;

Record::Record()
{
}


Record::~Record()
{
}

void Record::printRecord()
{
	int count = 0;
	for (int i = chessTypeData.size() - 11; i < chessTypeData.size(); i++)
	{
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { static_cast<short>(leftStart + count),  static_cast<short>(topStart + count * 2) });
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07);	// �]���©��զr
		std::cout << count << " ";
		count++;

		if(chessTypeData[i] <= 7)	// ��
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x08);
			std::cout << "��" << " " ;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07);
		}

		if(chessTypeData[i] > 7)	// ��
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0c);
			std::cout << "��" << " " ;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07);
		}
	}
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { static_cast<short>(leftStart + 0),  static_cast<short>(topStart + 0)});
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07);
	std::cout << 1 << " ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0c);
	std::cout << "��" << " " ;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07);
	std::cout << "�G" << " " << "��" << " " << "�K" << " " << "�i" << " " << "�C" << endl;
}

void Record::saveThisStep(int chessType, int fromX, int fromY, int toX, int toY)
{
	struct position from;
	struct position to;

	from.x = fromX;
	from.y = fromY;
	to.x = toX;
	to.y = toY;

	chessTypeData.push_back(chessType);
	fromPos.push_back(from);
	toPos.push_back(to);
	
}

void Record::clearRecord()
{
	chessTypeData.clear();
	fromPos.clear();
	toPos.clear();
}

