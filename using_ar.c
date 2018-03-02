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
int nodes=0,j,k=0;
int stack[50],top=-1,n;

void main()
{
	
	printf("Enter the size of array:");
	scanf("%d",&n);
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
	int x;
	if(top>=n-1)
		printf("STACK OVERFLOW");
	else
	{
		printf("ENter a value:");
		scanf("%d",&x);
		top++;
		stack[top]=x;
	}
}

void pop()
{
	if(top<=-1)
		printf("STACK UNDERFLOW");
	else
		top--;
}

void traverse()
{
	int x;
	if(top<=-1)
		printf("STACK EMPTY");
	else
	{	
		x=top;
		while(x!=-1)
		{
			printf("%d",stack[x]);
			x--;
		}
	}
		

}

