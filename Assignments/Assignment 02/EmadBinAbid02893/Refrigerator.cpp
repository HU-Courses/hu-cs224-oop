#include"Refrigerator.h"

Refrigerator::Refrigerator()
{
    for(int i=0; i<10; i++)
    {
        drinks[i].capacity= -1;
        drinks[i].name="NULL";
        //drinksConsumed=0;
        numOfConsumedDrinks=0;
        drinksConsumedReplenished=0;
        numOfRemainingDrinks=10;
    }
}

//--------------------------------------------------------------------------------------------------------------

/*Refrigerator::~Refrigerator()
{

}*/

//--------------------------------------------------------------------------------------------------------------

void Refrigerator::ShowDrinks()
{
    for(int i=0; i<10; i++)
    {
        cout<<i+1<<".\t"<<"Drink Name: "<<drinks[i].name<<"\t"<<"Capacity: "<<drinks[i].capacity<<endl;
    }

    /*cout<<endl<<"Consumed Drinks: "<<endl;
    for(int i=0; i<numOfConsumedDrinks;i++)
    {
        cout<<i+1<<".\t"<<"Drink Name: "<<drinks[i].name<<"\t"<<"Capacity: "<<drinks[i].capacity<<endl;
    }*/
}

//--------------------------------------------------------------------------------------------------------------

bool Refrigerator::CheckStatus()									//Checking whether number of drinks in fridge are less than 3
{
    int check=0;
    for(int i=0; i<10; i++)
    {
        if(drinks[i].capacity!= -1)
        {
            check++;
        }
    }

    if(check<3)
    {
        return true;
    }
    return false;
}

//--------------------------------------------------------------------------------------------------------------

void Refrigerator::RemoveDrinks()									//Removing the drinks from fridge randomnly
{
    numOfDrinksRemoved=1+rand()%3;
    numOfConsumedDrinks+=numOfDrinksRemoved;
    /*numOfRemainingDrinks=10-numOfConsumedDrinks;
    consumedDrinks=new Drink[numOfDrinksRemoved];
    remainingDrinks=new Drink[10-numOfDrinksRemoved];
    */
    int choice;
    for(int i=0; i<numOfDrinksRemoved;i++)
    {
        choice=rand()%10;
        //consumedDrinks[i].capacity=drinks[choice].capacity;
        //consumedDrinks[i].name=drinks[choice].name;
        if(drinks[choice].capacity!=-1)
        {
            drinks[choice].capacity= -1;
            drinks[choice].name="NULL";                         //Displaying NULL in position of drink that has been drunk
        }
    }
    numOfRemainingDrinks=0;
    for(int i=0; i<10; i++)
    {
        if(drinks[i].capacity!= -1)
        {
            numOfRemainingDrinks++;
        }
    }
    drinksConsumedReplenished= 10-numOfRemainingDrinks;
    /*while(numOfRemainingDrinks>=10)
    {
        numOfRemainingDrinks-=10;
    }
    numOfRemainingDrinks=10-numOfRemainingDrinks;
*/

}

//--------------------------------------------------------------------------------------------------------------

void Refrigerator::Refill()
{
    int selectName;
    int selectCapacity;
    //drinksConsumed=0;
    //numOfRemainingDrinks=10;
    /*
    selectName=0 --> "Pepsi"
    selectName=1 --> "Fanta"
    selectName=2 --> "Sprite"

    selectCapacity=0 --> 200ml
    selectCapacity=1 --> 250ml
    selectCapacity=2 --> 300ml
    */

    /*if(this->CheckStatus()==true)
    {*/
        for(int i=0; i<10; i++)
        {
            if (drinks[i].capacity== -1)
            {
                selectName=rand()%3;
                selectCapacity=rand()%3;

                switch(selectName)
                {
                    case 0:
                        drinks[i].name="Pepsi";
                        break;

                    case 1:
                        drinks[i].name="Fanta";
                        break;

                    default:
                        drinks[i].name="Sprite";
                        break;
                }

                switch(selectCapacity)
                {
                    case 0:
                        drinks[i].capacity=200;
                        break;

                    case 1:
                        drinks[i].capacity=250;
                        break;

                    default:
                        drinks[i].capacity=300;
                        break;
                }
            }
        }
    //}
}

//--------------------------------------------------------------------------------------------------------------

/*Refrigerator Refrigerator::Drinks()
{
    return drinks;
}*/

//--------------------------------------------------------------------------------------------------------------

int Refrigerator::DrinksConsumed()
{
    /*for(int i=0; i<10; i++)
    {
        if(drinks[i].capacity== -1)
            drinksConsumed++;
    }*/
    return numOfConsumedDrinks;
}

//--------------------------------------------------------------------------------------------------------------

int Refrigerator::DrinksLeft()
{
    return numOfRemainingDrinks;
}

int Refrigerator::DrinksConsumedReplenished()
{
    return drinksConsumedReplenished;
}



