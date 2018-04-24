/**
Artistik
By: Saman Gaziani(sg02494) and Emad Bin Abid(ea02893)
**/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<SDL.h>
#include<time.h>

#include"GlobalFunctions.h"
#include"Rectangle.h"
#include"Line.h"
#include"Point.h"
#include"Stack.h"

using namespace std;

const int SCREEN_HEIGHT=480;
const int SCREEN_WIDTH=640;

bool init();                                        ///Initializes SDL
bool loadMedia();                                   ///Loads media from file
void close();                                       ///Closes SDL activity

SDL_Window* gWindow;                                ///SDL Window declared
SDL_Renderer* gRenderer;                            ///SDL Renderer declared

bool init()
{
    bool success=true;
    if(SDL_Init(SDL_INIT_VIDEO)<0)
    {
        printf("SDL could not be initialized. SDL Error: %s\n", SDL_GetError());
        success=false;
    }
    else
    {
        if(!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY,"1"))
        {
            printf("Warning: Linear texture filtering not enabled. \n");
        }

        gWindow=SDL_CreateWindow("Shapes", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if(gWindow==NULL)
        {
            printf("Window could not be initialized. SDL Error: %s\n", SDL_GetError());
            success=false;
        }
        else
        {
            gRenderer=SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
            if(gRenderer==NULL)
            {
                printf("Renderer could not be created. SDL Error %s\n", SDL_GetError());
                success=false;
            }
            else
            {
                SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 0);
            }
        }
    }

    return success;
}

bool loadMedia()
{
    bool success=true;
    return success;
}

void close()
{
    SDL_DestroyRenderer(gRenderer);
    gRenderer=NULL;
    SDL_DestroyWindow(gWindow);
    gWindow=NULL;

    SDL_Quit();
}

