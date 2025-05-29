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
void explorePointers() {
    cout << "1. Basic Pointer: Enter an integer: ";
    int x;
    cin >> x;                // User inputs value
    int* ptr = &x;           // Pointer stores address of x
    cout << "x: " << x << ", Address: " << ptr << endl;  // Show value and address

    cout << "2. Dereferencing: Enter new value for x: ";
    int newVal;
    cin >> newVal;           // User inputs new value
    *ptr = newVal;           // Modify x via pointer
    cout << "New x: " << x << endl;  // Show updated x

    cout << "3. Pass-by-Reference: Enter value to double: ";
    int y;
    cin >> y;                // User inputs value
    int* yPtr = &y;          // Pointer to y
    changeValue(yPtr);       // Modify y via function
    cout << "Doubled y: " << y << endl;  // Show modified y

    cout << "4. Arrays and Pointers: Enter array size (1-10): ";
    int size;
    cin >> size;             // User inputs size
    if (size < 1 || size > 10) size = 3;  // Limit size for safety
    int* arr = new int[size]; // Dynamic array
    cout << "Enter " << size << " values: ";
    for (int i = 0; i < size; i++) cin >> arr[i];  // User inputs array values
    cout << "Array: ";
    for (int i = 0; i < size; i++) cout << arr[i] << " ";  // Print array
    cout << endl;

    cout << "5. Pointer Arithmetic: First element address: " << arr << endl;
    cout << "Second element: " << *(arr + 1) << ", Address: " << (arr + 1) << endl;  // Show next element

    cout << "6. Dynamic Memory: Allocated array, freeing now." << endl;
    delete[] arr;            // Free array memory
    arr = nullptr;           // Set to nullptr

    cout << "7. Null Pointer: Is arr null? " << (arr == nullptr ? "Yes" : "No") << endl;  // Check nullptr
}