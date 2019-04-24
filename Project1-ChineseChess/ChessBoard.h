#pragma once
#include <iostream>
#include <string>
#include "Chess.h"

using namespace std;

class ChessBoard
{
private:
	// ��ӴѽL���{�b����m�W�����e
	// �Ϋ��Цs���ANULL�N�O��e��m�S���Ѥl�����A
	Chess* wholePosition[9][10];
	// Black:0 Red:1
	int turns;


public:
	ChessBoard();
	~ChessBoard();
	ChessBoard(string fileTxt);

	void printThePlane();

	// ���ӦbŪ�J�ѽL�ɳЫئn�Ҧ�chess����
	void readTheBoard(string fileTxt);
	void saveTheBoard();
};

