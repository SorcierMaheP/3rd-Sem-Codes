#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    string s1, s2;
    cout << "Enter The string." << endl;
    cin >> s1;
    s2 = s1;
    reverse(s1.begin(), s1.end());
    if (s2 == s1)
        cout << "The string is a palindrome." << endl;
    else
        cout << "The string is not a palindrome." << endl;
    return 0;
}