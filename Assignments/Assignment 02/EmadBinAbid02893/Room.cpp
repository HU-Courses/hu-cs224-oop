#include"Room.h"
//#include <sstream>

Room::Room()
{
    personArray=NULL;
}

Room::Room(int roomNum)
{
    personArray= NULL;
    fridge.Refill();
    this->isBookedFlag=false;
    this->roomNum= roomNum;
    this->phoneNum= "0"+ GlobalFunctions::ToString(roomNum);//This ToString() is a custom method which in defined in "GlobalFunctions.h"
    this->floor= GlobalFunctions::ToString(roomNum)[0];
    occupancy=2+rand()%4;                                   //MAX HOTEL ROOM OCCUPANCY = 5
    //daysOfStay=1+rand()%7;

    switch(this->occupancy)									//Setting base charges
    {
    case 2:
        baseCharge=4000;
        break;
    case 3:
        baseCharge=5500;
        break;
    case 4:
        baseCharge=7000;
        break;
    default:
        baseCharge=10000;
        break;
    }
}

//--------------------------------------------------------------------------------------------------------------

Room::~Room()
{
    if(personArray!=NULL)
    {
        delete[] personArray;
    }
}

//--------------------------------------------------------------------------------------------------------------

int Room::GetRoomNumber()
{
    return roomNum;
}

//--------------------------------------------------------------------------------------------------------------

char Room::GetFloorNumber()
{
    return floor;
}

//--------------------------------------------------------------------------------------------------------------

void Room::RoomInfo()
{
    cout<< "Room No.: \t\t"<< this->roomNum<<endl;
    cout<< "Floor No.: \t\t"<< this->floor<<endl;
    cout<< "Phone No.: \t\t"<< this->phoneNum;
    cout<< "Occupancy: \t\t"<<this->occupancy<<endl;

    cout<<"Booking Status: \t";
    if(this->isBookedFlag==true)
    {
        cout<<"BOOKED"<<endl;
    }
    else if(this->isBookedFlag==false)
    {
        cout<<"UN-BOOKED"<<endl;
    }

    cout<<"Base Charges: \t\tPKR "<<baseCharge<<"/-"<<endl;
}

//--------------------------------------------------------------------------------------------------------------

void Room::FridgeInfo()
{
    this->fridge.ShowDrinks();
}

//--------------------------------------------------------------------------------------------------------------

int Room::Occupancy()
{
    return occupancy;
}

//--------------------------------------------------------------------------------------------------------------

bool Room::isBooked()
{
    /*if(personArray!= NULL)
    {
        this->isBookedFlag=true;
        return true;
    }
    return false;                       //not doing 'this->isBooked=false' because by default it is set to 'false'
*/
    return isBookedFlag;
}

//--------------------------------------------------------------------------------------------------------------

void Room::AddPeople(int& numOfPeople, People people[], int days, int bookingDay, int hour, int minute, int second)
{
    if(this->isBookedFlag==false)
    {
        if(numOfPeople==this->occupancy)
        {
        	//Setting class attributes to function parameters starts...
            this->dayOfBooking=bookingDay;
            checkinDate= DateTime::CurrentDateGenerator(dayOfBooking,hour, minute, second);
            cout<<checkinDate<<endl;
            checkinTime= DateTime::CurrentTimeGenerator();
            this->daysOfStay=days;
            this->numPeople=numOfPeople;
            //Setting class attributes to function parameters ends-

            isBookedFlag=true;

			//File Writing (.txt) starts...
            ofstream checkIn;
            checkIn.open("Hotel Check-ins.csv", ios_base::app);
            personArray= new People[numOfPeople];

			checkIn<<dayOfBooking<<","<<roomNum<<","<<floor<<","/*<<phoneNum<<","*/<<occupancy<<","<<isBooked()<<","<<numPeople<<","<<checkinDate<</*","<<checkinTime<<*/","<<StayDuration()<<"\n";

            for(int i=0; i<numOfPeople; i++)
            {
                //checkIn<<personArray[i]<<",";
                this->personArray[i]=people[i];
                checkIn<<", , , , , , , ,"<<personArray[i].name<<","<<personArray[i].CNIC<<","<<personArray[i].dob<<",\n";
            }
            checkIn<<"\n";
            checkIn.close();
            //File Writing (.txt) ends-


			//File Writing (.csv) starts...
            FILE* hotelRecordTXTFile;
            hotelRecordTXTFile=fopen("Hotel Record.txt", "a");

            if(hotelRecordTXTFile==NULL)
            {
                perror("Record could not be saved.");
            }
            else
            {
                strcpy(data,"!!~CHECK-IN~!!\n");
                fputs(data, hotelRecordTXTFile);

                strcpy(data,"\t~Room Information: \n");
                fputs(data, hotelRecordTXTFile);
                strcpy(data,"\t\t-Room No.: ");
                fputs(data, hotelRecordTXTFile);
                sprintf(data,"\t %d\n", roomNum);
                fputs(data, hotelRecordTXTFile);
                strcpy(data,"\t\t-Occupancy: ");
                fputs(data, hotelRecordTXTFile);
                sprintf(data,"\t %d\n", occupancy);
                fputs(data, hotelRecordTXTFile);
                strcpy(data,"\t\t-Base Charges: ");
                fputs(data, hotelRecordTXTFile);
                sprintf(data,"\t %d\n", baseCharge);
                fputs(data, hotelRecordTXTFile);

                strcpy(data,"\t\t-No. of People: ");
                fputs(data, hotelRecordTXTFile);
                sprintf(data," %d\n", numPeople);
                fputs(data, hotelRecordTXTFile);
            }
            fclose(hotelRecordTXTFile);
            //File Writing (.csv) ends-

            delete hotelRecordTXTFile;
            hotelRecordTXTFile==NULL;
        }
    }
}

