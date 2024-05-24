#include <iostream>
using namespace std;
class complex
{
public:
    float realp, imagp;
    complex()
    {
        realp = 0;
        imagp = 0;
    }
    friend complex operator+( complex & );

    friend istream & operator>>( istream &, complex & );
    friend ostream & operator<<( ostream &, complex & );
};

// for input
istream & operator>>( istream & din, complex & c )
{
    cout << "Enter real part of complex number:";
    din >> c.realp;
    cout << "Enter imaginary part of complex number:";
    din >> c.imagp;
    return din;
}

// for output
ostream & operator<<( ostream & dout, complex & c )
{
    dout << c.realp << "+" << c.imagp << "i" << endl;
    return dout;
}

complex operator+( complex & c1, complex & c2 )
{
    complex temp;
    temp.realp = c1.realp + c2.realp;
    temp.imagp = c1.imagp + c2.imagp;
    return temp;
}

int main()
{
    complex c1, c2, c3;

    cout << "Enter complex no.1\n";
    cin >> c1;
    cout << "Enter complex no.2\n";
    cin >> c2;
    cout << "complex no 1 is:";
    cout << c1;
    cout << "Complex number 2 is:";
    cout << c2;

    cout << "\nAddition of two complex number is:";
    c3 = c1 + c2;
    cout << c3;

    return 0;
}
