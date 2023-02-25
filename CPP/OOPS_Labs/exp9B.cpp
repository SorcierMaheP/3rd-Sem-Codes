#include <iostream>
#include <iomanip>
using namespace std;
void test(int x)
{
    try
    {
        if (x == 1)
            throw x; // int
        else if (x == 0)
            throw 'x'; // char
        else if (x == -1)
            throw 1.0; // double
        else
            throw "x";
    }
    catch (int m)
    {
        cout << "Caught int " << m << endl;
    }
    catch (char c)
    {
        cout << "Caught char " << c << endl;
    }
    catch (double d)
    {
        cout << "Caught double " << fixed << d << endl;
    }
    catch (...)
    {
        cout << "Caught default exception " << endl;
    }
}
int main()
{
    test(1);
    test(0);
    test(-1);
    test(2);
    return 0;
}
