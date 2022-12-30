#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
class student
{
    char name[20];
    int rollno;
    char address[30];
    char branch[10];

public:
    void getroll()
    {
        cout << "Enter roll number." << endl;
        cin >> rollno;
    }
    void getdetails()
    {
        cout << "Enter name." << endl;
        getchar();
        cin.getline(name, 20);
        cout << "Enter address." << endl;
        cin.getline(address, 30);
        cout << "Enter branch." << endl;
        cin.getline(branch, 10);
    }
    void show()
    {
        cout << "Name: " << name << endl;
        cout << "Address: " << address << endl;
        cout << "Roll number: " << rollno << endl;
        cout << "Branch: " << branch << endl;
    }
    int rollret()
    {
        return rollno;
    }
    char *retname()
    {
        return name;
    }
};
void addstudent(student s[], int n)
{
    fstream f1;
    char *s2, temp[20];
    s[n].getroll();
    s[n].getdetails();
    strcpy(temp, s[n].retname());
    s2 = strcat(temp, ".txt");
    f1.open(s2, ios::binary | ios::app);
    f1.write((char *)&s[n], sizeof(s[n]));
    f1.close();
    cout << "Student Database Has Been Created." << endl;
    cin.get();
}
void display_records(char *str)
{
    fstream f1;
    student s1;
    char *s2, temp[20];
    strcpy(temp, str);
    s2 = strcat(temp, ".txt");
    f1.open(s2, ios::binary | ios::in);
    if (!f1.good())
    {
        cout << "File couldn't be opened." << endl;
        cin.get();
        return;
    }
    cout << "The records are: " << endl;
    while (f1.read((char *)&s1, sizeof(s1)))
    {
        s1.show();
        cout << endl;
    }
    f1.close();
}
int search_roll(char *str, int roll)
{
    student s1;
    fstream f1;
    char *s2, temp[20];
    strcpy(temp, str);
    s2 = strcat(temp, ".txt");
    f1.open(s2, ios::binary | ios::in);
    if (!f1.good())
    {
        cout << "File couldn't be opened." << endl;
        cin.get();
        return -1;
    }
    while (f1.read((char *)&s1, sizeof(s1)))
    {
        if (s1.rollret() == roll)
        {
            s1.show();
            return 1;
        }
    }
    f1.close();
    return 0;
}
void delete_details(char *str, int roll)
{
    student s1;
    fstream f1;
    char *s2, temp[20];
    strcpy(temp, str);
    s2 = strcat(temp, ".txt");
    f1.open(s2, ios::binary | ios::in);
    if (!f1.good())
    {
        cout << "File couldn't be opened." << endl;
        cin.get();
        return;
    }
    fstream f2;
    f2.open("temp.txt", ios::binary | ios::out);
    f1.seekg(0, ios::beg);
    while (f1.read((char *)&s1, sizeof(s1)))
    {
        if (s1.rollret() != roll)
        {
            f2.write((char *)&s1, sizeof(s1));
        }
    }
    f1.close();
    f2.close();
    remove(s2);
    rename("temp.txt", s2);
    f1.open(s2, ios::binary | ios::in);
    f1.seekg(0, ios::end);
    int file_size = f1.tellg();
    if (file_size == 0)
        remove(s2);
    cout << "Record successfully deleted." << endl;
}
int modify_details(char *str, int roll)
{
    student s1;
    fstream f1;
    char *s2, temp[20];
    strcpy(temp, str);
    s2 = strcat(temp, ".txt");
    f1.open(s2, ios::binary | ios::in | ios::out);
    if (!f1.good())
    {
        cout << "File couldn't be opened." << endl;
        cin.get();
        return -1;
    }
    while (f1.read((char *)&s1, sizeof(s1)))
    {
        if (s1.rollret() == roll)
        {
            s1.show();
            cout << "Enter The New Details." << endl;
            s1.getdetails();
            int pos = (-1) * (int)(sizeof(s1));
            f1.seekp(pos, ios::cur);
            f1.write((char *)&s1, sizeof(s1));
            cout << "Successfully updated." << endl;
            return 1;
        }
    }
    f1.close();
    return 0;
}
int main()
{
    int ch, roll, i = 0, check, flag = 0;
    student s[10];
    while (1)
    {
        flag = 0;
        cout << "1.Add details." << endl;
        cout << "2.Display details." << endl;
        cout << "3.Search for student using roll number." << endl;
        cout << "4.Update student details using roll number." << endl;
        cout << "5.Delete student details using roll number." << endl;
        cout << "6.Exit." << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            addstudent(s, i++);
            break;
        case 2:
            cout << "The details are: " << endl;
            for (int j = 0; j < i; j++)
                display_records(s[j].retname());
            break;
        case 3:
            cout << "Enter roll number." << endl;
            cin >> roll;
            for (int j = 0; j < i; j++)
                check = search_roll(s[j].retname(), roll);
            if (!check)
                cout << "Records do not exist." << endl;
            break;
        case 4:
            cout << "Enter roll number." << endl;
            cin >> roll;
            for (int j = 0; j < i; j++)
                check = modify_details(s[j].retname(), roll);
            if (!check)
                cout << "Records do not exist." << endl;
            break;
        case 5:
            cout << "Enter roll number." << endl;
            cin >> roll;
            for (int j = 0; j < i; j++)
            {
                if (s[j].rollret() == roll)
                {
                    flag = 1;
                    for (int k = j; k < i - 1; k++)
                    {
                        s[k] = s[k + 1];
                    }
                    delete_details(s[j].retname(), roll);
                }
            }
            if (flag)
                i--;
            else
                cout << "Records do not exist." << endl;
            break;
        case 6:
            exit(1);
        default:
            cout << "Erroneous input." << endl;
        }
    }
}