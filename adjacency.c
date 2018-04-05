#include<stdio.h>

int a[50][50];
int n;

void main()
{	
	int choice;
	
		do
		{
			printf("Adjacencey matrix representations:\n");
			printf("ENter number of vertices:\n");
			scanf("%d",&n);
			printf("1.Unidirected graph\n2.Directed Graph\n3.Exit");
			scanf("%d",&choice);
		
			switch(choice)
			{
				case 1:undirg();
					break;
			
				case 2:dirg();
					break;
					
				case 3:	exit(0);
			}
		}while(1);


}
void dirg()
{
	int i,in_deg,out_deg,j;
	read_graph();
	for(i=1;i<=n;i++)
	{
		in_deg=0,out_deg=0;
		for(j=1;j<=n;j++)
		{
			if(a[i][j]==1)
				in_deg++;
			else
				out_deg++;
		}
		printf("in_Deg=%d%\nout_Deg=%d",in_deg,out_deg);
	}
}
void undirg()
{
	int i,j,deg;
	read_graph();
	for(i=1;i<=n;i++)
	{
		deg=0;
		for(j=1;j<=n;j++)
		{
			if (a[i][j]==1)
				deg++;
		}
		printf("Degree of %i is %d\n",i,deg);
	}
}

void read_graph()
{
	int c,i,j;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("Are vertices %d and %d adjacent?(1/0)\n",i,j);
			scanf("%d",&c);
			if(c==1)
				a[i][j]=1;
			else
				a[i][j]=0;
		}
	}
}
