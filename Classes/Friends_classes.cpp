#include<iostream>
using namespace std;

class Complex;

class Calculator {
public:
    int add(int a, int b) {
        return (a + b);
    }

    int sumRealComplex(Complex o1, Complex o2);
    int sumCompComplex(Complex o1, Complex o2);
};

class Complex {
private:
    int a, b;
    friend class Calculator;
public:
    void SetNumber(int n1, int n2) {
        a = n1;
        b = n2;
    }
    void printNumber() {
        cout << "Your number is " << a << "+" << b << "i" << endl;
    }
};

int Calculator::sumRealComplex(Complex o1, Complex o2) {
    return (o1.a + o2.a);
}

int Calculator::sumCompComplex(Complex o1, Complex o2) {
    return (o1.b + o2.b);
}

int main() {
	Calculator calc;
    Complex num1, num2;

    // Setting numbers for num1 and num2
    num1.SetNumber(3, 4);
    num2.SetNumber(5, 6);

    // Printing the numbers
    cout << "Number 1: ";
    num1.printNumber();
    cout << "Number 2: ";
    num2.printNumber();

    // Calculating and printing the sum of real parts
    cout << "Sum of real parts: " << calc.sumRealComplex(num1, num2) << endl;

    // Calculating and printing the sum of imaginary parts
    cout << "Sum of imaginary parts: " << calc.sumCompComplex(num1, num2) << endl;

    return 0;
}
