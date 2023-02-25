#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node node;

struct node
{
    int coef;
    int deg;
    node *link;
};

void remdupl(node *start)
{
    node *p, *q, *temp;
    p = start;
    while (p != NULL && p->link != NULL)
    {
        q = p;
        while (q->link != NULL)
        {
            if (p->deg == q->link->deg)
            {
                p->coef = p->coef + q->link->coef;
                temp = q->link;
                q->link = q->link->link;
                free(temp);
            }
            else
                q = q->link;
        }
        p = p->link;
    }
}

node *create(node *start, int polyno)
{
    node *temp, *p;
    int n;
    printf("Enter the terms of the polynomial in descending powers.\n");
    printf("Enter the number of terms of the polynomial %d: ", polyno);
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        temp = (node *)malloc(sizeof(node));
        printf("Enter the coefficient: ");
        scanf("%d", &temp->coef);
        printf("Enter the power: ");
        scanf("%d", &temp->deg);
        temp->link = NULL;
        if (start == NULL)
            start = temp;
        else
        {
            p = start;
            while (p->link != NULL)
                p = p->link;
            p->link = temp;
        }
    }
    remdupl(start);
    return start;
}

node *create_from_file(node *start, FILE *fp)
{
    node *temp, *p;
    int n;
    fscanf(fp, "%d ", &n);
    for (int i = 0; i < n; i++)
    {
        temp = (node *)malloc(sizeof(node));
        fscanf(fp, "%d %d ", &temp->coef, &temp->deg);
        temp->link = NULL;
        if (start == NULL)
            start = temp;
        else
        {
            p = start;
            while (p->link != NULL)
                p = p->link;
            p->link = temp;
        }
    }
    return start;
}

void display(node *start)
{
    node *p;
    p = start;
    while (p != NULL)
    {
        printf("%dx^%d", p->coef, p->deg);
        p = p->link;
        if (p != NULL)
            printf(" + ");
    }
    printf("\n");
}

node *add(node *start1, node *start2)
{
    node *start3, *p, *q, *temp;
    start3 = NULL;
    p = start1;
    q = start2;
    while (p != NULL && q != NULL)
    {
        temp = (node *)malloc(sizeof(node));
        temp->link = NULL;
        if (p->deg > q->deg)
        {
            temp->deg = p->deg;
            temp->coef = p->coef;
            p = p->link;
        }
        else if (p->deg < q->deg)
        {
            temp->deg = q->deg;
            temp->coef = q->coef;
            q = q->link;
        }
        else
        {
            temp->coef = p->coef + q->coef;
            temp->deg = p->deg;
            p = p->link;
            q = q->link;
        }
        if (start3 == NULL)
            start3 = temp;
        else
        {
            node *r = start3;
            while (r->link != NULL)
                r = r->link;
            r->link = temp;
        }
    }
    while (p != NULL)
    {
        temp = (node *)malloc(sizeof(node));
        temp->coef = p->coef;
        temp->deg = p->deg;
        temp->link = NULL;
        p = p->link;
        if (start3 == NULL)
            start3 = temp;
        else
        {
            node *r = start3;
            while (r->link != NULL)
                r = r->link;
            r->link = temp;
        }
    }
    while (q != NULL)
    {
        temp = (node *)malloc(sizeof(node));
        temp->coef = q->coef;
        temp->deg = q->deg;
        temp->link = NULL;
        q = q->link;
        if (start3 == NULL)
            start3 = temp;
        else
        {
            node *r = start3;
            while (r->link != NULL)
                r = r->link;
            r->link = temp;
        }
    }
    remdupl(start3);
    return start3;
}

node *multiply(node *start1, node *start2)
{
    node *start3, *p, *q, *temp;
    start3 = NULL;
    p = start1;
    while (p != NULL)
    {
        q = start2;
        while (q != NULL)
        {
            temp = (node *)malloc(sizeof(node));
            temp->coef = p->coef * q->coef;
            temp->deg = p->deg + q->deg;
            temp->link = NULL;
            if (start3 == NULL)
                start3 = temp;
            else
            {
                node *r = start3;
                while (r->link != NULL)
                    r = r->link;
                r->link = temp;
            }
            q = q->link;
        }
        p = p->link;
    }
    remdupl(start3);
    return start3;
}

