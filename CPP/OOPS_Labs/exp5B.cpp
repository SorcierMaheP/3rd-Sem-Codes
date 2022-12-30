#include <iostream>
using namespace std;
class student
{
protected:
    int rollno;

public:
    void get_no(int a)
    {
        rollno = a;
    }
    void put_no()
    {
        cout << "Roll number : " << rollno << endl;
    }
};
class test : virtual public student
{
protected:
    float part1, part2;

public:
    void get_m(float x, float y)
    {
        part1 = x;
        part2 = y;
    }
    void put_m()
    {
        cout << "Marks obtained : " << endl
             << "Part 1 : " << part1 << endl
             << "Part2 : " << part2 << endl;
    }
};
class sports : public virtual student
{
protected:
    float score;

public:
    void get_s(float s)
    {
        score = s;
    }
    void put_s()
    {
        cout << "Sports marks : " << score << endl;
    }
};
class result : public test, public sports
{
    float total;

public:
    void display()
    {
        total = part1 + part2 + score;
        put_no();
        put_m();
        put_s();
        cout << "Total score : " << total << endl;
    }
};
int main()
{
    result s1;
    s1.get_no(211105032);
    s1.get_m(87.5, 91.5);
    s1.get_s(7.0);
    s1.display();
    return 0;
}
