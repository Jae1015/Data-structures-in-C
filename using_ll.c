#include<stdio.h>
#include<stdlib.h>

struct queue
{
	int info;	
	struct queue *next;
};

typedef struct queue sq;

sq *front=NULL, *rear=NULL, *x,*y;
void enq();
void deq();
void traverse();

void main()
{
	int choice;	
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
	if((front==rear)&&(front==NULL))
	{
		x=(sq*)malloc(sizeof(sq));
		printf("Enter data:\n");
		scanf("%d",&x->info);
		x->next=NULL;
		front=x;
		rear=x;
	}
	else
	{
		x=(sq*)malloc(sizeof(sq));
		printf("Enter data:\n");
		scanf("%d",&x->info);
		x->next=NULL;
		rear->next=x;
		rear=rear->next;	
	}
	
}
void deq()
{
	if((front==rear)&&(front!=NULL))
	{
		x=front;
		front=NULL;
		rear=NULL;
		free(x);	
	}
	else
	{
		x=front;
		front=front->next;
		free(x);	
	}
}
void traverse()
{
	x=front;
	while(x!=rear->next)
	{
		printf("%d\n",x->info);
		x=x->next;
	}
}
