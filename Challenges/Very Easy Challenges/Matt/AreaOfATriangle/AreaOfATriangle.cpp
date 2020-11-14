#include <iostream>
#include <conio.h>

int triangleArea(double base, double height, double area)
{
    area = base * height * .5;

    return area;
}

int base(double tempBase)
{
    printf("Enter in the base of the triangle: ");

    std::cin >> tempBase;

    system ("cls");

    return tempBase;
}

int height(double tempHeight)
{
    printf("Enter in the height of the triangle: ");

    std::cin >> tempHeight;

    system ("cls");

    return tempHeight;
}

int main()
{
    system ("cls");

    printf("The area of the triangle is: %d", triangleArea(base(NULL), height(NULL), NULL) );

    while (kbhit() != 1);

    return 0;
}