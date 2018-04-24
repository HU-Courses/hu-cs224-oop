#pragma once

#include<SDL.h>
#include<iostream>

#include"Shape.h"

class Rectangle : public Shape
{
    private:

    public:
        Rectangle();                        ///base class Implementation                         //Implemented
        Rectangle(int, int, int, int);      ///base class Implementation                         //Implemented
        Rectangle(const Rectangle&);        ///base class Implementation                         //Implemented
        ~Rectangle();                                                                           ///Implemented

        void Draw(SDL_Renderer*);           ///draws the rectangle; pure virtual in base class   //Implemented
};
