// 4th Grad Math Problem by Eric Haas 06-December-2019

// Find a 9 digit nubmer such that:
// Each digit 1-9 is used once.
// The first 2 digits must be a number divisible by 2
// The first 3 digits must be a number divisible by 3
// The first 4 digits must be a number divisible by 4
// The first 5 digits must be a number divisible by 5
// The first 6 digits must be a number divisible by 6
// The first 7 digits must be a number divisible by 7
// The first 8 digits must be a number divisible by 8
// The first 9 digits must be a number divisible by 9

#include <iostream>
using namespace std;

int currentArray[] = {1, 2, 3, 4, 5, 6, 7, 8, 8};  //needs to be one before firt test
int stopArray[] = {9, 8, 7, 6, 5, 4, 3, 2, 2};  //needs to be one past the last array
int length = 9;  //length of arrays

//Print currentArray
void printArray(int currentArray[], int length){
        for (int i = 0; i < length; i++){
        cout << currentArray[i];
    }
}

//Iterate the currentArray by 1. Flips over to all zeros on overflow.
void incrementNumber(int currentArray[], int length){
    bool carry = true;
    int digit = 0;

    for (int i = length-1; i >= 0; i--){
        if (carry){
            digit = currentArray[i] + 1;
        }
        else{
            digit = currentArray[i];
        }

        if (digit < 10){
            currentArray[i] = digit;
            carry = 0;
            }
        else{
            currentArray[i] = digit - 10;
            carry = 1;
        }
    }
}

bool lastNumber(int currentArray[], int stopArray[], int length){
    for (int i = 0; i<length; i++){
        if (currentArray[i] != stopArray[i]){
            return 0;
        }
    }
    return 1;
}

//Check to see if each number 1-9 is used exactly once.
//Sorts a copy of currentArray and compares to an array 1-9.
bool oneNumberEach(int currentArray[], int length){
    //Copy currentArray to sortedArray
    int sortedArray[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
  
    for (int i = 0; i<length; i++){
        sortedArray[i] = currentArray[i];
    }

        // cout << "unsorted sortedArray = [";
        // printArray(sortedArray, length);
        // cout << "] \n";

    //Keep moving smaller numbers to the left until no chages are made.
    bool done = 0;
    while (!done){
        done = 1;
        for (int i = 0; i < (length-1); i++){
            if (sortedArray[i] > sortedArray[i+1]){
                int temp = sortedArray[i];
                sortedArray[i] = sortedArray[i+1];
                sortedArray[i+1] = temp;
                done = 0;
            }
            // cout << "being sorted sortedArray = [";
            // printArray(sortedArray, length);
            // cout << "] \n";
        }
    }
    
    // cout << "sorted sortedArray = [";
    // printArray(sortedArray, length);
    // cout << "] \n";

    //Does sortedArray match a sorted array of 1-9 used exactly once?
    int testArray[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int i = 0; i<length; i++){
        if (sortedArray[i] != testArray[i]){
            return 0;
        }
    }
    //cout << "Each digit 1-9 IS used exactly once \n";
    return 1;
}

//Are the
//first digit divisible by 1 AND
//first two digits divisitlbe by 2 AND
//first three digits divisble by 3 AND
//...AND
//first nine digits divisible by 9
bool divisibleTest(int currentArray[], int lengh){
    //testNumber is the number made of of the first (i + 1) digits of the currentArray
    int testNumber = 0;
    for (int i = 0; i<length; i++){
        testNumber = testNumber * 10 + currentArray[i];
        //cout << "test number is: " << testNumber << " divided by " << i + 1 << " with remainder " << testNumber % (i+1) << "\n";
        if (testNumber % (i+1) != 0){
            return 0;
        }
    }
    //cout << "number DOES meet all divisibility tests. \n";
    return 1;
 }


int main(){

    //Loop unitl stopArray is reached
    while (lastNumber(currentArray, stopArray, length) == 0){

        incrementNumber(currentArray, length);

        // cout << "\n";
        // cout << "currentArray is: [";
        // printArray(currentArray, length);
        // cout << "] \n";

        //If not 1-9 exactly once, go back to while statmeent
        if (oneNumberEach(currentArray, length) == 0){
            //cout << "digits are NOT 1-9 used exactly each once \n";
            continue;
        }

        //If the number does not meet all divisibility test, go back to while statemnt
        if (divisibleTest(currentArray, length) == 0){
            //cout << "Number does not meet all divisibility tests \n";
            continue;
        }

        //Only numbers that base the above two tests should get to this part
        cout << "This number works:  ";
        printArray(currentArray,length);
        cout << "\n";
    
    }
   //When while loop is done iterating all numbers, print this
   cout << "\n All nubmer from 123456789 to ";
   printArray(currentArray, length);
   cout << " have been checked \n";
}
