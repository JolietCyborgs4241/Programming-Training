#include <iostream>
#include <conio.h>
#include <windows.h>

int num1, num2, sumOfNum;

int summation(int number1, int number2) // function that sums up the values passed into the arguement
{
    number1 = number1 + number2;

    return number1; 
}

int moveToLine(int line) // using windows.h this function simply changes the line that the cursor is on.
{
    COORD coordInst;

    coordInst.Y = line;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordInst);
}

int main()
{ 
    printf("Enter in values: \n \n"); // Text prints once.

    for (int i = 0, cursorLine = 2, currentNum; i < 2; i++) // for-loop dictates the order that code is ran based on the conditions of the
    {                                                       // if-statements below and the value stored in i.
        std::cin >> currentNum;

        moveToLine(cursorLine); //puts the cursur back on line: 2 to update the screen. 

        if (i == 0) // i == 0 and i ==1 allows for the first and second number to be given and printed before finding the sum.
        {
            num1 = currentNum;

            printf("%i + ", num1);
        }
        if (i == 1)// Lastly, will print the entire equation, providing answer.
        {
            num2 = currentNum;

            printf("%i + %i = %i ",num1, num2, summation(num1, num2) ); 
        }
    }

    while (kbhit() != 1);// Program closes once a key is pressed.

    return 0;
}