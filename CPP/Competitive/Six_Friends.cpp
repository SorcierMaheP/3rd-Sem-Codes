#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T, X, Y;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++)
    {
        scanf("%d %d", &X, &Y);
        if (3 * X > 2 * Y)
            printf("%d", 2 * Y);
        else
            printf("%d", 3 * X);
        printf("\n");
    }
    return 0;
}