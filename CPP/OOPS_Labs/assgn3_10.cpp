#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s1;
    cout << "Enter the string." << endl;
    cin >> s1;
    for (string::iterator itr = s1.begin(); itr != s1.end(); itr++)
        cout << (*itr);
    cout << endl;
    return 0;
}