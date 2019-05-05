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
    SetPosition(chessToCursor({ 4,6 }));
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
int UI::showMenu()
{
    vector<string> list = { "�~��C��", "���s�}�l", "�ϥδ���", "�����C��" };
    const short MENU_TOP = 10, MENU_LEFT = 38, MENU_RIGHT = 57;
    short menuBottom = static_cast<short>(MENU_TOP + list.size() * 2);
    SetColor(0x01);      // �]�w�©��Ŧr

    for (short i = MENU_TOP; i < menuBottom; i++)              // �L�©�
    {
        SetPosition({ MENU_LEFT,i });
        for (short j = MENU_LEFT; j <= MENU_RIGHT; j++)
        {
            cout << " ";
        }
    }
    for (short i = MENU_LEFT; i <= MENU_RIGHT; i++)     // �e��u
    {
        SetPosition({ i,MENU_TOP });
        cout << "��";
        SetPosition({ i,menuBottom });
        cout << "��";
    }

    for (short i = MENU_TOP; i < menuBottom; i++)     // �e���u
    {
        SetPosition({ MENU_LEFT,i });
        cout << "��";
        SetPosition({ MENU_RIGHT - 1,i });
        cout << "��";
    }

    SetPosition({ MENU_LEFT,menuBottom });
    cout << "��";
    SetPosition({ MENU_RIGHT - 1,menuBottom });
    cout << "��";
    SetPosition({ MENU_LEFT,MENU_TOP });
    cout << "��";
    SetPosition({ MENU_RIGHT - 1,MENU_TOP });
    cout << "��";


    setCursorVisable(false);

    char key, choice = 0;
    for (short i = 0; i < static_cast<short>(list.size()); i++)
    {
        if (i == choice)
        {
            SetColor(0x70);      // �]�w�G�ǩ��¦r
        }
        else
        {
            SetColor(0x07);      // �]�w�©��G�Ǧr
        }
        SetPosition({ MENU_LEFT + 6,MENU_TOP + 1 + 2 * i });
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
                    SetColor(0x70);      // �]�w�G�ǩ��¦r
                }
                else
                {
                    SetColor(0x07);      // �]�w�©��G�Ǧr
                }
                SetPosition({ MENU_LEFT + 6,MENU_TOP + 1 + 2 * i });
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
                    SetColor(0x70);      // �]�w�G�ǩ��¦r
                }
                else
                {
                    SetColor(0x07);      // �]�w�©��G�Ǧr
                }
                SetPosition({ MENU_LEFT + 6,MENU_TOP + 1 + 2 * i });
                cout << list[i];
            }
            break;
        case ENTER:
            setCursorVisable(true);
            SetPosition({ ROW_ONE + 3,TOP_BOUND + 3 });

            return choice;
            break;
        }
    }
}

// Intent: ���XY/N����
// Pre: UI����
// Post: �^�ǯu����
bool UI::showAlert(string message)
{
    const short ALERT_TOP = TOP_BOUND + 9, ALERT_BOTTOM = BOTTOM_BOUND - 7, ALERT_LEFT = ROW_ONE + 8, ALERT_RIGHT = ROW_TWO - 7;
    SetColor(0x04);      // �]�w�©��t���r

    for (short i = ALERT_TOP; i < ALERT_BOTTOM; i++)              // �L�©�
    {
        SetPosition({ ALERT_LEFT,i });
        for (unsigned j = ALERT_LEFT; j <= ALERT_RIGHT; j++)
        {
            cout << " ";
        }
    }
    for (short i = ALERT_LEFT; i <= ALERT_RIGHT; i++)     // �e��u
    {
        SetPosition({ i,ALERT_TOP });
        cout << "��";
        SetPosition({ i,BOTTOM_BOUND - 7 });
        cout << "��";
    }

    for (short i = ALERT_TOP; i <= ALERT_BOTTOM; i++)     // �e���u
    {
        SetPosition({ ALERT_LEFT,i });
        cout << "��";
        SetPosition({ ALERT_RIGHT - 1,i });
        cout << "��";
    }

    SetPosition({ ALERT_LEFT,ALERT_BOTTOM });
    cout << "��";
    SetPosition({ ALERT_RIGHT - 1,ALERT_BOTTOM });
    cout << "��";
    SetPosition({ ALERT_LEFT,ALERT_TOP });
    cout << "��";
    SetPosition({ ALERT_RIGHT - 1,ALERT_TOP });
    cout << "��";

    SetColor(0x07);
    SetPosition({ ALERT_LEFT + 8,ALERT_TOP + 3 });
    cout << message;

    SetPosition({ ALERT_LEFT + 6,ALERT_TOP + 5 });
    cout << "�O        �_";
    SetPosition({ ALERT_LEFT + 16,ALERT_TOP + 5 });

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
                SetPosition({ ROW_ONE + 24,ALERT_TOP + 5 });
            }
            else
            {
                choice = true;
                SetPosition({ ROW_ONE + 14,ALERT_TOP + 5 });
            }
            break;
        case ENTER:
            return choice;
        }
    }
}