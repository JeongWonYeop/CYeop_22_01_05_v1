#ifndef __CYEOPMULTIPLEBLOCKARRAY
#define __CYEOPMULTIPLEBLOCKARRAY


template <class CRecord, int Size, int Count >
class CYeopMultipleBlockArray
{
public:
    CYeopMultipleBlockArray();
    ~CYeopMultipleBlockArray();
    const CRecord GetRecord(int pos);
    CRecord * GetNewRecord(int pos);
    void AddRecord();
    void BlockArrayClear();
    int getCount();

protected:
    //// ���� ���� ���� ����.


    //// CRecord �� �ּڰ��� ��� ���� mBlockArray.
    //// �װŸ� �Ѱ��� �ƴ϶� ������. �׷��� �迭.
    CRecord *mBlockArray[Size];

private :
    int mCount;


};


#include "CYeopMultipleBlockArray.cpp"

#endif