#ifndef CHESSBOARD_H
#define CHESSBOARD_H
#include <iostream>
#include <fstream>
#include <string>
#include "Chess.h"

using namespace std;

class ChessBoard
{
private:
    // ��ӴѽL���{�b����m�W�����e
    // �Ϋ��Цs���ANULL�N�O��e��m�S���Ѥl�����A
    Chess* wholePosition[9][10];//[col][row]
    // Black:0 Red:1
    int turns;


public:
    ChessBoard();
    ~ChessBoard();
    ChessBoard(string fileTxt);

	// �L�X���q�ѽL
    void printThePlane();
	// �L�X�t���襤�Ѫ��i�ʨB�ƪ��ѽL
	void printChosenPlane();


	// ���ʴѽL�A�������Ѯɷ|�I�s
	void moveTheChess(int fromX, int fromY, int toX, int toY);

    // ���ӦbŪ�J�ѽL�ɳЫئn�Ҧ�chess����
    void readTheBoard(string fileTxt);
    void saveTheBoard(string fileTxt);
	void saveTheBoard();

	vector <position> legalMove;	//�s��ਫ�����AUI�ઽ���ϥΨ쥦
	void manageLegalMove(int x, int y);		// UI�b��ܴѤl�H��I�s��
	void clearLegalMove();
};



#endif // !CHESSBOARD_H