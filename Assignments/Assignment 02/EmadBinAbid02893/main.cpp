//DRINKS CONSUMED WALI CHEEZ NEGATIVE MEIN AARHI, USKO THEEK KARNA HAI
//STAFF KO HISTORIC DATA KA ACCESS BHI DENA HAI

#include<time.h>
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<fstream>
#include<cstring>
#include<sstream>
#include <typeinfo>
#include<conio.h>
#include"Refrigerator.h"
#include"Room.h"
#include"Floor.h"
#include"People.h"
#include"DateTime.h"
#include"GlobalFunctions.h"

using namespace std;

//Defining function prototype starts...
People* GenerateRandomPeopleFromFile(int*);		//Generates random people from TEXT file
int RandomNumberGenerator();					//Generates a random number of how many people need to be selected
//int Helper(int);
int DaysOfStay();								//Generates a random number of stay duration of people
/*void Booking();							-not used
void staff(Floor*, int);					-not used*/

//Defining function prototype ends-

People* personArray;							//Array of people who are randomly generated at runtime (main.cpp)
//int x;


int main()
{
    srand(time(NULL));

    Floor f;									//Building hotel by building its floors (REF: floor.h)

	//Initialising variables to be used
    int daysOfStay;
    //char* currentDate;
    //char* currentTime;
    int randomSecond=0;
    int randomMinute=0;
    int randomHour=0;


    //File Writing (.csv) starts...
    ofstream checkIn;
    checkIn.open("Hotel Check-ins.csv");
    checkIn<< "================================ HOTEL CHECK-INS ================================\n\n\n";
    checkIn<< "Day of Booking,Room No.,Floor No.,Occupancy,Booked,No. of People Entered,Check-in Date/Time,Stay Duration,Names,CNIC,DOB\n\n";
    checkIn.close();
     //File Writing (.csv) ends-

     //File Writing (.csv) starts...
	ofstream checkOut;
    checkOut.open("Hotel Check-outs.csv");
    checkOut<< "================================ HOTEL CHECK-OUTS ================================\n\n\n";
    checkOut<< "Day of Booking,Room No.,Floor No.,Occupancy,Booked,No. of People Exited,Check-out Date/Time,Base Charges,Stay Duration,Total Charges,Names,CNIC,DOB\n\n";
    checkOut.close();
     //File Writing (.csv) ends-

	 //File Writing (.csv) starts...
    FILE* hotelRecord;
    char data[32];

    hotelRecord=fopen("Hotel Record.txt","w");

    if(hotelRecord==NULL)
    {
        perror("Data could not be saved due to technical issues");
    }
    else
    {
        strcpy(data,"                               \n");
        strcpy(data,"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        fputs(data, hotelRecord);
        strcpy(data,"                               \n");
        strcpy(data,"PEARL CONTINENTAL HOTEL RECORD\n");
        fputs(data,hotelRecord);
        strcpy(data,"                               \n");
        strcpy(data,"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
        fputs(data, hotelRecord);
    }
    fclose(hotelRecord);
     //File Writing (.csv) ends-

    delete hotelRecord;
    hotelRecord=NULL;


    //COMMAND PROMPT INTERFACE SETTING begins....

	string userInput;                  //Taking input from user. userInput can only be 'EDIT', 'READ' or 'EXIT'
    int countTotalCharacters= 0;       //Counting total number of characters read from different files every time when userInput=="READ"
    int* p_countCharacters= NULL;      //Creating a NULL pointer
    p_countCharacters = &countTotalCharacters;      //Pointer pointing towards 'countTotalCharacters'
    int totalNumOfCommands= 0;                      //Calculating number of times command screen is displayed

    bool loopRunning = true;

    while (loopRunning)                             //This loop will stop only if userInput=="EXIT"
    {
        system("CLS");                              //Clearing the command screen

        cout.width(37);
        for(int i=0; i<40; i++)
        {
            cout<< '~';
        }
        cout<< endl;
        cout.width(75);
        cout<< "Welcome To HOTEL MANAGEMENT SYSTEM \n";

        cout.width(37);
        for(int i=0; i<40; i++)
        {
            cout<< '~';
        }
        cout<< endl;

        while(userInput!= "SIMULATE" && userInput!= "READ" && userInput!= "EXIT" && userInput!= "STAFF")        //Taking 'userInput' unless condition is matched
        {
            cout<<"Please SIMULATE first else the staff will get corrupted data. Thank you. "<<endl<<endl;
            cout<< "Type 'simulate' to simulate Hotel's Running Mechanism"<< endl;
            cout<< "Type 'read' to see Hotel's Records"<< endl;
            cout<< "Type 'staff' to enter into Staff Mode"<<endl;
            cout<< "Type 'exit' to exit program"<< endl;

            cout<< "Choose what you want to do: ";
            cin>> userInput;                            //Taking user's choice as input
            userInput= GlobalFunctions::ToUpperCase(userInput);          //Calling a function
            cout<< endl;
            if(userInput!= "SIMULATE" && userInput!= "READ" && userInput!= "EXIT" && userInput!="STAFF")
            {
                cout<< "Sorry! The given command does not exist. Please try again. "<< endl<< endl<< endl;
            }
            totalNumOfCommands+= 1;
        }

        if(userInput=="EXIT")															//FIRST OPTION TO BE SELECTED
        {
            loopRunning= false;                                                             //Getting out of main while() loop. Meaning=End of Program
            return 0;
        }
        else if(userInput=="READ")														//SECOND OPTION TO BE SELECTED
        {
            GlobalFunctions::read(p_countCharacters);                                       //Calling a function
        }

        //Staff Area begins...
        else if(userInput=="STAFF")														//THIRD OPTION TO BE SELECTED
        {
            cout<<"Enabling staff access.."<<endl;
            GlobalFunctions::TimeDelay(3,"Processing");
            cout.width(35);
            cout<<"In Staff Accessing Mode.."<<endl;

            string staffInput;
            int choice;
            while(staffInput!= "PCHONE" && staffInput!= "PCHTWO" && staffInput!= "PCHTHREE")            //Taking 'userInput' unless condition is matched
            {
                cout<<"Please select your domain: "<<endl;
                cout<< "1) PCHOne\t 2) PCHTwo\t 3) PCHThree"<<endl;

                cin>> staffInput;                            //Taking user's choice as input
                staffInput= GlobalFunctions::ToUpperCase(staffInput);          //Calling a function
                cout<< endl;
                GlobalFunctions::TimeDelay(1, "Managing Controls");
                GlobalFunctions::TimeDelay(1, "Checking Domain Credentials");

                if(staffInput!= "PCHONE" && staffInput!= "PCHTWO" && staffInput!= "PCHTHREE")
                {
                    cout<< "Domain doesn't exist. Please try again.. "<< endl<< endl<< endl;
                }
                else
                {
                    cout<<"Valid Staff Domain. Confirmed! "<<endl;
                }
            }
            GlobalFunctions::TimeDelay(1,"Fetching Staff Data");
            cout<<endl<<staffInput<<" domain logged in."<<endl<<endl;

            cout<<"To access info of ALL ROOMS ON ALL FLOORS, type 1"<<endl;
            cout<<"To access info of ALL ROOMS ON A PARTICULAR FLOOR, type 2"<<endl;

            cin>>choice;

            if(choice==1)
            {
                int historicData;
                cout<< "To access Hotel's Historic Data, Press 1, else Press any key to view Current Data.. ";
                cin>>historicData;

                if(historicData==1)                                 //ADDITIONAL: ITS CODE CAN BE MADE
                {

                }
                else
                {
                    for(int m=0; m<30; m++)
                    {
                        cout<<"Room Info: "<<endl;
                        f.AllRooms()[m].RoomInfo();
                        cout<<endl<<endl;

                        cout<<"Residents' Info: "<<endl;
                        f.AllRooms()[m].ShowPeople();
                        cout<<endl<<endl;

                        cout<<"Refrigerator Status"<<endl;
                        cout<<"Drinks Consumed (Since Start):\t\t "<<f.AllRooms()[m].fridge.DrinksConsumed()<<endl;
                        cout<<"Drinks Consumed (After Replenishment):\t"<<f.AllRooms()[m].fridge.DrinksConsumedReplenished()<<endl;
                        cout<<"Drinks Remaining: \t\t\t"<<f.AllRooms()[m].fridge.DrinksLeft()<<endl;
                        f.AllRooms()[m].fridge.ShowDrinks();
                        cout<<endl<<endl;
                        cout<<"Press any key to view next room's info"<<endl<<endl;
                        getch();
                    }
                }
            }
            else if(choice==2)
            {
                int historicData;
                cout<< "To access Hotel's Historic Data, Press 1, else Press any key to view Current Data.. ";
                cin>>historicData;

                if(historicData==1)                                     //ADDITIONAL: ITS CODE CAN BE MODIFIED FURTHER
                {
                    string roomInfo;
                    cout<< "Which Room's info you want to access? "<<endl;
                    cin>> roomInfo;

                    if(roomInfo[0]=='1' || roomInfo[0]=='2' || roomInfo[0]=='3')
                    {
                        string roomnum;
                        string stream;
                        string numofpeople;
                        ifstream myFile;

                        myFile.open("Hotel Check-outs.csv");
                        while (getline(myFile, stream))
                        {
                            string roomnum;
                            string stream;
                            string numofpeople;
                            getline(myFile , stream, ',' );
                            getline(myFile , roomnum , ',');
                            if (roomnum == roomInfo )
                            {
                                cout<<"Room Number: " << roomnum << endl;
                                getline(myFile , stream , ',');
                                cout<< "Occupancy: " << stream << endl;
                                getline(myFile , stream , ',');
                                getline(myFile , numofpeople , ',');
                                cout<< "No of People: " <<numofpeople <<endl;
                                getline(myFile , stream , ',');
                                cout<< "Checked-out at: " << stream <<endl;
                                getline(myFile , stream , ',');
                                getline(myFile , stream , ',');
                                cout<< "Stayed for: " << stream <<endl;
                                getline(myFile , stream , ',');
                                cout<< "Total Charges paid: " <<stream <<endl;
                                int NumOfPeople = atoi(numofpeople.c_str());
                                getline(myFile , stream );
                                for (int i=0; i<NumOfPeople;i++)
                                {
                                    for (int i=0; i<9;i++)
                                    {
                                        getline(myFile , stream , ',');
                                    }
                                        getline(myFile , stream , ',');
                                        cout<< "Name: " << stream <<endl;
                                        getline(myFile , stream , ',');
                                        cout<< "CNIC: " << stream <<endl;
                                        getline(myFile , stream , ',');
                                        cout<< "DOB: " << stream <<endl;
                                        getline(myFile , stream );
                                }

                                cout<<endl<<endl;
                                getch();
                            }
                            else
                            {
                                cout<<"Room's Historic data doesnt exist"<<endl;
                                getch();
                            }
                        }
                    }
                    else
                    {
                        cout<<"Room No. doesn't exist"<<endl;
                        cout<<"Press any key to continue...";
                        getch();
                    }
                }
                /*cout<<"Press any key to continue...";
                getch();*/
                else
                {
                    int furtherChoice;
                    cout<<"Enter Floor Number"<<endl;
                    cin>>furtherChoice;

                    if(furtherChoice!=1 && furtherChoice!=2 && furtherChoice!=3)
                    {
                        cout<<"Floor doesn't exist.."<<endl;
                    }
                    else
                    {
                        if(furtherChoice==1)
                        {
                            for(int m=0; m<10; m++)
                            {
                                cout<<"Room Info: "<<endl;
                                f.FloorOneRooms()[m].RoomInfo();
                                cout<<endl<<endl;

                                cout<<"Residents' Info: "<<endl;
                                f.FloorOneRooms()[m].ShowPeople();
                                cout<<endl<<endl;

                                cout<<"Refrigerator Status"<<endl;
                                cout<<"Drinks Consumed (Since Start)\t\t: "<<f.FloorOneRooms()[m].fridge.DrinksConsumed()<<endl;
                                cout<<"Drinks Consumed (After Replenishment):\t"<<f.FloorOneRooms()[m].fridge.DrinksConsumedReplenished()<<endl;
                                cout<<"Drinks Remaining: \t\t\t"<<f.FloorOneRooms()[m].fridge.DrinksLeft()<<endl;
                                f.FloorOneRooms()[m].fridge.ShowDrinks();
                                cout<<endl<<endl;
                                cout<<"Press any key to view next room's info"<<endl<<endl;
                                getch();
                            }
                        }
                        else if(furtherChoice==2)
                        {
                            for(int m=0; m<10; m++)
                            {
                                cout<<"Room Info: "<<endl;
                                f.FloorTwoRooms()[m].RoomInfo();
                                cout<<endl<<endl;

                                cout<<"Residents' Info: "<<endl;
                                f.FloorTwoRooms()[m].ShowPeople();
                                cout<<endl<<endl;

                                cout<<"Refrigerator Status"<<endl;
                                cout<<"Drinks Consumed (Since Start)\t\t: "<<f.FloorTwoRooms()[m].fridge.DrinksConsumed()<<endl;
                                cout<<"Drinks Consumed (After Replenishment)\t:"<<f.FloorTwoRooms()[m].fridge.DrinksConsumedReplenished()<<endl;
                                cout<<"Drinks Remaining: \t\t\t"<<f.FloorTwoRooms()[m].fridge.DrinksLeft()<<endl;
                                f.FloorTwoRooms()[m].fridge.ShowDrinks();
                                cout<<endl<<endl;
                                cout<<"Press any key to view next room's info"<<endl<<endl;
                                getch();
                            }
                        }
                        else
                        {
                            for(int m=0; m<10; m++)
                            {
                                cout<<"Room Info: "<<endl;
                                f.FloorThreeRooms()[m].RoomInfo();
                                cout<<endl<<endl;

                                cout<<"Residents' Info: "<<endl;
                                f.FloorThreeRooms()[m].ShowPeople();
                                cout<<endl<<endl;

                                cout<<"Refrigerator Status"<<endl;
                                cout<<"Drinks Consumed (Since Start)\t\t: "<<f.FloorThreeRooms()[m].fridge.DrinksConsumed()<<endl;
                                cout<<"Drinks Consumed (After Replenishment):\t"<<f.FloorThreeRooms()[m].fridge.DrinksConsumedReplenished()<<endl;
                                cout<<"Drinks Remaining: \t\t\t"<<f.FloorThreeRooms()[m].fridge.DrinksLeft()<<endl;
                                f.FloorThreeRooms()[m].fridge.ShowDrinks();
                                cout<<endl<<endl;
                                cout<<"Press any key to view next room's info"<<endl<<endl;
                                getch();
                            }
                        }
                    }
                }
            }

            else
            {
                cout<<"Information code not matched. "<<endl;
                cout<<"Press any key to return to MAIN MENU";
                getch();
            }


        }
        //Staff area ends-

        //Simulation mode begins...
        else                                                                                //userInput=="SIMULATE"
        {
            cout<<endl<<"Entering 'Simulation Mode'"<<endl;
            GlobalFunctions::TimeDelay();

            //Actual Simulation starts...
            //int checkinCounter=0;
            //int checkoutCounter=0;
            char choice;

            cout<<"Press (a) to simulate day-by-day. Else Press any key to AUTO-SIMULATE"<<endl;
            cin>>choice;

            for(int day=1; day<=7; day++)
            {
                if(choice=='a')
                {
                    cout<<"Press any key to start simulating DAY: "<<day<<endl;
                    getch();

                    GlobalFunctions::TimeDelay(5, "Simulating");

                }
                //cout<<day;

                hotelRecord=fopen("Hotel Record.txt","a");
                if(hotelRecord==NULL)
                {
                    perror("Data could not be saved due to technical issues");
                }
                else
                {
                    strcpy(data, "- DAY: ");
                    fputs(data,hotelRecord);

                    sprintf(data, "%d\n", day);
                    fputs(data,hotelRecord);
                }

                fclose(hotelRecord);
                delete hotelRecord;
                hotelRecord=NULL;

                int* x=new int;													//Its value gets initialised when GenerateRandomPeopleFromFile(int*) is called

                GenerateRandomPeopleFromFile(x);                               //Calling a function

                int j=0;
                while(j<30)
                //for(int j=0; j<10; j++)
                {
                    daysOfStay=DaysOfStay();

                    if(f.AllRooms()[j].isBooked()==false)                     //Avoiding repetition of same set of people each time
                    {
                        randomHour=rand()%24;
                        randomMinute=rand()%60;
                        randomSecond=rand()%60;

                        f.AllRooms()[j].AddPeople(*x,personArray,daysOfStay,day, randomHour, randomMinute, randomSecond);
                        if(f.AllRooms()[j].isBooked()==true)                  //Avoiding repetition of same set of people each time
                        {
                            /*randomHour=rand()%24;
                            randomMinute=rand()%60;
                            randomSecond=rand()%60;
                            //currentDate=DateTime::CurrentDateGenerator(day-1,2,randomHour,randomMinute,randomSecond);
                            //currentTime=DateTime::CurrentTimeGenerator();
                            checkinCounter++;
*/
                            GenerateRandomPeopleFromFile(x);
                            delete x;

                            j=0;
                        }
                    }
                    if(f.AllRooms()[j].isBooked()==true)
                    {
                        f.AllRooms()[j].fridge.RemoveDrinks();

                        hotelRecord=fopen("Hotel Record.txt","a");
                        if(hotelRecord==NULL)
                        {
                            perror("Data could not be saved due to technical issues");
                        }
                        else
                        {
                            strcpy(data, "\t\t-Drinks Information: \n");
                            fputs(data,hotelRecord);

                            strcpy(data, "\t\t\t-Drinks Consumed: ");
                            fputs(data,hotelRecord);
                            sprintf(data,"%d\n", f.AllRooms()[j].fridge.DrinksConsumed());
                            fputs(data,hotelRecord);

                            strcpy(data, "\t\t\t-Drinks Remaining: ");
                            fputs(data,hotelRecord);
                            sprintf(data,"%d\n", f.AllRooms()[j].fridge.DrinksLeft());
                            fputs(data,hotelRecord);
                        }

                        fclose(hotelRecord);
                        delete hotelRecord;
                        hotelRecord=NULL;


                        //cout<< "Drinks Consumed: "<< f.AllRooms()[j].fridge.DrinksConsumed()<<endl;
                        //cout<< "Drinks Remaining: "<< f.AllRooms()[j].fridge.DrinksLeft()<<endl;                    //DrinksLeft showing negative values!

                        if(f.AllRooms()[j].fridge.CheckStatus()==true)
                        {
                            hotelRecord=fopen("Hotel Record.txt","a");
                            if(hotelRecord==NULL)
                            {
                                perror("Data could not be saved due to technical issues");
                            }
                            else
                            {
                                strcpy(data,"\t\t\t-Drinks Replenished...\n");
                                fputs(data, hotelRecord);
                            }

                            fclose(hotelRecord);
                            delete hotelRecord;
                            hotelRecord=NULL;

                            f.AllRooms()[j].fridge.Refill();
                        }
                    }
                    j++;

                    if(f.AllRooms()[j].isBooked()==true)
                    {
                        if(f.AllRooms()[j].StayDuration()==day-f.AllRooms()[j].DayOfBooking())
                        {
                            randomHour=rand()%24;
                            randomMinute=rand()%60;
                            randomSecond=rand()%60;

                            f.AllRooms()[j].CheckOut(randomHour,randomMinute,randomSecond);
                            //checkoutCounter++;
                        }
                    }
                }
            cout<<endl<<"DAY: "<<day<<" simulation done..."<<endl;
            }
            //Simulation mode ends-

            cout<<"Press any key to return to MAIN MENU"<<endl;
            getch();
            //Actual simulation ends-
        }
        userInput="";
    }
    return 0;
}

//-----------------------------------------------------------------------------------------------------------------------------

int RandomNumberGenerator()
{
    return rand()%5;
}

//--------------------------------------------------------------------------------------------------------------

People* GenerateRandomPeopleFromFile(int* valueOfx)
{
    string singleLine;
    int lineNum;

    string data;

    int newRandom= RandomNumberGenerator();      //taking random number of people
    *valueOfx=newRandom;


    personArray=new People[newRandom+1];         //OR generate 'random' in main and pass as parameter in AddPeople()

    //int position=0;
    int countFileLines=0;
    string line;
    ifstream file;
    file.open("People.txt");

    while(getline(file, line))
    {
        countFileLines++;
    }
    file.close();
    int random;
    int comma;

    for(int position=0; position<=newRandom; position++)
    {
        ifstream readFile;
        readFile.open("People.txt");
        //comma=1;
        lineNum=1;
        random= 1 + rand()%(countFileLines);
        comma=1;
        data="";
        //cout<<position<<endl;

        while(getline(readFile, singleLine))
        {
            if(lineNum==random)
            {
                for(int i=0; i<singleLine.length(); i++)
                {
                    if(singleLine[i]== ',')
                    {
                        if(comma==1)
                        {
                            //cout<<data<<endl;
                            personArray[position].name=data;
                            comma++;
                            data="";
                        }
                        else if(comma==2)
                        {
                            personArray[position].dob=data;
                            comma++;
                            data="";
                        }
                        else if(comma==3)
                        {
                            personArray[position].CNIC=data;
                            comma++;
                            data="";
                        }
                    }
                    else
                    {
                        data+=singleLine[i];
                    }
                }
            }
            lineNum++;
        }
        readFile.close();
    }
    return personArray;
}

//-----------------------------------------------------------------------------------------------------------------------------

int DaysOfStay()
{
    int daysOfStay=1+rand()%7;
    return daysOfStay;
}

//-----------------------------------------------------------------------------------------------------------------------------

/*void Booking()
{
    char static currentDateTime[32];

    time_t t = time(NULL);
    struct tm tm= *localtime(&t);

    for(int i=0; i<7; i++)
    sprintf(currentDateTime, "%d/%d/%d,%d:%d:%d,", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900, tm.tm_hour, tm.tm_min, tm.tm_sec);
}

//-----------------------------------------------------------------------------------------------------------------------------

void staff(Floor* floor, int roomNumber)
{

}*/






