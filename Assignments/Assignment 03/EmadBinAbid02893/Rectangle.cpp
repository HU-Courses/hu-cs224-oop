#include"Rectangle.h"

Rectangle::Rectangle()
{

}

Rectangle::Rectangle(int x1, int y1, int x2, int y2) : Shape(x1, y1, x2, y2)    ///Inherited implementation
{
    SetColor();
}

Rectangle::Rectangle(const Rectangle& rectangle) : Shape(rectangle)                              ///
{
    this->fillRect.x=rectangle.startingX;
    this->fillRect.y=rectangle.startingY;
    this->fillRect.w=rectangle.endingX;
    this->fillRect.h=rectangle.endingY;
}

Rectangle::~Rectangle()                                                         ///Destructor implementation
{
    std::cout<<"Rectangle destructor called. "<<std::endl;
}

void Rectangle::Draw(SDL_Renderer* gRenderer)                                   ///Draw() implementation
{
    SDL_SetRenderDrawColor(gRenderer, red, blue, green, 0);

    ///Draws the rectangle
    SDL_RenderFillRect(gRenderer, &(this->fillRect));
}
