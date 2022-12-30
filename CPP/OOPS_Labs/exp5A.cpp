#include <iostream>
using namespace std;
class Students
{
protected:
    char name[20];
    int rollno;

public:
    void getdata()
    {
        cout << "Enter name and roll number of student." << endl;
        cin >> name >> rollno;
    }
    void display()
    {
        cout << "Name: " << name << endl
             << "Roll Number: " << rollno << endl;
    }
};
class Arts : public Students
{
protected:
    int history_marks;
    int geography_marks;

public:
    void getdata()
    {
        cout << "Enter the history and geography marks." << endl;
        cin >> history_marks >> geography_marks;
    }
    void display()
    {
        cout << "History marks: " << history_marks << endl
             << "Geography Marks: " << geography_marks << endl;
    }
};
class Medical : public Students
{
protected:
    int anatomy_marks;
    int pathology_marks;

public:
    void getdata()
    {
        cout << "Enter the anatomy and pathology marks." << endl;
        cin >> anatomy_marks >> pathology_marks;
    }
    void display()
    {
        cout << "Anatomy marks: " << anatomy_marks << endl
             << "Pathology marks: " << pathology_marks << endl;
    }
};
class Engineering : public Students
{
protected:
    int maths_marks;

public:
    void getdata()
    {
        cout << "Enter the maths marks." << endl;
        cin >> maths_marks;
    }
    void display()
    {
        cout << "Maths marks: " << maths_marks << endl;
    }
};
class Mech : public Engineering
{
protected:
    int thermo_marks;

public:
    void getdata()
    {
        cout << "Enter the thermodynamic marks." << endl;
        cin >> thermo_marks;
    }
    void display()
    {
        cout << "Thermodynamics marks: " << thermo_marks << endl;
    }
};
class Elec : public Engineering
{
protected:
    int machines_marks;

public:
    void getdata()
    {
        cout << "Enter the machines marks." << endl;
        cin >> machines_marks;
    }
    void display()
    {
        cout << "Machines marks: " << machines_marks << endl;
    }
};
class Civil : public Engineering
{
protected:
    int geology_marks;

public:
    void getdata()
    {
        cout << "Enter the geology marks." << endl;
        cin >> geology_marks;
    }
    void display()
    {
        cout << "Geology marks: " << geology_marks << endl;
    }
};
int main()
{
    Arts s1;
    s1.Students::getdata();
    s1.getdata();
    s1.Students::display();
    s1.display();
    Medical s2;
    s2.Students::getdata();
    s2.getdata();
    s2.Students::display();
    s2.display();
    Mech s3;
    s3.Students::getdata();
    s3.Engineering::getdata();
    s3.getdata();
    s3.Students::display();
    s3.Engineering::display();
    s3.display();
    Elec s4;
    s4.Students::getdata();
    s4.Engineering::getdata();
    s4.getdata();
    s4.Students::display();
    s4.Engineering::display();
    s4.display();
    Civil s5;
    s5.Students::getdata();
    s5.Engineering::getdata();
    s5.getdata();
    s5.Students::display();
    s5.Engineering::display();
    s5.display();
    return 0;
}