int main(int argc, char* args[])
{
    srand(time(NULL));

    if(!init())
    {
        printf("Failed to initialize. \n");
    }
    else
    {
        if(!loadMedia())
        {
            printf("Failed to load media. \n");
        }
        else
        {
            bool quit=false;
            bool isDrawn;                           ///Checks whether shape is drawn
            bool mouseDrag;                         ///Checks whether mouse is in motion


            SDL_Event e;

            bool mouseClicked=false;

            int shapeFlag;

            /**
            shapeFlag = 0 -> POINT
            shapeFlag = 1 -> LINE
            shapeFlag = 2 -> RECTANGLE
            **/

            shapeFlag=2;                            ///Setting default shape to rectangle

            ///To set coordinates of shape
            Rectangle r;
            Line l;
            Point p;

            //SDL_Rect* rect;
            Shape* shape=NULL;                      ///Initializing pointer to Shape

            int oldx=0;                             ///Coordinates when mouse button is first down
            int oldy=0;

            int x, y;                               ///Coordinates when mouse button is up

            Stack primaryStack;                     ///Stack to store shapes
            Stack* intermediateStack=new Stack();   ///Stack to undo shapes

            ///while program is running
            while(!quit)
            {
                while(SDL_PollEvent(&e)!=0)
                {
                    ///Quit Event
                    if(e.type==SDL_QUIT)
                    {
                        quit=true;
                    }

                    ///Keyboard key Event
                    if(e.type==SDL_KEYDOWN)
                    {
                        switch(e.key.keysym.sym)
                        {
                        case SDLK_p:
                            shapeFlag=0;            ///Setting shape to POINT
                            break;
                        case SDLK_l:
                            shapeFlag=1;            ///Setting shape to LINE
                            break;
                        case SDLK_r:
                            shapeFlag=2;            ///Setting shape to RECTANGLE
                            break;
                        }
                    }

                    ///Mouse Event
                    if(e.type==SDL_MOUSEMOTION || e.type==SDL_MOUSEBUTTONDOWN || e.type==SDL_MOUSEBUTTONUP)
                    {
                        SDL_GetMouseState(&x, &y); ///Current mouse position

                        //std::cout << "oldx="<< oldx << ", "<< "oldy="<< oldy<<std::endl;
                        //std::cout << "x="<< x << ", "<< "y="<< y<<std::endl;

                        ///Mouse Drag Event
                        if(e.type==SDL_MOUSEMOTION)
                        {
                            if(mouseClicked==true)
                            {
                                mouseDrag=true;
                                if(shapeFlag==0)
                                {
                                    p.SetStartingX(x);
                                    p.SetStartingY(y);
                                }
                                else if(shapeFlag==1)
                                {
                                    l.SetStartingX(oldx);
                                    l.SetStartingY(oldy);
                                    l.SetEndingX(x);
                                    l.SetEndingY(y);
                                }
                                else if(shapeFlag==2)
                                {
                                    r.SetStartingX(oldx);
                                    r.SetStartingY(oldy);
                                    r.SetEndingX(x-oldx);
                                    r.SetEndingY(y-oldy);
                                }
                            }
                        }

                        ///Mouse Click Event
                        if(e.type==SDL_MOUSEBUTTONDOWN)
                        {
                            if(e.button.button==SDL_BUTTON_LEFT)
                            {
                                if(mouseClicked==false)
                                {
                                    mouseClicked=true;
                                    oldx=x;
                                    oldy=y;
                                    isDrawn=true;

                                    if(intermediateStack!=NULL)
                                    {
                                        intermediateStack->~Stack();
                                        intermediateStack=NULL;
                                        intermediateStack=new Stack();
                                    }
                                }
                            }

                            ///Code for UNDO
                            if(e.button.button==SDL_BUTTON_RIGHT)
                            {
                                intermediateStack->Push(primaryStack.Pop());

                                primaryStack.DrawStack(gRenderer);
                                SDL_RenderPresent(gRenderer);
                            }

                            ///Code for REDO
                            if(e.button.button==SDL_BUTTON_MIDDLE)
                            {
                                primaryStack.Push(intermediateStack->Pop());
                                primaryStack.DrawStack(gRenderer);
                                SDL_RenderPresent(gRenderer);
                            }

                        }

                        if(e.type==SDL_MOUSEBUTTONUP)
                        {
                            if(mouseClicked==true)
                            {
                                if(shapeFlag==0)
                                {
                                    p.SetStartingX(x);
                                    p.SetStartingY(y);

                                    ///Point object made
                                    shape=new Point(p.GetStartingX(), p.GetStartingY());
                                }

                                if(mouseDrag==true)
                                {
                                    if(isDrawn==true)
                                    {
                                        if(shapeFlag==1)
                                        {
                                            ///Line object made
                                            shape=new Line(l.GetStartingX(), l.GetStartingY(), l.GetEndingX(), l.GetEndingY());
                                        }
                                        else if(shapeFlag==2)
                                        {
                                            ///Rectangle object made
                                            shape=new Rectangle(r.GetStartingX(), r.GetStartingY(), r.GetEndingX(), r.GetEndingY());
                                        }
                                        isDrawn=false;
                                    }
                                    mouseDrag=false;
                                }
                                 mouseClicked=false;
                            }
                        }

                    }
                    if(e.type==SDL_KEYDOWN)
                    {
                        switch(e.key.keysym.sym)
                        {
                        case SDLK_DOWN:
                            primaryStack.MoveDown();
                            primaryStack.DrawStack(gRenderer);
                            SDL_RenderPresent(gRenderer);
                            e.type=0;
                            break;

                        case SDLK_UP:
                            primaryStack.MoveUp();
                            primaryStack.DrawStack(gRenderer);
                            SDL_RenderPresent(gRenderer);
                            e.type=0;
                            break;
                        case SDLK_a:
                            primaryStack.Pop();
                            primaryStack.DrawStack(gRenderer);
                            SDL_RenderPresent(gRenderer);
                            e.type=0;
                            break;
                        }
                    }
                }

                SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 0);
                SDL_RenderClear(gRenderer);                                 ///Clearing screen

                if(shape!=NULL)
                {
                    primaryStack.Push(shape);                               ///Adding shape to stack

                    shape=NULL;
                    shapeFlag=2;


                }
                primaryStack.DrawStack(gRenderer);                          ///Drawing stack
                SDL_RenderPresent(gRenderer);
            }
            if(intermediateStack!=NULL)
            {
                intermediateStack->~Stack();
                intermediateStack=NULL;
            }
        }
    }
    close();
    return 0;
}
