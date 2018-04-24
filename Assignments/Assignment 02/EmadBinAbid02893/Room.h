#pragma once

#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<string>
#include<fstream>
#include<cstring>
#include"Refrigerator.h"
#include"People.h"
#include"DateTime.h"

#include"GlobalFunctions.h"
//#include"RandomGenerator.h"

using namespace std;

class Room
{
    private:
        char data[32];
        //Refrigerator fridge;                      //a fridge in the room
        int numPeople;
        int roomNum;
        string phoneNum;
        char floor;
        int occupancy;                              //ranges from 2 to 5 persons per room
        bool isBookedFlag;                          //becomes 'true' if room gets booked
        People* personArray;                        //creates a dynamic memory of people in class 'Room'
        int daysOfStay;
        int dayOfBooking;

        //Base charge means -> Rent/day
        int baseCharge;
    public:
        char* checkinDate;
        char* checkinTime;
        char* checkoutDate;
        char* checkoutTime;
		Refrigerator fridge;
        Room();
        Room(int);                                  //loads values in the private fields(fridge, roomNum, phoneNum)     //Implemented
        ~Room();                                                                                                        //Implemented
        int GetRoomNumber();                        //returns the room number                                           //Implemented
        char GetFloorNumber();                      //returns the floor number                                          //Implemented
        void AddPeople(int&, People[], int, int, int, int, int);//takes a random no. of people & add them to the room   //Implemented
        void FridgeInfo();                          //displays information of fridge in this room                       //Implemented
        void RoomInfo();                            //displays information of rooms                                     //Implemented
        int RoomCharges();                          //calculates and returns room charges                              	//Implemented
        int Occupancy();                            //occupancy ranges from 2 to 5                                      //Implemented
        bool isBooked();                            //returns true if room is booked, else returns false                //Implemented
        void ShowPeople();                          //displays the list of people staying in a room                     //Implemented
        void CheckOut(int,int,int);                 //takes no. of days of stay deallocates the array of people         //Implemented
        Refrigerator Fridge();                      //returns the object fridge                                         //Implemented
        int StayDuration();                         //returns the duration of stay                                      //Implemented
        int DayOfBooking();
        int DayOfCheckout();
};
