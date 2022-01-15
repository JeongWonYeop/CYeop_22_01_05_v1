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
    //// 저장 공간 같은 느낌.


    //// CRecord 의 주솟값을 담는 변수 mBlockArray.
    //// 그거를 한개가 아니라 여러개. 그래서 배열.
    CRecord *mBlockArray[Size];

private :
    int mCount;


};


#include "CYeopMultipleBlockArray.cpp"

#endif