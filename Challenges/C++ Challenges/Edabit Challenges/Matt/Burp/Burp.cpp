#include <iostream>
#include <conio.h> 

std::string burpFunc(int repeatR)
{
    const std::string Bu = "Bu", r = "r", p = "p";
   
    std::string finalString = Bu; 

    for (int i = 0; i < repeatR; i++)
    {
        finalString = finalString + r;
    }

    finalString = finalString + p;

    return finalString;
}

int main(int numOfRs, std::string burp)
{   
    printf("Assigned amount of 'R's in burp: ");

    std::cin >>  numOfRs;

    burp = burpFunc(numOfRs);

    system ("cls");

    printf ("%s", burp.c_str() );

    while(kbhit() != 1);

    return 0;
}
