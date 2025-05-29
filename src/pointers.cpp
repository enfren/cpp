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
    int stackArr[3];         // Stack-allocated array of 3 ints
    stackArr[0] = 1; stackArr[1] = 2; stackArr[2] = 3;  // Initialize stack array
    cout << "Stack array: " << stackArr[0] << ", " << stackArr[1] << ", " << stackArr[2] << endl;  // Print: 1, 2, 3

    int* heapArr = new int[3];  // Heap-allocated array of 3 ints
    heapArr[0] = 4; heapArr[1] = 5; heapArr[2] = 6;  // Initialize heap array
    cout << "Heap array: " << heapArr[0] << ", " << heapArr[1] << ", " << heapArr[2] << endl;  // Print: 4, 5, 6
    delete[] heapArr;        // Free array memory
    heapArr = nullptr;       // Set to nullptr to avoid dangling pointer
}