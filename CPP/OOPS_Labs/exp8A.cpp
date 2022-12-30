#include <iostream>
using namespace std;
template <class T>
void my_swap(T &a, T &b)
{
    T temp;
    temp = a;
    a = b;
    b = temp;
}
int main()
{
    int i1 = 5, i2 = 10;
    cout << "For int." << endl;
    cout << "i1= " << i1 << " i2= " << i2 << endl;
    my_swap(i1, i2);
    cout << "i1= " << i1 << " i2= " << i2 << endl;
    float f1 = 5.5, f2 = 10.56;
    cout << "For float." << endl;
    cout << "f1= " << f1 << " f2= " << f2 << endl;
    my_swap(f1, f2);
    cout << "f1= " << f1 << " f2= " << f2 << endl;
    char c1 = 'a', c2 = 'b';
    cout << "For char." << endl;
    cout << "c1= " << c1 << " c2= " << c2 << endl;
    my_swap(c1, c2);
    cout << "c1= " << c1 << " c2= " << c2 << endl;
    return 0;
}