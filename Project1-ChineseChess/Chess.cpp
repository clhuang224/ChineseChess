#include "Chess.h"

Chess::Chess()
{
	chessType = NULL;
	currentPosition.x = NULL;
	currentPosition.y = NULL;
	chosen = NULL;
}

Chess::Chess(int chessTypeInput, int xInput, int yInput)
{
	chessType = chessTypeInput;
	currentPosition.x = xInput;
	currentPosition.y = yInput;
	chosen = false;
}

Chess::~Chess()
{

}

int Chess::getChessType()
{
	return chessType;
}

void Chess::setCurrentPosition(int xInput, int yInput)
{
	currentPosition.x = xInput;
	currentPosition.y = yInput;
}

position Chess::getCurrentPosition()
{
	return currentPosition;
}

void Chess::setChosen(bool chosenInput)
{
	chosen = chosenInput;
}

bool Chess::getChosen()
{
	return chosen;
}

void Chess::setLegalMove()
{
	position temp = currentPosition;
	switch (chessType)
	{
	case 1: //�±N
		if (temp.x > 3) //�V��
		{
			temp.x--;
			legalMove.push_back(temp);
		}
		temp = currentPosition;
		if (temp.x < 5) //�V�k
		{
			temp.x++;
			legalMove.push_back(temp);
		}
		temp = currentPosition;
		if (temp.y > 0) //�V�W
		{
			temp.y--;
			legalMove.push_back(temp);
		}
		temp = currentPosition;
		if (temp.y < 2) //�V�U
		{
			temp.y++;
			legalMove.push_back(temp);
		}
		break;

	case 2: //�¤h
		if (temp.x > 3 && temp.y > 0) //�V���W
		{
			temp.x--;
			temp.y--;
			legalMove.push_back(temp);
		}
		temp = currentPosition;
		if (temp.x < 5 && temp.y > 0) //�V�k�W
		{
			temp.x++;
			temp.y--;
			legalMove.push_back(temp);
		}
		temp = currentPosition;
		if (temp.x > 3 && temp.y < 2) //�V���U
		{
			temp.x--;
			temp.y++;
			legalMove.push_back(temp);
		}
		temp = currentPosition;
		if (temp.x < 5 && temp.y < 2) //�V�k�U
		{
			temp.x++;
			temp.y++;
			legalMove.push_back(temp);
		}
		break;

	case 3: //�¶H
		if (temp.x - 2 >= 0 && temp.y - 2 >= 0) //�V���W
		{
			temp.x = temp.x - 2;
			temp.y = temp.y - 2;
			legalMove.push_back(temp);
		}
		temp = currentPosition;
		if (temp.x + 2 <= 8 && temp.y - 2 >= 0) //�V�k�W
		{
			temp.x = temp.x + 2;
			temp.y = temp.y - 2;
			legalMove.push_back(temp);
		}
		temp = currentPosition;
		if (temp.x - 2 >= 0 && temp.y + 2 <= 4) //�V���U
		{
			temp.x = temp.x - 2;
			temp.y = temp.y + 2;
			legalMove.push_back(temp);
		}
		temp = currentPosition;
		if (temp.x + 2 <= 8 && temp.y + 2 <= 4) //�V�k�U
		{
			temp.x = temp.x + 2;
			temp.y = temp.y + 2;
			legalMove.push_back(temp);
		}
		break;

	case 4: //�¨�
		while (temp.x > 0) //�V��
		{
			temp.x--;
			legalMove.push_back(temp);
		}
		temp = currentPosition;
		while (temp.x < 8) //�V�k
		{
			temp.x++;
			legalMove.push_back(temp);
		}
		temp = currentPosition;
		while (temp.y > 0) //�V�W
		{
			temp.y--;
			legalMove.push_back(temp);
		}
		temp = currentPosition;
		while (temp.y < 9) //�V�U
		{
			temp.y++;
			legalMove.push_back(temp);
		}
		break;

	case 5: //�°�
		break;

	case 6: //�¥]
		break;

	case 7: //�¨�
		break;

	case 8: //����
		if (temp.x > 3) //�V��
		{
			temp.x--;
			legalMove.push_back(temp);
		}
		temp = currentPosition;
		if (temp.x < 5) //�V�k
		{
			temp.x++;
			legalMove.push_back(temp);
		}
		temp = currentPosition;
		if (temp.y > 7) //�V�W
		{
			temp.y--;
			legalMove.push_back(temp);
		}
		temp = currentPosition;
		if (temp.y < 9) //�V�U
		{
			temp.y++;
			legalMove.push_back(temp);
		}
		break;

	case 9: //���K
		if (temp.x > 3 && temp.y > 7) //�V���W
		{
			temp.x--;
			temp.y--;
			legalMove.push_back(temp);
		}
		temp = currentPosition;
		if (temp.x < 5 && temp.y > 7) //�V�k�W
		{
			temp.x++;
			temp.y--;
			legalMove.push_back(temp);
		}
		temp = currentPosition;
		if (temp.x > 3 && temp.y < 9) //�V���U
		{
			temp.x--;
			temp.y++;
			legalMove.push_back(temp);
		}
		temp = currentPosition;
		if (temp.x < 5 && temp.y < 9) //�V�k�U
		{
			temp.x++;
			temp.y++;
			legalMove.push_back(temp);
		}
		break;

	case 10: //����
		if (temp.x - 2 >= 0 && temp.y - 2 >= 5) //�V���W
		{
			temp.x = temp.x - 2;
			temp.y = temp.y - 2;
			legalMove.push_back(temp);
		}
		temp = currentPosition;
		if (temp.x + 2 <= 8 && temp.y - 2 >= 5) //�V�k�W
		{
			temp.x = temp.x + 2;
			temp.y = temp.y - 2;
			legalMove.push_back(temp);
		}
		temp = currentPosition;
		if (temp.x - 2 >= 0 && temp.y + 2 <= 9) //�V���U
		{
			temp.x = temp.x - 2;
			temp.y = temp.y + 2;
			legalMove.push_back(temp);
		}
		temp = currentPosition;
		if (temp.x + 2 <= 8 && temp.y + 2 <= 9) //�V�k�U
		{
			temp.x = temp.x + 2;
			temp.y = temp.y + 2;
			legalMove.push_back(temp);
		}
		break;

	case 11: //����
		while (temp.x > 0) //�V��
		{
			temp.x--;
			legalMove.push_back(temp);
		}
		temp = currentPosition;
		while (temp.x < 8) //�V�k
		{
			temp.x++;
			legalMove.push_back(temp);
		}
		temp = currentPosition;
		while (temp.y > 0) //�V�W
		{
			temp.y--;
			legalMove.push_back(temp);
		}
		temp = currentPosition;
		while (temp.y < 9) //�V�U
		{
			temp.y++;
			legalMove.push_back(temp);
		}
		break;

	case 12: //���X
		break;

	case 13: //����
		break;

	case 14: //���L
		break;
	}
}

void Chess::clearLegalMove()
{
	legalMove.clear();
}

vector <position> Chess::getLegalMove()
{
	return legalMove;
}