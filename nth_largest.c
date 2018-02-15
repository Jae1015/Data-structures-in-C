#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct nodes
{
	int info;
	struct nodes *next;	
};

void create();
void print_list();
void n_largest();
void sort();

typedef struct nodes snodes;
snodes *head,*x,*y,*temp,*temp1;
int nodes=0,j,k=0;
char a[20];

void main()
{
	int ch;
	while(1)
	{
		printf("Enter your choice:\n 1.Create circular list\n2.Print_list\n3.Find nth largest\n4.Sort\n5.Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				create();
				break;
			case 2:
				print_list();
				break;
			case 3:
				n_largest();
				break;	
			case 4:
				sort();
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
	nodes=0;
	nodes++;
	x=(snodes*)malloc(sizeof(snodes));
	printf("Enter info:");
	scanf(" %d",&(x->info));
/*The %d conversion specifier won't automatically skip any leading whitespace, so if there's a stray newline in the input stream (from a previous entry, for example) the scanf call will consume it immediately. scanf(" %d", &c);*/
	x->next=x; //CLL
	head=x;
	printf("If you wish to continue press 1 else 0:");
	scanf("%d",&i);
	while(i)
	{
		y=(snodes*)malloc(sizeof(snodes));
		nodes++;
		printf("Enter info:");
		scanf(" %d",&y->info);
		x->next=y;
		y->next=head;
		x=y;
		printf("If you wish to continue,press 1 ,else 0:");
		scanf("%d",&i);			
	}
}

void print_list()
{
	x=head;
	do
	{
		printf("%d\n",x->info);
		x=x->next;
	}while(x!=head);
	//printf("%d\n",nodes);
}

void sort()
{
	temp=head;
	int s;
	temp1=temp->next;
	do
	{
		temp1=temp->next;	
		while(temp1!=head)
		{	
			if(temp->info > temp1->info)
			{
				s=temp->info;
				temp->info=temp1->info;
				temp1->info=s;
			
			}
			temp1=temp1->next;
		}
		temp=temp->next;
	}while(temp!=head);
}
void n_largest()
{
	int n,l=1;
	printf("Enter n:");
	scanf("%d",&n);
	sort();
	while(l<n)
	{
		x=x->next;
		++l;	
	}
	printf("%d",x->info);
}
