#include <iostream>
#include <cstring>
using namespace std;
class String
{
    char *p;
    int len;

public:
    String()
    {
        len = 0;
        p = NULL;
    }
    String(char *s)
    {
        len = strlen(s);
        p = new char[len + 1];
        strcpy(p, s);
    }
    String operator+(String &s)
    {
        String temp;
        temp.len = len + s.len;
        temp.p = new char[temp.len + 1];
        strcpy(temp.p, p);
        strcat(temp.p, s.p);
        return temp;
    }
    int operator<(String &s)
    {
        int m = strlen(p);
        int n = strlen(s.p);
        if (m < n)
            return 1;
        else
            return 0;
    }
    void display()
    {
        cout << p << endl;
    }
};
int main()
{
    char s2[20], s3[20];
    cout << "Enter the strings." << endl;
    cin >> s2 >> s3;
    String str1, str2, str3;
    str2 = String(s2);
    str3 = String(s3);
    str1 = str2 + str3;
    str1.display();
    char s4[20], s5[20];
    cout << "Enter the strings to be compared." << endl;
    cin >> s4 >> s5;
    String str4, str5;
    str4 = String(s4);
    str5 = String(s5);
    if (str4 < str5)
        cout << "First string is smaller." << endl;
    else
        cout << "Second string is smaller." << endl;
}