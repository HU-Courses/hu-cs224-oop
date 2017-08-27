#include<iostream>
#include<math.h>
#include<time.h>
#include<stdlib.h>
#include<fstream>

using namespace std;

int main()
{
	srand(time(NULL));

	int numOfJumps= 0;
	int distanceBadFrog= 0;
	int distanceSuperFrog= 0;

	while(distanceBadFrog< 1000 && distanceSuperFrog< 1000)
	{
		numOfJumps= numOfJumps+ 1;
		int random= rand()%50;

		if (random== 1)
		{
			distanceBadFrog= distanceBadFrog+ 4;
		}
		else if (random== 2)
		{
			distanceSuperFrog= distanceSuperFrog+ 4;
		}
		else
		{
			distanceBadFrog= distanceBadFrog+ 3;
			distanceSuperFrog= distanceSuperFrog+ 3;
		}

		if (numOfJumps%50== 0)
		{
			cout<<"Number of Jumps: "<<numOfJumps<<endl;
			cout<<"Bad Frog Distance: "<<distanceBadFrog<<endl;
			cout<<"Super Frog Distance: "<<distanceSuperFrog<<endl<<endl;
		}
	}
	cout<<"Number of Jumps: "<<numOfJumps<<endl;
	cout<<"Bad Frog Distance: "<<distanceBadFrog<<endl;
	cout<<"Super Frog Distance: "<<distanceSuperFrog<<endl<<endl;

	return 0;
}



// if rand()%100 < 2
