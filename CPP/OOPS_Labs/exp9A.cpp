#include <iostream>
using namespace std;
void divide(int a, int b)
{
    cout << "Inside function.\n";
    try
    {
        if (b != 0)
        {
            cout << "Result of division is :" << float(a) / b << endl;
        }
        else
        {
            cout << "Error.Throwing..." << endl;
            throw b;
        }
    }
    catch (int i)
    {
        cout << "Cannot handle the exception.Rethrowing..." << endl;
        throw;
    }
}
int main()
{
    try
    {
        divide(5, 3);
        divide(10, 0);
    }
    catch (int j)
    {
        cout << "Caught the exception :" << j << endl;
    }
    return 0;
}