#include <stdio.h>
#include <stdlib.h>
#define MAX 10
int cqueue_arr[MAX];
int rear = -1;
int front = -1;
void insert(int item);
int del();
int peek();
int isFull();
int isEmpty();
void display();
int main()
{

    int choice, item;
    while (1)
    {

        printf("1.Insert\n");
        printf("2.Delete\n");
        printf("3.Display the element at the front.\n");
        printf("4.Display all the elements of the queue.\n");
        printf("5.Quit.\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:

            printf("Enter the element.\n");
            scanf("%d", &item);
            insert(item);
            break;
        case 2:

            item = del();
            printf("Deleted item is : %d\n ", item);
            break;
        case 3:

            printf("Item at the front is : %d\n ", peek());
            break;
        case 4:

            display();
            break;
        case 5:
            exit(1);
        default:

            printf("Wrong choice\n");
        }
    }
    return 0;
}

void insert(int item)
{
    if (isFull())
    {
        printf("Circular Queue Overflow\n");
        return;
    }
    if (front == -1)
        front = 0;
    if (rear == MAX - 1)
        rear = 0;
    else
        rear = rear + 1;
    cqueue_arr[rear] = item;
}

int isFull()
{
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1))
        return 1;
    else
        return 0;
}

int del()
{
    int item;
    if (isEmpty())
    {
        printf("Circular Queue Underflow\n");
        exit(1);
    }
    item = cqueue_arr[front];
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if (front == MAX - 1)
        front = 0;
    else
        front = front + 1;
    return item;
}

int isEmpty()
{
    if (front == -1)
        return 1;
    else
        return 0;
}

int peek()
{
    if (isEmpty())
    {
        printf("Circular Queue Underflow\n");
        exit(1);
    }
    return cqueue_arr[front];
}

void display()
{
    int i;
    if (isEmpty())
    {
        printf("Circular Queue is empty\n");
        return;
    }
    printf("Queue is :\n");
    i = front;
    if (front <= rear)
    {
        while (i <= rear)
            printf("%d ", cqueue_arr[i++]);
    }
    else
    {
        while (i <= MAX - 1)
            printf("%d ", cqueue_arr[i++]);
        i = 0;
        while (i <= rear)
            printf("%d ", cqueue_arr[i++]);
    }
    printf("\n");
}