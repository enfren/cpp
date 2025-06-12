#include <iostream>
#include <string>
#include "pointers.h"
using namespace std;

// 1. Basic Pointer
void basicPointer() {
  cout << "\n1. Basic Pointer: Stores a variable's memory address.\n"
       << "   Enter an integer: ";
  int x;
  if (!(cin >> x)) {
    cout << "   Invalid input. Using default value 0.\n";
    cin.clear();
    cin.ignore(10000, '\n');
    x = 0;
  }
  int* ptr = &x;
  cout << "   Value of variable x: " << x << "\n"
       << "   Address of variable x: " << ptr << "\n"
       << "   Value via pointer: " << *ptr << endl;
}

// 2. Dereferencing
void dereference() {
  cout << "2. Use * to access/modify a pointer's value.\n"
       << "Enter an integer: ";
  int i1;
  // cout << "Garbage value of i1: " << i1 << " &i1: " << &i1 << endl;
  cin >> i1;
  cout << "Value of i1: " << i1 << endl;
  int* ptr = &i1;
  cout << "ptr: " << ptr << " &i1: " << &i1 << endl;
  cout << "&ptr: " << &ptr << endl;
  cout << "Enter a second integer: ";
  int i2;
  cin >> i2;
  *ptr = i2; // At address stored in ptr overwrite i1 with i2
  cout << "Value of i2: " << i2 << endl;
  cout << "Address of i2: " << &i2 << " ptr :" << ptr << endl;
}

// 3. Null Pointer
void nullPointer() {
  cout << "3. Null Pointer: A pointer can point to nothing (nullptr).\n";
  int* ptr = nullptr;
  cout << "Is ptr null? " << (ptr == nullptr ? "Yes" : "No") << endl;
}

// 4. Pointer Parameter
void pointerParameter() {
  cout << "4. Pointer Parameter: Pass pointers to modify variables.\n"
       << "Enter an integer to modify: ";
  int val;
  cin >> val;
  cout << "What value do you want to change it to? ";
  int num;
  cin >> num;
  int* p = &val;
  *p = num; // Modify value via pointer
  cout << "Modified value: " << val << endl;
}

// 5. Arrays and Pointers
void arraysAndPointers() {
  cout << "5. Arrays and Pointers: An array's name is a pointer.\n"
       << "Enter array size (1-10): ";
  int size;
  cin >> size;
  if (size < 1 || size > 10) size = 3;
  int* arr = new int[size];
  cout << "Enter " << size << " values: ";
  for (int i = 0; i < size; i++) cin >> arr[i];
  cout << "Array: ";
  for (int i = 0; i < size; i++) cout << arr[i] << " ";
  cout << "\nFirst element address: " << arr << endl;
  delete[] arr;
  arr = nullptr;
}

// 6. Pointer Arithmetic
void pointerArithmetic() {
  cout << "6. Pointer Arithmetic: Navigate arrays with pointers.\n"
       << "Enter array size (1-10): ";
  int size;
  cin >> size;
  if (size < 1 || size > 10) size = 3;
  int* arr = new int[size];
  cout << "Enter " << size << " values: ";
  for (int i = 0; i < size; i++) cin >> arr[i];
  cout << "First element: " << *arr << ", Address: " << arr << endl;
  cout << "Second element: " << *(arr + 1) << ", Address: " << (arr + 1) << endl;
  delete[] arr;
  arr = nullptr;
}

// 7. Subscripts as Pointer Arithmetic
void subscriptsAsPointerArithmetic() {
  cout << "7. Subscripts as Pointer Arithmetic: arr[i] equals *(arr + i).\n";
  int arr[5] = {1, 2, 3, 4, 5};
  cout << "Array: ";
  for (int i = 0; i < 5; i++) cout << arr[i] << " ";
  cout << "\nEnter index (0-4): ";
  int idx;
  cin >> idx;
  if (idx >= 0 && idx < 5) {
    cout << "arr[" << idx << "]: " << arr[idx] << endl;
    cout << "*(arr + " << idx << "): " << *(arr + idx) << endl;
  } else {
    cout << "Invalid index.\n";
  }
}

