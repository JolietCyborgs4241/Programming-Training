#include <iostream>
#include <string.h>
#include <cstdio>
#include <algorithm>

using namespace std;

string test[] { "Test one",
         "Test 1",
         "Test 1, 2, 3",
         "Space at the end ",
         " Space at the front",
         "   Hi   ",
         " 3    Hi   ",
         "  1  2  3  ",
         "  Double  Space  is  Fun.",
         "      ",
         "aaaaaaaaaa"};

int countWords (string userString) {
    int count = 0;
    bool word = false;
    bool wordCounted = false;
    
    for (int i = 0; i < userString.size(); i++) { //Check every character of userString
         if (isalnum(userString[i])) {
             word = true;
         }
         
         if (isalnum(userString[i]) == false) { //Once we find a space we are no longer in the same word
             word = false;
             wordCounted = false;
         }
         
         if (word && wordCounted == false) { //We need to make sure we haven't already counted this word
             count += 1;
             word = false;
             wordCounted = true;
         }
    }
    
    return count;
}

int main () {
    for (int x = 0; x < sizeof(test)/sizeof(test[0]); x++) {
        cout << "This string \"" << test[x] << "\" has " << countWords(test[x]) << " words" << endl;
    }
    
    return 0;
}