#include <iostream>
using namespace std;
class profile
{
    char user[30];
    int units;
    float price = 0.0;

public:
    void enter()
    {
        cout << "Enter name." << endl;
        cin >> user;
        cout << "Enter units." << endl;
        cin >> units;
    }
    void calc()
    {
        while (units > 0)
        {
            if (units <= 100)
            {
                price += units * 0.6;
                units = 0;
            }
            if (units > 100 && units <= 300)
            {
                price += (units - 100) * 0.8;
                units = 100;
            }
            if (units > 300)
            {
                price += (units - 300) * 0.9;
                units = 300;
            }
        }
        if (price < 50.0)
            price = 50.0;
        if (price > 300.0)
            price += 0.15 * price;
    }
    void display()
    {
        cout << "The charge incurred by user " << user << " is " << price << " Rs." << endl;
    }
};
int main()
{
    int num;
    cout << "Enter the total number of users." << endl;
    cin >> num;
    profile p[num];
    for (int i = 0; i < num; i++)
    {
        cout << "Enter details of user " << i + 1 << "." << endl;
        p[i].enter();
        p[i].calc();
        p[i].display();
    }
    return 0;
}