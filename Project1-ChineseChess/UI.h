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
    void printUI();

    // Ū����L
    void readKeyBoard();

	// �L�_�l�e��
	void printStartScreen(string);

    ChessBoard chessBoard;

private:
    
    // �L�Xsetting
    void printSetting();

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

    Chess* lastChosed;
    bool cueMode;
    unsigned music;
};

#endif // !UI_H

