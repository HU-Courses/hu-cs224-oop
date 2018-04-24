#include"Line.h"

Line::Line()
{

}

Line::Line(int x1, int y1, int x2, int y2) : Shape(x1, y1, x2, y2)              ///Inherited implementation
{
    SetColor();
}

Line::Line(const Line& line)
{
    this->fillRect.x=line.startingX;
    this->fillRect.y=line.startingY;
    this->fillRect.w=line.endingX;
    this->fillRect.h=line.endingY;
}

Line::~Line()                                                                   ///Destructor implementation
{
    std::cout<< "Line destructor called. "<<std::endl;
}

void Line::Draw(SDL_Renderer* gRenderer)                                        ///Draw() implementation
{
    SDL_SetRenderDrawColor(gRenderer, red, blue, green, 255);

    ///Draws the line
    SDL_RenderDrawLine(gRenderer, this->fillRect.x, this->fillRect.y, this->fillRect.w, this->fillRect.h);
}
