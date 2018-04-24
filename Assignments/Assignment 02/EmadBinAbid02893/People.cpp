#include "People.h"

People::People()
{
    name="";
    CNIC="";
    dob="";
}

People::People(string name, string CNIC, string dob)
{
    this->name=name;
    this->CNIC=CNIC;
    this->dob=dob;
}

//--------------------------------------------------------------------------------------------------------------

void People::ShowDetails()
{
    cout<<"Person's Name: \t\t"<< name<<endl;
    cout<<"CNIC: \t\t\t"<< CNIC<< endl;
    cout<<"Date of Birth: \t\t"<< dob<<endl;
}
