#pragma once

#include<string>
#include<iostream>
#include<sstream>
#include<time.h>
#include<stdlib.h>
#include<stdio.h>
#include<windows.h>
#include<fstream>

using namespace std;

struct GlobalFunctions
{
    //static char* ToCharArray(int&);                     //converts integer to char array               //
    static string ToString(int&);                         //converts integer to string                   //Implemented
    static void TimeDelay(int delay=3, string message="Processing");//creates a time delay in system     //Implemented
    static string ToUpperCase(string&);                   //converts strings to uppercase                //Implemented
    static void read(int*);                               //reads a file from system                     //Implemented
};
