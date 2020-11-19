#include <iostream>
#include <cstdio>

using namespace std;

int num1, num2;

int twoNumberSum (){

return num1 + num2;
}

int main()
{

cout << "Input your first number and hit enter" << endl;
cin >> num1;
cout << "Input your first number and hit enter" << endl;
cin >> num2;

cout << num1 << "+" << num2 << "=" << twoNumberSum() << endl;


return 0;
}
