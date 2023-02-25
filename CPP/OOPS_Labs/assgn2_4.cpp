#include <iostream>
using namespace std;
class counting
{
    int count[6];

public:
    counting()
    {
        for (int i = 0; i < 6; i++)
            count[i] = 0;
    }
    void vote(int n)
    {
        count[n]++;
    }
    void display()
    {
        for (int i = 0; i < 5; i++)
            cout << "Candidate " << i + 1 << " : " << count[i] << " votes." << endl;
        cout << "Spoilt ballots: " << count[5] << endl;
    }
};
int main()
{
    counting c;
    int ch;
    cout << "Enter votes of candidates from 1 to 5." << endl;
    cout << "Enter 0 to exit and display result." << endl;
    cout << "Other entries will be counted as spoiled." << endl;
    while (1)
    {
        cin >> ch;
        if (ch >= 1 && ch <= 5)
            c.vote(ch - 1);
        else if (ch != 0)
            c.vote(5);
        else
        {
            c.display();
            break;
        }
    }
}