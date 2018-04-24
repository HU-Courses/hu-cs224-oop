#include"Point.h"

Point::Point()
{

}

Point::Point(int x, int y) : Shape(x, y, x, y)                  ///Inherited implementation
{
    SetColor();
}

Point::Point(const Point& point)
{
    this->fillRect.x=point.startingX;
    this->fillRect.y=point.startingY;
    this->fillRect.w=point.endingX;
    this->fillRect.h=point.endingY;
}

Point::~Point()                                                 ///Destructor implementation
{
    std::cout<< "Point destructor called. "<<std::endl;
}

void Point::Draw(SDL_Renderer* gRenderer)                       ///Draw() implementation
{
    SDL_SetRenderDrawColor(gRenderer, red, blue, green, 255);

    ///Draws the point
    SDL_RenderDrawPoint(gRenderer, this->fillRect.x, this->fillRect.y);
}
