#include <stdio.h>
#include <stdlib.h>
typedef struct node node;
struct node
{
    node *prev;
    int data;
    node *next;
};

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

void list_search(node *start)
{
    node *p = start;
    int pos = 1, item;
    printf("Enter the element to be searched.\n");
    scanf("%d", &item);
    while (p != NULL)
    {
        if (p->data == item)
        {
            printf("Item %d found at position %d \n", item, pos);
            return;
        }
        p = p->next;
        pos++;
    }
    printf("Item %d not found in list \n", item);
}

int count_nodes(struct node *start)
{
    struct node *p;
    int count = 0;
    p = start;
    while (p != NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}

node *add_to_empty(node *start)
{
    node *temp;
    int item;
    if (start != NULL)
    {
        printf("List is not empty.\n");
        return start;
    }
    printf("Enter the data to be inserted.\n");
    scanf("%d", &item);
    temp = (node *)malloc(sizeof(node));
    temp->data = item;
    temp->prev = temp->next = NULL;
    start = temp;
    return start;
}

node *add_at_beginning(node *start)
{
    node *temp;
    int item;
    if (start == NULL)
    {
        printf("List is empty.\n");
        return start;
    }
    printf("Enter the data to be inserted.\n");
    scanf("%d", &item);
    temp = (node *)malloc(sizeof(node));
    temp->data = item;
    temp->prev = NULL;
    temp->next = start;
    start = temp;
    return start;
}

node *add_at_end(node *start)
{
    node *temp, *p;
    int item;
    if (start == NULL)
    {
        printf("List is empty.\n");
        return start;
    }
    printf("Enter the data to be inserted.\n");
    scanf("%d", &item);
    temp = (node *)malloc(sizeof(node));
    temp->data = item;
    temp->next = NULL;
    p = start;
    while (p->next != NULL)
        p = p->next;
    p->next = temp;
    temp->prev = p;
    return start;
}

node *add_before(node *start)
{
    node *temp, *p;
    int elem, item;
    if (start == NULL)
    {
        printf("List is empty.\n");
        return start;
    }
    printf("Enter the node value and the data to be inserted.\n");
    scanf("%d%d", &elem, &item);
    if (start->data == elem)
    {
        temp = (node *)malloc(sizeof(node));
        temp->data = item;
        temp->prev = NULL;
        temp->next = start;
        start->prev = temp;
        start = temp;
        return start;
    }
    p = start;
    while (p != NULL)
    {
        if (p->data == elem)
        {
            temp = (node *)malloc(sizeof(node));
            temp->data = item;
            temp->prev = p->prev;
            temp->next = p;
            p->prev->next = temp;
            p->prev = temp;
            return start;
        }
        p = p->next;
    }
    printf("Entered item not found in list.\n");
    return start;
}

node *add_after(node *start)
{
    node *temp, *p;
    int elem, item;
    if (start == NULL)
    {
        printf("List is empty.\n");
        return start;
    }
    printf("Enter the node value and the data to be inserted.\n");
    scanf("%d%d", &elem, &item);
    p = start;
    while (p != NULL)
    {
        if (p->data == elem)
        {
            temp = (node *)malloc(sizeof(node));
            temp->data = item;
            temp->prev = p;
            temp->next = p->next;
            p->next = temp;
            p->next->prev = temp;
            return start;
        }
        p = p->next;
    }
    printf("Entered item not found in list.\n");
    return start;
}

node *add_at_position(node *start)
{
    node *temp, *p;
    int posn, item;
    printf("Enter the position.\n");
    scanf("%d", &posn);
    if (start == NULL)
    {
        if (posn == 1)
        {
            start = add_to_empty(start);
            return start;
        }
        else
        {
            printf("Empty list.\n");
            return start;
        }
    }
    if (posn == 1)
    {
        start = add_at_beginning(start);
        return start;
    }
    else if (posn == count_nodes(start) + 1)
    {
        start = add_at_end(start);
        return start;
    }
    else
    {
        printf("Enter the data to be added.\n");
        scanf("%d", &item);
        temp = (node *)malloc(sizeof(node));
        temp->data = item;
        p = start;
        while (posn >= 1)
        {
            if (posn == 1)
            {
                temp->next = p;
                temp->prev = p->prev;
                p->prev->next = temp;
                p->next->prev = temp;
            }
            posn--;
            p = p->next;
        }
        return start;
    }
}

struct node *del(struct node *start)
{

    struct node *tmp;
    if (start == NULL)
    {
        printf("List is empty.\n");
        return start;
    }
    int data;
    printf("Enter the data to be deleted.\n");
    scanf("%d", &data);
    if (start->next == NULL)
    {
        if (start->data == data)
        {
            tmp = start;
            start = NULL;
            free(tmp);
            return start;
        }
        else
        {
            printf("Element %d not found in LL.\n", data);
            return start;
        }
    }
    if (start->data == data)
    {
        tmp = start;
        start = start->next;
        start->prev = NULL;
        free(tmp);
        return start;
    }
    tmp = start->next;
    while (tmp->next != NULL)
    {
        if (tmp->data == data)
        {
            tmp->prev->next = tmp->next;
            tmp->next->prev = tmp->prev;
            free(tmp);
            return start;
        }
        tmp = tmp->next;
    }
    if (tmp->data == data)
    {
        tmp->prev->next = NULL;
        free(tmp);
        return start;
    }
    printf("Element %d not found in LL.\n", data);
    return start;
}

node *reverse_linked_list(node *start)
{
    node *p1, *p2;
    p1 = start;
    p2 = p1->next;
    p1->prev = p2;
    p1->next = NULL;
    while (p2 != NULL)
    {
        p2->prev = p2->next;
        p2->next = p1;
        p1 = p2;
        p2 = p2->prev;
    }
    start = p1;
    return start;
}

int main()
{
    node *start = NULL;
    int choice;
    while (1)
    {
        printf("Enter 1 to create linked list.\n");
        printf("Enter 2 to display linked list.\n");
        printf("Enter 3 to search for an element.\n");
        printf("Enter 4 to count the number of nodes.\n");
        printf("Enter 5 to add to empty.\n");
        printf("Enter 6 to add at beginning.\n");
        printf("Enter 7 to add at end.\n");
        printf("Enter 8 to add before a node.\n");
        printf("Enter 9 to add after a node.\n");
        printf("Enter 10 to add at a position.\n");
        printf("Enter 11 to delete a node.\n");
        printf("Enter 12 to reverse the linked list.\n");
        printf("Enter 13 to exit.\n");
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
            list_search(start);
            break;
        case 4:
            printf("Number of nodes in the linked list is: %d\n",
                   count_nodes(start));
            break;
        case 5:
            start = add_to_empty(start);
            break;
        case 6:
            start = add_at_beginning(start);
            break;
        case 7:
            start = add_at_end(start);
            break;
        case 8:
            start = add_before(start);
            break;
        case 9:
            start = add_after(start);
            break;
        case 10:
            start = add_at_position(start);
            break;
        case 11:
            start = del(start);
            break;
        case 12:
            start = reverse_linked_list(start);
            break;
        case 13:
            exit(1);
        default:
            printf("Erroneous input.\n");
        }
    }
    return 0;
}
