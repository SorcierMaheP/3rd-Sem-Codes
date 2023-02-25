#include <iostream>
using namespace std;
class Integer
{
    int i;

public:
    Integer(int m=0)
    {
        i = m;
    }
    Integer operator++() // Unary Prefix Increment
    {
        Integer temp;
        temp.i = ++i;
        return temp;
    }
    Integer operator++(int) // Unary Postfix Increment
    {
        Integer temp;
        temp.i = i++;
        return temp;
    }
    Integer operator--() // Unary Prefix Decrement
    {
        Integer temp;
        temp.i = --i;
        return temp;
    }
    Integer operator--(int) // Unary Postfix Decrement
    {
        Integer temp;
        temp.i = i--;
        return temp;
    }
    void display()
    {
        cout << "The value is " << i << endl;
    }
};
int main()
{
    Integer I1(5), I2;
    cout << "Initial value." << endl;
    I1.display();
    I2 = ++I1;
    cout << "Value after pre increment." << endl;
    I2.display();
    I2 = I1++;
    cout << "Value after post increment." << endl;
    I2.display();
    cout << "Initial value." << endl;
    I1.display();
    I2 = --I1;
    cout << "Value after pre decrement." << endl;
    I2.display();
    I2 = I1--;
    cout << "Value after post decrement." << endl;
    I2.display();
    return 0;
}