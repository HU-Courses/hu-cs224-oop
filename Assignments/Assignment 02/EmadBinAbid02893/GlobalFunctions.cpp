#include"GlobalFunctions.h"

/*char* GlobalFunctions::ToCharArray(int& num)
{
    itoa();
}*/

//-----------------------------------------------------------------------------------------------------

string GlobalFunctions::ToString(int& num)
{
    stringstream ss;
    ss<< num <<endl;

    return ss.str();
}

//-----------------------------------------------------------------------------------------------------

void GlobalFunctions::TimeDelay(int delay, string message)
{
    if(delay>=0 && delay<=10)
    {
        int clock= delay+1;
        cout<<message;						//User Engaging Prompt	
        for(int i=0; i<=delay; i++)
        {
            Sleep(1000);                    //delay of 1 second. 1000 millisecond = 1 second
            cout<<". ";              		//User Engaging Prompt
        }
        cout<<endl<<endl;
        //cout << "Done";
    }
}

//-----------------------------------------------------------------------------------------------------

string GlobalFunctions::ToUpperCase(string& text)
{
    for(int i=0; i<text.length(); i++)
    {
        text[i] = toupper(text[i]);         //Converting to upper-case character by character
    }
    return text;
}

//-----------------------------------------------------------------------------------------------------

void GlobalFunctions::read(int* countCharacters)
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

            if(GlobalFunctions::ToUpperCase(userDecision)== "Y")
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
    cout<<"Returning to MAIN MENU"<<endl;
    GlobalFunctions::TimeDelay(5);
    readFile.close();
}

//-----------------------------------------------------------------------------------------------------
