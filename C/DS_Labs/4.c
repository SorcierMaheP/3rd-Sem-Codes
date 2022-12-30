#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX 10000
char s1[MAX], s2[MAX];
int top = -1, nums = 0;
void push(char[], char);
char pop(char[]);
int isFull();
void parentheses(char[]);
void dec_to_base(int, int);
void palicheck(char[]);
void rev_string(char[]);
int isEmpty();
int main()
{

    int choice, num, base;
    char c;
    while (1)
    {
        memset(s1, '\0', MAX);
        memset(s2, '\0', MAX);
        top = -1;
        printf("Enter 1 for parentheses checking.\n");
        printf("Enter 2 for reversal of string.\n");
        printf("Enter 3 for palindrome checking.\n");
        printf("Enter 4 for decimal to base conversion.\n");
        printf("Enter 5 to exit.\n");
        scanf("%d", &choice);
        getchar();
        if (choice >= 1 && choice < 6)
        {
            if (choice == 1 || choice == 2 || choice == 3)
            {
                printf("Enter the string.\n");
                while ((c = getchar()) != 10)
                    push(s1, c);
            }
            else if (choice == 4)
            {
                printf("Enter the decimal number and the base to be converted.\n");
                scanf("%d%d", &num, &base);
            }
        }
        switch (choice)
        {
        case 1:
            parentheses(s1);
            break;
        case 2:
            rev_string(s1);
            break;
        case 3:
            palicheck(s1);
            break;
        case 4:
            dec_to_base(num, base);
            printf("The converted equivalent is : ");
            for (int i = 0; i < nums; i++)
                printf("%c", pop(s1));
            printf("\n");
            break;
        case 5:
            exit(1);
        default:
            printf("Invalid input.\n");
        }
    }
    return 0;
}
int isFull()
{
    if (top == MAX - 1)
        return 1;
    else
        return 0;
}
int isEmpty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}
void push(char a[], char item)
{
    if (isFull())
    {
        printf("Stack Overflow\n");
        exit(1);
    }
    a[++top] = item;
}
char pop(char a[])
{
    char item;
    if (isEmpty())
    {
        printf("Stack Underflow.\n");
        exit(1);
    }
    else if (top > -1)
    {
        return a[top--];
    }
}
void parentheses(char a[])
{
    char ch;
    int flag = 0, brack_count = 0;
    for (int i = 0; a[i] != '\0'; i++)
    {
        ch = a[i];
        switch (ch)
        {
        case '(':
        case '[':
        case '{':
            push(s1, ch);
            break;
        case ')':
            if ('(' == pop(s1))
                brack_count++;
            else
                flag = 1;
            break;
        case ']':
            if ('[' == pop(s1))
                brack_count++;
            else
                flag = 1;
            break;
        case '}':
            if ('{' == pop(s1))
                brack_count++;
            else
                flag = 1;
            break;
        }
    }
    if (flag == 0)
        printf("%d pairs of parentheses matched.\n", brack_count);
    else if (flag == 1)
        printf("There was parentheses mismatch.\n");
}
void dec_to_base(int n, int base)
{
    if (n > 0)
    {
        int m = n % base;
        if (m <= 9)
            push(s1, m + 48);
        else
            push(s1, m - 10 + 'A');
        nums++;
        dec_to_base(n / base, base);
    }
}
void rev_string(char a[])
{
    int k;
    s1[top + 1] = '\0';
    for (k = 0; k < strlen(a); k++)
        s2[k] = pop(a);
    s2[k] = '\0';
    printf("The reversed string is : ");
    puts(s2);
}
void palicheck(char a[])
{
    int flag = 0, k;
    s1[top + 1] = '\0';
    for (k = 0; k < strlen(a); k++)
        s2[k] = pop(a);
    s2[k] = '\0';
    for (int i = 0; s1[i] != '\0'; i++)
    {
        if (a[i] != s2[i])
        {
            flag = 1;
            break;
        }
    }
    if (flag == 0)
        printf("The string is a palindrome.\n");
    else
        printf("The string is not a palindrome.\n");
}
