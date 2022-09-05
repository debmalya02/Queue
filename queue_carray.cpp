#include <stdio.h>
#include <stdlib.h>
#define size 5
typedef struct queue
{
    int arr[size];
    int front;
    int rear;
} q;
void enqueue(q *);
void dequeue(q *);
void display(q *);
int main()
{
    int ch, f = 1;
    q p;
    p.front = -1;
    p.rear = -1;
    while (f)
    {
        printf("\n\n\t\t\t Enter Your choise \n\t\t\t\t(1) to Push \n\t\t\t\t(2) to Pop \n\t\t\t\t(3) to display \n\t\t\t\t(0) to exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            enqueue(&p);
            break;
        case 2:
            dequeue(&p);
            break;
        case 3:
            display(&p);
            break;
        case 0:
            f = 0;
            break;
        default:
            printf("\n\t\t\t!!! Invalid input !!!");
            break;
        }
    }
}
void enqueue(q *pos)
{
    int n;
    if ((pos->front == 0 && pos->rear == size - 1) || (pos->front == pos->rear + 1))
    {
        printf("\n\t\t\t!!! The queue is over flowing !!!");
        return;
    }
    else
    {
        printf("Enter the element to push in the queue : ");
        scanf("%d", &n);
        if (pos->rear == -1)
        {
            pos->front = pos->rear = 0;
            pos->arr[pos->rear] = n;
        }
        else
        {
            pos->rear = (pos->rear + 1) % size;
            pos->arr[pos->rear] = n;
        }
    }
}
void dequeue(q *pos)
{
    if (pos->front == -1)
    {
        printf("\n\t\t\t !!! The queue is empty !!!");
        return;
    }
    printf("Deleted item is %d", pos->arr[pos->front]);
    if (pos->front == pos->rear)
    {
        pos->front = pos->rear = -1;
    }
    else
    {
        pos->front = (pos->front + 1) % size;
    }
}
void display(q *pos)
{
    char c;
    int front_pos = pos->front, rear_pos = pos->rear;
    if (pos->front == -1)
    {
        printf("\n\t\t\t Queue is empty...");
        c = getchar();
        c = getchar();
        return;
    }
    printf("\n\t\t\t Queue elements :\n");
    if (front_pos <= rear_pos)
        while (front_pos <= rear_pos)
        {
            printf("%d ", pos->arr[front_pos]);
            front_pos++;
        }
    else
    {
        while (front_pos <= size - 1)
        {
            printf("%d ", pos->arr[front_pos]);
            front_pos++;
        }
        front_pos = 0;
        while (front_pos <= rear_pos)
        {
            printf("%d ", pos->arr[front_pos]);
            front_pos++;
        }
    }
    printf("\n");
}