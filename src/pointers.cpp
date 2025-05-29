#include <iostream>
#include "pointers.h"
using namespace std;
void demoPointers() {
    int x = 10;
    int* ptr = &x;
    cout << "Value: " << x << ", Address: " << &x << endl;
    cout << "Pointer stores: " << ptr << ", Points to: " << *ptr << endl;
    *ptr = 20;
    cout << "New value: " << x << endl;
}