#ifndef CONSOLE_H
#define CONSOLE_H

#include <Windows.h>

struct position
{
    int x, y;
    bool operator==(position other)
    {
        if (x == other.x&&y == other.y)return true;
        else return false;
    }
};

// �]�w�C��
void SetColor(int = 0x07);
// �]�w��Ц�m
void SetPosition(position);
// ���o��Ц�m
position getCursorPosition();
// ���o��ЬO�_���
void setCursorVisable(bool);
// �]�w�����Φr��j�p
void setConsole(int = 110, int=29, int = 18);

// �ഫ�y��
position cursorToChess(position);
position chessToCursor(position);

#endif // !CONSOLE_H
