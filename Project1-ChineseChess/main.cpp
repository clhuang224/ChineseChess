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

	/*��ĳ���n��while(1)��render�A�ӬOwhile(1)��detect���L��J�~render*/
	while (1)
	{
        


		thisGameUI.printUI(); // �L�X��ӵe���ج[
		Record::printRecord();	// �L�X��������
		//chessBoard.printThePlane();// �L�X�ѽL
		chessBoard.printThePlaneInCout();// �L�X�ѽL

		// UIŪ����L

		system("pause");
		system("CLS");	// �M����ӭ���
	}
}