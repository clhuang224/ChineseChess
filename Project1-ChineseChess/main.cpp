#include "UI.h"
#include "Record.h"
// #include "Marquee.h"


using namespace std;

int main()
{

    // setWindow(); //�վ�����j�p �r��j�p��  �ק襤

	UI thisGameUI;
    Music::setMusic(2);
	
	thisGameUI.printUI();
	thisGameUI.chessBoard.printThePlane();
	Record::printRecord();
	// Marquee::runWord();

    thisGameUI.readKeyBoard();

}