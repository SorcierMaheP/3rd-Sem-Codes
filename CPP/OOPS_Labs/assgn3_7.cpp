#include <iostream>
using namespace std;
void func1()
{
    cout << "Function 1 invoked.\n";
    throw 1;
    cout << "Function 1 completed.\n";
}
void func2()
{
    cout << "Function 2 invoked.\n";
    func1();
    cout << "Function 2 completed.\n";
}
void func3()
{
    cout << "Function 3 invoked.\n";
    try
    {
        func2();
    }
    catch (int a)
    {
        cout << "Error Caught.\n";
    }
    cout << "Function 3 Completed.\n";
}
int main()
{
    func3();
    return 0;
}