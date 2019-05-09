#include "Console.h"

const short TOP_BOUND = 1, ROW_ONE = 28;

// Intent: �]�w�C��
// Pre: �C��s���]0x���r�F0�� 3�� 4�t�� 7�G�� 8�t�� C�G�� D���� F�� ex. 0x07�©��G�Ǧr�^
// Post: ��Ц�m�Q����
void SetColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// Intent: �]�w��Ц�m
// Pre: �L
// Post: ��Ц�m�Q����
void SetPosition(position newPosition)
{
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { static_cast<short>(newPosition.x),static_cast<short>(newPosition.y) });
}

// Intent: ���o��e��Ц�m
// Pre: �L
// Post: �^��position
position getCursorPosition()
{
    CONSOLE_SCREEN_BUFFER_INFO cSBInfo;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cSBInfo);
    return { cSBInfo.dwCursorPosition.X,cSBInfo.dwCursorPosition.Y };
}

// Intent: �]�w��ЬO�_���
// Pre: �u����
// Post: �����ܩ�����
void setCursorVisable(bool set)
{
    CONSOLE_CURSOR_INFO cci;
    cci.dwSize = 100;
    cci.bVisible = set;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
}

// Intent: �N��Юy���ର�ѽL�y��
// Pre: ��Юy��
// Post: �ѽL�y��
position cursorToChess(position cursorPosition)
{
    position chessPosition;
    chessPosition.x = (cursorPosition.x - ROW_ONE - 3) / 4;
    chessPosition.y = (cursorPosition.y - TOP_BOUND - 3) / 2;
    return chessPosition;
}

// Intent: �N�ѽL�y���ର��Юy��
// Pre: �ѽL�y��
// Post: ��Юy��
position chessToCursor(position chessPosition)
{
    position cursorPosition;
    cursorPosition.x = chessPosition.x * 4 + ROW_ONE + 3;
    cursorPosition.y = chessPosition.y * 2 + TOP_BOUND + 3;
    return cursorPosition;
}