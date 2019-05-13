#ifndef UI_H
#define UI_H
#include <iostream>
#include <fstream>
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

    // ���X�T�w����
    void showAlert(vector<string>);

    // ���XY/N����
    bool showAlert(vector<string>, bool);

    // ���X��J����
    string showInput(string);

    // ���X��ӵ���
    bool showWin(unsigned);

    // ���X���
    int showMenu(vector<string>);

	//�L�_�l�e��
	void printStartScreen(string);

    ChessBoard chessBoard;

private:
    Chess* lastChosed;
    bool cueMode;
};

#endif // !UI_H

