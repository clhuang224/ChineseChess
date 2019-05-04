#include "UI.h"

const short TOP_BOUND = 1, BOTTOM_BOUND = 24, LEFT_BOUND = 1, RIGHT_BOUND = 106, ROW_ONE = 28, ROW_TWO = 66;
const char ESC = 0x1B, UP = 0x48, DOWN = 0x50, LEFT = 0x4B, RIGHT = 0x4D, ENTER = 0x0D;

UI::UI()
{
    lastChosed = NULL;
    cueMode = true;
}

// Intent: Ū����L
// Pre: UI����
// Post: �̾���L�ǤJ���Ȱ��X����
void UI::readKeyBoard()
{
    SetPosition(chessToCursor({4,6}));
    char key;
    while (1)
    {
        position cursorPosition = getCursorPosition();  // ���o��e��Ц�m
        switch (key = _getch())
        {
        case UP:                                        // �W
            if (cursorPosition.y - 2 > TOP_BOUND + 2)
            {
                SetPosition({ cursorPosition.x,cursorPosition.y - 2 });
            }
            break;
        case DOWN:                                      // �U
            if (cursorPosition.y + 2 < BOTTOM_BOUND)
            {
                SetPosition({ cursorPosition.x,cursorPosition.y + 2 });
            }
            break;
        case  LEFT:                                     // ��
            if (cursorPosition.x - 4 > ROW_ONE + 2)
            {
                SetPosition({ cursorPosition.x - 4,cursorPosition.y });
            }
            break;
        case  RIGHT:                                     // �k
            if (cursorPosition.x + 4 < ROW_TWO - 2)
            {
                SetPosition({ cursorPosition.x + 4,cursorPosition.y });
            }
            break;
        case ENTER:
            position chessPosition = cursorToChess(cursorPosition);
            if (lastChosed == NULL)                                         // �Y�D��Ѫ��A
            {
                Chess* currentChosed = chessBoard.getChess(chessPosition);
                if (currentChosed != NULL)                                   // �諸�a��S���Ѥl
                {
                    if (chessBoard.getTurn() == 0 && currentChosed->getChessType() <= 7 ||
                        chessBoard.getTurn() == 1 && currentChosed->getChessType() >= 8)    // ��ѲŦXturn
                    {
                        chessBoard.manageLegalMove(chessPosition.x, chessPosition.y);
                        lastChosed = chessBoard.getChess(chessPosition);
                        lastChosed->setChosen(true);
                        if (cueMode == true)                                    // �Y���ܶ}�ҫh�L�X����
                        {
                            chessBoard.printChosenPlane();
                        }
                    }
                }
            }
            else                                                           // �Y�w����ܪ���
            {
                bool legal = false;                                         // �ݯ�_�X�k����
                for (unsigned i = 0; i < chessBoard.legalMove.size(); i++)
                {
                    if (chessPosition == chessBoard.legalMove[i])
                    {
                        legal = true;
                        chessBoard.moveTheChess(lastChosed->getCurrentPosition().x,
                            lastChosed->getCurrentPosition().y,
                            chessPosition.x,
                            chessPosition.y);
                        
                        lastChosed->setChosen(false);
                        lastChosed = NULL;
                        chessBoard.changTurn();
                        chessBoard.printThePlane();
                        chessBoard.clearLegalMove();
                        break;
                    }
                }
                if (legal == false)                                         // �S�X�k�N��F
                {
                    // ��F
                }

            }
            break;
        case ESC:                                      // ���
            switch (showMenu())
            {
            case 0:                                     // �~��C��
                chessBoard.printThePlane();
                break;
            case 1:                                     // ���s�}�l
                // �A�ݬݻݤ��ݭn��
                chessBoard.printThePlane();
                break;
            case 2:                                     // �ϥδ���
                if (showAlert("�ϥδ��ܡH") == true)
                {
                    cueMode = true;
                    chessBoard.printThePlane();
                }
                else
                {
                    cueMode = false;
                    chessBoard.printThePlane();
                }
                break;
                break;
            case 3:                                     // �����C��
                if (showAlert("�����C���H") == true)
                {
                    return;
                }
                else
                {
                    chessBoard.printThePlane();
                }
                break;
            }
            break;
        case 'u':
        case 'U':                                       // ����
            if (showAlert("�T�w���ѡH") == true)
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
            if (showAlert("�T�w�٭�H") == true)
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
    SetPosition({ LEFT_BOUND + 2, BOTTOM_BOUND - 1 });              // ���檺�U��
    for (short i = 0; i < ROW_ONE - 2; i++)
    {
        cout << "��";
    }
    SetPosition({ ROW_TWO, TOP_BOUND + 1 });             // �k�檺�W��
    for (short i = 0; i < RIGHT_BOUND - 2 - ROW_TWO; i++)
    {
        cout << "��";
    }
    SetPosition({ ROW_TWO + 1, BOTTOM_BOUND - 1 });          // �k�檺�U��
    for (short i = 0; i < RIGHT_BOUND - 2 - ROW_TWO; i++)
    {
        cout << "��";
    }
    SetPosition({ ROW_TWO, BOTTOM_BOUND - 9 });                  // �k�檺���j�u
    for (short i = 0; i < RIGHT_BOUND - ROW_TWO - 1; i++)
    {
        cout << "��";
    }

    SetPosition({ LEFT_BOUND, TOP_BOUND });                 // �L����
    cout << "��";
    SetPosition({ LEFT_BOUND + 2, TOP_BOUND + 1 });
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
    SetPosition({ ROW_TWO, BOTTOM_BOUND - 1 });
    cout << "��";

    SetPosition({ RIGHT_BOUND, BOTTOM_BOUND });
    cout << "��";
    SetPosition({ RIGHT_BOUND - 2, BOTTOM_BOUND - 1 });
    cout << "��";
    SetPosition({ ROW_ONE, BOTTOM_BOUND - 1 });
    cout << "��";

    SetPosition({ ROW_TWO, BOTTOM_BOUND - 9 });
    cout << "��";
    SetPosition({ RIGHT_BOUND - 2, BOTTOM_BOUND - 9 });
    cout << "��";

    SetPosition({ LEFT_BOUND + 6, TOP_BOUND + 1 });           // �L�r
    cout << "  ��  �p  ��  ��  ";
    SetPosition({ ROW_TWO + 6,BOTTOM_BOUND - 8 });
    cout << "ESC ���    U ����    R �٭�";
    SetPosition({ ROW_TWO + 9,BOTTOM_BOUND - 6 });
    cout << "Enter     ����Ѥl";
    SetPosition({ ROW_TWO + 11,BOTTOM_BOUND - 4 });
    cout << "��";
    SetPosition({ ROW_TWO + 9,BOTTOM_BOUND - 3 });
    cout << "��  ��  ��V�䱱����";
    SetPosition({ ROW_TWO + 11,BOTTOM_BOUND - 2 });
    cout << "��";
}

// Intent: ���X���
// Pre: UI����
// Post: �^�ǿ��
int showMenu()
{
    vector<string> list = { "�~��C��", "���s�}�l", "�ϥδ���", "�����C��" };
    const short MENU_TOP = 10, MENU_LEFT = 38, MENU_RIGHT = 57;
    short menuBottom = static_cast<short>(MENU_TOP + list.size() * 2);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x01);      // �]�w�©��Ŧr

    for (short i = MENU_TOP; i < menuBottom; i++)              // �L�©�
    {
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { MENU_LEFT,i });
        for (short j = MENU_LEFT; j <= MENU_RIGHT; j++)
        {
            cout << " ";
        }
    }
    for (short i = MENU_LEFT; i <= MENU_RIGHT; i++)     // �e��u
    {
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { i,MENU_TOP });
        cout << "��";
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { i,menuBottom });
        cout << "��";
    }

    for (short i = MENU_TOP; i < menuBottom; i++)     // �e���u
    {
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { MENU_LEFT,i });
        cout << "��";
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { MENU_RIGHT - 1,i });
        cout << "��";
    }

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { MENU_LEFT,menuBottom });
    cout << "��";
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { MENU_RIGHT - 1,menuBottom });
    cout << "��";
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { MENU_LEFT,MENU_TOP });
    cout << "��";
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { MENU_RIGHT - 1,MENU_TOP });
    cout << "��";


    CONSOLE_CURSOR_INFO temp;                                                   // ���ô��
    temp.dwSize = 100;
    temp.bVisible = false;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &temp);

    char key, choice = 0;
    for (short i = 0; i < static_cast<short>(list.size()); i++)
    {
        if (i == choice)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x70);      // �]�w�թ��¦r
        }
        else
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07);      // �]�w�©��զr
        }
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { MENU_LEFT + 6,MENU_TOP + 1 + 2 * i });
        cout << list[i];
    }
    while (1)
    {
        key = _getch();
        switch (key)
        {
        case UP:
            if (choice > 0)
            {
                choice--;
            }
            else
            {
                choice = 3;
            }
            for (short i = 0; i < static_cast<short>(list.size()); i++)
            {
                if (i == choice)
                {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x70);      // �]�w�թ��¦r
                }
                else
                {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07);      // �]�w�©��զr
                }
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { MENU_LEFT + 6,MENU_TOP + 1 + 2 * i });
                cout << list[i];
            }
            break;
        case DOWN:
            if (choice < 3)
            {
                choice++;
            }
            else
            {
                choice = 0;
            }
            for (short i = 0; i < static_cast<short>(list.size()); i++)
            {
                if (i == choice)
                {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x70);      // �]�w�թ��¦r
                }
                else
                {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07);      // �]�w�©��զr
                }
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { MENU_LEFT + 6,MENU_TOP + 1 + 2 * i });
                cout << list[i];
            }
            break;
        case ENTER:
            temp.dwSize = 100;                                                           // ��ܴ��
            temp.bVisible = true;
            SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &temp);
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { ROW_ONE + 3,TOP_BOUND + 3 });

            return choice;
            break;
        }
    }
}

