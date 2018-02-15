#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct nodes
{
	char info;
	struct nodes *next;	
};

void create();
void print_list();
void end();

typedef struct nodes snodes;
snodes *head,*x,*y;
int nodes=0,j,k=0;
char a[20];

void main()
{
	int ch;
	while(1)
	{
		printf("Enter your choice:\n 1.Create circular list\n2.Print_list\n3.Find nth element from the end\n4.Exit\n");
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
				end();
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
	printf("Enter data:");
	scanf(" %c",&(x->info));
/*The %c conversion specifier won't automatically skip any leading whitespace, so if there's a stray newline in the input stream (from a previous entry, for example) the scanf call will consume it immediately. scanf(" %c", &c);*/
	x->next=x; //CLL
	head=x;
	printf("If you wish to continue press 1 else 0:");
	scanf("%d",&i);
	while(i)
	{
		y=(snodes*)malloc(sizeof(snodes));
		nodes++;
		printf("Enter data:");
		scanf(" %c",&y->info);
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
		printf("%c\n",x->info);
		x=x->next;
	}while(x!=head);
	printf("%d\n",nodes);
}

void end()
{
	x=head;
	int p,l=1;
	printf("Enter position of element from the end:\n");
	scanf("%d",&p);
	k=nodes-p+1;
	while(l<k)
	{
		x=x->next;
		++l;	
	}
	printf("%c",x->info);
}
