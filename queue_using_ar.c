#include<stdio.h>
#include<stdlib.h>

int queue[5],front=-1,rear=-1,n;

void enq();
void deq();
void traverse();

void main()
{
	int choice;
	printf("Enter size of array:\n");
	scanf("%d",&n);
	printf("1.Enqueue\n2.Dequeue\n3.Traverse\n4.Exit\n");
	printf("Enter your choice:\n");
	scanf(" %d",&choice);
	do
	{
		switch(choice)
		{
			case 1:enq();
				break;
			case 2:deq();
				break;
			case 3:traverse();
				break;
			case 4:exit(0);
				//break;
			default:printf("Enter  valid choice:\n");
		}
		
		printf("1.Enqueue\n2.Dequeue\n3.Traverse\n4.Exit\n");
		printf("Enter your choice:\n");
		scanf(" %d",&choice);

	}while(1);
	//getch();
}

void enq()
{
	int i;	
	if((rear+1)%n==front)
		printf("QUEUE FULL");
	else if(front==-1)
	{
		printf("Enter data:\n");
		scanf("%d",&i);
		rear=(rear+1)%n;
		queue[rear]=i;
		front=rear;
	}

	else
	{
		printf("Enter data:\n");
		scanf("%d",&i);
		rear=(rear+1)%n;
		queue[rear]=i;
	}
}
void deq()
{
	if(front==rear)
	{
		printf("QUEUE EMPTY");
	}
	else
	{
		front=(front+1)%n;
	}
}
void traverse()
{
	int x=(front-1)%n;
	do
	{
		x=(x+1)%n;
		printf("%d:%d\n",x,queue[x]);			
	}while(x!=rear);
}
