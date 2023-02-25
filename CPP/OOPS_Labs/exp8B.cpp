#include <iostream>
using namespace std;
template <class T>
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
    T *A = new T(n);

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
    void modify(int m)
    {
        T temp;
        if (m > 0)
        {
            cout << "Enter the element to replace the current one." << endl;
            cin >> temp;
            *(A + m - 1) = temp;
        }
    }
};

int main()
{
    vector<int> v1;
    vector<float> v2;
    vector<char> v3;
    int m;
    cout << "Int vector." << endl;
    v1.getsize();
    v1.getelem();
    cout << "Original values." << endl;
    v1.display();
    cout << "Enter value of position which is to be changed(<1 no change)." << endl;
    cin >> m;
    v1.modify(m);
    cout << "Changed values." << endl;
    v1.display();
    cout << "Float vector" << endl;
    v2.getsize();
    v2.getelem();
    cout << "Original values." << endl;
    v2.display();
    cout << "Enter value of position which is to be changed(<1 no change)." << endl;
    cin >> m;
    v2.modify(m);
    cout << "Changed values." << endl;
    v2.display();
    cout << "Char vector" << endl;
    v3.getsize();
    v3.getelem();
    cout << "Original values." << endl;
    v3.display();
    cout << "Enter value of position which is to be changed(<1 no change)." << endl;
    cin >> m;
    v3.modify(m);
    cout << "Changed values." << endl;
    v3.display();
    return 0;
}