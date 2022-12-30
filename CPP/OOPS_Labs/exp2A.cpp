#include <iostream>
using namespace std;
class num
{
public:
    void my_swap(int &m, int &n)
    {

        int temp;
        temp = m;
        m = n;
        n = temp;
    }
};
int main()
{
    num n;
    int a, b;
    cout << "Enter the values of a and b." << endl;
    cin >> a >> b;
    cout << "Values of a and b are a: " << a << " b: " << b << endl;
    n.my_swap(a, b);
    cout << "After swapping:" << endl;
    cout << "Values of a and b are a: " << a << " b: " << b << endl;
    return 0;
}