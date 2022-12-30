# include <iostream>
using namespace std;
class Base
{
    public:
    virtual void display()
    {
        cout<<"Display base class."<<endl;
    }
    virtual void show()
    {
        cout<<"Show base class."<<endl;
    }
};
class Derived:public Base
{
    public:
    void display()
    {
        cout<<"Display derived class."<<endl;
    }
    void show()
    {
        cout<<"Show derived class."<<endl;
    }
};
int main()
{
    Base B;
    Derived D;
    Base *bptr;
    bptr=&B;
    cout<<"bptr points to base."<<endl;
    bptr->display();
    bptr->show();
    bptr=&D;
    cout<<"bptr points to derived."<<endl;
    bptr->display();
    bptr->show();
    return 0;
}