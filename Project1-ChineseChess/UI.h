#pragma once

static struct cursorPos 
{
	int x;
	int y;
};

class UI
{
public:
	UI();
	~UI();

	static void printUI();
	static void showMenu();

	// ���o��e��Ц�m
	static struct cursorPos getCursorPos();

};

