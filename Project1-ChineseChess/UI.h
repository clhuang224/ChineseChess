#ifndef UI_H
#define UI_H
#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include <direct.h>
#include "ChessBoard.h"
#include "Record.h"
#include <thread>
#include "Music.h"
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
    bool showAlert(string, bool);
    bool showAlert(string, bool, string);

    // ���X��J����
    string showInput(string);

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

