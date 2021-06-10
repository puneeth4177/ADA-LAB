#include <stdio.h>
void DFS(int);
int a[10][10], new[10], n;

void main()
{

    int i, j, comp=1;
printf("enter number of vertices\n");
 scanf("%d", &n);
 printf("enter adjacency matrix\n");
for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    for (i = 1; i <= n; i++)
        new[i] = 0;

    for(i=1;i<=n;i++){
        if(new[i]==0){
            printf("component %d:\n",comp );
            comp++;
            DFS(i);
            printf("\n");
        }  
    }

    
}

void DFS(int v)

{

    int i;
    new[v] = 1;
    printf("%d ", v);
    for (i = 1; i <= n; i++)
    {
        if (a[v][i] == 1 && new[i] == 0)
            DFS(i);
    }
}