// 8. Dynamic Memory
void dynamicMemory() {
  cout << "8. Dynamic Memory: Allocate memory with new, free with delete.\n"
       << "Enter an integer to allocate: ";
  int val;
  cin >> val;
  int* ptr = new int(val);
  cout << "Allocated value: " << *ptr << endl;
  delete ptr;
  ptr = nullptr;
  cout << "Memory freed, ptr is null: " << (ptr == nullptr ? "Yes" : "No") << endl;
}

// 9. Memory Leak Demo
void memoryLeakDemo() {
  cout << "9. Memory Leak: Forgetting to free memory causes leaks.\n"
       << "Allocate without freeing? (1=yes, 0=no): ";
  int leak;
  cin >> leak;
  if (leak) {
    int* leakP = new int(42);
    cout << "Memory allocated, not freed (leak simulation).\n";
  }
}

// 10. Pointers to Array Elements
void pointersToArrayElements() {
  cout << "10. Pointers to Array Elements: Manipulate array elements with pointers.\n";
  int arr[5] = {1, 2, 3, 4, 5};
  cout << "Original array: ";
  for (int i = 0; i < 5; i++) cout << arr[i] << " ";
  cout << "\nEnter two indices (0-4) to swap: ";
  int i, j;
  cin >> i >> j;
  if (i >= 0 && i < 5 && j >= 0 && j < 5) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
    cout << "Array after swap: ";
    for (int k = 0; k < 5; k++) cout << arr[k] << " ";
    cout << endl;
  } else {
    cout << "Invalid indices.\n";
  }
}

// 11. Array Decay
void arrayDecay() {
  cout << "11. Array Decay: Arrays become pointers when passed to functions.\n";
  int arr[5] = {1, 2, 3, 4, 5};
  cout << "Array: ";
  for (int i = 0; i < 5; i++) cout << arr[i] << " ";
  cout << endl;
}

// 12. Pointers as Iterators
void pointersAsIterators() {
  cout << "12. Pointers as Iterators: Use pointers to iterate over arrays.\n";
  int arr[5] = {1, 2, 3, 4, 5};
  cout << "Array: ";
  int* end = arr + 5;
  for (int* it = arr; it != end; ++it) {
    cout << *it << " ";
  }
  cout << endl;
}

// Main pointers function with menu
void pointers() {
  while (true) {
    cout << "\nExploring Pointer Concepts - Choose an option (1-12, 0 to exit):\n";
    cout << "1. Basic Pointer\n";
    cout << "2. Dereferencing\n";
    cout << "3. Null Pointer\n";
    cout << "4. Pointer Parameter\n";
    cout << "5. Arrays and Pointers\n";
    cout << "6. Pointer Arithmetic\n";
    cout << "7. Subscripts as Pointer Arithmetic\n";
    cout << "8. Dynamic Memory\n";
    cout << "9. Memory Leak Demo\n";
    cout << "10. Pointers to Array Elements\n";
    cout << "11. Array Decay\n";
    cout << "12. Pointers as Iterators\n";
    cout << "Enter choice: ";

    int choice;
    if (!(cin >> choice)) {
      cout << "Invalid input. Please enter a number.\n";
      cin.clear();
      cin.ignore(10000, '\n');
      continue;
    }

    if (choice == 0) {
      cout << "Exiting.\n";
      break;
    }

    switch (choice) {
      case 1: basicPointer(); break;
      case 2: dereference(); break;
      case 3: nullPointer(); break;
      case 4: pointerParameter(); break;
      case 5: arraysAndPointers(); break;
      case 6: pointerArithmetic(); break;
      case 7: subscriptsAsPointerArithmetic(); break;
      case 8: dynamicMemory(); break;
      case 9: memoryLeakDemo(); break;
      case 10: pointersToArrayElements(); break;
      case 11: arrayDecay(); break;
      case 12: pointersAsIterators(); break;
      default: cout << "Invalid choice. Choose 1-12 or 0 to exit.\n"; break;
    }
  }
}