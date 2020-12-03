#include <iostream>

#include <conio.h>

    int arraySize, absoluteSum;

    int sizeOfArray() // requests an array size.
    {
        system ("cls");

        printf ("Enter amount of slots for the array (array size): ");

        std::cin >> arraySize; 

        system ("cls");

        return arraySize; 
    }

int main()
{
    int array[sizeOfArray()]; // integer type array is created

        for (int i = 0; i < arraySize; i++) // The slots or indexes of the array are assigned values
                 {
                     int assignedValue, currentSlot = i + 1;

                       printf ("Provide values for each slot. Current slot: %i out of %i \n \n Assigned Value: ", currentSlot, arraySize);

                      std::cin >> assignedValue;

                    array[i] = assignedValue; 

                   system ("cls"); 
                 }

    for (int i = 0; i < arraySize; i++) // array is displayed and the absolute sum is calculated
    {
        int slotValue = array[i];

        if (i == 0)
        {
            printf ("Your array is: { ");
        }

         printf ("%i ", slotValue);

        if (slotValue < 0) //if the current index or slot of the array is negative, make it positve.
        {
            slotValue = slotValue*-1;
        }

        absoluteSum = absoluteSum + slotValue; // all absolutes within the slots or indexes of the array are added up.

       if (i + 1 == arraySize)
        {
            printf ("} \n");
        }
        else
        {
            printf (", ");
        }
    }

    printf ("\n The absolute sum is: %i \n", absoluteSum); // the absolute sum is diplayed. 

   while (kbhit() != 1); // Closes program once a key is pressed. 

    return 0; 
}