#pragma once

#include<SDL.h>
#include<iostream>

#include"Shape.h"

class Line : public Shape
{
    private:

    public:
        Line();                         ///base class Implementation                         //Implemented
        Line(int, int, int, int);       ///base class Implementation                         //Implemented
        Line(const Line&);              ///base class Implementation                         //Implemented
        ~Line();                                                                            ///Implemented

        void Draw(SDL_Renderer*);       ///draws the line; pure virtual in base class        //Implemented
};
