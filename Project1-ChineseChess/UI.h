#ifndef UI_H
#define UI_H

#include <windows.h>
#include <conio.h>
#include <iostream>
#include <string>
#include <vector>
#include "ChessBoard.h"
using std::cout;

class UI
{
public:
	ChessBoard chessBoard;

    // �L�X�C���e��
	static void printUI();



	// ���o��e��Ц�m
	static position getCursorPos();

    // �]�w��e��X����
    static void SetColor(int = 7);

    // �]�w��Ц�m
    static void SetPosition(position);

    // Ū����L
    void readKeyBoard();

private:
    // ��e��Ц�m
    static position cursorPosition;
    Chess* lastChosed;
    
};

bool showAlert(string);
// ���X���
int showMenu();

position cursorToChess(position);

#endif // !UI_H

