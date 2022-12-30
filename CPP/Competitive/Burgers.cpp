#include <bits/stdc++.h>
int main()
{
    int T, A, B, lcm = 0;
    scanf("%d", &T);
    int i;
    for (i = 0; i < T; i++)
    {
        scanf("%d%d", &A, &B);
        int j;
        printf("%d\n", A > B ? B : A);
    }
}