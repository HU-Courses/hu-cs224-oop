#pragma once

#include<string>
#include<iostream>
#include<sstream>
#include<time.h>
#include<stdlib.h>
#include<stdio.h>

using namespace std;

struct DateTime
{
    static int CurrentDayGenerator();					//returns system's current day(date)             //Implemented
    static int CurrentMonthGenerator();                 //returns system's current month(date)	         //Implemented
    static int CurrentYearGenerator();                  //returns system's current year(date)            //Implemented
    static int CurrentSecondGenerator();                //returns system's current seconds(time)         //Implemented
    static int CurrentMinuteGenerator();                //returns system's current minutes(time)         //Implemented
    static int CurrentHourGenerator();                  //returns system's current hours(time)           //Implemented
    static char* CurrentTimeGenerator();                                                                 //Implemented
    static char* CurrentDateGenerator(int,int,int,int); //returns the maniupulated datetime(for simulation) //Implemented

};
