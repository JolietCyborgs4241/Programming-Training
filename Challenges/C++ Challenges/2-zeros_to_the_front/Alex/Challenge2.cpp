#include "iostream"

using namespace std;

int	test1[] = { 1, 4, -6,  0,  3, -100, 0 };

int	test2[] = { -100, -6, 1, 4, 3, 0 };

int	test3[] = { 1, 2, 3, 0, 4, 0, 5, 6, 0 };

int	test4[] = { -1, -2, -3, 0, -4, 0, -5, -6, 0 };

int	test5[] = { 0, -2, -3, 0, -4, 0, -5, -6, 0 };

int	test6[] = {0, 0, 0, 0, 0 };

int	test7[] = { 10, 10, 10, 10, 10 };

int	test8[] = { 3 };

int	test9[] = { 0 };

void    runTest(const char *, int *, int), zerosToTheFront(int *, int);


int
main() {

	runTest("test1", test1, 7);

	runTest("test2", test2, 6);

	runTest("test3", test3, 9);

	runTest("test4", test4, (sizeof(test4) / sizeof(test4[0])) );

	runTest("test5", test5, (sizeof(test5) / sizeof(test5[0])));

	runTest("test6", test6, (sizeof(test6) / sizeof(test6[0])));

	runTest("test7", test7, (sizeof(test7) / sizeof(test7[0])));

	runTest("test8", test8, (sizeof(test8) / sizeof(test8[0])));

	runTest("test9", test9, (sizeof(test9) / sizeof(test9[0])));

	runTest("the nothing test (don't crash!)", (int *) 0, 0);

    cout << "All tests completed!\n";

    return 0;
}


// runTest
//
// this function will print out the test label, the entire array
// before any changes, call zerosToTheFront(), and then print out
// the modified array
//
// you should be able to manually confirm the results by looking
// at them and ensuring the 0�s all moved to the front of the array

void
runTest(const char *name, int array[], int count) {

    int i;

	cout << name << ":\n";

	for (i = 0 ; i < count ; i++) {     // show the list before moving the 0's
	    cout << "   " << array[i];
	}
	cout << "\n";

	zerosToTheFront(array, count);

	for (i = 0 ; i < count ; i++) {     // show the list after moving the 0's
	    cout << "   " << array[i];
	}
	cout << "\n\n";
}


// zerosToTheFront
//
// this is where you�ll do the actual moving around of the data in
// the array to get the 0�s moved to the front of the list

void
zerosToTheFront(int array[], int count) {
    int temp, val1, val2, zero;
    zero = 0;

    for (int a = 0; a < count; a++) {
        if (array[a] == 0 && a > zero) {
            val1 = array[a];
            val2 = array[zero];
            array[a] = val2;
            array[zero] = val1;
            zero++;
        }
    }
}

