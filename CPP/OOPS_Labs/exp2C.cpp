#include <iostream>
#define PI 3.14159
using namespace std;
class calc
{
    float ca;

public:
    void area(int s)
    {
        cout << "This figure is square." << endl;
        ca = s * s;
        display();
    }
    void area(int l, int b)
    {
        cout << "This figure is rectangle." << endl;
        ca = l * b;
        display();
    }
    void area(float r)
    {
        cout << "This figure is circle." << endl;
        ca = PI * r * r;
        display();
    }
    void display()
    {
        cout << "The area is : " << ca << endl;
    }
};
int main()
{
    calc c1, c2, c3;
    int a = 5, b = 5, c = 10;
    float d = 5.5;
    cout << "Here, square and rectangle have integer dimensions and circle has float dimensions." << endl;
    cout << "a=" << a << endl;
    c1.area(a);
    cout << "b=" << b << " "
         << "c=" << c << endl;
    c2.area(b, c);
    cout << "d=" << d << endl;
    c3.area(d);
    return 0;
}