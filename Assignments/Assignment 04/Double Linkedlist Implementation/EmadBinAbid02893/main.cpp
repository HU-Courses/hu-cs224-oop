#include <iostream>

#include"MyList.h"

using namespace std;

int main()
{
    MyList l;
    /*l=l+0;
    l=l+3;
    l=l+1;
    l=l+2;
    l=l+3;
    l=l+3;
    l=l+3;
    l=l+4;
    l=l+5;
    l=l+3;
    l=l+3;
    l=l+2;
    l=l+2;
    l=l+3;
    l=l+2;
    l=l+3;
    l=l+6;
    l=l+3;
    l=l+7;
    l=l+3;
    l=l+2;
    l=l+3;
    l=l+8;*/

    //l.Show();
    //l.PopAt(8-2);                       //maza nae aaya
    //l.Show();

    MyList k;
    k.Append(2);
    k.Append(3);
    k.Append(4);
    k.Append(5);
    k.Append(6);
    k.Append(7);

    MyList j;
    j.Append(7);
    j.Append(6);
    j.Append(5);
    j.Append(4);
    j.Append(3);
    j.Append(2);

    return 0;
}
