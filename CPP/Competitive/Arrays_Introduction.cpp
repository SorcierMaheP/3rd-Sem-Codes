#include <iostream>
using namespace std;
int main()
{
    int N;
    scanf("%d", &N);
    int a[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = N - 1; i >= 0; i--)
    {
        printf("%d ", a[i]);
    }
    return 0;
}