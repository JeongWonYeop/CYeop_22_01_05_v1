#include <vcruntime.h>
#include <cstring>

template <class CRecord, int Size, int count >
CYeopMultipleBlockArray< CRecord, Size, count >::CYeopMultipleBlockArray()
    :mCount(0)
 {
    for( int i = 0 ; i < Size ; i++)
    {
        mBlockArray[i] = NULL;
    }

    BlockArrayClear();
 }
template <class CRecord, int Size, int Count  >
 CYeopMultipleBlockArray< CRecord, Size, Count >::~CYeopMultipleBlockArray()
 {
     // 초기화
     int iAccumulatedCount = mCount / Size;

     for (int i = 0; i < iAccumulatedCount; i++)
     {
         if (NULL != mBlockArray[i])
         {
             delete[] mBlockArray[i];
             mBlockArray[i] = NULL;
         }
     }
 }
 template <class CRecord, int Size, int Count  >
 const CRecord *CYeopMultipleBlockArray< CRecord, Size, Count >::GetRecord(int pos)
 {
// 있는 것 안에서.
     CRecord *ret = NULL;
     int iFindSize = pos / Size;
     int iFindCount = pos % Size;
     if( NULL != mBlockArray [iFindSize] )
     {
         //// 여태까지 들어가 있는 데이터 갯수 mCount 개.
         if( iFindCount <= mCount % Size )
         {
             ret = &mBlockArray[iFindSize][iFindCount];
         }
         
     }

     return ret;
 }

 template <class CRecord, int Size, int Count  >
 CRecord * CYeopMultipleBlockArray< CRecord, Size, Count >::GetNewRecord(int pos)
 {
     CRecord *ret = NULL;
     int iFindSize = pos / Size;
     int iFindCount = pos % Size;

     if( iFindSize < Size )
     {
         if( NULL == mBlockArray[iFindSize] )
         {

             //// 갯수 설정. 얼마나 메모리 확보 할 건데?
             mBlockArray[iFindSize] = new CRecord[Count];
             //// 포인터를 sizeof 로 쓰는 건 안된다. 왜냐면 모든 포인터는 4byte.
             memset(mBlockArray[iFindSize], 0, sizeof(CRecord)*Count);
         }

         ret = &mBlockArray[iFindSize][iFindCount];
//        mBlockArray[iFindSize] = new CRecord* count;
//        ret = &mBlockArray[iFindSize][iFindCount];
     }

     return ret;

 }

 template <class CRecord, int Size, int Count  >
 void CYeopMultipleBlockArray< CRecord, Size, Count >::AddRecord()
 {
     mCount += 1;
 }


 template <class CRecord, int Size, int Count >
 void CYeopMultipleBlockArray< CRecord, Size, Count >::BlockArrayClear()
 {

     // 초기화
     int iAccumulatedCount = mCount / Size;

     for (int i = 0; i < iAccumulatedCount; i++)
     {
         memset(mBlockArray[i], 0, sizeof(mBlockArray[i]));
     }

 }


 template <class CRecord, int Size, int Count >
int CYeopMultipleBlockArray< CRecord, Size, Count >::getCount()
{
    return mCount;
}




