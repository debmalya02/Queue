#include <stdio.h>
#include <stdlib.h>
int arr[5];
int front = -1;
int rear = -1;
int isemty()
{
    if (front == -1 || front > rear)
        return 0;
    else
        return 1;
}
int isfull()
{
    if (rear == 4)
        return 0;
    else
        return 1;
}
void enqueue()
{
    int n;
    if (isfull())
    {
        printf("\n\t\t\tThe queue is full");
        return;
    }
    else if (isemty())
    {
        front++;
        rear++;
        printf("Enter the element to push in the queue : ");
        scanf("%d", &n);
        arr[rear] = n;
        return;
    }
    else
    {
        printf("Enter the element to push in the queue : ");
        scanf("%d", &n);
        rear++;
        arr[rear] = n;
        return;
    }
}
void dequeue()
{
    if (isemty())
    {
        printf("\n\t\t\tThe queue is empty");
        return;
    }
    else
    {
        printf("The popped item is %d", arr[front++]);
    }
}
void display()
{
    int i;
    if (isemty())
    {
        printf("\n\t\t\tThe queue is empty");
        return;
    }
    else
    {
        printf("The queue is : ");
        for (i = front; i <= rear; i++)
            printf("%5d", arr[i]);
    }
}
int main()
{
    int ch, f = 1;
    system("clear");
    while (f)
    {
        printf("\n\n\t\t\t Enter Your choise \n\t\t\t\t(1) to Push \n\t\t\t\t(2) to Pop \n\t\t\t\t(3) to display \n\t\t\t\t(0) to exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
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