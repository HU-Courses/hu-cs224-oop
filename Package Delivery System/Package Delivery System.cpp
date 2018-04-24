#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;

const int amountPerLitre= 2.73;

int trucksOnJourney(char* fileName)
{
    FILE* filePointer;
    char buff[32];

    filePointer= fopen(fileName, "r");

    if(filePointer== NULL)
    {
        perror("Error opening file. ");
        return 0;
    }

    int lines= 0;
    int trucksQualifiedForJourney= 0;
    int pointingVariable= 0;                 //keeping track of one truck at a time
    int currentPetrol;
    int money;
    const float amountPerLitre= 2.73f;
    const int capacity= 50;
    while(fgets(buff,32,filePointer) != NULL)
    {
        pointingVariable++;
        if(pointingVariable== 2)
        {
            currentPetrol= atoi(buff);
        }
        else if(pointingVariable== 3)
        {
            money= atoi(buff);
        }
        else if(pointingVariable== 5)
        {
            pointingVariable= 0;
            if((capacity-currentPetrol)*amountPerLitre <= money)
            {
                trucksQualifiedForJourney++;
            }
        }
        lines++;
    }
    int totalTrucks= lines/5;

    //cout<<"Total Number of Trucks= "<<totalTrucks<<endl;
    //cout<<"Number of Trucks Making Journey= "<<trucksQualifiedForJourney<<endl;

    return trucksQualifiedForJourney;
}

struct Box
{
    int length;
    int width;
    int height;

    int random;                     //can random be declared dynamically?

    Box()
    {
        random= 5 + rand()%26;
        length= random;

        random= 5 + rand()%26;
        width= random;

        random= 5 + rand()%26;
        height= random;
    }

    int volume()
    {
        return length*width*height;
    }
};

struct Truck
{
    string driver;
    int currentPetrol;
    int money;
    int emptyMileage;
    int loadedMileage;
    Box* box;

    int noOfBoxes;

    Truck()
    {
        noOfBoxes= 12 + rand()%9;
    }

    void loadBoxes(int numOfBoxes)
    {

    }

    float cost()
    {
        return ((loadedMileage+emptyMileage)*60)/2.73;
    }
};

int main()
{
    srand(time(NULL));
    //char* fileName= "Drivers.txt";
    //cout<< fileName;
    //cout<<trucksOnJourney("Drivers.txt");

    /*Box b;
    cout<<b.length<<endl;
    cout<<b.width<<endl;
    cout<<b.height<<endl;
    */

    FILE* filePointer;
    char buff[32];

    filePointer= fopen("Drivers.txt", "r");

//    box= new Box[5];

    Truck* truck;
    truck= new Truck[trucksOnJourney("Drivers.txt")];

    int lines= 0;
    int trucksQualifiedForJourney= 0;
    int pointingVariable= 0;                 //keeping track of one truck at a time

    string driverName;
    int currentPetrol;
    int money;
    int emptyMileage;
    int loadedMileage;

    //string truckName;


    const int capacity= 50;

    int i=0;
    while(fgets(buff,32,filePointer) != NULL)
    {
        pointingVariable++;

        if(pointingVariable== 1)
        {
            //truckName= string(buff);
            //Truck truckName;

        }
        if(pointingVariable== 1)
        {
            driverName= buff;
        }

        else if(pointingVariable== 2)
        {
            currentPetrol= atoi(buff);
        }

        else if(pointingVariable== 3)
        {
            money= atoi(buff);
        }

        else if(pointingVariable== 4)
        {
            emptyMileage= atoi(buff);
        }

        else if(pointingVariable== 5)
        {
            loadedMileage= atoi(buff);
            pointingVariable= 0;
            if((capacity-currentPetrol)*amountPerLitre <= money)
            {
                truck[i].driver= driverName;
                truck[i].currentPetrol= currentPetrol;
                truck[i].money= money;
                truck[i].emptyMileage= emptyMileage;
                truck[i].loadedMileage= loadedMileage;

                truck[i].box= new Box[truck[i].noOfBoxes];

                i++;
            }
        }
        lines++;
    }

    cout<< "Welcome to the 'Package Delivery System'! "<<endl;
    cout<< "------------------------------------------"<<endl<<endl;
    cout<< "Number of Trucks on Journey= "<< trucksOnJourney("Drivers.txt")<<endl<<endl;
    cout<< "                     Journey has started...                 " <<endl<<endl;
    cout<< "*** DETAILS OF TRUCKS ***"<<endl;
    cout<< "-------------------------"<< endl;
    int counter= 1;

    for(int i=0; i<trucksOnJourney("Drivers.txt"); i++)
    {
        cout<<"TRUCK NO: "<<counter<<endl;

        cout<<"Driver's Name: "<<truck[i].driver<<endl;
        cout<<"Current Fuel Status: "<<truck[i].currentPetrol<<endl;
        cout<<"Reserved Amount for Petrol: "<<truck[i].money<<"$"<<endl;
        cout<<"Mileage (Loaded Truck): "<<truck[i].loadedMileage<<endl;
        cout<<"Mileage (Empty Truck): "<<truck[i].emptyMileage<<endl<<endl;

        cout<<"No. of Boxes in TRUCK NO: "<<counter<<" = "<<truck[i].noOfBoxes<<endl;
        counter++;

        cout<<"                 Unloading boxes....          "<<endl<<endl;
        for(int j=0; j<truck[i].noOfBoxes; j++)
        {
            cout<<"Volume of BOX "<<j+1<<"= "<<truck[i].box[j].volume()<<endl;
        }
        delete[] truck[i].box;
        cout<<endl<<endl;
    }
    cout<<"               Trucks are returning....           "<<endl<<endl;
    delete[] truck;

    getch();
    return 0;
}
