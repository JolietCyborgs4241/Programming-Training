#include <iostream>
#include <cstdio>

using namespace std;

int base, height;

int areaTriangle(){

return 0.5*base*height;

}

int main (){

cout << "what is your base?" << endl;
cin >>base;
cout << "what is your height" << endl;
cin >> height;
cout << "The area of your triangle is " << areaTriangle()<< endl;

return 0;
}
