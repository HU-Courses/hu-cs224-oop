/*#include"RandomGenerator.h"

int RandomGenerator::RandomNumberGenerator()
{
    return rand()%5;
}


//--------------------------------------------------------------------------------------------------------------

People* RandomGenerator::GenerateRandomPeopleFromFile()
{
    string singleLine;
    int lineNum;

    string data;

    int newRandom= this->RandomNumberGenerator();      //taking random number of people
    personArray=new People[newRandom];                 //OR generate 'random' in main and pass as parameter in AddPeople()

    //int position=0;


    int random;
    int comma;
    int i;

    for(int position=0; position<newRandom; position++)
    {
        ifstream readFile;
        readFile.open("People.txt");

        //comma=1;
        lineNum=1;
        random= 1 + rand()%8;
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
                            personArray[position].CNIC=data;
                            comma++;
                            data="";
                        }
                        else if(comma==3)
                        {
                            personArray[position].dob=data;
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
}*/
