#include <iostream>
using namespace std;

// Abstract Base Class
class Shape {
public:
    virtual void calculate() = 0; // Pure virtual function
};

// Derived class for Circle
class Circle : public Shape {
    float radius;
public:
    void calculate() {
        cout << "Enter radius: ";
        cin >> radius;
        cout << "Area of Circle = " << 3.14 * radius * radius << endl;
    }
};

// Derived class for Triangle
class Triangle : public Shape {
    float base, height;
public:
    void calculate() {
        cout << "Enter base and height: ";
        cin >> base >> height;
        cout << "Area of Triangle = " << 0.5 * base * height << endl;
    }
};

// Derived class for Rectangle
class Rectangle : public Shape {
    float length, width;
public:
    void calculate() {
        cout << "Enter length and width: ";
        cin >> length >> width;
        cout << "Area of Rectangle = " << length * width << endl;
    }
};

int main() {
    Shape *s;
    int choice;

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Area of Circle\n";
        cout << "2. Area of Triangle\n";
        cout << "3. Area of Rectangle\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                s = new Circle();
                s->calculate();
                break;
            case 2:
                s = new Triangle();
                s->calculate();
                break;
            case 3:
                s = new Rectangle();
                s->calculate();
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }

    } while(choice != 4);

    return 0;
}