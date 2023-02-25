#include <stdio.h>
#include <stdlib.h>
typedef struct node node;
struct node
{
    int info;
    node *link;
};

node *create_list(node *last)
{
    node *temp, *p;
    int n;
    printf("Enter the number of nodes.\n");
    scanf("%d", &n);
    if (n == 0)
        return last;
    printf("Enter the data.\n");
    for (int i = 0; i < n; i++)
    {
        temp = (node *)malloc(sizeof(node));
        scanf("%d", &temp->info);
        temp->link = NULL;
        if (last == NULL)
        {
            last = temp;
            last->link = last;
        }
        else
        {
            temp->link = last->link;
            last->link = temp;
            last = temp;
        }
    }
    return last;
}

void display_list(node *last)
{
    node *p;
    if (last == NULL)
    {
        printf("The circular linked list is empty.\n");
        return;
    }
    p = last->link;
    printf("The elements of the circular linked list are : ");
    do
    {
        printf("%d ", p->info);
        p = p->link;
    } while (p != last->link);
    printf("\n");
}

node *del(node *last, int data)
{
    struct node *tmp, *p;
    if (last->link == last && last->info == data)
    {
        tmp = last;
        last = NULL;
        free(tmp);
        return last;
    }
    if (last->link->info == data)
    {
        tmp = last->link;
        last->link = tmp->link;
        free(tmp);
        return last;
    }
    p = last->link;
    while (p->link != last)
    {
        if (p->link->info == data)
        {
            tmp = p->link;
            p->link = tmp->link;
            free(tmp);
            return last;
        }
        p = p->link;
    }
    if (last->info == data)
    {
        tmp = last;
        p->link = last->link;
        last = p;
        free(tmp);
        return last;
    }
    return last;
}

node *delete_alt_nodes(node *last)
{
    node *p, *q, *temp;
    if (last == NULL)
        return;
    p = q = last->link;
    int count = 0;
    do
    {

        if (count % 2 == 1)
        {
            temp = p;
            p = p->link;
            last = del(last, temp->info);
        }
        else
            p = p->link;
        count++;
    } while (p != q);
    return last;
}

int main()
{
    int ch;
    node *last = NULL;
    while (1)
    {
        printf("Enter 1 to create circular LL and delete alternate nodes.\n");
        printf("Enter 2 to exit.\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            last = create_list(last);
            printf("Circular list before removal:\n");
            display_list(last);
            printf("Circular list after removal.\n");
            last = delete_alt_nodes(last);
            display_list(last);
            break;
        case 2:
            exit(1);
        default:
            printf("Erroneous input.\n");
        }
    }
}