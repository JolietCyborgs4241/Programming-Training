#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    cout << "Enter Size of Array" << endl;
    int arraySize;
    cin >> arraySize;
    int absoluteSum[arraySize]; //Sets array size to the value desired by the user

    for (int i = 0; i <= arraySize; i++) {
        cout << "Enter value for array slot " << i << endl;
        int elementValue;
        cin >> elementValue;
        absoluteSum[i] = elementValue; //Sets current array element to value user desires 
    }

    int sum = 0;
    for (int x = 0; x <= arraySize; x++) {
        sum = sum + absoluteSum[x];
    }

    sum = abs(sum);

    cout << "The absolute value of your array is: " << sum << endl;

    return 0;
}