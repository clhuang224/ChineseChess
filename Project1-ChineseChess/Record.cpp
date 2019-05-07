#include "Record.h"
#include <Windows.h>
#include <iostream>
#include "Console.h"

vector<int> Record::chessTypeData;
vector<struct position> Record::fromPos;
vector<struct position> Record::toPos;
vector<int> Record::ifOnly;
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
	int i = 0;
	if (chessTypeData.size() > 9)
	{
		i = chessTypeData.size() - 10;
	}
	position storeCursor = getCursorPosition();

	while(i < chessTypeData.size())
	{
		position printPosition = { leftStart, topStart + count * 2 };
		SetPosition(printPosition);
		SetColor(0x07);	// �]���©��զr
		std::cout << i + 1 << " ";
		count++;

		if(chessTypeData[i] <= 7)	// ��
		{
			SetColor(0x08);
			std::cout << "��" << " " ;
		}

		if(chessTypeData[i] > 7)	// ��
		{
			SetColor(0x0c);
			std::cout << "��" << " " ;
		}

		SetColor(0x07);
		if (ifOnly[i] == 0)			// ���q�����p
		{
			switch (chessTypeData[i])
			{
			case 1:
				std::cout << "�G" << " " << "�N" << " ";
				break;
			case 2:
				std::cout << "�G" << " " << "�h" << " ";
				break;
			case 3:
				std::cout << "�G" << " " << "�H" << " ";
				break;
			case 4:
				std::cout << "�G" << " " << "��" << " ";
				break;
			case 5:
				std::cout << "�G" << " " << "��" << " ";
				break;
			case 6:
				std::cout << "�G" << " " << "�]" << " ";
				break;
			case 7:
				std::cout << "�G" << " " << "��" << " ";
				break;
			case 8:
				std::cout << "�G" << " " << "��" << " ";
				break;
			case 9:
				std::cout << "�G" << " " << "�K" << " ";
				break;
			case 10:
				std::cout << "�G" << " " << "��" << " ";
				break;
			case 11:
				std::cout << "�G" << " " << "��" << " ";
				break;
			case 12:
				std::cout << "�G" << " " << "�X" << " ";
				break;
			case 13:
				std::cout << "�G" << " " << "��" << " ";
				break;
			case 14:
				std::cout << "�G" << " " << "�L" << " ";
				break;
			default:
				break;
			}

			if (chessTypeData[i] <= 7)		// ��
			{
				switch (fromPos[i].x)
				{
				case 0:
					std::cout << "��" << " ";
					break;
				case 1:
					std::cout << "��" << " ";
					break;
				case 2:
					std::cout << "��" << " ";
					break;
				case 3:
					std::cout << "��" << " ";
					break;
				case 4:
					std::cout << "��" << " ";
					break;
				case 5:
					std::cout << "��" << " ";
					break;
				case 6:
					std::cout << "��" << " ";
					break;
				case 7:
					std::cout << "��" << " ";
					break;
				case 8:
					std::cout << "��" << " ";
					break;
				default:
					break;
				}

				int move = toPos[i].y - fromPos[i].y;
				if (move > 0)
				{
					std::cout << "�i" << " ";
				}
				else if (move < 0)
				{
					std::cout << "�h" << " ";
					move = -move;
				}
				else if (move == 0)
				{
					std::cout << "��" << " ";
					move = toPos[i].x + 1;
				}

				switch (move)
				{
				case 1:
					std::cout << "��";
					break;
				case 2:
					std::cout << "��";
					break;
				case 3:
					std::cout << "��";
					break;
				case 4:
					std::cout << "��";
					break;
				case 5:
					std::cout << "��";
					break;
				case 6:
					std::cout << "��";
					break;
				case 7:
					std::cout << "��";
					break;
				case 8:
					std::cout << "��";
					break;
				case 9:
					std::cout << "��";
					break;
				default:
					break;
				}

			}
			else if (chessTypeData[i] > 7)		// ��
			{
				switch (fromPos[i].x)
				{
				case 0:
					std::cout << "�@" << " ";
					break;
				case 1:
					std::cout << "�G" << " ";
					break;
				case 2:
					std::cout << "�T" << " ";
					break;
				case 3:
					std::cout << "�|" << " ";
					break;
				case 4:
					std::cout << "��" << " ";
					break;
				case 5:
					std::cout << "��" << " ";
					break;
				case 6:
					std::cout << "�C" << " ";
					break;
				case 7:
					std::cout << "�K" << " ";
					break;
				case 8:
					std::cout << "�E" << " ";
					break;
				default:
					break;
				}

				int move = toPos[i].y - fromPos[i].y;
				if (move > 0)
				{
					std::cout << "�h" << " ";
				}
				else if (move < 0)
				{
					std::cout << "�i" << " ";
					move = -move;
				}
				else if (move == 0)
				{
					std::cout << "��" << " ";
					move = toPos[i].x + 1;
				}

				switch (move)
				{
				case 1:
					std::cout << "�@";
					break;
				case 2:
					std::cout << "�G";
					break;
				case 3:
					std::cout << "�T";
					break;
				case 4:
					std::cout << "�|";
					break;
				case 5:
					std::cout << "��";
					break;
				case 6:
					std::cout << "��";
					break;
				case 7:
					std::cout << "�C";
					break;
				case 8:
					std::cout << "�K";
					break;
				case 9:
					std::cout << "�E";
					break;
				default:
					break;
				}
			}
		}
		else		// �p�G�o�ӴѤ��O�ۤv�o���u�W�ߤ@���@�Ӧۤv�������A�ݭn�B�~�B�z
		{



		}

		i++;
	}

	SetPosition(storeCursor);
	
}

void Record::saveThisStep(int chessType, int fromX, int fromY, int toX, int toY, int only)
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
	ifOnly.push_back(only);
	
}

void Record::clearRecord()
{
	chessTypeData.clear();
	fromPos.clear();
	toPos.clear();
}

