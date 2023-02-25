#include <iostream>
#include <iomanip>
using namespace std;
class complex
{
    float real, imag;

public:
    void display()
    {
        cout << "The complex nuber is : " << setprecision(4) << real << " + " << setprecision(4) << imag << "I" << endl;
    }
    void enter()
    {
        cout << "Enter the real and imaginary parts." << endl;
        cin >> real >> imag;
    }
    friend complex sum(complex &c1, complex &c2);
};
complex sum(complex &a, complex &b)
{
    complex c;
    c.real = a.real + b.real;
    c.imag = a.imag + b.imag;
    return c;
}
int main()
{
    complex c1, c2, c3;
    c1.enter();
    c2.enter();
    c3 = sum(c1, c2);
    c3.display();
}