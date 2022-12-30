#include <iostream>
#include <fstream>
using namespace std;
void bubbleSort(int array[], int size)
{
    for (int step = 0; step < size - 1; step++)
    {
        for (int i = 0; i < size - step - 1; i++)
        {
            if (array[i] > array[i + 1])
            {
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
        }
    }
}
int main()
{
    int num;
    char c;
    fstream f1, f2, f3;
    f1.open("file1.txt", ios::out);
    cout << "Enter the elements into the first file." << endl;
    for (int i = 0; i < 5; i++)
    {
        cin >> num;
        f1 << num << " ";
    }
    f1.close();
    f1.open("file1.txt", ios::in);
    f2.open("file2.txt", ios::out);
    cout << "Enter the elements into the second file." << endl;
    for (int i = 0; i < 3; i++)
    {
        cin >> num;
        f2 << num << " ";
    }
    f2.close();
    f2.open("file2.txt", ios::in);
    f3.open("file3.txt", ios::out);
    cout << "Contents of 1st file." << endl;
    while (f1)
    {
        f1 >> num;
        if (f1.eof() == 1)
            continue;
        cout << num << " ";
        f3 << num << " ";
    }
    cout << endl
         << "Contents of 2nd file." << endl;
    while (f2)
    {
        f2 >> num;
        if (f2.eof() == 1)
            continue;
        cout << num << " ";
        f3 << num << " ";
    }
    f1.close();
    f2.close();
    f3.close();
    f3.open("file3.txt", ios::in);
    int a[8], i = 0;
    while (f3)
    {
        f3 >> a[i++];
        if (f3.eof() == 1)
            continue;
    }
    f3.close();
    bubbleSort(a, 8);
    f3.open("file3.txt", ios::out);
    for (int i = 0; i < 8; i++)
    {
        f3 << a[i] << " ";
    }
    f3.close();
    f3.open("file3.txt", ios::in);
    cout << endl
         << "Contents of 3rd file." << endl;
    while (f3)
    {
        f3 >> num;
        if (f3.eof() == 1)
            continue;
        cout << num << " ";
    }
    cout << endl;
    f3.close();
    return 0;
}