#include <iostream>
using namespace std;
class Integer
{
    int m, n;

public:
    Integer(int a = 0, int b = 0)
    {
        m = a;
        n = b;
    }
    friend ostream &operator<<(ostream &, const Integer &);
    friend istream &operator>>(istream &, Integer &);
};

ostream &operator<<(ostream &os, const Integer &I)
{
    os << "m:" << I.m << " "
       << "n:" << I.n << endl;
    return os;
}

istream &operator>>(istream &is, Integer &I)
{
    is >> I.m >> I.n;
    return is;
}
int main()
{
    Integer I1, I2;
    cout << "Enter values of I1 and I2." << endl;
    cin >> I1 >> I2;
    cout << "Values of I1 and I2 respectively are:" << endl;
    cout << I1 << I2;
    return 0;
}