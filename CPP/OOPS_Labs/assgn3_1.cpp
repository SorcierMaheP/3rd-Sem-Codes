#include <iostream>
#include <cmath>
using namespace std;
class Rectangle;
class Polar
{
    float radius, angle;

public:
    Polar()
    {
        radius = 0;
        angle = 0;
    }
    void getPolar()
    {
        cout << "Enter  Radius and Angle.\n";
        cin >> radius >> angle;
    }
    Polar(Rectangle &);
    void display()
    {
        cout << "The Radius = " << radius << endl;
        cout << "The Angle = " << angle << endl;
    }
    float retradius()
    {
        return radius;
    }
    float retangle()
    {
        return angle;
    }
};
class Rectangle
{
    float x, y;

public:
    Rectangle()
    {
        x = 0;
        y = 0;
    }
    void getRectangle()
    {
        cout << "Enter  X and Y coordinates.\n";
        cin >> x >> y;
    }
    Rectangle(Polar &p)
    {
        x = p.retradius() * cos(p.retangle());
        y = p.retradius() * sin(p.retangle());
    }
    void display()
    {
        cout << "The X coordinate is " << x << "\n"
             << "The Y coordinate is " << y << endl;
    }
    float retx()
    {
        return x;
    }
    float rety()
    {
        return y;
    }
};
Polar::Polar(Rectangle &r)
{
    float a;
    a = atan((r.rety() / r.retx()));
    angle = a * (180 / 3.14);
    radius = sqrt((r.retx() * r.retx() + r.rety() * r.rety()));
}
int main()
{
    Polar p1;
    Rectangle r1;
    int ch;
    while (1)
    {
        cout << "1.Polar to Rectangle.\n";
        cout << "2.Rectangle to polar.\n";
        cout << "3.Exit.\n";
        cout << "Enter your choice.\n";
        cin >> ch;
        switch (ch)
        {
        case 1:
            p1.getPolar();
            r1 = p1;
            r1.display();
            break;
        case 2:
            r1.getRectangle();
            p1 = r1;
            p1.display();
            break;
        case 3:
            exit(1);
        default:
            cout << "Erroneous input.\n";
        }
    }
}