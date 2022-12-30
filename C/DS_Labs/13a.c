#include <stdio.h>
#include <stdlib.h>
typedef struct node node;

struct node
{
    node *prev;
    int data;
    node *next;
};

int dig(int n)
{
    int count = 0;
    while (n)
    {
        count++;
        n /= 10;
    }
    return count;
}

node *create_linked_list(node *start)
{
    node *temp, *p;
    int n;
    printf("Enter the number of nodes.\n");
    scanf("%d", &n);
    start = NULL;
    if (n == 0)
        return start;
    for (int i = 0; i < n; i++)
    {
        temp = (node *)malloc(sizeof(node));
        printf("\nEnter the data for node %d: ", i + 1);
        scanf("%d", &temp->data);
        temp->next = NULL;
        if (start == NULL)
        {
            temp->prev = NULL;
            start = temp;
        }
        else
        {
            p = start;
            while (p->next != NULL)
                p = p->next;
            temp->prev = p;
            p->next = temp;
        }
    }
    return start;
}

void display_num(node *start)
{
    node *p;
    if (start == NULL)
    {
        printf("Linked list is empty\n");
        return;
    }
    p = start;
    while (p->next != NULL)
        p = p->next;
    printf("The number is: ");
    while(p!=NULL)
    {
        printf("%d", p->data);
        p = p->prev;
    }
    printf("\n");
}

void display_linked_list(node *start)
{
    node *p;
    if (start == NULL)
    {
        printf("Linked list is empty\n");
        return;
    }
    p = start;
    printf("Linked list is: \n");
    while (p->next != NULL)
    {
        printf("%d->", p->data);
        p = p->next;
    }
    printf("%d\n", p->data);
}

node *swap(node *start)
{
    node *p, *q, *r;
    int count = 0;
    p = start;
    q = start->next;
    while (q != NULL)
    {
        r = p->prev;
        p->prev = p->next;
        p->next = q->next;
        q->next = q->prev;
        q->prev = r;
        if (count == 0)
            start = q;
        if (p->next != NULL)
            p->next->prev = p;
        if (q->prev != NULL)
            q->prev->next = q;
        p = p->next;
        if (p != NULL)
            q = p->next;
        else
            q = NULL;
        count++;
    }
    return start;
}

node *create_num_ll(node *start, int num, int digmax)
{
    node *temp, *p;
    start = NULL;
    if (digmax == 0)
        return start;
    for (int i = 0; i < digmax; i++)
    {
        temp = (node *)malloc(sizeof(node));
        temp->data = num % 10;
        temp->next = NULL;
        if (start == NULL)
        {
            temp->prev = NULL;
            start = temp;
        }
        else
        {
            p = start;
            while (p->next != NULL)
                p = p->next;
            temp->prev = p;
            p->next = temp;
        }
        num /= 10;
    }
    return start;
}

node *add_ll(node *start1, node *start2, node *start3)
{
    node *p = start1, *q = start2, *temp, *r;
    int carry = 0, sum, p_dig, q_dig;
    while (p != NULL && q != NULL)
    {
        temp = (node *)malloc(sizeof(node));
        if (p == NULL)
            p_dig = 0;
        else
            p_dig = p->data;
        if (q == NULL)
            q_dig = 0;
        else
            q_dig = q->data;
        sum = carry + p_dig + q_dig;
        if (sum >= 10)
        {
            carry = 1;
            sum -= 10;
        }
        else
            carry = 0;
        temp->data = sum;
        temp->next = NULL;
        if (start3 == NULL)
        {
            temp->prev = NULL;
            start3 = temp;
        }
        else
        {
            r = start3;
            while (r->next != NULL)
                r = r->next;
            temp->prev = r;
            r->next = temp;
        }
        p = p->next;
        q = q->next;
    }
    if (carry == 1)
    {
        r = start3;
        while (r->next != NULL)
            r = r->next;
        temp = (node *)malloc(sizeof(node));
        temp->data = 1;
        temp->next = NULL;
        temp->prev = r;
        r->next = temp;
    }
    return start3;
}
int main()
{
    int ch, num1, num2, digmax;
    node *start1 = NULL, *start2 = NULL, *start3 = NULL;
    while (1)
    {
        printf("Enter 1 to swap elements of doubly linked list.\n");
        printf("Enter 2 to create two DLL in which info info part contains digit of a given number.Also addition is performed on them.\n");
        printf("Enter 3 to exit.\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            start1 = create_linked_list(start1);
            printf("Before swapping:\n");
            display_linked_list(start1);
            start1 = swap(start1);
            printf("After swapping:\n");
            display_linked_list(start1);
            break;
        case 2:
            printf("Enter the numbers 1 and 2.\n");
            scanf("%d%d", &num1, &num2);
            if (dig(num1) > dig(num2))
                digmax = dig(num1);
            else
                digmax = dig(num2);
            start1 = create_num_ll(start1, num1, digmax);
            printf("Number 1 is:\n");
            display_linked_list(start1);
            start2 = create_num_ll(start2, num2, digmax);
            printf("Number 2 is:\n");
            display_linked_list(start2);
            start3 = add_ll(start1, start2, start3);
            printf("The added number is:\n");
            display_linked_list(start3);
            display_num(start3);
            break;
        case 3:
            exit(1);
        default:
            printf("Erroneous input.\n");
        }
    }
}
