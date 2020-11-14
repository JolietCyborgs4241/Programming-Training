#include <iostream>
#include <conio.h>

float triangleArea(float base, float height, float area)
{
    area = base * height * .5;

    return area;
}

float base(float tempBase)
{
    printf("Enter in the base of the triangle: ");

    std::cin >> tempBase;

    system ("cls");

    return tempBase;
}

float height(float tempHeight)
{
    printf("Enter in the height of the triangle: ");

    std::cin >> tempHeight;

    system ("cls");

    return tempHeight;
}

int main()
{
    printf("The area of the triangle is: %f", triangleArea(base(NULL), height(NULL), NULL) );

    while (kbhit() != 1);

    return 0;
}