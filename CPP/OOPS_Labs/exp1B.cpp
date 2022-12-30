#include <iostream>
#include <cstdlib>
#include <cstring>
#include <ctime>
using namespace std;
class lib
{
private:
    int copies, accno;
    char title[20], author[20], subj[20];
    struct publdate
    {
        int date, mon, year;
    } dop;

public:
    void my_insert(int n)
    {
        cout << "Enter title, author, subject, number of copies and publishing date in DD MM YYYY format of book" << (n) << "\n";
        cin >> title >> author >> subj >> copies >> dop.date >> dop.mon >> dop.year;
        accno = rand();
    }
    void my_display(int n)
    {
        cout << "The details of book " << n + 1 << " are:"
             << "\n";
        cout << "Title:" << title << "\n"
             << "Author:" << author << "\n"
             << "Subject:" << subj << "\n"
             << "Accession Number:" << accno << "\n"
             << "Number of copies:" << copies << "\n"
             << "Publishing Date:-" << dop.date << "/" << dop.mon << "/" << dop.year << "\n";
    }
    void my_search(char strch, char input[], int n)
    {

        switch (strch)
        {
        case 't':
            if (strcmp(input, title) == 0)
            {
                cout << "BOOK FOUND\n";
                my_display(n);
            }
            else
                cout << "BOOK NOT FOUND." << endl;
            break;
        case 'a':
            if (strcmp(input, author) == 0)
            {
                cout << "BOOK FOUND\n";
                my_display(n);
            }
            else
                cout << "BOOK NOT FOUND." << endl;
            ;
        }
    }
};
int main()
{
    int num;
    cout << "Enter the maximum number of books.\n";
    cin >> num;
    lib *books = new lib[num];
    int choice, count = 0;
    srand(time(0));
    while (1)
    {
        cout << "Enter 1 to insert book, 2 to search book either by title or author, 3 to display entire book list, 4 to exit."
             << "\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            if (num == count)
            {
                cout << "Max size reached.\n";
                break;
            }
            books[count++].my_insert(count);
            break;
        case 2:
            char strch[7], input[20];
            cout << "Do you want to search by title or author?"
                 << "\n";
            cin >> strch;
            cout << "Enter the input."
                 << "\n";
            cin >> input;
            for (int i = 0; i < count; i++)
                books[i].my_search(strch[0], input, i);
            break;
        case 3:
            for (int i = 0; i < count; i++)
                books[i].my_display(i);
            break;
        case 4:
            cout << "Exit.\n";
            exit(1);
        default:
            cout << "Wrong input.\n";
        }
    }
}