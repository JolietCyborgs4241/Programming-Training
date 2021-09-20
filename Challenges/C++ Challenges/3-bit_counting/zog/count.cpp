//  count
//
// two, two, two ways to count bits

#include <iostream>

using namespace std;


// testing constants
const   int VALUE        = 0;       // value to test
const   int BIT_COUNT    = 1;       // correct number of '1' bits
const   int NUM_OF_TESTS = 19;      // total number of tests


int     bitTests[NUM_OF_TESTS][2] = { {   0, 0 },
                                      {   1, 1 },
                                      {   2, 1 },
                                      {   3, 2 },
                                      {   4, 1 },
                                      {   5, 2 },
                                      {   6, 2 },
                                      {   7, 3 },
                                      {   8, 1 },
                                      { 254, 7 },
                                      { 255, 8 },
                                      { 129, 2 },
                                      { 128, 1 },
                                      { 127, 7 },
                                      { 234, 5 },
                                      {  15, 4 },
                                      {  16, 1 },
                                      {  17, 2 },
                                      {  65, 2 } };


void    runTest(int, int, int);

int     countBits(unsigned char);

void    zogCounter();



int main() {

    int testNum;

    zogCounter();   // initialize our magic table

    for (testNum = 0 ; testNum < NUM_OF_TESTS ; testNum++) {
        runTest(testNum, bitTests[testNum][VALUE], bitTests[testNum][BIT_COUNT]);
    }

    cout << "Please hit Enter to continue..." << endl;
    cin.get();

    return 0;
}



// runTest
//
// print the test number, call bitCount() with the byte value, and test the return result

void runTest(int testNum, int byteValue, int oneBits) {

    int retVal;

    retVal = countBits(byteValue);

    cout << "Test " << testNum << ":  countBits(" << byteValue << ") returned " << retVal;

    if (retVal == oneBits) {
        cout << "  [PASS]" << endl;
    } else {
        cout << "  [FAIL] - should be " << oneBits << endl;
    }
}


// this is where the magic happens
//
// we use a loop to manuall count the bits but only once
//
// our actual "countBits()" function doesn't do any counting - it just returns the precounted value
//
// this is commonly used when you need speed - you're trading speed for the space needed to store the
// table of precounted values
//
// if you're coing to count a lot of bits, it's worth both the speed and the time to calculate the
// table.  if you're only going to do it once, it might not be worth it.
//
// you don't have to use your progran to calculate the number of bits, you could calculte it
// using ANOTHER program and just plug the values in to this program as constants
//
// this would be the fastest since you don't do any calculations at all - just fetch the
// precalculated values


const int   BIGGEST_VALUE_YOU_CAN_GET_IN_A_BYTE = 256;

int preCountedBits[BIGGEST_VALUE_YOU_CAN_GET_IN_A_BYTE];


// countBits
//
// return the number of '1' bits in an unsigned character

int countBits(unsigned char c) {

    return preCountedBits[c];

}



void zogCounter() {

    for (int i ; i < BIGGEST_VALUE_YOU_CAN_GET_IN_A_BYTE ; i++) {

        unsigned char    c;
        int     numOfBits;

        c         = i;      // we're actually going to mess with this so save a copy of "i" in "c"

        numOfBits = 0;

        while (c) {         // if it every reaches 0, we're done
        
            if (c & 0x01) { // found a bit at the lowest end

                numOfBits++;
            }

            c = c >> 1;   // shift right; "c >>= 1" would be equivalent BTW

        }

        preCountedBits[i] = numOfBits;      // save the count for this value
    }
}
