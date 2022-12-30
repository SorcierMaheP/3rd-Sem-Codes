#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
class telephone
{
    char name[20];
    int phone;

public:
    void getname()
    {
        cout << "Enter Name: " << endl;
        getchar();
        cin.getline(name, 20);
    }
    void getphone()
    {
        cout << "Enter Phone Number: " << endl;
        cin >> phone;
    }
    void show()
    {
        cout << "Name: " << name << endl;
        cout << "Phone Number: " << phone << endl;
    }
    char *ret_name()
    {
        return name;
    }
};
void add_telephone()
{
    telephone t1;
    fstream f1;
    f1.open("telephone.txt", ios::binary | ios::app);
    t1.getname();
    t1.getphone();
    f1.write((char *)&t1, sizeof(t1));
    f1.close();
    cout << "Telephone Directory Has Been Created" << endl;
    cin.get();
}
void display_records()
{
    telephone t1;
    fstream f1;
    f1.open("telephone.txt", ios::binary | ios::in);
    if (!f1.good())
    {
        cout << "File couldn't be opened." << endl;
        cin.get();
        return;
    }
    cout << "The records are: " << endl;
    while (f1.read((char *)&t1, sizeof(t1)))
    {
        t1.show();
        cout << endl;
    }
    f1.close();
}
void display_phone(char *str)
{
    telephone t1;
    fstream f1;
    f1.open("telephone.txt", ios::binary | ios::in);
    if (!f1.good())
    {
        cout << "File couldn't be opened." << endl;
        cin.get();
        return;
    }
    int flag = 0;
    while (f1.read((char *)&t1, sizeof(t1)))
    {
        if (strcmp(t1.ret_name(), str) == 0)
        {
            t1.show();
            flag = 1;
        }
    }
    f1.close();
    if (flag == 0)
        cout << "Record does not exist." << endl;
}

void delete_telephone(char *str)
{
    telephone t1;
    fstream f1;
    f1.open("telephone.txt", ios::binary | ios::in | ios::out);
    if (!f1.good())
    {
        cout << "File couldn't be opened." << endl;
        cin.get();
        return;
    }
    fstream f2;
    f2.open("temp.txt", ios::out);
    f1.seekg(0, ios::beg);
    while (f1.read((char *)&t1, sizeof(t1)))
    {
        if (strcmp(t1.ret_name(), str) != 0)
        {
            f2.write((char *)&t1, sizeof(t1));
        }
    }
    f1.close();
    f2.close();
    remove("telephone.txt");
    rename("temp.txt", "telephone.txt");
    cout << "Record successfully deleted." << endl;
}
void modify_telephone(char *str)
{
    int flag = 0;
    telephone t1;
    fstream f1;
    f1.open("telephone.txt", ios::binary | ios::in | ios::out);
    if (!f1.good())
    {
        cout << "File couldn't be opened." << endl;
        cin.get();
        return;
    }
    while (!f1.eof() && flag == 0)
    {

        f1.read((char *)&t1, sizeof(t1));
        if (strcmp(t1.ret_name(), str) == 0)
        {
            t1.show();
            cout << "Enter The New Details." << endl;
            t1.getphone();
            int pos = (-1) * (int)(sizeof(t1));
            f1.seekp(pos, ios::cur);
            f1.write((char *)&t1, sizeof(t1));
            cout << "Successfully updated." << endl;
            flag = 1;
        }
    }
    f1.close();
    if (flag == 0)
        cout << "Record does not exist." << endl;
}
int main()
{
    int ch;
    char str[20];
    while (1)
    {
        cout << "1.Add Telephone Records." << endl;
        cout << "2.Show Telephone Records." << endl;
        cout << "3.Search a Telephone Record as per name." << endl;
        cout << "4.Modify a Telephone Record as per name." << endl;
        cout << "5.Delete a Telephone Record as per name." << endl;
        cout << "6.Exit." << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            add_telephone();
            break;
        case 2:
            display_records();
            break;
        case 3:
            cout << "Enter the name." << endl;
            cin >> str;
            display_phone(str);
            break;
        case 4:
            cout << "Enter the name." << endl;
            cin >> str;
            modify_telephone(str);
            break;
        case 5:
            cout << "Enter the name." << endl;
            cin >> str;
            delete_telephone(str);
            break;
        case 6:
            exit(1);
        default:
            cout << "Erroneous input." << endl;
        }
    }
    return 0;
}