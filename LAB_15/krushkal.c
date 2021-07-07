#include <stdio.h>

void kruskals();

int cost[10][10], min, n, i, j, count, k, u, v, parent[10], sum, t[10][2],num_edge=0;
void union_ij(int i, int j)
{
    if (i < j)
        parent[j] = i;
    else
        parent[i] = j;
}
int find(int v)
{
    while(parent[v] != v)
        v = parent[v];
    return v;
}

void main()
{
    printf("Enter the number of vertices\n");
    scanf("%d", &n);
    printf("Enter the cost of adjacency matrix\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);
            if(cost[i][j]!=0&&cost[i][j]<999)num_edge++;
        }
    }
    kruskals();
}
void kruskals()
{
    count = 0;
    k = 0;
    sum = 0;
    for (i = 0; i < n; i++)
        parent[i] = i;
    while (count != num_edge/2)
    {
        min = 999;
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (cost[i][j] < min && cost[i][j] != 0)
                {
                    min = cost[i][j];
                    u = i;
                    v = j;
                }
            }
        }

        i = find(u);
        j = find(v);
        if(i==j)
        {
            printf("Vertext forming cycle: %d and %d\n",u,v);
            count++;
        }
        else if (i != j)
        {
            t[k][0] = u;
            t[k][1] = v;
            k++;
            count++;
            sum = sum + cost[u][v];
            union_ij(i, j);
        }
        else
        {
            count++;
        }
        cost[u][v] = cost[v][u] = 999;
    }
    printf("Minimum Spanning Tree\n");
    for (i = 0; i <= n - 1; i++)
    {
        if(t[i][0]!=t[i][1])
        printf("%d -> %d\n", t[i][0], t[i][1]);
    }
    printf("Total Cost = %d", sum);
}