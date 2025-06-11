#include <iostream>
#include <string>
#include "classes.h"
using namespace std;

// 1. Basic Class
void basicClass() {
  cout << "\n1. Basic Class: Encapsulate data and methods.\n";
  class Point {
   public:
    int x, y;
    Point(int x = 0, int y = 0) : x(x), y(y) {}
    void print() const {
      cout << "   Point(" << x << ", " << y << ")\n";
    }
  };
  cout << "   Enter x and y coordinates: ";
  int x, y;
  if (!(cin >> x >> y)) {
    cout << "   Invalid input. Using default (0, 0).\n";
    cin.clear();
    cin.ignore(10000, '\n');
    x = y = 0;
  }
  Point p(x, y);
  p.print();
}

// 2. Inheritance
void inheritance() {
  cout << "\n2. Inheritance: Derived class inherits from base class.\n";
  class Animal {
   public:
    string name;
    Animal(const string& n) : name(n) {}
    void speak() const {
      cout << "   " << name << " makes a sound.\n";
    }
  };
  class Dog : public Animal {
   public:
    Dog(const string& n) : Animal(n) {}
    void speak() const {
      cout << "   " << name << " says Woof!\n";
    }
  };
  cout << "   Enter a dog name: ";
  string name;
  cin >> name;
  Dog dog(name);
  dog.speak();
}

// 3. Polymorphism
void polymorphism() {
  cout << "\n3. Polymorphism: Virtual functions for dynamic dispatch.\n";
  class Shape {
   public:
    virtual void draw() const {
      cout << "   Drawing a generic shape.\n";
    }
    virtual ~Shape() {}
  };
  class Circle : public Shape {
   public:
    void draw() const override {
      cout << "   Drawing a circle.\n";
    }
  };
  class Square : public Shape {
   public:
    void draw() const override {
      cout << "   Drawing a square.\n";
    }
  };
  Shape* shapes[] = {new Circle(), new Square()};
  for (int i = 0; i < 2; ++i) {
    shapes[i]->draw();
    delete shapes[i];
  }
}

// 4. Abstract Class
void abstractClass() {
  cout << "\n4. Abstract Class: Cannot instantiate, requires derived classes.\n";
  class Vehicle {
   public:
    virtual void move() const = 0; // Pure virtual
    virtual ~Vehicle() {}
  };
  class Car : public Vehicle {
   public:
    void move() const override {
      cout << "   Car drives on roads.\n";
    }
  };
  class Boat : public Vehicle {
   public:
    void move() const override {
      cout << "   Boat sails on water.\n";
    }
  };
  Vehicle* vehicles[] = {new Car(), new Boat()};
  for (int i = 0; i < 2; ++i) {
    vehicles[i]->move();
    delete vehicles[i];
  }
}

// Main classes function with menu
void classes() {
  while (true) {
    cout << "\nExploring Classes, Inheritance, Polymorphism - Choose an option (1-4, 0 to exit):\n"
         << "1. Basic Class\n"
         << "2. Inheritance\n"
         << "3. Polymorphism\n"
         << "4. Abstract Class\n"
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
      case 1: basicClass(); break;
      case 2: inheritance(); break;
      case 3: polymorphism(); break;
      case 4: abstractClass(); break;
      default: cout << "Invalid choice. Choose 1-4 or 0 to exit.\n"; break;
    }
  }
}