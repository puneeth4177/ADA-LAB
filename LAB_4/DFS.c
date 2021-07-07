#include<stdio.h>
#include<conio.h>
#include <time.h>
int a[1][10];

void DFS(int n, int cost[10][10], int u, int s[])
{
	int v;
	s[u]=1;
	for(v=0;v<n;v++)
	{
		if((cost[u][v]==1) && (s[v]==0))
			DFS(n,cost,v,s);
	}
}

void main()
{
	int n,i,j,cost[10][10];
    int s[10],con,flag;
    clock_t start,end;
    double cc;
	printf("Enter the number of nodes\n");
	scanf("%d", &n);
	printf("Enter the adjacency matrix\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			scanf("%d", &cost[i][j]);
	}
    start=clock();
	con=0;
	for(j=0;j<n;j++)
	{
		for(i=0;i<n;i++)
		s[i]=0;

		DFS(n,cost,j,s);
		flag=0;
		for(i=0;i<n;i++)
		{
			if(s[i]==0)
				flag=1;
		}
		if(flag==0)
			con=1;
	}
	if(con==1)
		printf("Graph is connected\n");
	else
		printf("Graph is not connected\n");
        end=clock();
         /* cc=((double)end-start);
  printf("The number of clock cycles taken = %f \n",cc);
  printf("The total time taken = %f \n",(cc/CLOCKS_PER_SEC));*/
	
}
