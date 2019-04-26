#include "UI.h"

int UI::color = 7;
position UI::cursorPosition = { 0,0 };

static short TOP_BOUND = 1, BOTTOM_BOUND = 40, LEFT_BOUND = 1, RIGHT_BOUND = 148, ROW_ONE = 39, ROW_TWO = 107;

void UI::readKeyBoard()
{
    SetPosition({ ROW_ONE+11,TOP_BOUND+4 });
    char input;
    while (1)
    {
        input = _getch();
        switch (input)
        {
        case 0X1B:          // ESC
            return;
        case 0x48:          //�W
            if (cursorPosition.y - 4 > TOP_BOUND + 2)
            {
                cursorPosition.y -= 4;
                SetPosition(cursorPosition);
            }
            break;
        case 0x50:          //�U
            if (cursorPosition.y + 4 < BOTTOM_BOUND - 2)
            {
                cursorPosition.y += 4;
                SetPosition(cursorPosition);
            }
            break;
        case  0x4B:         //��
            if (cursorPosition.x - 5 > ROW_ONE + 10)
            {
                cursorPosition.x -= 5;
                SetPosition(cursorPosition);
            }
            break;
        case  0x4D:         //�k
            if (cursorPosition.x + 5 < ROW_TWO - 10)
            {
                cursorPosition.x += 5;
                SetPosition(cursorPosition);
            }
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
    SetPosition({ ROW_TWO + 11,TOP_BOUND + 4 });
    cout << " �ġġġġġġġġġ� ";
    SetPosition({ ROW_TWO + 11,TOP_BOUND + 5 });
    cout << "�U�@�@Chinese�@�@ �@�U";
    SetPosition({ ROW_TWO + 11,TOP_BOUND + 6 });
    cout << "�U�@�@�@�@Chess�@�@ �U";
    SetPosition({ ROW_TWO + 11,TOP_BOUND + 7 });
    cout << " �ááááááááá� ";
    SetColor(7);

    // ����
    SetPosition({ ROW_TWO + 13,TOP_BOUND + 15 });
    cout << "�ثe����";
    SetColor(252);
    cout << "����";
    SetColor(7);
    cout << "�U��";
    SetPosition({ ROW_TWO + 13,TOP_BOUND + 16 });
    cout << "���M�N�O";
    SetColor(240);
    cout << "�¤�";
    SetColor(7);
    cout << "�U��";


    // �e���
    SetPosition({ ROW_TWO + 13,TOP_BOUND + 24 });
    cout << "��V��G���ʴ��";
    SetPosition({ ROW_TWO + 13,TOP_BOUND + 27 });
    cout << " Enter�G���/�T�w";
    SetPosition({ ROW_TWO + 13,TOP_BOUND + 30 });
    cout << "�@��@�G  �� ��";
    SetPosition({ ROW_TWO + 13,TOP_BOUND + 33 });
    cout << "�@��@�G  �� ��";
    SetPosition({ ROW_TWO + 13,TOP_BOUND + 36 });
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