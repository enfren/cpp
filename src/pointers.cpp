#include <iostream>   // Include input/output stream library for cout
#include "pointers.h" // Include header with demoPointers function declaration
using namespace std;  // Use standard namespace to avoid std:: prefix
void demoPointers() {
    int x = 10;
    int* ptr = &x;
    cout << "Value: " << x << ", Address: " << &x << endl;
    cout << "Pointer stores: " << ptr << ", Points to: " << *ptr << endl;
    *ptr = 20;
    cout << "New value: " << x << endl;
}