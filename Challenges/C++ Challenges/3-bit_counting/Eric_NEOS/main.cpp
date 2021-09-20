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



int main() {

    int testNum;

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



// countBits
//
// return the number of '1' bits in an unsigned character

int countBits(unsigned char c) {

    // PUT YOUR CODE IN HERE!!
    int powersOfTwo[] = {128, 64, 32, 16, 8, 4, 2, 1};
    char charPowers[8] = {0};
    int length = 8;
    int oneBits = 0;

    for (int i = 0; i<length; i++){
        charPowers[i] = powersOfTwo[i];
        }

    for (int i = 0; i<length; i++){
        if (c & charPowers[i]){
            oneBits++;
        }
    }    

    return oneBits;

}
