#pragma once
#include <iostream>
#include <string>
#include "Chess.h"

using namespace std;

class ChessBoard
{
private:
	// ��ӴѽL���{�b����m�W�����e
	Chess wholePosition[9][10];
	// Black:0 Red:1
	int turns;
	// ��e��Ъ���m
	int cursorPosition[2];

public:
	ChessBoard();
	~ChessBoard();
	ChessBoard(string fileTxt);

	// UI���ӷ|�Ψ쪺�A���o�ѽL���e
	Chess* getTheBoard();

	// ���ӦbŪ�J�ѽL�ɳЫئn�Ҧ�chess����
	void readTheBoard(string fileTxt);
	void saveTheBoard();
};

