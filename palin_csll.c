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
void palin();

typedef struct nodes snodes;
snodes *head,*x,*y;
int nodes=0,j,k=0;
char a[20];

void main()
{
	int ch;
	while(1)
	{
		printf("Enter your choice:\n 1.Create circular list\n2.Print_list\n3.Palindrome Check\n4.Exit\n");
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
				palin();
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

void palin()
{
	int i=0,j=0,l=0;
	x=head;
	l=floor(nodes/2);
	printf("%d",l);
	for(i=0;i<l;i++)
	{
		a[j]=x->info;
		printf("%c",a[j]);
		x=x->next;
		++j;
	}
	if((nodes%2)==0)
	{
		k=l-1;
		while(x!=head)
		{			
			if(x->info==a[k])
			{
				printf("x is %c\narray %c\n",x->info,a[k]);				
				++l;
				--k;
				x=x->next;
				if(l==nodes)
				{
					printf("It is a palindrome\n");
					break;
				}				
			}
			else
			{
				printf("Not a palindrome\n");
				break;			
			}				
		}
	}
	else
	{
		
		k=l-1;
		l++;
		x=x->next; //to skip one node for odd length palindrome
		while(x!=head)
		{			
			if(x->info==a[k])
			{
				printf("\nx is %c\narray %c\n",x->info,a[k]);				
				++l;
				--k;
				x=x->next;
				if(l==nodes)
				{
					printf("It is a palindrome\n");
					break;
				}				
			}
			else
			{
				printf("Not a palindrome\n");
				break;			
			}				
		}
	}
}
