#ifndef UI_H
#define UI_H

#include <windows.h>
#include <conio.h>

typedef struct cursorPos 
{
	int x;
	int y;
} cursorPos;

class UI
{
public:
	UI();
	~UI();

	static void printUI();
	static void showMenu();

	// ���o��e��Ц�m
	static cursorPos getCursorPos();

    // �]�w��e��X����
    static void SetColor(int = 7);
    // �]�w��Ц�m
    static void SetPosition(cursorPos);

private:
    // ��e��X����
    static int color;
    // ��e��Ц�m
    static cursorPos cursorPosition;
};

#endif // !UI_H

