#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int burps[] {1, 2, 3, 4, 5};

int burp (int rCount) {
    string burp = "Bup";
    burp.insert(burp.begin() + 2, rCount, 'r');
    cout << burp << endl;
}

int main () {
    for (int i = 0; i < sizeof(burps)/sizeof(burps[0]); i++) {
        burp(burps[i]);
    }
}