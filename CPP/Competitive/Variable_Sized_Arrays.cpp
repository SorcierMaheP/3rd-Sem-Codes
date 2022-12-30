#include <iostream>
using namespace std;
int main()
{
    int n, q, k, i1, j1, *a;
    scanf("%d%d", &n, &q);
    for (int l = 1; l <= n; l++)
    {
        scanf("%d", &k);
        a = new int[n][k];
        for (int j = 0; j < k; j++)
        {
            scanf("%d", &a[l - 1][j]);
        }
    }
    for (int m = 1; m <= q; m++)
    {
        scanf("%d %d", &i1, &j1);
        printf("%d\n", a[i1][j1]);
    }
    return 0;
}