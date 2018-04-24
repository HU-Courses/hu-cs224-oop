#pragma once

#include <iostream>

using namespace std;

class People
{
    public:
    //Attributes
        string name;
        string CNIC;
        string dob;

    //Methods
        People();
        People(string, string, string);                 //assigns values to attributes                      //Implemented
        void ShowDetails();                             //shows name, CNIC, dob                             //Implemented
};
