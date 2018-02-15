#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *next;	
};

void create();
void ins_at_beg();
//void ins_at_pos();
void reverse();
void print_list();

typedef struct node snode;
snode *head,*x,*y;
void main()
{
	int ch;
	while(1)
	{
		printf("Enter your choice:\n 1.Create circular list\n2.Insert at beginning\n3.Print_list\n4.Reverse\n5.Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				create();
				break;
			case 2:
				ins_at_beg();
				break;
			case 3:
				print_list();
				break;
			case 4:
				reverse();
				break;	
			default:
				exit(0);
		}
	}	
}

//Function to create a x circular linked list
void create()
{
	int i;
	x=(snode*)malloc(sizeof(snode));
	printf("Enter data:");
	scanf("%d",&x->info);
	x->next=x; //CLL
	head=x;
	printf("If you wish to continue press 1 else 0:");
	scanf("%d",&i);
	while(i)
	{
		y=(snode*)malloc(sizeof(snode));
		printf("Enter data:");
		scanf("%d",&y->info);
		x->next=y;
		y->next=head;
		x=y;
		printf("If you wish to continue,press 1 ,else 0:");
		scanf("%d",&i);			
	}
}

void ins_at_beg()
{	
	y=head;
	x=(snode*)malloc(sizeof(snode));
	printf("Enter data:");
	scanf("%d",&x->info);
	while(y->next!=head)
	{
		y=y->next;
	}
	x->next=y->next;
	y->next=x;
	head=x;
}

void print_list()
{
	x=head;
	do
	{
		printf("%d\n",x->info);
		x=x->next;
	}while(x!=head);
}

void reverse()
{
	snode* p=NULL;
	snode* c= head;
	snode* n;
	do
	{
		n=c->next;
		c->next=p;
		p=c;
		c=n;
	}while(c!=head);

	head->next=p;
	head=p;
}
