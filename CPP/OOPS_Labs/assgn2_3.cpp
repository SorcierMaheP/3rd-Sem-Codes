#include <iostream>
using namespace std;
class DB;
class DM
{
    int m, cm;

public:
    DM()
    {
        m = 0.0;
        cm = 0.0;
    }
    void get()
    {
        cout << "Enter the data in metric units." << endl;
        cin >> m >> cm;
    }
    void display()
    {
        cout << "\nMetre: " << m;
        cout << "\nCentimetre: " << cm << endl;
        ;
    }
    friend void add(DM, DB, int);
};
class DB
{
    int ft, ic;

public:
    DB()
    {
        ft = 0.0;
        ic = 0.0;
    }
    void get()
    {
        cout << "Enter the data in imperial units." << endl;
        cin >> ft >> ic;
    }
    void display()
    {
        cout << "\nFeet: " << ft;
        cout << "\nInch: " << ic << endl;
    }
    friend void add(DM, DB, int);
};

void add(DM a, DB b, int n)
{
    if (n == 1)
    {
        DM sum;
        float c = (a.m * 100.0 + a.cm + b.ft * 30.48 + b.ic * 2.54);
        if (c >= 100)
        {
            sum.m = c / 100;
            sum.cm = c - sum.m * 100;
        }
        else
        {
            sum.m = 0.0;
            sum.cm = c;
        }
        sum.display();
    }
    else if (n == 2)
    {
        DB sum;
        float i = (a.m * 39.37 + a.cm / 2.54 + b.ft * 12.0 + b.ic);
        if (i >= 12)
        {
            sum.ft = i / 12;
            sum.ic = i - sum.ft * 12;
        }
        else
        {
            sum.ft = 0.0;
            sum.ic = i;
        }
        sum.display();
    }
}

int main()
{
    DM a;
    DB b;
    int ch;
    a.get();
    b.get();
    cout << "Enter 1 for result in metric units or 2 for result in imperial units." << endl;
    cin >> ch;
    if (ch == 1 || ch == 2)
        add(a, b, ch);
    return 0;
}