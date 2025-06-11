#include <iostream>
#include <string>
#include "references.h"
using namespace std;

// 1. Basic Reference
void basicReference() {
  cout << "\n1. Basic Reference: An alias for a variable.\n"
       << "   Enter an integer: ";
  int x;
  if (!(cin >> x)) {
    cout << "   Invalid input. Using default value 0.\n";
    cin.clear();
    cin.ignore(10000, '\n');
    x = 0;
  }
  int& ref = x; // ref is an alias for x
  cout << "   Value of x: " << x << "\n"
       << "   Value via ref: " << ref << "\n"
       << "   Address of x: " << &x << "\n"
       << "   Address of ref: " << &ref << "\n";
  ref = 42; // Modifies x
  cout << "   After ref = 42, x: " << x << endl;
}

// 2. Pass by Reference
void passByReference() {
  cout << "\n2. Pass by Reference: Modify variables in functions.\n"
       << "   Enter an integer: ";
  int x;
  if (!(cin >> x)) {
    cout << "   Invalid input. Using default value 0.\n";
    cin.clear();
    cin.ignore(10000, '\n');
    x = 0;
  }
  auto swap = [](int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
  };
  cout << "   Enter another integer: ";
  int y;
  if (!(cin >> y)) {
    cout << "   Invalid input. Using default value 0.\n";
    cin.clear();
    cin.ignore(10000, '\n');
    y = 0;
  }
  cout << "   Before swap: x = " << x << ", y = " << y << "\n";
  swap(x, y);
  cout << "   After swap: x = " << x << ", y = " << y << endl;
}

// 3. Const Reference
void constReference() {
  cout << "\n3. Const Reference: Prevent modification, avoid copying.\n"
       << "   Enter an integer: ";
  int x;
  if (!(cin >> x)) {
    cout << "   Invalid input. Using default value 0.\n";
    cin.clear();
    cin.ignore(10000, '\n');
    x = 0;
  }
  const int& ref = x; // Cannot modify x via ref
  cout << "   Value via const ref: " << ref << "\n"
       << "   Address of x: " << &x << "\n"
       << "   Address of ref: " << &ref << "\n";
  // ref = 42; // Error: ref is const
  cout << "   Cannot modify x via const ref.\n";
  x = 42; // Can modify x directly
  cout << "   Modified x directly: " << x << "\n"
       << "   Value via const ref: " << ref << endl;
}

// 4. Reference vs Pointer
void referenceVsPointer() {
  cout << "\n4. Reference vs Pointer: Compare behavior.\n"
       << "   Enter an integer: ";
  int x;
  if (!(cin >> x)) {
    cout << "   Invalid input. Using default value 0.\n";
    cin.clear();
    cin.ignore(10000, '\n');
    x = 0;
  }
  int& ref = x;
  int* ptr = &x;
  cout << "   Value of x: " << x << "\n"
       << "   Value via ref: " << ref << "\n"
       << "   Value via ptr: " << *ptr << "\n"
       << "   Address via ref: " << &ref << "\n"
       << "   Address via ptr: " << ptr << "\n";
  ref = 100;
  cout << "   After ref = 100, x: " << x << "\n";
  *ptr = 200;
  cout << "   After *ptr = 200, x: " << x << endl;
}

// Main references function with menu
void references() {
  while (true) {
    cout << "\nExploring Reference Concepts - Choose an option (1-4, 0 to exit):\n"
         << "1. Basic Reference\n"
         << "2. Pass by Reference\n"
         << "3. Const Reference\n"
         << "4. Reference vs Pointer\n"
         << "Enter choice: ";
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
      case 1: basicReference(); break;
      case 2: passByReference(); break;
      case 3: constReference(); break;
      case 4: referenceVsPointer(); break;
      default: cout << "Invalid choice. Choose 1-4 or 0 to exit.\n"; break;
    }
  }
}