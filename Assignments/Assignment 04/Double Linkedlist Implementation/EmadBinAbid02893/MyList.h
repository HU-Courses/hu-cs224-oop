#pragma once

#include<iostream>

#include"Node.h"

using namespace std;

class MyList
{
private:
    Node* head;
    Node* tail;

public:
    MyList();                           ///creates an empty linked list (stack)             ///Implemented
    MyList(const MyList&);              ///copies one linked list to another                ///Implemented
    ~MyList();                          ///deallocates the linked list                      ///Implemented

    void Append(int);                   ///adds element to the end of linked list           ///Implemented
    int Pop();                          ///removes the last element of linked list          ///Implemented
    int PopAt(int);                     ///takes an integer and removes it from this list   ///Implementing...
    int GetLength();                    ///returns the length of this list                  ///Implemented

    void Show();                        ///displays all the elements of linked list (stack) ///Implemented

    MyList operator=(const MyList&);    /**copies all the elements from passed list to      ///Implemented
                                            this list**/
    MyList operator+(int);              ///appends an integer in the end of this list       ///Implemented
    MyList operator+(MyList&);          ///appends a MyList in the end of this list         ///Implemented
    MyList operator-(int);              ///removes passed values from this list             ///Implementing...
    int operator[](int);                ///reads/writes values at particular index          ///Implementing...

    ///void operator[]=(int);              ///writes values at particular index                ///Implemented

    friend ostream& operator<<(ostream&, const MyList&);   ///displays this list            ///Implemented
    bool operator==(MyList&);           /**returns true if values at corresponding          ///Implemented
                                            index are equal**/


};
