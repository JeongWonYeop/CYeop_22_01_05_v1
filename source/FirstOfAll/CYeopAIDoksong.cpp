#define _CRT_SECURE_NO_WARNINGS
#include "CYeopAIDoksong.h"
#include <stdio.h>

CYeopAIDokSong::CYeopAIDokSong() :
    mIsDoksong(false),
    mScore(0)
{
}
CYeopAIDokSong::~CYeopAIDokSong() {

}

void CYeopAIDokSong::execute()
{
    bool bIsTurnOn = true;
    bool bIsKeepGoing = true;

    while (bIsTurnOn)
    {
        bIsKeepGoing = true;
        CheckDokSong();
        


        while(bIsKeepGoing)
        {
            CheckKeepGoing(bIsTurnOn, bIsKeepGoing);
        }
    }
    
}

void CYeopAIDokSong::CheckDokSong()
{
    int iTempAnswer = -1;
       
    printf("[AIYEOP] 당신은 오늘 하루 동안 독송 5회를 진행하였나요? \n");
    scanf("%d", &iTempAnswer);
    mIsDoksong = AnswerCheck(iTempAnswer);


    printf("[AIYEOP] 한번 시작한 독송을 끝까지 맺지 못한 적이 있었나요 ?\n");
    scanf("%d", &iTempAnswer);
    if(iTempAnswer == 1)
    {
        mScore = mScore - 1;
    }

    printf("[AIYEOP] 오늘 몇년도 몇월 몇일 인가요?\n");
    date dateAnswer;
    dateAnswer.clear();
    scanf("%d-%d-%d", &dateAnswer.year, &dateAnswer.month, &dateAnswer.day);
    

    date * Date = mStorage.GetNewRecord(mStorage.getCount());
 
    if (NULL != Date)
    {
        Date->year = dateAnswer.year;
        Date->month = dateAnswer.month;
        Date->day = dateAnswer.day;
        mStorage.AddRecord();
    }


     
}






bool CYeopAIDokSong::AnswerCheck(int iTempAnswer)
{
    bool ret = false;
    int TerminateCnt = 0;
    while ( true )
    {
        if(iTempAnswer == 0 || iTempAnswer == 1)
        {
            break;
        }
        else
        {
            printf("[AIYEOP] 당신이 입력한 답변 : %d , Yes : 1   |   No : 0\n , 남은횟수 : %d \n",iTempAnswer, 5 - TerminateCnt);
            scanf("%d", &iTempAnswer);
            TerminateCnt++;
            if( TerminateCnt > 5)
            {
                break;
            }
        }
    }

    if(iTempAnswer == 0)
    {
        ret = false;
    }
    else
    {
        ret = true;
    }

    return ret;

}

void CYeopAIDokSong::CheckKeepGoing(bool &IsTurnOn, bool &IsKeepGoing)
{
    printf("\n\n[CYeopAIDokSong]선택 하세요.  1. 목록   2. 다시 입력  3.  종료 \n");
    int iChoice = -1;
    scanf("%d", &iChoice);
  
    if(1 == iChoice)
    {
        int iCount = mStorage.getCount();
        for(int i = 0 ; i < iCount ; i++)
        {
            const date * pData = mStorage.GetRecord(i);

            if( NULL != pData)
            {
                printf("저장된 데이터[%d], Year<%d>Month<%d>Day<%d>\n", i + 1, pData->year, pData->month, pData->day);
            }
        }

    }
    else if(2 == iChoice)
    {
        IsKeepGoing = false;
    }
    else if(3 == iChoice)
    {
        IsKeepGoing = false;
        IsTurnOn = false;
    }




}