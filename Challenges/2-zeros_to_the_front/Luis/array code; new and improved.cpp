#include <iostream>

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

	runTest("test4", test4, (sizeof(test4) / sizeof(test4[9])) );

	runTest("test5", test5, (sizeof(test5) / sizeof(test5[9])));

	runTest("test6", test6, (sizeof(test6) / sizeof(test6[5])));

	runTest("test7", test7, (sizeof(test7) / sizeof(test7[5])));

	runTest("test8", test8, (sizeof(test8) / sizeof(test8[1])));

	runTest("test9", test9, (sizeof(test9) / sizeof(test9[1])));

	runTest("The nothing test (don't crash!)", (int *) 0, 0);

	cout << "All tests completed!\n";

    return 0;
}
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



void zerosToTheFront(int array[], int count) {
int num1, num 2;
 int num0;
 num0 = 0;
for (int l=0, l < count; l++;){
    if( array[l]==0; l > num0){
        num1 = array[l];
        num2 = array[num0];

        num1 = array[num0];
        num2 = array[l];
        num0++;


    }}



}






