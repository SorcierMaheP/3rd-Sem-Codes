#include <stdio.h>
#include <stdlib.h>

typedef struct node node;

struct node
{
    int info;
    node *next;
};

node *create(node *start, int setno)
{
    node *temp, *p;
    int num = 0;
    printf("Set %d:\n", setno);
    printf("Enter the number of elements.\n");
    scanf("%d", &num);
    printf("Enter the elements.\n");
    for (int i = 0; i < num; i++)
    {
        temp = (node *)malloc(sizeof(node));
        scanf("%d", &temp->info);
        temp->next = NULL;
        if (start == NULL)
            start = temp;
        else
        {
            p = start;
            while (p->next != NULL)
                p = p->next;
            p->next = temp;
        }
    }
    return start;
}

int search(struct node *s, int num)
{
    while (s != NULL)
    {
        if (s->info == num)
        {
            return 1;
        }
        s = s->next;
    }
    return 0;
}

void display(node *start, int setno)
{
    node *p;
    p = start;
    printf("The elements of set %d are : ", setno);
    while (p != NULL)
    {
        printf("%d ", p->info);
        p = p->next;
    }
    printf("\n");
}

node *setunion(node *s1, node *s2)
{
    node *s3 = NULL;
    node *p = s1;
    node *temp;
    while (s1 != NULL)
    {
        temp = (node *)malloc(sizeof(node));
        temp->info = s1->info;
        temp->next = NULL;
        if (s3 == NULL)
            s3 = temp;
        else
        {
            node *q = s3;
            while (q->next != NULL)
                q = q->next;
            q->next = temp;
        }
        s1 = s1->next;
    }
    while (s2 != NULL)
    {
        if (!search(p, s2->info))
        {
            temp = (node *)malloc(sizeof(node));
            temp->info = s2->info;
            temp->next = NULL;
            node *r = s3;
            while (r->next != NULL)
                r = r->next;
            r->next = temp;
        }
        s2 = s2->next;
    }
    return s3;
}

node *setintersect(node *s1, node *s2)
{
    node *s3 = NULL, *p, *q, *temp;
    p = s1;
    while (p != NULL)
    {
        q = s2;
        while (q != NULL)
        {
            temp = (node *)malloc(sizeof(node));
            if (p->info == q->info)
            {
                temp->info = q->info;
                temp->next = NULL;
                if (s3 == NULL)
                    s3 = temp;
                else
                {
                    node *r = s3;
                    while (r->next != NULL)
                        r = r->next;
                    r->next = temp;
                }
            }
            q = q->next;
        }
        p = p->next;
    }
    return s3;
}

node *delnode(node *start, int data)
{

    node *tmp, *p;
    if (start == NULL)
    {
        printf("List is empty\n");
        return start;
    }
    if (start->info == data)
    {
        tmp = start;
        start = start->next;
        free(tmp);
        return start;
    }
    p = start;
    while (p->next != NULL)
    {
        if (p->next->info == data)
        {
            tmp = p->next;
            p->next = tmp->next;
            free(tmp);
            return start;
        }
        p = p->next;
    }
    printf("Element not found.\n");
    return start;
}

node *setdifference(node *s1, node *s2)
{
    node *s3 = NULL, *temp;
    while (s1 != NULL)
    {
        temp = (node *)malloc(sizeof(node));
        temp->info = s1->info;
        temp->next = NULL;
        if (s3 == NULL)
            s3 = temp;
        else
        {
            node *q = s3;
            while (q->next != NULL)
                q = q->next;
            q->next = temp;
        }
        s1 = s1->next;
    }
    while (s2 != NULL)
    {
        if (search(s3, s2->info))
        {
            delnode(s3, s2->info);
        }
        s2 = s2->next;
    }
    return s3;
}

int main()
{
    node *set1 = NULL, *set2 = NULL;
    int ch;
    while (1)
    {
        printf("Enter 1 to enter elements of set 1 and 2.\n");
        printf("Enter 2 to display elements of set 1 and 2.\n");
        printf("Enter 3 for performing set union.\n");
        printf("Enter 4 for performing set intersection.\n");
        printf("Enter 5 for performing set difference.\n");
        printf("Enter 6 to exit.\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            set1 = NULL;
            set2 = NULL;
            set1 = create(set1, 1);
            set2 = create(set2, 2);
            break;
        case 2:
            display(set1, 1);
            display(set2, 2);
            break;
        case 3:
            display(setunion(set1, set2), 3);
            break;
        case 4:
            display(setintersect(set1, set2), 3);
            break;
        case 5:
            display(setdifference(set1, set2), 3);
            break;
        case 6:
            exit(1);
        default:
            printf("Invalid input.\n");
        }
    }
}