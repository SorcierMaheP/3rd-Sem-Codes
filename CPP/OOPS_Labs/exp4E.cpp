#include <iostream>
using namespace std;
class vector
{
    int n;

public:
    void getsize()
    {
        cout << "Enter size." << endl;
        cin >> n;
    }

private:
    int *A = new int(n);

public:
    void getelem()
    {
        cout << "Enter the elements of the vector." << endl;
        for (int i = 0; i < n; i++)
            cin >> *(A + i);
    }
    void display()
    {
        for (int i = 0; i < n; i++)
            cout << *(A + i) << " ";
        cout << endl;
    }
    vector operator+(vector &v)
    {
        vector w;
        w.n = n;
        for (int i = 0; i < n; i++)
        {
            w.A[i] = A[i] + v.A[i];
        }
        return w;
    }
    friend vector operator*(int &, vector &);
};
vector operator*(int &m, vector &v)
{
    vector w;
    w.n = v.n;
    for (int i = 0; i < v.n; i++)
    {
        w.A[i] = m * v.A[i];
    }
    return w;
}

int main()
{
    vector v1, v2;
    int m;
    v1.getsize();
    v1.getelem();
    cout << "Original values." << endl;
    v1.display();
    cout << "Enter value of m." << endl;
    cin >> m;
    v2 = m * v1;
    cout << "Changed values." << endl;
    v2.display();
    vector v3, v4, v5;
    cout << "Enter the vectors for addition.Size should be same." << endl;
    v3.getsize();
    v3.getelem();
    cout << "Original values." << endl;
    v3.display();
    v4.getsize();
    v4.getelem();
    cout << "Original values." << endl;
    v4.display();
    v5 = v3 + v4;
    cout << "Added vector." << endl;
    v5.display();
    return 0;
}