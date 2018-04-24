#include"DateTime.h"

int DateTime::CurrentDayGenerator()
{
    time_t t = time(NULL);
    struct tm tm= *localtime(&t);
    return tm.tm_mday;
}

//-----------------------------------------------------------------------------------------------------

int DateTime::CurrentMonthGenerator()
{
    time_t t = time(NULL);
    struct tm tm= *localtime(&t);
    return tm.tm_mon+1;
}

//-----------------------------------------------------------------------------------------------------

int DateTime::CurrentYearGenerator()
{
    time_t t = time(NULL);
    struct tm tm= *localtime(&t);
    return tm.tm_year+1900;
}

//-----------------------------------------------------------------------------------------------------

int DateTime::CurrentSecondGenerator()
{
    time_t t = time(NULL);
    struct tm tm= *localtime(&t);
    return tm.tm_sec;
}

//-----------------------------------------------------------------------------------------------------

int DateTime::CurrentMinuteGenerator()
{
    time_t t = time(NULL);
    struct tm tm= *localtime(&t);
    return tm.tm_min;
}

//-----------------------------------------------------------------------------------------------------

int DateTime::CurrentHourGenerator()
{
    time_t t = time(NULL);
    struct tm tm= *localtime(&t);
    return tm.tm_hour;
}

//-----------------------------------------------------------------------------------------------------

char* DateTime::CurrentTimeGenerator()
{
    char static currentTime[16];

    /*time_t t = time(NULL);
    struct tm tm= *localtime(&t);

    sprintf(currentTime, "%d:%d:%d", hours, minutes, seconds);
*/
    return currentTime;
}

//-----------------------------------------------------------------------------------------------------

char* DateTime::CurrentDateGenerator(int dayIncrement, int hourIncrement, int minuteIncrement, int secondIncrement)
{
    char static currentDate[16];

    int seconds=DateTime::CurrentSecondGenerator()+secondIncrement;				//secondIncrement= random number generated in main.cpp
    int minutes=DateTime::CurrentMinuteGenerator()+minuteIncrement;				//minuteIncrement= random number generated in main.cpp
    int hours=DateTime::CurrentHourGenerator()+hourIncrement;					//hourIncrement= random number generated in main.cpp

    int day=DateTime::CurrentDayGenerator()+dayIncrement;						//dayIncrement= out of 7 iterations done in main.cpp
    int month=DateTime::CurrentMonthGenerator();
    int year=DateTime::CurrentYearGenerator();

    //cout<<seconds<<"|"<<minutes<<"|"<<hours<<endl;

    //Time manipulation started...
    if(seconds>60)
    {
        minutes++;
        seconds=seconds-60;
    }
    if(minutes>60)
    {
        hours++;
        minutes=minutes-60;
    }
    if(hours>24)
    {
        //day++;
        hours=hours-24;
    }
    //Time manipulation ended-


    //Date manipulation started...
    if(month==2 && year%4==0)                       //Checking leap-year in February
    {
        if(day>29)
        {
            month++;
            day=day-29;
        }
    }
    else if(month==2 && year%4!=0)                  //Checking leap-year in February
    {
        if(day>28)
        {
            month++;
            day=day-28;
        }
    }

    if(month<8 && month%2==1)                       //Checking no. of days in a particular month
    {
        if(day>31)
        {
            day=day-31;
            month++;
        }
    }
    else if(month<8 && month%2==0)                  //Checking no. of days in a particular month
    {
        if(day>30)
        {
            day=day-30;
            month++;
        }
    }
    if(month>8 && month%2==1)                       //Checking no. of days in a particular month
    {
        if(day>30)
        {
            day=day-30;
            month++;
        }
    }
    else if(month>8 && month%2==0)                  //Checking no. of days in a particular month
    {
        if(day>31)
        {
            day=day-31;
            month++;
        }
    }

    if(month>12)                                    //If month is greater than 12, it should add 1 to the year
    {
        year++;
        month=1;
    }
    //Date manipulation ended-

    time_t t = time(NULL);
    struct tm tm= *localtime(&t);
    sprintf(currentDate, "%d/%d/%d - %d:%d:%d", day, month, year, hours, minutes, seconds);

    //DateTime::CurrentTimeGenerator(seconds, minutes, hours);


    return currentDate;
}

//-----------------------------------------------------------------------------------------------------
