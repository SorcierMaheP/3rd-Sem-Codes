#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
class telephone
{
    char name[20];
    int phone;

public:
    char *ret_name()
    {
        return name;
    }
    int ret_phone()
    {
        return phone;
    }
    void getname(char *str)
    {
        strcpy(name, str);
    }
    void getphone(int num)
    {
        phone = num;
    }
};

void display_phone(char *str, int i, telephone t[])
{
    int flag = 0;
    for (int j = 0; j < i; j++)
    {
        if (strcmp(str, t[j].ret_name()) == 0)
        {
            cout << "Phone number is: " << t[j].ret_phone() << endl;
            flag = 1;
            break;
        }
    }
    if (flag == 0)
        cout << "Record does not exist." << endl;
}

void display_name(int num, int i, telephone t[])
{
    int flag = 0;
    for (int j = 0; j < i; j++)
    {
        if (num == t[j].ret_phone())
        {
            cout << "Name is: " << t[j].ret_name() << endl;
            flag = 1;
            break;
        }
    }
    if (flag == 0)
        cout << "Record does not exist." << endl;
}
void modify_telephone(char *str, int i, telephone t[])
{
    int flag = 0, newnum;
    for (int j = 0; j < i; j++)
    {
        if (strcmp(str, t[j].ret_name()) == 0)
        {
            cout << "Enter the new phone number." << endl;
            cin >> newnum;
            t[j].getphone(newnum);
            fstream f1;
            f1.open("temp.txt", ios::out);
            char str[20];
            int num;
            for (int j = 0; j < i; j++)
            {
                f1 << t[j].ret_name();
                f1.put(' ');
                f1 << t[j].ret_phone();
                f1.put('\n');
            }
            f1.close();
            remove("tel.txt");
            rename("temp.txt", "tel.txt");
            flag = 1;
            break;
        }
    }
    if (flag == 0)
        cout << "Record does not exist." << endl;
}
int main()
{
    int ch, i = 0, tempnum, num;
    char str[20], tempstr[20];
    telephone t[10];
    fstream f;
    f.open("tel.txt", ios::in);
    f >> tempstr;
    while (f.good())
    {
        t[i].getname(tempstr);
        f >> tempnum;
        t[i++].getphone(tempnum);
        f >> tempstr;
    }
    while (1)
    {
        cout << "1.Search a Telephone Record as per name." << endl;
        cout << "2.Search a name as per Telephone Record." << endl;
        cout << "3.Modify a Telephone Record as per name." << endl;
        cout << "4.Exit." << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Enter the name." << endl;
            cin >> str;
            display_phone(str, i, t);
            break;
        case 2:
            cout << "Enter the number." << endl;
            cin >> num;
            display_name(num, i, t);
            break;
        case 3:
            cout << "Enter the name." << endl;
            cin >> str;
            modify_telephone(str, i, t);
            break;
        case 4:
            exit(1);
        default:
            cout << "Erroneous input." << endl;
        }
    }
    return 0;
}