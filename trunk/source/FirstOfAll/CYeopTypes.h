#ifndef __CYEOPTYPES
#define __CYEOPTYPES


#define BASECOUNT 100 
#define BASESIZE 100 

struct date {

public:
    void clear()
    {
        year = 0;
        month = 0;
        day = 0;
    }

    int year;
    int month;
    int day;
};

#endif 