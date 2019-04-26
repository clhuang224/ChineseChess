#ifndef UI_H
#define UI_H

#include <windows.h>
#include <conio.h>
#include <iostream>
#include "ChessBoard.h"
#include "Record.h"
using namespace std;

class UI
{
public:

	ChessBoard chessBoard;

	static void printUI();
	static void showMenu();

	// ���o��e��Ц�m
	static position getCursorPos();

    // �]�w��e��X����
    static void SetColor(int = 7);
    // �]�w��Ц�m
    static void SetPosition(position);

    static void readKeyBoard();

private:
    // ��e��X����
    static int color;
    // ��e��Ц�m
    static position cursorPosition;
};

#endif // !UI_H

