#include "UI.h"

int UI::color = 7;
position UI::cursorPosition = { 0,0 };

void UI::readKeyBoard()
{
    SetPosition({ 10,10 });
    char input;
    while (1)
    {
        input = _getch();
        switch (input)
        {
        case 0X1B:          // ESC
            return;
        case 0x48:          //�W
            cursorPosition.y--;
            SetPosition(cursorPosition);
            break;
        case 0x50:          //�U
            cursorPosition.y++;
            SetPosition(cursorPosition);
            break;
        case  0x4B:         //��
            cursorPosition.x--;
            SetPosition(cursorPosition);
            break;
        case  0x4D:         //�k
            cursorPosition.x++;
            SetPosition(cursorPosition);
            break;
        }
    }



}

void UI::printUI()
{
    keybd_event(VK_MENU, 0x38, 0, 0);                   // ���ù�
    keybd_event(VK_RETURN, 0x1c, 0, 0);
    keybd_event(VK_MENU, 0xb8, KEYEVENTF_KEYUP, 0);
    keybd_event(VK_RETURN, 0x9c, KEYEVENTF_KEYUP, 0);

    short TOP_BOUND = 1, BOTTOM_BOUND = 40, LEFT_BOUND = 1, RIGHT_BOUND = 148, ROW_ONE = 39, ROW_TWO = 107;

    for (short i = LEFT_BOUND; i <= RIGHT_BOUND; i++)   // �e��u
    {
        SetPosition({ i,TOP_BOUND });
        cout << "/";
        SetPosition({ i,BOTTOM_BOUND });
        cout << "/";
    }
    for (short i = TOP_BOUND; i <= BOTTOM_BOUND; i++)   // �e���u
    {
        SetPosition({ LEFT_BOUND,i });
        cout << "/";
        SetPosition({ RIGHT_BOUND,i });
        cout << "/";
        SetPosition({ ROW_ONE,i });
        cout << "/";
        SetPosition({ ROW_TWO,i });
        cout << "/";
    }

    // �e���D
    SetColor(100);
    SetPosition({ ROW_TWO + 11,TOP_BOUND + 8 });
    cout << " �ġġġġġġġġġ� ";
    SetPosition({ ROW_TWO + 11,TOP_BOUND + 9 });
    cout << "�U�@�@Chinese�@�@ �@�U";
    SetPosition({ ROW_TWO + 11,TOP_BOUND + 10 });
    cout << "�U�@�@�@�@Chess�@�@ �U";
    SetPosition({ ROW_TWO + 11,TOP_BOUND + 11 });
    cout << " �ááááááááá� ";
    SetColor(7);

    // �e���
    SetPosition({ ROW_TWO + 13,TOP_BOUND + 23 });
    cout << "��V��G���ʴ��";
    SetPosition({ ROW_TWO + 13,TOP_BOUND + 26 });
    cout << " Enter�G���/�T�w";
    SetPosition({ ROW_TWO + 13,TOP_BOUND + 29 });
    cout << "�@U�@�G  �� ��";
    SetPosition({ ROW_TWO + 13,TOP_BOUND + 32 });
    cout << "�@U�@�G  �� ��";
    SetPosition({ ROW_TWO + 13,TOP_BOUND + 35 });
    cout << "�Ӣ�ѡG���}�C��";

}

void UI::showMenu()
{
}


position UI::getCursorPos()
{
    return cursorPosition;
}

void UI::SetColor(int newColor)
{
    UI::color = newColor;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void UI::SetPosition(position newPosition)
{
    UI::cursorPosition = newPosition;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { static_cast<short>(cursorPosition.x),static_cast<short>(cursorPosition.y) });
}