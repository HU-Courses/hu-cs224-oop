#include"Shape.h"

Shape::Shape()                                                  ///Constructor implementation
{
    this->fillRect.x=0;
    this->fillRect.y=0;
    this->fillRect.w=0;
    this->fillRect.h=0;
}

Shape::Shape(int x, int y, int width, int height)               ///Over-loaded constructor implementation
{
    this->fillRect.x=x;
    this->fillRect.y=y;
    this->fillRect.w=width;
    this->fillRect.h=height;
}

Shape::Shape(const Shape& shape)                                ///Copy constructor implementation
{
    this->fillRect.x=shape.startingX;
    this->fillRect.y=shape.startingY;
    this->fillRect.w=shape.endingX;
    this->fillRect.h=shape.endingY;
}

Shape::~Shape()                                                 ///Destructor implementation
{
    std::cout<<"Shape destructor called. "<<std::endl;
}

void Shape::SetStartingX(int value)                             ///Setter implementation
{
    this->fillRect.x=value;
}

void Shape::SetStartingY(int value)                             ///Setter implementation
{
    this->fillRect.y=value;
}

void Shape::SetEndingX(int value)                               ///Setter implementation
{
    this->fillRect.w=value;
}

void Shape::SetEndingY(int value)                               ///Setter implementation
{
    this->fillRect.h=value;
}

int Shape::GetStartingX()                                       ///Getter implementation
{
    return this->fillRect.x;
}

int Shape::GetStartingY()                                       ///Getter implementation
{
    return this->fillRect.y;
}

int Shape::GetEndingX()                                       ///Getter implementation
{
    return this->fillRect.w;
}

int Shape::GetEndingY()                                       ///Getter implementation
{
    return this->fillRect.h;
}

void Shape::SetColor()                                        ///SetColor() implementation
{
    red=GlobalFunctions::RandomColor();
    green=GlobalFunctions::RandomColor();
    blue=GlobalFunctions::RandomColor();
}