node *addatbeg(node *start, node *p)
{
    p->link = start;
    start = p;
    return start;
}

node *addatend(node *start, node *p)
{
    node *temp = start;
    if (temp == NULL)
    {
        start = p;
        return start;
    }
    while (temp->link != NULL)
        temp = temp->link;
    temp->link = p;
    return start;
}

struct node *powerdel(struct node *start, int exp)
{
    struct node *p = start;
    if (start == NULL)
        return start;
    else if (start->deg == exp)
    {
        p = start;
        start = start->link;
        free(p);
        return start;
    }
    while (p->link != NULL)
    {
        if (p->link->deg == exp)
        {
            struct node *temp = (struct node *)malloc(sizeof(struct node));
            temp = p->link;
            p->link = temp->link;
            free(temp);
            return start;
        }
        p = p->link;
    }
}

node *adder(node *start, node *p)
{
    if ((start == NULL) || (p->deg > start->deg))
    {
        start = addatbeg(start, p);
        return start;
    }
    node *temp = start;
    while ((temp->link != NULL) && (p->deg < temp->link->deg))
        temp = temp->link;
    if (temp->link == NULL)
    {
        if (p->deg > temp->deg)
        {
            p->link = temp;
            start = p;
        }
        else if (p->deg == temp->deg)
        {
            temp->coef += p->coef;
        }
        else if (p->deg < temp->deg)
        {
            temp->link = p;
        }
        return start;
    }
    else
    {
        if (p->deg == temp->link->deg)
            temp->link->coef += p->coef;
        else if (p->deg > temp->link->deg)
        {
            p->link = temp->link;
            temp->link = p;
        }
    }
    return start;
}

node *modify(node *start)
{
    printf("Press 1 to insert a term, 2 to delete a term.\n");
    int ch, coef, deg;
    scanf("%d", &ch);
    node *temp = (node *)malloc(sizeof(node));
    switch (ch)
    {
    case 1:
        printf("Enter the coefficient : ");
        scanf("%d", &(temp->coef));
        printf("Enter the power : ");
        scanf("%d", &(temp->deg));
        temp->link = NULL;
        adder(start, temp);
        break;
    case 2:
        printf("Enter the power of the term to be deleted.\n");
        scanf("%d", &deg);
        start = powerdel(start, deg);
        break;
    default:
        printf("Invalid input.\n");
    }
    return start;
}

int main()
{
    node *start1, *start2;
    while (1)
    {
        printf("Enter 1 to enter polynomials.\n");
        printf("Enter 2 to display polynomials.\n");
        printf("Enter 3 to add polynomials.\n");
        printf("Enter 4 to multiply polynomials.\n");
        printf("Enter 5 to modify a polynomial.\n");
        printf("Enter 6 to get polynomials from file.\n");
        printf("Enter 7 to exit.\n");
        int choice;
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            node *start1 = NULL, *start2 = NULL;
            start1 = create(start1, 1);
            start2 = create(start2, 2);
            break;
        case 2:
            printf("Polynomial 1: ");
            display(start1);
            printf("Polynomial 2: ");
            display(start2);
            break;
        case 3:
            printf("Addition Result is: ");
            display(add(start1, start2));
            break;
        case 4:
            printf("Multiplication Result is: ");
            display(multiply(start1, start2));
            break;
        case 5:
            printf("Which polynomial should be modified: 1 or 2?\n");
            int polynum;
            scanf("%d", &polynum);
            if (polynum == 1)
                modify(start1);
            else
                modify(start2);
            break;
        case 6:
            start1 = NULL, start2 = NULL;
            FILE *fp;
            fp = fopen("poly.txt", "r");
            start1 = create_from_file(start1, fp);
            start2 = create_from_file(start2, fp);
            fclose(fp);
            break;
        case 7:
            exit(1);
            break;
        default:
            printf("Invalid choice.\n");
            break;
        }
    }
    return 0;
}