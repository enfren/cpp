#include <iostream>
#include <limits>
#include "include/pointers.h"
#include "include/references.h"
#include "include/classes.h"
using namespace std;

int main() {
  while (true) {
    cout << "\nC++ Learning Menu - Choose a topic (1-3, 0 to exit):\n"
         << "1. Pointers\n"
         << "2. References\n"
         << "3. Classes, Inheritance, Polymorphism\n"
         << "Enter choice: ";
    int choice;
    if (!(cin >> choice)) {
      cout << "Invalid input. Please enter a number.\n";
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      continue;
    }
    if (choice == 0) {
      cout << "Exiting.\n";
      break;
    }
    switch (choice) {
      case 1: pointers(); break;
      case 2: references(); break;
      case 3: finance::classes(); break;
      default: cout << "Invalid choice. Choose 1-3 or 0 to exit.\n"; break;
    }
  }
  return 0;
}