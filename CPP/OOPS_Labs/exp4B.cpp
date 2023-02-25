#include <iostream>
using namespace std;
class Integer
{
    int m, n;

public:
    Integer(int a = 0, int b = 0)
    {
        m = a;
        n = b;
    }
    Integer operator*(Integer &a)
    {
        Integer temp;
        temp.m = m * a.m;
        temp.n = n * a.n;
        return temp;
    }
    Integer operator-(int a)
    {
        Integer temp;
        temp.m = m - a;
        temp.n = n - a;
        return temp;
    }
    void display()
    {
        cout << "Values of m and n are " << m << " and " << n << endl;
    }
    friend Integer operator+(int, Integer);
    friend int main();
};

Integer operator+(int a, Integer I)
{
    Integer temp;
    temp.m = a + I.m;
    temp.n = a + I.n;
    return temp;
}

int main()
{
    Integer x, y(5, 6);
    cout << "x=5+y" << endl;
    cout << "Values of y: " << endl;
    y.display();
    x = 5 + y;
    cout << "Values of x:" << endl;
    x.display();
    cout << "x=x*y" << endl;
    x = Integer(3, 4);
    y = Integer(5, 6);
    cout << "Values of x: " << endl;
    x.display();
    cout << "Values of y: " << endl;
    y.display();
    x = x * y;
    cout << "New values of x: " << endl;
    x.display();
    x = Integer();
    y = Integer(5, 6);
    cout << "x=y-5" << endl;
    cout << "Values of y: " << endl;
    y.display();
    x = y - 5;
    cout << "Values of x:" << endl;
    x.display();
}