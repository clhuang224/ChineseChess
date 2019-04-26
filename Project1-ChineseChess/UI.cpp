#include "UI.h"

position UI::cursorPosition = { 0,0 };

const short TOP_BOUND = 1, BOTTOM_BOUND = 40, LEFT_BOUND = 1, RIGHT_BOUND = 148, ROW_ONE = 39, ROW_TWO = 107;

// Intent: Ū����L
// Pre: UI����
// Post: �̾���L�ǤJ���Ȱ��X����
void UI::readKeyBoard()
{
    const char ESC = 0x1B, UP = 0x48, DOWN = 0x50, LEFT = 0x4B, RIGHT = 0x4D;
    SetPosition({ ROW_ONE + 11,TOP_BOUND + 4 });
    char input;
    while (1)
    {
        input = _getch();
        switch (input)
        {
        case UP:                                        //�W
            if (cursorPosition.y - 4 > TOP_BOUND + 2)
            {
                cursorPosition.y -= 4;
                SetPosition(cursorPosition);
            }
            break;
        case DOWN:                                      // �U
            if (cursorPosition.y + 4 < BOTTOM_BOUND - 2)
            {
                cursorPosition.y += 4;
                SetPosition(cursorPosition);
            }
            break;
        case  LEFT:                                     // ��
            if (cursorPosition.x - 5 > ROW_ONE + 10)
            {
                cursorPosition.x -= 5;
                SetPosition(cursorPosition);
            }
            break;
        case  RIGHT:                                     // �k
            if (cursorPosition.x + 5 < ROW_TWO - 10)
            {
                cursorPosition.x += 5;
                SetPosition(cursorPosition);
            }
            break;
        case ESC:                                      // ���}�C��
            if (showAlert("�n�����C���ܡH") == true)
            {
                return;
            }
            else
            {
                // �������N�����L�쥻�ѽL��alert�\��
                chessBoard.printThePlane();
            }
            break;
        case 'u':
        case 'U':                                       // ����
            if (showAlert("�@�n���ѶܡH�@") == true)
            {
                /*

                �o�̭n call ���Ѫ�function

                */
                // �����ѫ�L�X��s�᪺�ѽL
                chessBoard.printThePlane();
            }
            else
            {
                // �����ѴN�����L�쥻�ѽL��alert�\��
                chessBoard.printThePlane();
            }
            break;
        case 'r':
        case 'R':                                       // �٭�
            if (showAlert("�@�n�٭�ܡH�@") == true)
            {
                /*

                �o�̭n call �٭쪺function

                */
                // ���٭��L�X��s�᪺�ѽL
                chessBoard.printThePlane();
            }
            else
            {
                // ���٭�N�����L�쥻�ѽL��alert�\��
                chessBoard.printThePlane();
            }
            break;
        }
    }
}

// Intent: �L�X�ާ@�e��
// Pre: UI����
// Post: �L�X���G
void UI::printUI()
{
    keybd_event(VK_MENU, 0x38, 0, 0);                   // �]�w���ù�
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
    
    SetColor(100);                                      // �e���D
    SetPosition({ ROW_TWO + 11,TOP_BOUND + 4 });
    cout << " �ġġġġġġġġġ� ";
    SetPosition({ ROW_TWO + 11,TOP_BOUND + 5 });
    cout << "�U�@�@Chinese�@�@ �@�U";
    SetPosition({ ROW_TWO + 11,TOP_BOUND + 6 });
    cout << "�U�@�@�@�@Chess�@�@ �U";
    SetPosition({ ROW_TWO + 11,TOP_BOUND + 7 });
    cout << " �ááááááááá� ";
    SetColor(7);

    SetPosition({ ROW_TWO + 13,TOP_BOUND + 15 });       // ��ܽ����
    cout << "�ثe����";
    //if (chessBoard.getTurn() == 0)        // static function �L�k�ϥ� �Dstatic ��chessBoard
    //                                      // �o�q�i�൹ChessBoard �ӦL����n
    //{
    //    SetColor(240);
    //    cout << "�¤�";
    //}
    //else
    //{
    SetColor(252);
    cout << "����";
    //}
    SetColor(7);
    cout << "�U��";

    SetPosition({ ROW_TWO + 13,TOP_BOUND + 24 });       // �e���
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

// Intent: ���XY/N����
// Pre: UI����
// Post: �^�ǯu����
bool showAlert(string message)
{
    for (short i = LEFT_BOUND + 44; i <= RIGHT_BOUND - 46; i++)     // �e��u
    {
        UI::SetPosition({ i,TOP_BOUND + 10 });
        cout << "-";
        for (short j = TOP_BOUND + 11; j <= BOTTOM_BOUND - 11; j++)
        {
            UI::SetPosition({ i,j });
            cout << " ";
        }
        UI::SetPosition({ i,BOTTOM_BOUND - 10 });
        cout << "-";
    }

    for (short i = TOP_BOUND + 10; i <= BOTTOM_BOUND - 10; i++)     // �e���u
    {

        UI::SetPosition({ ROW_ONE + 5,i });
        cout << "|";
        UI::SetPosition({ ROW_TWO - 5,i });
        cout << "|";
    }

    UI::SetCursorVisible(false);                                    // �L�X���e�����ô��
    UI::SetPosition({ LEFT_BOUND + 65,TOP_BOUND + 18 });
    cout << message;
    UI::SetPosition({ LEFT_BOUND + 63,TOP_BOUND + 21 });
    cout << "[Y]�T�w   [N]����";
    UI::SetPosition({ 200,100 });

    char decision;                                                  // ��ܽT�w�Ψ���
    while (1)
    {
        decision = _getch();
        switch (decision)
        {
        case 'y':
        case 'Y':
            UI::SetCursorVisible(true);
            UI::SetPosition({ 50,5 });
            return true;
        case 'n':
        case 'N':
            UI::SetCursorVisible(true);
            UI::SetPosition({ 50,5 });
            return false;
        }
    }
}

// Intent: ���o��e��Ц�m
// Pre: UI����
// Post: �^��position
position UI::getCursorPos()
{
    return cursorPosition;
}

// Intent: �]�w��r�C��
// Pre: UI����
// Post: ��r�C��Q����
void UI::SetColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// Intent: �]�w��Ц�m
// Pre: UI����
// Post: ��Ц�m�Q����
void UI::SetPosition(position newPosition)
{
    UI::cursorPosition = newPosition;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { static_cast<short>(cursorPosition.x),static_cast<short>(cursorPosition.y) });
}

// Intent: �]�w��ЬO�_��ܤΤj�p
// Pre: UI����
// Post: �����ܪ��A�Q����
void UI::SetCursorVisible(bool visible, DWORD size)
{
    CONSOLE_CURSOR_INFO cci;
    cci.bVisible = visible;
    cci.dwSize = size;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
}