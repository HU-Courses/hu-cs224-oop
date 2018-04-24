#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
//#include <ctype.h>
#include <cstdlib>
#include <windows.h>
//#include<conio.h>

using namespace std;

void TimeDelay(int delay = 3);          //Creating a time delay of 3 seconds by default. parameter 'delay' ranges from 0 sec to 10 sec.
string ToUpperCase(string&);            //Converting strings to upper-case
void read(int*);                        //Reading a file. Parameter takes pointer to the variable holding the count of characters.
int edit();                             //Creating a new file and writing to it (not appending)

int main()
{
    string userInput;                  //Taking input from user. userInput can only be 'EDIT', 'READ' or 'EXIT'
    int countTotalCharacters= 0;       //Counting total number of characters read from different files every time when userInput=="READ"
    int* p_countCharacters= NULL;      //Creating a NULL pointer
    p_countCharacters = &countTotalCharacters;      //Pointer pointing towards 'countTotalCharacters'
    //string text;
    int totalNumOfCommands= 0;      //Calculating number of times command screen is displayed

    bool loopRunning = true;

    while (loopRunning)               //This loop will stop only if userInput=="EXIT"
    {
        if(totalNumOfCommands> 0)
        {
            TimeDelay();              //Calling a function
        }

        system("CLS");                //Clearing the command screen
        cout<< "Total characters read so far = "<< *p_countCharacters<< endl<< endl;

        //countTotalCharacters= 0;

        for(int i=0; i<40; i++)
        {
            cout<< '~';
        }
        cout<< endl;
        cout.width(35);
        cout<< "Welcome To SimpleTextEdit! \n";

        for(int i=0; i<40; i++)
        {
            cout<< '~';
        }
        cout<< endl;

        while(userInput!= "EDIT" && userInput!= "READ" && userInput!= "EXIT")       //Taking 'userInput' unless condition is matched
        {
            cout<< "Type 'edit' to edit a textfile"<< endl;
            cout<< "Type 'read' to read a textfile"<< endl;
            cout<< "Type 'exit' to exit program"<< endl;
            cout<< "Choose what you want to do: ";
            cin>> userInput;                            //Taking user's choice as input
            userInput= ToUpperCase(userInput);          //Calling a function
            cout<< endl;
            if(userInput!= "EDIT" && userInput!= "READ" && userInput!= "EXIT")
            {
                cout<< "Sorry! The given command does not exist. Please try again. "<< endl<< endl<< endl;
            }
            totalNumOfCommands+= 1;
        }
        //text= ToUpperCase(userInput);
        //cout<< userInput;

        if(userInput=="EXIT")
        {
            loopRunning= false;                         //Getting out of main while() loop. Meaning=End of Program
        }
        else if(userInput=="READ")
        {
            read(p_countCharacters);                    //Calling a function
        }
        else                                            //userInput=="EDIT"
        {
            edit();                                     //Calling a function
        }
        userInput="";
        //TimeDelay(0);
        //cout<< "Command Screen Displayed: "<< totalNumOfCommands<< endl;
    }
    return 0;
}

void TimeDelay(int delay)
{
    if(delay>=0 && delay<=10)
    {
        int clock= delay+1;
        cout<<endl<<"Returning to main menu in: ";  //User Engaging Prompt
        for(int i=0; i<=delay; i++)
        {
            Sleep(1000);                      //delay of 1 second. 1000 millisecond = 1 second
            cout<<--clock<<". ";              //User Engaging Prompt
        }
        cout<<endl<<endl;
        //cout << "Done";
    }
}

string ToUpperCase(string& text)
{
    for(int i=0; i<text.length(); i++)
    {
        text[i] = toupper(text[i]);         //Converting to upper-case character by character
    }
    return text;
}

void read(int* countCharacters)
{
    int line = 1;
    int lineNum = 24;
    int countMultiples= 0;                  //keeping track of multiple occurences of each 24th line
    string userDecision;

    char fileName[50];
    //string fileName;

    ifstream readFile;
    cout<< "Enter name of the file to read: "<< endl;
    cin.ignore();
    cin.getline(fileName, 50);                          //Storing the user's input as an array of characters
    //getline(cin, fileName);
    readFile.open(fileName);

    if(!readFile)
    {
        cout<<"No such file exits in specified path! "<<endl;
    }
    //readFile>> fileName;
    //cout<< fileName<< endl;

    int totalCharactersInFile= 0;
    string singleLine;
    while (getline(readFile, singleLine))               //Checking condition when the file ends & getline(....) is used to store a single line as a string
    {
        if(line<= lineNum)
        {
            cout<< countMultiples+line<< "> ";
            cout<< singleLine<<endl;
            totalCharactersInFile+= singleLine.length();
            line+= 1;
        }
        else
        {                                //Enabling the program to go back to read the lines after every 24th line
            cout<< "File has more content. Do you want to continue reading?"<< endl;
            cout<< "Enter 'Y' to continue or any other key to finish reading: "<< endl;
            cin>> userDecision;

            if(ToUpperCase(userDecision)== "Y")
            {
                line=1;                  //Setting line=1 to repeat the process
                countMultiples+= 24;     //To generate distinguished line numbers
                cout<< countMultiples+line<< "> ";
                cout<< singleLine<<endl;
                totalCharactersInFile+= singleLine.length();
                line+= 1;
            }
            else
            {
                break;
            }

        }
    }
    *countCharacters+= totalCharactersInFile;
    //cout<< *countCharacters;

    readFile.close();
}

int edit()
{
    char fileName[20];

    ofstream writeFile;
    cout<< "Enter name of the file to edit: "<< endl;
    cin.ignore();
    cin.getline(fileName, 20);

    cout<< "Start typing. Enter / or CTRL + X to stop editing this file. "<< endl;

    writeFile.open(fileName/*, ios::app*/);         //ios::app ensures that file won't be overwritten

    string singleLine;
    //char x;

    int serialNumber= 1;
    while(true)
    {
        cout<< serialNumber<< "> ";
        /*x=getch();
        if (x==24)
        {
            break;
        }*/
        getline(cin, singleLine);
        if(singleLine== "/" || (singleLine[0]== 24 && singleLine.length()==1))      //End of writing a file
        {
            break;
        }
        else
        {
            writeFile<< singleLine<< endl;
        }
        serialNumber+= 1;
    }
    writeFile.close();
    return 0;
}
