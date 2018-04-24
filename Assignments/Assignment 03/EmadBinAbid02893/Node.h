#pragma once

#include"Shape.h"

struct Node
{
    Shape* shape;
    Node* previous;
    Node* next;
};
