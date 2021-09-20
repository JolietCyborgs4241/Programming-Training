#include <iostream>
#include <cstdio>

using namespace std;

int num1;
int num2;

int main() {
    cout << "Enter Two Numbers to be added" << endl;
    cin >> num1;
    cin >> num2;
}

int addition() {
    int solution;
    solution = num1 + num2;
    cout << "The answer is: " << solution << endl;

    return 0;
}
