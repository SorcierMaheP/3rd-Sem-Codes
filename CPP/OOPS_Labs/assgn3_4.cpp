#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
int main()
{
    char arr[1000], c;
    int i = 0;
    fstream f1;
    f1.open("input.txt", ios::in);
    f1.get(c);
    while (f1.good())
    {
        arr[i++] = c;
        f1.get(c);
    }
    arr[i] = '\0';
    cout << "Contents of the file are:\n"
         << arr << endl;
    f1.close();
    f1.open("output.txt", ios::out);
    for (int j = 0; j < i; j++)
    {
        c = arr[j];
        if (c == ' ')
        {
            while (arr[j + 1] == ' ' && j < i)
                j++;
        }
        f1.put(c);
    }
    f1.close();
    f1.open("output.txt");
    cout << "The resultant file is:\n";
    f1.get(c);
    while (f1.good())
    {
        cout << c;
        f1.get(c);
    }
    f1.close();
    cout << endl;
    return 0;
}