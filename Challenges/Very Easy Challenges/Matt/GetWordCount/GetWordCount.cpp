#include <iostream>
#include <conio.h>
#include <string.h>

int wordCount(std::string providedString)
{
   int currentPlace, wordCountInt;

   char endMarker = (char)219u;

   bool readingWord = false;

   providedString = providedString + endMarker;

   for (int i = 0; providedString[i] != endMarker; i++)
   {
       if (providedString[i] != ' ' && readingWord == false)
       {
           wordCountInt++;

           readingWord = true;
       }
       else if (providedString[i] == ' ')
       {
           readingWord = false;
       }
   }

   return wordCountInt;
}

void userInputAndOutput()
{
    std::string userProvidedString;
    
    printf("Provide text: ");

    getline(std::cin, userProvidedString);

    system ("cls");

    printf("The text is: %s \n \n The word count is: %i \n", userProvidedString.c_str(), wordCount(userProvidedString) );
}

int main()
{
    userInputAndOutput();

    while (kbhit() != 1);

    return 0;
}