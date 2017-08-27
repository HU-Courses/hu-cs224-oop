#include<iostream>
#include<math.h>
#include<time.h>
#include<stdlib.h>
#include<fstream>

using namespace std;

int main()
{
	ofstream myFile;
	myFile.open("sinegraph.txt");

	for(double angle= 0; angle<=360; angle++)
	{
		double value= sin(angle*(3.14/180));

		if (value<0)
        {
            value= -value;
        }

        double newValue= 10*value;
		int ans= (int)newValue;
		//cout<<ans<<endl;
		for (int i=0; i<ans; i++)
		{
			myFile<<" ";
		}
		myFile<<'*';
		myFile<<endl;
	}
	return 0;
}
