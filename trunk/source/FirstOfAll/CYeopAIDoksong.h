#ifndef FIRSTOFALL
#define FIRSTOFALL 
#include "CYeopTypes.h"
#include "CYeopMultipleBlockArray.h"


class CYeopAIDokSong 
{

public:
    CYeopAIDokSong();

    ~CYeopAIDokSong();

    void execute();




    CYeopMultipleBlockArray<date, 100, 100> mStorage;
private:

    bool mIsDoksong;
    int mScore;
    date mDate;
    void CheckDokSong();
    bool AnswerCheck(int iTempAnswer);
};


#endif 




