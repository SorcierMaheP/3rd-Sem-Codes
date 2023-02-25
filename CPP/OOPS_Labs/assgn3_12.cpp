#include <iostream>
#include <list>
using namespace std;
int main()
{
    list<int> L1;
    L1.push_front(1); // Put in front
    L1.push_front(2);
    L1.push_back(3);
    L1.push_back(4); // Put in back
    cout << "Original list: ";
    for (int x : L1)
    {
        cout << x << " ";
    }
    cout << endl;
    list<int> L2;
    list<int>::iterator it;
    it = L1.begin();
    advance(it, 2);
    L2.push_back(5);
    L2.push_back(6);
    L2.push_back(7);
    L1.splice(it, L2); // Add L2 elems to any position of L1 list
    cout << "After splice: ";
    for (int x : L1)
    {
        cout << x << " ";
    }
    cout << endl;
    L1.sort(); // Sort L1 list
    cout << "After sort: ";
    for (int x : L1)
    {
        cout << x << " ";
    }
    cout << endl;
    list<int> L3;
    L3.push_back(8);
    L3.push_back(9);
    L3.push_back(10);
    L1.merge(L3); // Merge sorted lists
    cout << "After merge: ";
    for (int x : L1)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}