#pragma once
#include <vector>
using std::vector;

struct position
{
	int positionX;
	int positionY;
};

class Chess
{
public:
	Chess();
	~Chess();
	// �bŪ�ѽL��󪺮ɭԥi�H��
	Chess(int type, int posX, int posY);
	
	// Black:1~7 Red:8~14 
	int chessType;
	struct position currentPosition;
	vector<struct position> legalMove;

	// ��Ѥl�Q��쪺�ɭԡA��chessboard�ӧ��ܳo�ӭ�
	bool chosen;
};

