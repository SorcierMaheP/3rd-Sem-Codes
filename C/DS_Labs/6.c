#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *front = NULL;
struct node *rear = NULL;
void insert(int);
void del();
void display();
void peek();
void insert(int data)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    if (front == NULL)
        front = rear = temp;
    else
    {
        rear->next = temp;
        rear = temp;
    }
}
void del()
{
    if (front == NULL)
    {
        printf("Queue is empty.\n\n");
    }
    else if (front == rear)
    {
        printf("Deleted %d.\n", front->data);
        free(front);
        front = rear = NULL;
    }
    else
    {
        struct node *temp = front;
        printf("Deleted %d.\n", front->data);
        front = front->next;
        free(temp);
    }
}
void display()
{
    if (front == NULL)
    {
        printf("Empty Queue.\n");
        return;
    }
    struct node *temp = front;
    printf("Queue contents are : \n");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void peek()
{
    if (front == NULL)
    {
        printf("Empty Queue.\n");
        return;
    }
    else
        printf("The front element is : %d.\n", front->data);
    printf("\n");
}
int main()
{
    int choice, data;
    while (1)
    {
        printf("\n1:Insert \n2:Delete \n3:Display\n4:Peek\n5:Exit\n");
        printf("Enter your choice.\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the data :\n");
            scanf("%d", &data);
            insert(data);
            break;
        case 2:
            del();
            break;
        case 3:
            display();
            break;
        case 4:
            peek();
            break;
        case 5:
            exit(1);
        default:
            printf("Erroneous input.\n");
            break;
        }
    }
    return 0;
}