#include <iostream>
using namespace std;
#define PI 3.14

// macro is the piece of code in a program that is replaced by value of macro and there are different types of macros 
// Object-Like Macros
// chain Macros
// Multi-Line Macros
// Function-Like Macros

int main()
{
    int r = 5;
    // double pi = 3.14;
    // double area = pi * r * r;
    // it takes an extra space of 8 bytes as well as it can be changeable i.e pi = pi + 1;

    double area = PI * r * r;
    cout<<"Area is "<<area<<endl;

    return 0;
}