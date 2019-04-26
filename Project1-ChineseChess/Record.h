#ifndef RECORD_H
#define RECORD_H

#include <vector>
using namespace std;

struct position
{
    int x;
    int y;
};

class Record
{
public:
    Record();
    ~Record();

    // �Ψ��x�s��ƪ�
    static vector<int> chessType;
    static vector<struct position> fromPos;
    static vector<struct position> toPos;


    static void printRecord();
    static void saveThisStep(int chessType, int fromX, int fromY, int toX, int toY);
};

#endif // !RECORD_H

