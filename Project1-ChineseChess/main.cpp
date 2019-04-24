#include <iostream>
#include "Chess.h"
#include "ChessBoard.h"
#include "Record.h"
#include "UI.h"

using namespace std;

int main()
{
	ChessBoard chessBoard;
	UI thisGameUI;

	chessBoard.readTheBoard("file.txt");
	while (1)
	{
		thisGameUI.printUI(); // �L�X��ӵe���ج[
		Record::printRecord();	// �L�X��������
		chessBoard.printThePlane();		// �L�X�ѽL
		system("CLS");	// �M����ӭ���
	}
}