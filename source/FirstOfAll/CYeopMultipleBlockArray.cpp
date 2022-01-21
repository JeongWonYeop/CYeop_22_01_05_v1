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
     // �ʱ�ȭ
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
// �ִ� �� �ȿ���.
     CRecord *ret = NULL;
     int iFindSize = pos / Size;
     int iFindCount = pos % Size;
     if( NULL != mBlockArray [iFindSize] )
     {
         //// ���±��� �� �ִ� ������ ���� mCount ��.
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

             //// ���� ����. �󸶳� �޸� Ȯ�� �� �ǵ�?
             mBlockArray[iFindSize] = new CRecord[Count];
             //// �����͸� sizeof �� ���� �� �ȵȴ�. �ֳĸ� ��� �����ʹ� 4byte.
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

     // �ʱ�ȭ
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