//--------------------------------------------------------------------------------------------------------------

void Room::ShowPeople()
{
    //cout<<personArray[0].name;
    if(this->personArray != NULL)
    {
        for(int i=0; i<this->occupancy; i++)
        {
            cout<<"Name: \t"<<personArray[i].name<<endl;
        }
    }
}

//--------------------------------------------------------------------------------------------------------------

void Room::CheckOut(int hour, int minute, int second)
{
    if(personArray!=NULL && isBookedFlag==true)
    {
        checkoutDate= DateTime::CurrentDateGenerator(dayOfBooking,hour, minute, second);
        checkoutTime= DateTime::CurrentTimeGenerator();


		//File Writing (.csv) starts...
        FILE* hotelRecordTXTFile;
        hotelRecordTXTFile=fopen("Hotel Record.txt", "a");

        if(hotelRecordTXTFile==NULL)
        {
            perror("Record could not be saved.");
        }
        else
        {
            strcpy(data,"!!~CHECK-OUT~!!\n");
            fputs(data, hotelRecordTXTFile);
            strcpy(data,"\t~Room Information: \n");
            fputs(data, hotelRecordTXTFile);
            strcpy(data,"\t\t-Room No.: ");
            fputs(data, hotelRecordTXTFile);
            sprintf(data,"\t %d\n", roomNum);
            fputs(data, hotelRecordTXTFile);
            strcpy(data,"\t\t-Occupancy: ");
            fputs(data, hotelRecordTXTFile);
            sprintf(data,"\t %d\n", occupancy);
            fputs(data, hotelRecordTXTFile);
            strcpy(data,"\t\t-Stay Duration: ");
            fputs(data, hotelRecordTXTFile);
            sprintf(data,"%d\n", daysOfStay);
            fputs(data, hotelRecordTXTFile);
            strcpy(data,"\t\t-Base Charges: ");
            fputs(data, hotelRecordTXTFile);
            sprintf(data,"\t %d\n", baseCharge);
            fputs(data, hotelRecordTXTFile);

            strcpy(data,"\t\t-Total Charges: ");
            fputs(data, hotelRecordTXTFile);
            sprintf(data,"%d\n", RoomCharges());
            fputs(data, hotelRecordTXTFile);

            strcpy(data,"\t\t-No. of People: ");
            fputs(data, hotelRecordTXTFile);
            sprintf(data," %d\n", numPeople);
            fputs(data, hotelRecordTXTFile);
        }
        fclose(hotelRecordTXTFile);
        //File Writing (.csv) ends-

        delete hotelRecordTXTFile;
        hotelRecordTXTFile==NULL;

		//File Writing (.txt) starts...
        ofstream checkOut;
        checkOut.open("Hotel Check-outs.csv", ios_base::app);

        checkOut<<dayOfBooking<<","<<roomNum<<","<<floor<<","/*<<phoneNum<<","*/<<occupancy<<","<<1-isBooked()<<","<<numPeople<<","<<checkoutDate<</*","<<checkoutTime<<*/","<<baseCharge<<","<<StayDuration()<<","<<RoomCharges()<<"\n";

        for(int i=0; i<numPeople; i++)
        {
            checkOut<<", , , , , , , , , ,"<<personArray[i].name<<","<<personArray[i].CNIC<<","<<personArray[i].dob<<",\n";
        }
        checkOut<<"\n";
        checkOut.close();
        //File Writing (.txt) ends...


        this->isBookedFlag=false;                                           //Marking the room as un-booked

        delete[] personArray;
        this->personArray=NULL;
    }
}

//--------------------------------------------------------------------------------------------------------------

int Room::RoomCharges()
{
    //For more realistic scenario, charges can also vary from floor-to-floor can also be added
    if(this->isBookedFlag==true)
    {
        //cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<StayDuration()<<endl;
        return baseCharge*StayDuration();
    }
}

//--------------------------------------------------------------------------------------------------------------


Refrigerator Room::Fridge()
{
    return fridge;                              /*Returning this is not changing its properties in main.cpp.
                                                That's why I made the attribute directly public*/
}

//--------------------------------------------------------------------------------------------------------------

int Room::StayDuration()
{
    return daysOfStay;
}

int Room::DayOfBooking()
{
    return dayOfBooking;
}

//--------------------------------------------------------------------------------------------------------------

int Room::DayOfCheckout()
{
    return dayOfBooking+daysOfStay;
}
