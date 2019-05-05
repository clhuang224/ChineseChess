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
#endif // !UI_H

