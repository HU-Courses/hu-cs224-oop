#pragma once

#include <iostream>
#include <stdlib.h>
#include "Drink.h"

using namespace std;

class Refrigerator
{
    private:
        Drink drinks[10];                   //array of stored drinks
        Drink* consumedDrinks;				//for dynamic array, stores the drinks which are consumed
        Drink* remainingDrinks;				//for dynamic array, stores the drinks which are left in fridge
        int numOfConsumedDrinks;
        int numOfRemainingDrinks;
        int numOfDrinksRemoved;
        int drinksConsumedReplenished;
        /*const*/ int totalDrinks=10;

    public:
        Refrigerator();                     //fills the fridge(initially empty) to 10 drinks                        //Implemented
        //~Refrigerator();                    //removes the drinks from fridge once check-out is made                 //Implemented
        //Refrigerator(const Refrigerator&)   //copies the items of one fridge to another fridge                      //Not necessary!
        //void AddDrink(int);                 //takes 'x' number and adds 'x' number of drinks in the fridge          //On hold.
        void Refill();                      //refills the fridge when less than 3 drinks are left                   //Implemented
        void ShowDrinks();                  //displays all the drinks currently present in the fridge               //Implemented
        bool CheckStatus();                 //returns true if no. of drinks in fridge < 3, else returns false       //Implemented
        void RemoveDrinks();                //removes the drink from fridge if customer drinks it                   //Implemented
       // Refrigerator Drinks();           	//returns an array of drinks                                            //Implemented
       int DrinksLeft();                    //returns the numOfRemainingDrinks                                      //Implemented
       int DrinksConsumed();                //returns the numOfConsumedDrinks                                       //Implemented
       int DrinksConsumedReplenished();                                                                              //Implemented
};
