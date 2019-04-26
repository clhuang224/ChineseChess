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

    void printThePlane();
	void printThePlaneInCout();

    // ���ӦbŪ�J�ѽL�ɳЫئn�Ҧ�chess����
    void readTheBoard(string fileTxt);
    void saveTheBoard(string fileTxt);
	void saveTheBoard();
};



#endif // !CHESSBOARD_H