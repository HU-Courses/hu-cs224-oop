#pragma once

#include<stdlib.h>
#include<iostream>

#include"GlobalFunctions.h"
#include"Node.h"
#include"Shape.h"

using namespace std;

class Stack
{
private:
    Node* tempShape;                      ///a reference pointer to head i.e. it always points to where ever the head points
    Node* head;
    Node* tail;

    int destructorCounter=0;              ///prints on console the number of elements removed from stack
    int pushCounter=0;                    ///prints on console the number of elements pushed in stack
    int popCounter=0;                     ///prints on console the number of elements popped from stack
    int drawCounter=0;                    ///prints on console the number of elements drawn on screen

public:
    Stack();                              ///sets the default values                         //Implemented
    ~Stack();                             /**removes elements from stack
                                            and sets pointer to NULL**/                      ///Implemented
    void Push(Shape*);                    ///adds the shape at the end of stack              //Implemented
    Shape* Pop();                         ///removes the shape from the end of stack         //Implemented
    void MoveDown();                      ///moves the shape one step down                   //Implemented
    void MoveUp();                        ///moves the shape one step up                     //Implemented
    void DrawStack(SDL_Renderer*);        ///draws all the shapes in stack                   //Implemented
    ///int PopAt(int);                       ///removes the shape from specified index          //Not Implemented
    ///PushAt(int, int);                     ///adds the shape at specified index               //Not Implemented
};
