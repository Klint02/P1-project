#include <stdio.h>

void dijkstra(int graph[5][5]);

#define TRUE 1
#define FALSE 0

int main(void)
{

    int graph[5][5] = {{0, 1, 8, 0, 0},
                       {1, 0, 3, 5, 9},
                       {8, 3, 0, 1, 0},
                       {0, 5, 1, 0, 2},
                       {0, 9, 0, 2, 0}};

    dijkstra(graph);
    return 0;
}

int selectMinVertex(int value[5], int processed[5])
{
    int minimum = __INT_MAX__;
    int vertex;

    for (int i = 0; i < 5; ++i)
    {
        if (processed[i] == FALSE && value[i] < minimum)
        {
            vertex = i;
            minimum = value[i];
        }
    }

    return vertex;
}

void dijkstra(int graph[5][5])
{
    int parent[5] = {0, 0, 0, 0, 0};
    int value[5] = {__INT_MAX__, __INT_MAX__, __INT_MAX__, __INT_MAX__, __INT_MAX__};
    int processed[5] = {0, 0, 0, 0, 0};

    value[0] = 0;   //start node has value 0
    parent[0] = -1; //start node has no parent

    for (int i = 0; i < 5 - 1; ++i)
    {
        //select best vertex
        int U = selectMinVertex(value, processed);
        processed[U] = TRUE; // include new vertex in shortest path graph

        //relaxes adjecent vertices (not yet included in shortest path graph)
        for (int j = 0; j < 5; ++j)
        {
            if (graph[U][j] != 0 && processed[j] == FALSE && value[U] != __INT_MAX__ && (value[U] + graph[U][j] < value[j]))
            {
                value[j] = value[U] + graph[U][j];
                parent[j] = U;
            }
        }
    }

    for (int i = 1; i < 5; ++i)
    {
        printf("U->V: %d -> %d wt = %d\n", parent[i], i, graph[parent[i]][i]);
    }
}