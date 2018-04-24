#include "Floor.h"

Floor::Floor()
{
    int roomNum=101;
    for(int i=0; i<10; i++)                         //predefining the length as the no. of rooms is given to be '10'
    {
        Room singleRoom(roomNum);

        floor1Array[i]= singleRoom;

        roomNum++;
    }

    roomNum=201;
    for(int i=0; i<10; i++)                         //predefining the length as the no. of rooms is given to be '10'
    {
        Room singleRoom(roomNum);

        floor2Array[i]= singleRoom;

        roomNum++;
    }

    roomNum=301;
    for(int i=0; i<10; i++)                         //predefining the length as the no. of rooms is given to be '10'
    {
        Room singleRoom(roomNum);

        floor3Array[i]= singleRoom;

        roomNum++;
    }

    for(int i=0; i<10; i++)
    {
        allRooms[i]= floor1Array[i];
    }
    for(int i=10; i<20; i++)
    {
        allRooms[i]= floor2Array[i-10];
    }
    for(int i=20; i<30; i++)
    {
        allRooms[i]= floor3Array[i-20];
    }
    //.........continuee wirh the same
}

//--------------------------------------------------------------------------------------------------------------

/*Floor::~Floor()
{
}*/

//--------------------------------------------------------------------------------------------------------------

Room* Floor::FloorOneRooms()
{
    return floor1Array;
}

//--------------------------------------------------------------------------------------------------------------

Room* Floor::FloorTwoRooms()
{
    return floor2Array;
}

//--------------------------------------------------------------------------------------------------------------

Room* Floor::FloorThreeRooms()
{
    return floor3Array;
}

//--------------------------------------------------------------------------------------------------------------

Room* Floor::AllRooms()
{

    return allRooms;
}












