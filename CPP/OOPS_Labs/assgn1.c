#include <stdio.h>
#include <string.h>
typedef struct
{
    int date, mon, year;
} PublDate;
typedef struct
{
    char title[20], author[20], subj[20];
    int num;
    PublDate Publ;
} Books;
void my_insert(Books b[], int n)
{
    printf("Enter title, author, subject, number of copies and publishing date in DD MM YYYY format of book %d.\n", n + 1);
    scanf("%s%s%s%d%d%d%d", b[n].title, b[n].author, b[n].subj, &b[n].num, &b[n].Publ.date, &b[n].Publ.mon, &b[n].Publ.year);
}
void my_display(Books b[], int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        printf("The details of book %d are:\n", i + 1);
        printf("Title:%s\nAuthor:%s\nSubject:%s\nNumber of copies:%d\nPublishing Date:-%d/%d/%d\n", b[i].title, b[i].author, b[i].subj, b[i].num, b[i].Publ.date, b[i].Publ.mon, b[i].Publ.year);
    }
}
void my_search(Books b[], int n)
{
    char strch[20], input[20];
    int i;
    printf("Do you want to search by title or author?\n");
    scanf("%s", strch);
    printf("Enter the input.\n");
    scanf("%s", input);

    switch (strch[0])
    {
    case 't':
        for (i = 0; i < n; i++)
        {
            if (strcmp(input, b[i].title) == 0)
                printf("BOOK FOUND:\nTitle:%s\nAuthor:%s\nSubject:%s\nNumber of copies:%d\n", b[i].title, b[i].author, b[i].subj, b[i].num);
            else
                printf("BOOK NOT FOUND IN RECORDS.\n");
        }
        break;
    case 'a':
        for (i = 0; i < n; i++)
        {
            if (strcmp(input, b[i].author) == 0)
                printf("BOOK FOUND:\nTitle:%s\nAuthor:%s\nSubject:%s\nNumber of copies:%d\n", b[i].title, b[i].author, b[i].subj, b[i].num);
            else
                printf("BOOK NOT FOUND IN RECORDS.\n");
        }
        break;
    default:
        printf("Erroneous input.\n");
    }
}
void my_delete(Books b[], int n)
{
    char input[20];
    int i, j;
    printf("Enter the title of the book to be deleted.\n");
    scanf("%s", input);

    for (i = 0; i < n; i++)
    {
        if (strcmp(input, b[i].title) == 0)
        {
            for (j = i; j < n - 1; j++)
                b[j] = b[j + 1];
        }
    }
}
int main()
{
    Books Lib[20];
    int choice, i = 0;

    do
    {
        printf("Enter 1 to insert a book record.\nEnter 2 to search for book record.\nEnter 3 for deleting a book record.\nEnter 4 to display all book records.\nEnter number greater or equal to 5 to exit.\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            my_insert(Lib, i++);
            break;

        case 2:
            my_search(Lib, i);
            break;

        case 3:
            my_delete(Lib, i);
            i--;
            break;

        case 4:
            my_display(Lib, i);
            break;
        }
    } while (!(choice >= 5));

    return 0;
}
