#include <iostream>
using namespace std;
int main()
{
    string s = "object", s2 = "", s3 = "";
    for (int i = 0; i < 6; i++)
    {
        s2 = "";
        s3 = "";
        for (int j = 0; j < 6 - i; j++)
            s2 += s[j];
        cout << s2;
        for (int j = 5 - i; j >= 0; j--)
        {
            cout.width(6 + i);
            cout.setf(ios::right, ios::adjustfield);
            s3 += s[j];
        }
        if (i == 5)
            cout.fill('*');
        cout << s3;
        cout << endl;
    }
    for (int i = 4; i >= 0; i--)
    {
        s2 = "";
        s3 = "";
        for (int j = 0; j < 6 - i; j++)
            s2 += s[j];
        cout << s2;
        cout.fill(' ');
        for (int j = 5 - i; j >= 0; j--)
        {
            cout.width(6 + i);
            cout.setf(ios::right, ios::adjustfield);
            s3 += s[j];
        }
        cout << s3;
        cout << endl;
    }
}