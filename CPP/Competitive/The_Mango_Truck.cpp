#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T, X, Y, Z, num, rem, div;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++)
    {
        scanf("%d %d %d", &X, &Y, &Z);
        rem = Z - Y;
        div = rem % X;
        num = (rem - div) / X;
        printf("%d\n", num);
    }
    return 0;
}