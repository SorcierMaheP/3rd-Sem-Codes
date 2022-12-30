#include <iostream>
using namespace std;
class alpha
{
    int x;

public:
    alpha(int i = 0)
    {
        x = i;
        cout << "alpha initialized." << endl;
    }
    void show_x()
    {
        cout << "x = " << x << endl;
    }
};
class beta
{
    float y;

public:
    beta(float j = 0.0f)
    {
        y = j;
        cout << "beta initialized." << endl;
    }
    void show_y()
    {
        cout << "y = " << y << endl;
    }
};
class gamma : public beta, public alpha // Beta is initialized first
{
    int m, n;

public:
    gamma(int a, int b, float c, int d) : alpha(d), beta(c) // Initialization List
    {
        m = a;
        n = b;
        cout << "gamma initialized." << endl;
    }
    void show_mn()
    {
        cout << "m = " << m << endl
             << "n = " << n << endl;
    }
};
int main()
{
    gamma g(5, 10, 3.75, 7);
    g.show_x();
    g.show_y();
    g.show_mn();
    return 0;
}