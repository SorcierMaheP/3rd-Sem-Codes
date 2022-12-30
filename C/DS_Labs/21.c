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

node *addtoempty(node *last, int data)
{
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info = data;
    last = tmp;
    last->link = last;
    return last;
}

node *addatbeg(node *last, int data)
{
    node *tmp;
    tmp = (node *)malloc(sizeof(node));
    tmp->info = data;
    tmp->link = last->link;
    last->link = tmp;
    return last;
}
node *addatend(node *last, int data)
{
    node *tmp;
    tmp = (node *)malloc(sizeof(node));
    tmp->info = data;
    tmp->link = last->link;
    last->link = tmp;
    last = tmp;
    return last;
}

void listsplit(node *last, node **last1, node **last2)
{
    node *temp = last->link;
    int count = 0;
    do
    {
        if (count % 2 == 0 && count == 0)
            *last1 = addtoempty(*last1, temp->info);
        else if (count % 2 == 0)
            *last1 = addatend(*last1, temp->info);
        else if (count % 2 == 1 && count == 1)
            *last2 = addtoempty(*last2, temp->info);
        else if (count % 2 == 1)
            *last2 = addatend(*last2, temp->info);
        temp = temp->link;
        count++;
    } while (temp != last->link);
}

int main()
{
    int ch, elem;
    struct node *last = NULL, *last1 = NULL, *last2 = NULL;
    while (1)
    {
        printf("\n1.Create list.\n");
        printf("2.Add at beginning.\n");
        printf("3.Add at end.\n");
        printf("4.Display.\n");
        printf("5.Delete.\n");
        printf("6.Split.\n");
        printf("7.Exit.\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            last = create_list(last);
            break;
        case 2:
            printf("Enter the element to be added.\n");
            scanf("%d", &elem);
            last = addatbeg(last, elem);
            break;
        case 3:
            printf("Enter the element to be added.\n");
            scanf("%d", &elem);
            last = addatend(last, elem);
            break;
        case 4:
            display_list(last);
            break;
        case 5:
            printf("Enter the element to be added.\n");
            scanf("%d", &elem);
            last = del(last, elem);
            break;
        case 6:
            listsplit(last, &last1, &last2);
            printf("\nEven list is:\n");
            display_list(last1);
            printf("\nOdd list is:\n");
            display_list(last2);
            break;
        case 7:
            exit(1);
        default:
            printf("Erroneous input.\n");
        }
    }
    return 0;
}
