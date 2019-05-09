#ifndef CHESSBOARD_H
#define CHESSBOARD_H
#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <string>
#include "Chess.h"
#include "Console.h"
using std::cout;
using std::string;
using std::vector;
using std::fstream;
using std::ios;
class ChessBoard
{
public:
    // ��ӴѽL���{�b����m�W�����e
    // �Ϋ��Цs���ANULL�N�O��e��m�S���Ѥl�����A
    Chess* wholePosition[9][10];//[col][row]
    // Black:0 Red:1
    int turns;

    ChessBoard();
    ~ChessBoard();
    ChessBoard(string fileTxt);

    // �L�X�ťմѽL
    void printEmptyPlane();
	// �L�X���q�ѽL
    void printThePlane();
	// �L�X�t���襤�Ѫ��i�ʨB�ƪ��ѽL�A�ϥΫe�ݭn���T�wlegalMove���O�_�w�ư��䰨�B
	// �Ψ�L�S��W�h�A�H�Τ���Y�o�ѡA�H�γQ��L���ɨ쪺�Ѿl��m
	void printChosenPlane();
    // �L�X��e��turn
    void printTurn();


	// ���ʴѽL�A�������Ѯɷ|�I�s
	void moveTheChess(int fromX, int fromY, int toX, int toY);
    // ����turn
    void changTurn();

    // ���ӦbŪ�J�ѽL�ɳЫئn�Ҧ�chess����
    bool readTheBoard(string fileTxt);
    bool saveTheBoard(string fileTxt);
	bool saveTheBoard();

	vector <position> legalMove;	//�s��ਫ�����AUI�ઽ���ϥΨ쥦
	void manageLegalMove(int x, int y);		// UI�b��ܴѤl�H��I�s��
	void clearLegalMove();

    
    // �H��m���o�Ѥl����
    Chess* getChess(position);
    // ���o��U��turn
    int getTurn();
};


#endif // !CHESSBOARD_H