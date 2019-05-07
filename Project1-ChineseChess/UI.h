#ifndef UI_H
#define UI_H
#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
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

    // ���X�T�{����
    bool showAlert(string);

    // ���X��ӵ���
    bool showWin(unsigned);

    // ���X���
    int showMenu();

    ChessBoard chessBoard;

private:
    Chess* lastChosed;
    bool cueMode;
};

#endif // !UI_H