// Intent: ���XY/N����
// Pre: UI����
// Post: �^�ǯu����
bool showAlert(string message)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);      // �]�w�©��զr

    for (short i = TOP_BOUND + 10; i < BOTTOM_BOUND - 7; i++)              // �L�©�
    {
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { static_cast<short>(ROW_ONE + 8),static_cast<short>(i) });
        for (unsigned j = ROW_ONE + 8; j < ROW_TWO - 6; j++)
        {
            cout << " ";
        }
    }
    for (short i = ROW_ONE + 8; i < ROW_TWO - 6; i++)     // �e��u
    {
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { static_cast<short>(i),static_cast<short>(TOP_BOUND + 10) });
        cout << "��";
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { static_cast<short>(i),static_cast<short>(BOTTOM_BOUND - 7) });
        cout << "��";
    }

    for (short i = TOP_BOUND + 10; i <= BOTTOM_BOUND - 7; i++)     // �e���u
    {
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { static_cast<short>(ROW_ONE + 8),static_cast<short>(i) });
        cout << "��";
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { static_cast<short>(ROW_TWO - 8),static_cast<short>(i) });
        cout << "��";
    }

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { static_cast<short>(ROW_ONE + 8),static_cast<short>(BOTTOM_BOUND - 7) });
    cout << "��";
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { static_cast<short>(ROW_TWO - 8),static_cast<short>(BOTTOM_BOUND - 7) });
    cout << "��";
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { static_cast<short>(ROW_ONE + 8),static_cast<short>(TOP_BOUND + 10) });
    cout << "��";
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { static_cast<short>(ROW_TWO - 8),static_cast<short>(TOP_BOUND + 10) });
    cout << "��";

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { static_cast<short>(ROW_ONE + 16),static_cast<short>(TOP_BOUND + 13) });
    cout << message;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { static_cast<short>(ROW_ONE + 14),static_cast<short>(TOP_BOUND + 15) });
    cout << "�O        �_";
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { static_cast<short>(ROW_ONE + 24),static_cast<short>(TOP_BOUND + 15) });

    char key;
    bool choice = false;
    while (1)
    {
        key = _getch();
        switch (key)
        {
        case LEFT:
        case RIGHT:
            if (choice == true)
            {
                choice = false;
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { static_cast<short>(ROW_ONE + 24),static_cast<short>(TOP_BOUND + 15) });
            }
            else
            {
                choice = true;
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { static_cast<short>(ROW_ONE + 14),static_cast<short>(TOP_BOUND + 15) });
            }
            break;
        case ENTER:
            return choice;
        }
    }
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
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { static_cast<short>(newPosition.x),static_cast<short>(newPosition.y) });
}



// Intent: ���o��e��Ц�m
// Pre: UI����
// Post: �^��position
position UI::getCursorPosition()
{
    CONSOLE_SCREEN_BUFFER_INFO cSBInfo;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cSBInfo);
    return { cSBInfo.dwCursorPosition.X,cSBInfo.dwCursorPosition.Y };
}