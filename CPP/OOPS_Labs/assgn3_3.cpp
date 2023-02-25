#include <iostream>
#include <cstring>
using namespace std;
class str
{
    char *s;
    int len;

public:
    str()
    {
        len = 0;
        s = new char[len + 1];
        strcpy(s, "");
    }
    str(char *str)
    {
        len = strlen(str);
        s = new char[len + 1];
        s = strcpy(s, str);
    }
    friend str operator+(str &, str &);
    void operator=(str);
    void display()
    {
        cout << s << endl;
    }
    ~str()
    {
        cout << "Destructor called." << endl;
    }
};
str operator+(str &n, str &m)
{
    str temp;
    temp.len = strlen(n.s) + strlen(m.s);
    temp.s = new char[temp.len + 1];
    strcpy(temp.s, n.s);
    strcat(temp.s, m.s);
    return temp;
}
void str::operator=(str strn)
{
    strcpy(s, strn.s);
}
int main()
{
    str s1("Sorcier ");
    str s2("MaheP");
    str s3;
    s3 = s1 + s2;
    cout << "FIRST STRING : ";
    s1.display();
    cout << "SECOND STRING : ";
    s2.display();
    cout << "COMBINED STRING : ";
    s3.display();
    return 0;
}