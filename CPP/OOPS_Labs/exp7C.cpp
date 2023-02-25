#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    float sum;
    cout << setw(2) << "n" << setw(20) << "Inverse_of_n" << setw(25) << "Sum_of_terms" << endl
         << endl;
    for (int i = 1; i <= 10; i++)
    {
        cout << setw(2) << i << setw(18) << setprecision(4) << setiosflags(ios::showpoint) << setiosflags(ios::scientific) << 1.0 / i;
        sum += 1.0 / i;
        cout << setw(23) << resetiosflags(ios::scientific) << setprecision(5) << sum << endl;
    }
}