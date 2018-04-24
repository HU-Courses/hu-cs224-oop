#pragma once

#include<SDL.h>
#include<iostream>

#include"Shape.h"

class Point : public Shape
{
    private:


    public:
        Point();                    ///base class Implementation                         //Implemented
        Point(int, int);            ///base class Implementation                         //Implemented
        Point(const Point&);        ///base class Implementation                         //Implemented
        ~Point();                                                                       ///Implemented

        void Draw(SDL_Renderer*);   ///draws the point; pure virtual in base class       //Implemented
};
