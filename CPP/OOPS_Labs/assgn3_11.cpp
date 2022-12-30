#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> v(10, 0);
    v[0] = 100;
    v[9] = 200;
    for (int i = 1; i < 9; i++)
        v[i] = 10;
    for (int i = 0; i < 10; i++)
        cout << v[i] << " ";
    cout << endl;
    return 0;
}