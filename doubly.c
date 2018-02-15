#include<stdio.h>
#include<stdlib.h>

struct node
{
	struct node *next,*prev;
	int info;
};

typedef struct node snode;
snode *head,*a,*b;

void create();
void traverse();
void count_nodes();
void ins_beg();
void ins_end();
void ins_any_pos();
void del_beg();
void del_end();
void del_any_pos();
void search();

void main()
{
		
	int ch;
	while(1)
	{
	
		printf("Enter your choice:\n1 Create Double linked list\n2 Traverse\n3 Count Nodes\n4 Insert at beginning\n5 Insert at end\n6 Insert at any position\n7 Delete from beginning\n8 Delete from end\n9 Delete from any position\n10 Search for a node\nDefault:Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{	case 1:
			create();
			break;
		
			case 2:
			traverse();
			break;
		
			case 3:
			count_nodes();
			break;
			
			case 4:
			ins_beg();
			break;

			case 5:
			ins_end();
			break;
			
			case 6:
			ins_any_pos();
			break;
			
			case 7:
			del_beg();
			break;
			
			case 8:
			del_end();
			break;

			case 9:
			del_any_pos();
			break;

			case 10:
			search();
			break;

			default:
				exit(0);
		}
	}
}
void create()
{
	int i;
	a=(snode*)malloc(sizeof(snode));
	printf("Enter data\n");
	scanf("%d",&a->info);
	a->prev=a->next=NULL;
	head=a;
	printf("If you wish to continue,press 1 else 0:\n");
	scanf("%d",&i);
	while(i)
	{
		b=(snode*)malloc(sizeof(snode));
		printf("Enter data\n");
		scanf("%d",&b->info);
		b->prev=a;
		b->next=NULL;
		a->next=b;
		a=b;
		printf("If you wish to continue,press 1 else 0:\n");
		scanf("%d",&i);
	}
}

void traverse()
{
	a=head;
	printf("List:\n");
	while(a!=NULL)
	{
		printf("%d\n",a->info);
		a=a->next;
	}
}

void count_nodes()
{
	int nodes;
	a=head;
	while(a!=NULL)
	{
		nodes++;
		a=a->next;
	}
	printf("\n%d\n",nodes);
}

void ins_beg()
{
	if(head!=NULL)
	{	
		a=(snode*)malloc(sizeof(snode));
		printf("enter data:");
		scanf("%d",&a->info);
		a->next=head;
		a->prev=NULL;
		head->prev=a;
		head=head->prev;
	}
	else
	{
		a=(snode*)malloc(sizeof(snode));
		printf("Enter data\n");
		scanf("%d",&a->info);
		a->prev=a->next=NULL;
		head=a;
	}
}

void ins_end()
{
	b=head;
	while(b->next!=NULL)
	{
		b=b->next;
	}
	a=(snode*)malloc(sizeof(snode));
	printf("enter data:");
	scanf("%d",&a->info);
	b->next=a;
	a->next=NULL;
}

void ins_any_pos()
{
	int i,j=2;
	printf("Enter position:");
	scanf("%d",&i);
	a=head;
	while(j<i)
	{
		a=a->next;
		j++;
	}
	b=(snode*)malloc(sizeof(snode));
	printf("Enter data:\n");
	scanf("%d",&b->info);
	b->next=a->next;
	b->prev=a;
	a->next=b;
}

void del_beg()
{
	a=head;
	head=head->next;
	head->prev=NULL;
	free(a);
}

void del_end()
{
	a=head;
	while(a->next!=NULL)
		a=a->next;
	a->prev->next=NULL;
	free(a);
}

void del_any_pos()
{
	a=head;
	int i,j=1;
	printf("Enter position:");
	scanf("%d",&i);
	while(j<i)
	{
		a=a->next;
		j++;
	}
	printf("%d",a->info);
	a->next->prev=a->prev;
	a->prev->next=a->next;
	free(a);
}

void search()
{
	int i=1,temp;
	printf("Enter data to be searched:");
	scanf("%d",&temp);
	a=head;
	while(a!=NULL)
	{
		if(a->info==temp)
		{
			printf("Node found at %d\n",i);
			break;		
		}
		else
		{
			i++;
			if(a->next==NULL)
			{
				printf("Sorry,NOde not found!\n");
			}

			a=a->next;	
		}
	}
}
