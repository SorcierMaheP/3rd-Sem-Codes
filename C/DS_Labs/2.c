#include <stdio.h>
#include <stdlib.h>

/* For defining of the structure of a node */
struct node
{
    int info;
    struct node *link;
};

/* To create a linked list */
struct node *
create_linked_list(struct node *start)
{
    struct node *temp, *p;
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    start = NULL;
    if (n == 0)
        return start;
    for (int i = 0; i < n; i++)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        printf("\nEnter the data for node %d: ", i + 1);
        scanf("%d", &temp->info);
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
};

/* To display the linked list */
void display_linked_list(struct node *start)
{
    struct node *p;
    if (start == NULL)
    {
        printf("Linked list is empty\n");
        return;
    }
    p = start;
    printf("Linked list is: \n");
    while (p->link != NULL)
    {
        printf("%d->", p->info);
        p = p->link;
    }
    printf("%d\n", p->info);
};

/* To count the number of nodes in the linked list */
int count_nodes(struct node *start)
{
    struct node *p;
    int count = 0;
    p = start;
    while (p != NULL)
    {
        count++;
        p = p->link;
    }
    return count;
};

/*To search for an element in the linked list */
void list_search(struct node *start)
{
    struct node *p = start;
    int pos = 1, item;
    printf("Enter the element to be searched.\n");
    scanf("%d", &item);
    while (p != NULL)
    {
        if (p->info == item)
        {
            printf("Item %d found at position %d \n", item, pos);
            return;
        }
        p = p->link;
        pos++;
    }
    printf("Item %d not found in list \n", item);
}

/* To insert a node at the beginning of the linked list */
struct node *
insert_at_beginning(struct node *start)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data for the node: \n");
    scanf("%d", &temp->info);
    temp->link = start;
    start = temp;
    return start;
};

/* To insert a node at the end of the linked list */
struct node *
insert_at_end(struct node *start)
{
    struct node *temp, *p;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data for the node:\n ");
    scanf("%d", &temp->info);
    temp->link = NULL;
    p = start;
    while (p->link != NULL)
        p = p->link;
    p->link = temp;
    return start;
};

/* To insert a node at a given position in the linked list */
struct node *
insert_at_position(struct node *start)
{
    struct node *temp, *p;
    int pos, i;
    printf("Enter the position:\n ");
    scanf("%d", &pos);
    int count = count_nodes(start);
    if (pos > count + 1 || pos < 1)
    {
        printf("Invalid position\n");
        return start;
    }
    if (pos == 1)
        start = insert_at_beginning(start);
    else if (pos == count + 1)
        start = insert_at_end(start);
    else
    {
        temp = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data for the node: \n");
        scanf("%d", &temp->info);
        p = start;
        for (i = 1; i < pos - 1; i++)
            p = p->link;
        temp->link = p->link;
        p->link = temp;
    }
    return start;
};

/*To add before in the linked list*/
struct node *addbefore(struct node *start)
{
    struct node *p, *tmp;
    if (start == NULL)
    {
        printf("List is empty.\n");
        return start;
    }
    int data, item;
    printf("Enter the element in LL to be inserted before and the data to be inserted.\n");
    scanf("%d%d", &item, &data);
    if (start->info == item)
    {
        tmp = (struct node *)malloc(sizeof(struct node));
        tmp->info = data;
        tmp->link = start;
        start = tmp;
        return start;
    }
    p = start;
    while (p->link != NULL)
    {
        if (p->link->info == item)
        {
            tmp = (struct node *)malloc(sizeof(struct node));
            tmp->info = data;
            tmp->link = p->link;
            p->link = tmp;
            return start;
        }
        p = p->link;
    }
    printf("Item %d not found in LL.\n", item);
    return start;
}

/*To add after in the linked list*/
struct node *addafter(struct node *start)
{
    struct node *p, *tmp;
    p = start;
    int data, item;
    printf("Enter the element in LL to be inserted after and the data to be inserted.\n");
    scanf("%d%d", &item, &data);
    while (p != NULL)
    {
        if (p->info == item)
        {
            tmp = (struct node *)malloc(sizeof(struct node));
            tmp->info = data;
            tmp->link = p->link;
            p->link = tmp;
            return start;
        }
        p = p->link;
    }
    printf("Item %d not found in LL.\n", item);
    return start;
}

/* To delete a node from the linked list */
struct node *del(struct node *start)
{
    struct node *tmp, *p;
    if (start == NULL)
    {
        printf("List is empty.\n");
        return start;
    }
    int data;
    printf("Enter the data for the node:\n");
    scanf("%d", &data);
    if (start->info == data)
    {
        tmp = start;
        start = start->link;
        free(tmp);
        return start;
    }
    p = start;
    while (p->link != NULL)
    {
        if (p->link->info == data)
        {
            tmp = p->link;
            p->link = tmp->link;
            free(tmp);
            return start;
        }
        p = p->link;
    }
    printf("Element %d not found in LL.\n", data);
    return start;
}

/* To reverse the linked list */
struct node *
reverse_linked_list(struct node *start)
{
    struct node *prev, *next, *p;
    p = start;
    prev = NULL;
    while (p != NULL)
    {
        next = p->link;
        p->link = prev;
        prev = p;
        p = next;
    }
    start = prev;
    return start;
};

int main()
{
    struct node *start = NULL;
    int choice;
    while (1)
    {
        printf("Enter 1 to create linked list.\n");
        printf("Enter 2 to display linked list.\n");
        printf("Enter 3 to count the number of nodes.\n");
        printf("Enter 4 to search for an element.\n");
        printf("Enter 5 to insert a node at the beginning.\n");
        printf("Enter 6 to insert a node at the end.\n");
        printf("Enter 7 to insert a node at a given position.\n");
        printf("Enter 8 to insert node before another node.\n");
        printf("Enter 9 to insert node after specified node.\n");
        printf("Enter 10 to delete a node.\n");
        printf("Enter 11 to reverse the linked list.\n");
        printf("Enter 12 to exit.\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            start = create_linked_list(start);
            break;
        case 2:
            display_linked_list(start);
            break;
        case 3:
            printf("Number of nodes in the linked list is: %d\n",
                   count_nodes(start));
            break;
        case 4:
            list_search(start);
            break;
        case 5:
            start = insert_at_beginning(start);
            break;
        case 6:
            start = insert_at_end(start);
            break;
        case 7:
            start = insert_at_position(start);
            break;
        case 8:
            start = addbefore(start);
            break;
        case 9:
            start = addafter(start);
            break;
        case 10:
            start = del(start);
            break;
        case 11:
            start = reverse_linked_list(start);
            break;
        case 12:
            exit(1);
        default:
            printf("Erroneous input.\n");
        }
    }
    return 0;
}