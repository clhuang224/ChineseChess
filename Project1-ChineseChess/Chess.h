#pragma once
#include <vector>
using std::vector;

struct position
{
	int x;
	int y;
};

class Chess
{
private:
	struct position currentPosition;		// �o�ӴѪ���e��m
	// Black:1~7 Red:8~14 
	int chessType;
	vector<struct position> legalMove;

public:
	Chess();
	~Chess();
	// �bŪ�ѽL��󪺮ɭԥi�H��
	Chess(int type, int posX, int posY);
	
	
	void changePosition(int x, int y);
	

	// ��Ѥl�Q��쪺�ɭԡA��chessboard�ӧ��ܳo�ӭ�
	// ��쪺�ɭԨϩҦ�legalmove�ܦ�]�O�ѥL��
	bool chosen;
};

