#include<stdio.h>
#include<stdlib.h>

struct nodes
{
	char info;
	struct nodes *next;	
};

void create();
void print_list();
void rev_pairwise();

typedef struct nodes snodes;
snodes *head,*x,*y;
int nodes=0,j,k=0;
char a[20];

void main()
{
	int ch;
	while(1)
	{
		printf("Enter your choice:\n 1.Create circular list\n2.Print_list\n3.Reverse Pairwise(Make sure that the length of the linked list is even)\n4.Exit\n");
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
				rev_pairwise();
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
	nodes=1;
	x=(snodes*)malloc(sizeof(snodes));
	printf("Enter data:");
	scanf(" %c",&(x->info));
/*The %c conversion specifier won't automatically skip any leading whitespace, so if there's a stray newline in the input stream (from a previous entry, for example) the scanf call will consume it immediately. scanf(" %c", &c);*/
	x->next=NULL; //CLL
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
		y->next=NULL;
		x=y;
		printf("If you wish to continue,press 1 ,else 0:");
		scanf("%d",&i);			
	}
}

void print_list()
{
	x=head;
	while(x!=NULL)
	{
		printf("%c\n",x->info);
		x=x->next;
	}
	printf("%d\n",nodes);
}

void rev_pairwise()
{
	int temp;
	x=head;	
	while(x!=NULL){
		y=x->next;
		temp=x->info;
		x->info=y->info;
		y->info=temp;
		x=x->next->next;
	}
	
}
