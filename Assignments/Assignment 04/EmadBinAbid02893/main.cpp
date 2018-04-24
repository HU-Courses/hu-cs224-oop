/**
Assignment: 04
By: Emad Bin Abid (ea02893) and Saman Gaziani (sg02494)
**/

#include <iostream>

#include"MyList.h"

using namespace std;

int main()
{
    cout<< "Hello, MyList! "<<endl<<endl;

    MyList q;
    q=q+0;
    q=q+1;
    q=q+2;
    q=q+3;
    q=q+4;
    q=q+5;

    //cout<<q;
    q.PopAt(4);
    cout<<q;
    return 0;
}
