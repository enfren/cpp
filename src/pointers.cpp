#include <iostream>     // Include input/output stream library for cout
#include <string>       // Include string library for string references
#include "pointers.h"   // Include header with function declarations
using namespace std;    // Use standard namespace to avoid std:: prefix

void changeValue(int* p) {  // Modify value via pointer
    *p = 30;
}
void pointers() {
    int x = 10;
    int* ptr = &x;
    cout << "Print initial value: " << x << endl; 
    changeValue(ptr);
    cout << "Print modified value: " << x << endl; 
}
void dynamicMemory() {
    int* ptr = new int(10);  // Allocate int on heap
    cout << "Dynamic value: " << *ptr << endl;  // Print value: 10
    delete ptr;
    ptr = nullptr;           // Avoid dangling pointer
}
void arrayDemo() {
    int stackArr[3];         // Stack-allocated array
    stackArr[0] = 1; stackArr[1] = 2; stackArr[2] = 3;  // Initialize stack array
    cout << "Stack array: " << stackArr[0] << ", " << stackArr[1] << ", " << stackArr[2] << endl;  // Print: 1, 2, 3
    int* heapArr = new int[3];  // Heap-allocated array
    heapArr[0] = 4; heapArr[1] = 5; heapArr[2] = 6;  // Initialize heap array
    cout << "Heap array: " << heapArr[0] << ", " << heapArr[1] << ", " << heapArr[2] << endl;  // Print: 4, 5, 6
    delete[] heapArr;
    heapArr = nullptr;       // Avoid dangling pointer
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
    cout << "5. Pointer Arithmetic: First element address: " << arr << endl;  // Show array address
    cout << "Second element: " << *(arr + 1) << ", Address: " << (arr + 1) << endl;  // Show next element and address
    cout << "6. Dynamic Memory: Allocated array, freeing now." << endl;  // Indicate deallocation
    delete[] arr;
    arr = nullptr;           // Set to nullptr to avoid dangling pointer
    cout << "7. Null Pointer: Is arr null? " << (arr == nullptr ? "Yes" : "No") << endl;  // Check nullptr
}
void pointerPractice() {
    cout << "1. Memory Management: Enter an integer to allocate: ";
    int val;
    cin >> val;              // User inputs value
    int* p = new int(val);   // Allocate int on heap
    cout << "Allocated: " << *p << endl;  // Show value
    delete p;                // Free memory
    p = nullptr;             // Avoid dangling pointer
    cout << "Freed, p is null: " << (p == nullptr ? "Yes" : "No") << endl;  // Confirm nullptr

    cout << "2. Memory Leak Demo (safe): Allocate without freeing? (1=yes, 0=no): ";
    int leak;
    cin >> leak;             // User chooses
    if (leak) {
        int* leakP = new int(42);  // Allocate, no delete (simulates leak)
        cout << "Memory allocated, not freed (leak simulation)." << endl;
    }

    cout << "3. Reference Parameter: Enter a string: ";
    string s;
    cin >> s;                // User inputs string
    auto printStr = [](string& str) { cout << "String: " << str << endl; };  // Lambda for ref param
    printStr(s);             // Pass by reference, no copy

    cout << "4. Non-const Reference: Enter number to increment: ";
    int num;
    cin >> num;              // User inputs number
    auto addOneRef = [](int& n) { ++n; };  // Lambda to modify via reference
    addOneRef(num);          // Modify num
    cout << "Incremented: " << num << endl;  // Show modified value

    cout << "5. Pointer Parameter: Enter number to change: ";
    int val2;
    cin >> val2;             // User inputs number
    changeValue(&val2);      // Pass address to modify
    cout << "Changed: " << val2 << endl;  // Show modified value

    cout << "6. Pointers to Array Elements: Enter two indices (0-4) to swap: ";
    int arr[5] = {1, 2, 3, 4, 5};  // Fixed array
    int i, j;
    cin >> i >> j;           // User inputs indices
    if (i >= 0 && i < 5 && j >= 0 && j < 5) {
        auto swap = [](int* x, int* y) { int temp = *x; *x = *y; *y = temp; };  // Lambda to swap
        swap(&arr[i], &arr[j]);  // Swap elements
        cout << "Array after swap: ";
        for (int k = 0; k < 5; k++) cout << arr[k] << " ";  // Print array
        cout << endl;
    } else {
        cout << "Invalid indices." << endl;
    }

    cout << "7. Array Decay: Passing array to function." << endl;
    auto printArr = [](int* a, int size) {  // Array decays to pointer
        for (int k = 0; k < size; k++) cout << a[k] << " ";
        cout << endl;
    };
    printArr(arr, 5);        // Array decays to pointer

    cout << "8. Pointer Arithmetic: First element address: " << arr << endl;  // Show address
    cout << "Third element: " << *(arr + 2) << ", Address: " << (arr + 2) << endl;  // Show element and address

    cout << "9. Subscripts as Pointer Arithmetic: Enter index (0-4): ";
    int idx;
    cin >> idx;              // User inputs index
    if (idx >= 0 && idx < 5) {
        cout << "arr[" << idx << "]: " << arr[idx] << endl;  // Subscript
        cout << "*(arr + " << idx << "): " << *(arr + idx) << endl;  // Pointer arithmetic
    }

    cout << "10. Pointers as Iterators: Looping through array." << endl;
    int* end = arr + 5;      // Pointer to one past end
    for (int* it = arr; it != end; ++it) {
        cout << *it << " ";  // Print each element
    }
    cout << endl;
}