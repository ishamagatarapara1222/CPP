#include <iostream>
using namespace std;

class Number {
private:
    int value;

public:
    // Constructor
    Number(int v) {
        value = v;
    }

    // Overload < operator
    bool operator < (Number obj) {
        if (this->value < obj.value)
            return true;
        else
            return false;
    }

    void display() {
        cout << value;
    }
};

int main() {
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;

    Number n1(a), n2(b);

    if (n1 < n2)
        cout << "Second object has higher value: " << b << endl;
    else if (n2 < n1)
        cout << "First object has higher value: " << a << endl;
    else
        cout << "Both values are equal" << endl;

    return 0;
}