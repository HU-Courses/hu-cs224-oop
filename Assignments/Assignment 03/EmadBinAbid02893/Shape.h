#pragma once

#include<SDL.h>
#include<iostream>

#include"GlobalFunctions.h"

class Shape
{
    protected:
        ///Attributes
        SDL_Rect fillRect;

        int startingX;
        int startingY;
        int endingX;
        int endingY;

        Uint8 red;
        Uint8 green;
        Uint8 blue;

    public:
        ///Methods
        Shape();                                   ///sets the default values to attributes            //Implemented
        Shape(int, int, int, int);                 ///sets the input values to attributes              //Implemented
        Shape(const Shape&);                       ///makes a copy of original shape                   //Implemented
        virtual ~Shape();                          ///deallocates the shape                            //Implemented
        virtual void Draw(SDL_Renderer*)=0;        ///pure virtual                                     //Child-class Implements

        void SetStartingX(int);                    ///sets starting X position of screen               //Implemented
        void SetStartingY(int);                    ///sets starting Y position of screen               //Implemented
        void SetEndingX(int);                      ///sets ending X position of screen                 //Implemented
        void SetEndingY(int);                      ///sets ending Y position of screen                 //Implemented

        int GetStartingX();                        ///gets starting X position of screen               //Implemented
        int GetStartingY();                        ///gets starting Y position of screen               //Implemented
        int GetEndingX();                          ///gets ending X position of screen                 //Implemented
        int GetEndingY();                          ///gets ending Y position of screen                 //Implemented
        void SetColor();                           ///sets random color to the shape                   //Implemented
};
