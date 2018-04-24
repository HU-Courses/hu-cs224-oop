For this exercise, you will be creating a package delivery system. You need to think in terms of 
objects. The first object is the delivery truck that can store 50 liters of petrol. The cost per liter 
of petrol is 2.73$. You will be using the sample file, Drivers.txt for this assignment. Your code 
should however take into account that if an entry is increased or reduced (5 lines per entry) it reads 
all the entries in the file. For example, if there is just one entry, it should give the following 
lines as output:

Elton John
34
218
9
7

Based on this entry, the driver’s name is Elton John, his truck has 34 liters already, his total funds 
are 218$. His truck covers 9 km per liter if empty and 7 km per liter when loaded.

The trucks can carry 12 to 20 packages with random dimensions. The length, width and height of every 
package can range from 5 to 30 inches. This means that you will need to declare a dynamic array of 
boxes for each truck and every box will have a different dimension.

Calculate the total cost it will take the loaded truck to travel 60 km, drop the cargo and return 
empty based on the fuel consumption when the tank was full. This means that the drivers need to fill 
the tank first before making the journey. Based on the amount of money they have, calculate if everyone 
can do the journey. This means that you will need to declare a dynamic array of Trucks as well.

When unloading the boxes show the volume of all the boxes and then deallocate the array of boxes.

Once the trucks return, deallocate the array of all trucks after calculating the cost for the trip.