#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    string s1;
    cout << "Enter the string." << endl;
    cin >> s1;
    cout << "substr(0,3) function." << endl
         << s1.substr(0, 3) << endl;
    cout << "capacity() function." << endl
         << s1.capacity() << endl;
    cout << "find('h') function." << endl
         << s1.find('h') << endl;
    cout << "insert(5,\"b\") function." << endl
         << s1.insert(6, "br") << endl;
}