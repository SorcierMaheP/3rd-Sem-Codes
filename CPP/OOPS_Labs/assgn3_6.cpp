#include <iostream>
using namespace std;
int main()
{
    double a;
    try
    {
        cout << "Enter value." << endl;
        cin >> a;
        if (a > 9999)
            throw a;
        else
            cout << "Input= " << a;
    }
    catch (double a)
    {
        cout << "Error caught.Input greater than 9999." << endl;
    }
    cout << endl;
    return 0;
}