#include <stdio.h>

int visited[20], adj[20][20], n;

// DFS function
void dfs(int v)
{
    int i;

    printf("%d ", v);      // Step 1: Visit the vertex
    visited[v] = 1;        // Step 2: Mark it as visited

    for (i = 0; i < n; i++) // Step 3: Check all adjacent vertices
    {
        if (adj[v][i] == 1 && visited[i] == 0)
        {
            dfs(i);        // Step 4: Go deeper (recursive call)
        }
    }
}

int main()
{
    int i, j, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    for (i = 0; i < n; i++)
        visited[i] = 0;    // Step 5: Initialize visited array

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("DFS traversal: ");
    dfs(start);            // Step 6: Start DFS

    return 0;
}
