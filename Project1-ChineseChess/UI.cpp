#include "UI.h"

position UI::cursorPosition = { 0,0 };

const short TOP_BOUND = 1, BOTTOM_BOUND = 28, LEFT_BOUND = 1, RIGHT_BOUND = 106, ROW_ONE = 28, ROW_TWO = 66;

// Intent: Ū����L
// Pre: UI����
// Post: �̾���L�ǤJ���Ȱ��X����
void UI::readKeyBoard()
{
    const char ESC = 0x1B, UP = 0x48, DOWN = 0x50, LEFT = 0x4B, RIGHT = 0x4D;
    SetPosition({ ROW_ONE + 3,TOP_BOUND + 3 });
    char input;
    while (1)
    {
        input = _getch();
        switch (input)
        {
        case UP:                                        //�W
            if (cursorPosition.y - 2 > TOP_BOUND + 2)
            {
                cursorPosition.y -= 2;
                SetPosition(cursorPosition);
            }
            break;
        case DOWN:                                      // �U
            if (cursorPosition.y + 2 < BOTTOM_BOUND )
            {
                cursorPosition.y += 2;
                SetPosition(cursorPosition);
            }
            break;
        case  LEFT:                                     // ��
            if (cursorPosition.x - 4 > ROW_ONE + 2)
            {
                cursorPosition.x -= 4;
                SetPosition(cursorPosition);
            }
            break;
        case  RIGHT:                                     // �k
            if (cursorPosition.x + 4 < ROW_TWO - 2)
            {
                cursorPosition.x += 4;
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
    
    for (short i = 0; i < BOTTOM_BOUND - 1; i++)            // �L���u
    {
        SetPosition({ LEFT_BOUND, TOP_BOUND + i });             // �̥����
        cout << "�� ��";
        SetPosition({ ROW_ONE, TOP_BOUND + i });                // �ѽL����
        cout << "��";
        SetPosition({ ROW_TWO, TOP_BOUND + i });                // �ѽL�k��
        cout << "��";
        SetPosition({ RIGHT_BOUND - 2, TOP_BOUND + i });        // �̥k���
        cout << "�� ��";
    }

    SetPosition({ LEFT_BOUND, TOP_BOUND });                 // �L��u
    for (short i = 0; i < RIGHT_BOUND - 1; i++)                 // �̤W
    {
        cout << "��";
    }
    SetPosition({ LEFT_BOUND, BOTTOM_BOUND });                  // �̤U
    for (short i = 0; i < RIGHT_BOUND - 1; i++)
    {
        cout << "��";
    }
    SetPosition({ LEFT_BOUND + 2, TOP_BOUND + 1 });             // ���檺�W��
    for (short i = 0; i < ROW_ONE - 2; i++)
    {
        cout << "��";
    }
    SetPosition({ LEFT_BOUND+2, BOTTOM_BOUND-1 });              // ���檺�U��
    for (short i = 0; i < ROW_ONE-2; i++)
    {
        cout << "��";
    }
    SetPosition({ ROW_TWO, TOP_BOUND + 1 });             // �k�檺�W��
    for (short i = 0; i < RIGHT_BOUND-2-ROW_TWO; i++)
    {
        cout << "��";
    }
    SetPosition({ ROW_TWO + 1, BOTTOM_BOUND - 1 });          // �k�檺�U��
    for (short i = 0; i < RIGHT_BOUND - 2 - ROW_TWO; i++)
    {
        cout << "��";
    }
    SetPosition({ ROW_TWO, BOTTOM_BOUND -9 });                  // �k�檺���j�u
    for (short i = 0; i < RIGHT_BOUND - ROW_TWO-1; i++)
    {
        cout << "��";
    }

    SetPosition({ LEFT_BOUND, TOP_BOUND });                 // �L����
    cout << "��";
    SetPosition({ LEFT_BOUND+2, TOP_BOUND+1 });
    cout << "��";
    SetPosition({ ROW_TWO, TOP_BOUND + 1 });
    cout << "��";

    SetPosition({ RIGHT_BOUND, TOP_BOUND });
    cout << "��";
    SetPosition({ RIGHT_BOUND - 2, TOP_BOUND + 1 });
    cout << "��";
    SetPosition({ ROW_ONE, TOP_BOUND + 1 });
    cout << "��";

    SetPosition({ LEFT_BOUND, BOTTOM_BOUND });
    cout << "��";
    SetPosition({ LEFT_BOUND + 2, BOTTOM_BOUND - 1 });
    cout << "��";
    SetPosition({ ROW_TWO, BOTTOM_BOUND -1 });
    cout << "��";

    SetPosition({ RIGHT_BOUND, BOTTOM_BOUND });
    cout << "��";
    SetPosition({ RIGHT_BOUND - 2, BOTTOM_BOUND - 1 });
    cout << "��";
    SetPosition({ ROW_ONE, BOTTOM_BOUND - 1 });
    cout << "��";

    SetPosition({ ROW_TWO, BOTTOM_BOUND - 9 });
    cout << "��";
    SetPosition({ RIGHT_BOUND-2, BOTTOM_BOUND - 9 });
    cout << "��";

    SetPosition({ LEFT_BOUND+6, TOP_BOUND + 1 });           // �L�r
    cout << "  ��  �p  ��  ��  ";
    SetPosition({ROW_TWO+6,BOTTOM_BOUND-8});
    cout << "ESC ���    < ����    > �٭�";
    SetPosition({ ROW_TWO + 9,BOTTOM_BOUND - 6 });
    cout << "Enter     ����Ѥl";
    SetPosition({ ROW_TWO + 11,BOTTOM_BOUND - 4 });
    cout << "��";
    SetPosition({ ROW_TWO + 9,BOTTOM_BOUND - 3 });
    cout << "��  ��  ��V�䱱����";
    SetPosition({ ROW_TWO + 11,BOTTOM_BOUND - 2 });
    cout << "��";
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