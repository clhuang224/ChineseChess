#ifndef CHESSBOARD_H
#define CHESSBOARD_H
#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <string>
#include <Windows.h>
#include "Chess.h"
using namespace std;


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
	// �L�X�t���襤�Ѫ��i�ʨB�ƪ��ѽL�A�ϥΫe�ݭn���T�wlegalMove���O�_�w�ư��䰨�B
	// �Ψ�L�S��W�h�A�H�Τ���Y�o�ѡA�H�γQ��L���ɨ쪺�Ѿl��m
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
	void SetColor(int = 7);//�hUI����ƹL�ӳ]�w�C��
};

void printEmptyPlane();

#endif // !CHESSBOARD_H