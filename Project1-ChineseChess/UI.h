#ifndef UI_H
#define UI_H

#include <windows.h>
#include <conio.h>
#include <iostream>
#include <string>
#include <vector>
#include "ChessBoard.h"
#include "Record.h"
using std::cout;

class UI
{
public:
    UI();

    // �L�X�C���e��
	static void printUI();

	// ���o��e��Ц�m
	static position getCursorPosition();

    // �]�w��e��X����
    static void SetColor(int = 7);

    // �]�w��Ц�m
    static void SetPosition(position);

    

    // Ū����L
    void readKeyBoard();

    ChessBoard chessBoard;

private:
    Chess* lastChosed;
    bool cueMode;
};

bool showAlert(string);
// ���X���
int showMenu();
position cursorToChess(position);
position chessToCursor(position);

#endif // !UI_H

