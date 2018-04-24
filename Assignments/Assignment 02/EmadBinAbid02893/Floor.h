#pragma once

#include "Room.h"

using namespace std;

class Floor
{
    private:
        Room floor1Array[10];				//allocating array for rooms on floor one
        Room floor2Array[10];				//allocating array for rooms on floor two
        Room floor3Array[10];				//allocating array for rooms on floor two
        Room allRooms[30];					//allocating array for all rooms on all floors
    public:
        Floor();                            //takes in the array of rooms & fills rooms on the floor    //Implemented
        //~Floor();                                                                                       //Implemented
        Room* FloorOneRooms();             //returns floor1Array                                        //Implemented
        Room* FloorTwoRooms();             //returns floor2Array                                        //Implemented
        Room* FloorThreeRooms();           //returns floor3Array                                        //Implemented
        Room* AllRooms();                  //returns allRooms                                           //Implemented
};

