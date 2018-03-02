#include<stdio.h>
#include<stdlib.h>

struct nodes
{
	int info;
	struct nodes *next;	
};

void push();
void pop();
void traverse();

typedef struct nodes snodes;
snodes *top=NULL,*x,*y;
int nodes=0,j,k=0;
char a[20];

void main()
{
	int ch;
	while(1)
	{
		printf("Enter your choice:\n 1.Push elements into stack\n2.Pop\n3.Traverse\n4.Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				push();
				break;
			case 2:
				pop();
				break;
			case 3:
				traverse();
				break;
			default:
				exit(0);
		}
	}	
}

void push()
{
	int i;
	if(top!=NULL)
	{
		x=(snodes*)malloc(sizeof(snodes));
		printf("Enter data:");
		scanf(" %d",&(x->info));
/*The %d conversion specifier won't automatically skip any leading whitespace, so if there's a stray newline in the input stream (from a previous entry, for example) the scanf call will consume it immediately. scanf(" %d", &c);*/
		x->next=NULL;
		top=x;
		printf("If you wish to continue press 1 else 0:");
		scanf("%d",&i);
		while(i)
		{
			y=(snodes*)malloc(sizeof(snodes));
			nodes++;
			printf("Enter data:");
			scanf(" %d",&y->info);
			y->next=x;
			top=y;
			x=y;
			printf("If you wish to continue,press 1 ,else 0:");
			scanf("%d",&i);			
		}
	}
	else
	{
		x=top;
		while(i)
		{
			y=(snodes*)malloc(sizeof(snodes));
			nodes++;
			printf("Enter data:");
			scanf(" %d",&y->info);
			y->next=x;
			top=y;
			x=y;
			printf("If you wish to continue,press 1 ,else 0:");
			scanf("%d",&i);			
		}
	}
}

void pop()
{
	x=top;
	top=top->next;
	free(x);
}

void traverse()
{
	x=top;
	while(x!=NULL)
	{
		printf("%d\n",x->info);
		x=x->next;
	}
}

