#include <iostream>
using namespace std;
int max_of_four(int a, int b, int c, int d)
{
    int ret;
    if (a >= b && a >= c && a >= d)
        ret = a;
    else if (b >= a && b >= c && b >= d)
        ret = b;
    else if (c >= a && c >= b && c >= d)
        ret = c;
    else
        ret = d;
    return ret;
}
int main()
{
    int m, n, o, p, ans;
    cin >> m >> n >> o >> p;
    ans = max_of_four(m, n, o, p);
    cout << ans;
    return 0;
}