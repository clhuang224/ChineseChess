#include "ChessBoard.h"



ChessBoard::ChessBoard()
{
	//開局初始化
	turns = 1;
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 9; j++)
			wholePosition[j][i] = NULL;

	//指標賦值
	wholePosition[0][0] = new Chess(4, 0, 0);
	wholePosition[1][0] = new Chess(5, 1, 0);
	wholePosition[2][0] = new Chess(3, 2, 0);
	wholePosition[3][0] = new Chess(2, 3, 0);
	wholePosition[4][0] = new Chess(1, 4, 0);
	wholePosition[5][0] = new Chess(2, 5, 0);
	wholePosition[6][0] = new Chess(3, 6, 0);
	wholePosition[7][0] = new Chess(5, 7, 0);
	wholePosition[8][0] = new Chess(4, 8, 0);
	wholePosition[1][2] = new Chess(6, 1, 2);
	wholePosition[7][2] = new Chess(6, 7, 2);
	wholePosition[0][3] = new Chess(7, 0, 3);
	wholePosition[2][3] = new Chess(7, 2, 3);
	wholePosition[4][3] = new Chess(7, 4, 3);
	wholePosition[6][3] = new Chess(7, 6, 3);
	wholePosition[8][3] = new Chess(7, 8, 3);

	wholePosition[0][9] = new Chess(11, 0, 9);
	wholePosition[1][9] = new Chess(12, 1, 9);
	wholePosition[2][9] = new Chess(10, 2, 9);
	wholePosition[3][9] = new Chess(9, 3, 9);
	wholePosition[4][9] = new Chess(8, 4, 9);
	wholePosition[5][9] = new Chess(9, 5, 9);
	wholePosition[6][9] = new Chess(10, 6, 9);
	wholePosition[7][9] = new Chess(12, 7, 9);
	wholePosition[8][9] = new Chess(11, 8, 9);
	wholePosition[1][7] = new Chess(6, 1, 7);
	wholePosition[7][7] = new Chess(6, 7, 7);
	wholePosition[0][6] = new Chess(7, 0, 6);
	wholePosition[2][6] = new Chess(7, 2, 6);
	wholePosition[4][6] = new Chess(7, 4, 6);
	wholePosition[6][6] = new Chess(7, 6, 6);
	wholePosition[8][6] = new Chess(7, 8, 6);
}

ChessBoard::~ChessBoard()
{
}

ChessBoard::ChessBoard(string fileTxt)
{	
	readTheBoard(fileTxt);
}

void ChessBoard::printThePlane()
{
}

void ChessBoard::printThePlaneInCout()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if(wholePosition[j][i]!=NULL)cout << wholePosition[j][i]->getChessType() << "\t";
			else cout << "0\t";
		}
		cout << "\n";
	}
	cout << turns << "\n";
}

void ChessBoard::readTheBoard(string fileTxt)
{
	//開檔讀取並新建所需的棋子
	fstream file(fileTxt);
	if (file.is_open())
	{
		//丟掉現存的棋盤內容
		/*待補record部分的清除*/
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 9; j++)
				if (wholePosition[j][i] != NULL)
					delete wholePosition[j][i];
		}

		int tmp;
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				file >> tmp;
				if (tmp != 0)wholePosition[j][i] = new Chess(tmp, j, i);
			}
		}
		file >> turns;
	}
	file.close();
	file.clear();
}

void ChessBoard::saveTheBoard(string fileTxt)
{
	fstream file(fileTxt);
	if (file.is_open())
	{
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				wholePosition[j][i] == NULL ? file << wholePosition[j][i]->getChessType() : file << '0';
				file << ' ';
			}
			file << '\n';
		}
		file << turns;
	}
	file.close();
	file.clear();
}

void ChessBoard::saveTheBoard()
{
	fstream file;
	file.open("file.txt", ios::trunc);
	if (file.is_open())
	{
		file.clear();
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				wholePosition[j][i] == NULL ? file << wholePosition[j][i]->getChessType() : file << '0';
				file << ' ';
			}
			file << '\n';
		}
		file >> turns;
	}
	file.close();
	file.clear();
}
