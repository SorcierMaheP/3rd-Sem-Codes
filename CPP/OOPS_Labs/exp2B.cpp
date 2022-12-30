#include <iostream>
#define PI 3.14159
using namespace std;
class calc
{
    float r;
    float s;
    float circar;

public:
    inline float area(int);
    void get()
    {
        cout << "Enter radius of circle and side of square." << endl;
        cin >> r >> s;
    }
    void calcar()
    {
        circar = area(r);
    }
    void display()
    {
        cout << "Area of circle is " << circar << "." << endl;
    }
    friend float sqarcalc(float);
};

float calc::area(int r)
{
    float a = PI * r * r;
    return a;
}
float sqarcalc(int s)
{
    float a = s * s;
    return a;
}

int main()
{
    calc c;
    float sqarar;
    c.get();
    c.calcar();
    c.display();
    sqarar = sqarcalc(5);
    cout << "Area of square is " << sqarar << "." << endl;
    return 0;
}