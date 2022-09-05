#include <stdio.h>
#include <stdlib.h>
#define size 5
int arr[size];
int front = -1;
int rear = -1;
void enqueue()
{
	int n, elm, i;
	if ((front == 0 && rear == size - 1) || front == rear + 1)
	{
		printf("\n !!! The Queue is full !!!");
		return;
	}
	else
	{
		if (front == -1)
		{
			front = 0;
		}
		printf("\nEnter the elements : ");
		rear = (rear + 1) % size;
		scanf("%d", &elm);
		arr[rear] = elm;
		return;
	}
}
void dequeue()
{
	if (rear == -1)
	{
		printf("\n !!! The Queue is empty !!!");
		return;
	}
	else
		printf("\nThe deleted item is : %d", arr[front]);
	if (front == rear)
	{
		front = -1;
		rear = -1;
	}
	else
	{
		front = (front + 1) % size;
	}
	return;
}
void display()
{
	int i;
	int front_pos = front;
	int rear_pos = rear;
	if (rear == -1)
	{
		printf("\n !!! The Queue is empty !!!");
		return;
	}
	else
	{
		printf("\nThe Queue is : ");
		if (front <= rear)
		{
			while (front_pos <= rear_pos)
			{
				printf("%d ", arr[front_pos++]);
			}
		}
		else
		{
			while (front_pos <= size - 1)
				printf("%d ", arr[front_pos++]);
			front_pos = 0;
			while (front_pos <= rear_pos)
				printf("%d ", arr[front_pos++]);
		}
		return;
	}
}
int main()
{
	int ch, f = 1;
	system("clear");
	while (f)
	{
		printf("\n\n\t\t\t Enter Your choise \n\t\t\t\t(1) to Push \n\t\t\t\t(2) to Pop \n\t\t\t\t(3) to display \n\t\t\t\t(4) to exit\n");
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
		case 4:
			f = 0;
			break;
		default:
			printf("\n\t\t\t!!! Invalid input !!!");
			break;
		}
	}
}