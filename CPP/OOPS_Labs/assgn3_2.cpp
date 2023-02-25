#include <iostream>
using namespace std;
class list
{
    char name[20];
    int code;
    float price;

public:
    void getinfo(int i)
    {
        cout << "Enter name of item " << i << "\n";
        getchar();
        cin.getline(name, 20);
        cout << "Enter code of item " << i << " \n";
        cin >> code;
        cout << "Enter price of item " << i << " \n";
        cin >> price;
    }
    void display()
    {
        cout.setf(ios::showpoint);
        cout.precision(5);
        cout.setf(ios::left, ios::adjustfield);
        cout.width(10);
        cout << name;
        cout.width(7);
        cout << code;
        cout.width(8);
        cout.setf(ios::right, ios::adjustfield);
        cout << price;
        cout << "\n";
    }
};
int main()
{
    list *l;
    int n;
    cout << "Enter total no. of list items.\n";
    cin >> n;
    l = new list[n];
    for (int i = 0; i < n; i++)
        l[i].getinfo(i + 1);
    cout.fill('-');
    cout.width(25);
    cout << "\n";
    cout.setf(ios::left, ios::adjustfield);
    cout.fill(' ');
    cout.width(10);
    cout << "Name";
    cout.width(7);
    cout << "Code";
    cout.width(8);
    cout << "Price";
    cout.fill('-');
    cout.width(25);
    cout << "\n";
    cout.fill(' ');
    cout << "\n";
    for (int i = 0; i < n; i++)
        l[i].display();
    return 0;
}