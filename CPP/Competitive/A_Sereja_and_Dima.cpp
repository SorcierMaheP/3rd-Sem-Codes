#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, ser = 0, dim = 0;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int left = 0, right = n - 1, i = 0;
    while (left <= right)
    {
        if (i % 2 == 0)
        {
            if (a[left] > a[right])
                ser += a[left++];
            else
                ser += a[right--];
        }
        else
        {
            if (a[left] > a[right])
                dim += a[left++];
            else
                dim += a[right--];
        }
        i++;
    }
    cout << ser << " " << dim;
    return 0;
}
