#include <iostream>
using namespace std;
int count=0;
class A
{
    int m, n;

public:
    A() // Default Constructor
    {
        cout<<"Constructor called."<<endl;
        cout<<"Object created."<<endl<<endl;
        m = 0;
        n = 0;
    }
    A(int a, int b) // Parameterized Constructor
    {
        cout<<"Constructor called."<<endl;
        cout<<"Object created."<<endl<<endl;
        m = a;
        n = b;
    }
    A(A &i) // Copy Constructor
    {
        cout<<"Constructor called."<<endl;
        cout<<"Object created."<<endl<<endl;
        m = i.m;
        n = i.n;
    }
    ~A() //Destructor
    {
        cout<<"Destructor called."<<endl;
        cout<<"Object destroyed."<<endl<<endl;
    }
    void display()
    {
        cout << "Value of m:" << m << " "
             << "n:" << n << endl;
    }
};
int main()
{
    cout<<"Passed values will be displayed."<<endl;
    A a(100, 50);
    a.display();
    cout<<"Copied values will be displayed."<<endl;
    A b(a);
    b.display();
    {
        A c;
    }
    {
        A d(11,12);
    }
    return 0;
}