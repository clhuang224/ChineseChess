#ifndef UI_H
#define UI_H

#include <windows.h>
#include <conio.h>
#include <iostream>
#include <string>
#include <vector>
#include "ChessBoard.h"
using namespace std;

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
    
};

bool showAlert(string);
// ���X���
int showMenu();

#endif // !UI_H

