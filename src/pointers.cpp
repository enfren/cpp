#include <iostream>     // Include input/output stream library for cout
#include "pointers.h"   // Include header with function declarations
using namespace std;    // Use standard namespace to avoid std:: prefix

void changeValue(int* p) {  // Function to modify value via pointer
    *p = 30;
}
void pointers() {
    int x = 10;
    int* ptr = &x;
    cout << "Before: " << x << endl;  // Print initial value: 10
    changeValue(ptr);                 // Pass pointer to modify x
    cout << "After: " << x << endl;   // Print modified value: 30
}
void dynamicMemory() {
    int* ptr = new int(10);  // Allocate int on heap, initialize to 10
    cout << "Dynamic value: " << *ptr << endl;  // Print value: 10
    delete ptr;              // Free allocated memory
    ptr = nullptr;           // Set to nullptr to avoid dangling pointer
}
void arrayDemo() {
    int* arr = new int[3];   // Allocate array of 3 ints on heap
    arr[0] = 1; arr[1] = 2; arr[2] = 3;  // Initialize array
    cout << "Array values: " << arr[0] << ", " << arr[1] << ", " << arr[2] << endl;  // Print: 1, 2, 3
    delete[] arr;            // Free array memory
    arr = nullptr;           // Set to nullptr to avoid dangling pointer
}