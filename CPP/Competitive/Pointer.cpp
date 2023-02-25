#include <iostream>
#include <math.h>
using namespace std;
void update(int *m, int *n)
{
    int temp = (*m);
    (*m) = (*m) + (*n);
    (*n) = abs(temp - (*n));
}
int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    update(&a, &b);
    cout << a << "\n"
         << b;
    return 0;
}