# include <iostream>
using namespace std;
class Integer
{
    int m,n;
    public:
    Integer(int a=0,int b=0)
    {
        m=a;
        n=b;
    }
    void display()
    {
        cout<<"The values of m and n are "<<m<<" and "<<n<<"."<<endl;
    }
    friend void operator-(Integer&);
};

void operator-(Integer &I)
{
    I.m=-I.m;
    I.n=-I.n;
}

int main()
{
    Integer I1(5,10);
    I1.display();
    operator-(I1);
    I1.display();
    return 0;
}
