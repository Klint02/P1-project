#include <stdio.h>


#define TRUE 1
#define FALSE 0
#define NUMBEROFNODE 10

int findShortestUnvisited(int visited[NUMBEROFNODE], int shortestDistance[NUMBEROFNODE], int nodeParent[NUMBEROFNODE], int currentNode);
void findShortestPath(int graph[NUMBEROFNODE][NUMBEROFNODE]);
void findLenghtsFromNode(int currentNode, int graph[NUMBEROFNODE][NUMBEROFNODE], int shortestDistance[NUMBEROFNODE], int nodeParent[NUMBEROFNODE]);
void printResult(int nodeParent[NUMBEROFNODE], int shortestDistance[NUMBEROFNODE], int visited[NUMBEROFNODE]);

int main(void)
{

    int graph[NUMBEROFNODE][NUMBEROFNODE] = {
        /*0*/ {0, 1, 0, 2, 0, 0, 0, 0, 0, 0},
        /*1*/ {1, 0, 3, 4, 1, 0, 0, 0, 0, 0},
        /*2*/ {0, 3, 0, 3, 0, 0, 0, 0, 0, 0},
        /*3*/ {2, 4, 3, 0, 0, 0, 0, 0, 2, 0},
        /*4*/ {0, 1, 0, 0, 0, 2, 1, 0, 0, 0},
        /*5*/ {0, 0, 0, 0, 2, 0, 4, 0, 0, 0},
        /*6*/ {0, 0, 0, 0, 1, 4, 0, 0, 0, 0},
        /*7*/ {0, 0, 0, 0, 0, 0, 0, 0, 5, 1},
        /*8*/ {0, 0, 0, 2, 0, 0, 0, 5, 0, 3},
        /*9*/ {0, 0, 0, 0, 0, 0, 0, 1, 3, 0}};

    findShortestPath(graph);
    return 0;
}

void findShortestPath(int graph[NUMBEROFNODE][NUMBEROFNODE])
{
    //Node: 0-1-2-3-4

    //they are all false since they have not been visited.
    int visited[NUMBEROFNODE] = {FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE};

    //unviseted nodes have a distance of infinity since we dont know the distance. start node has a distance of 0 since that's the distance to itself.
    int shortestDistance[NUMBEROFNODE] = {0, __INT_MAX__, __INT_MAX__, __INT_MAX__, __INT_MAX__, __INT_MAX__, __INT_MAX__, __INT_MAX__, __INT_MAX__, __INT_MAX__};
    //nodeParent defines the shortes path to a node from previous node. since no parent has been found yet all a -1
    int nodeParent[NUMBEROFNODE] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    int currentNode = 0;

    for (int i = 0; i < NUMBEROFNODE; i++)
    {
        currentNode = findShortestUnvisited(visited, shortestDistance, nodeParent, currentNode);

        visited[currentNode] = TRUE;

        findLenghtsFromNode(currentNode, graph, shortestDistance, nodeParent);
    }

    printResult(nodeParent, shortestDistance, visited);
}

void findLenghtsFromNode(int currentNode, int graph[NUMBEROFNODE][NUMBEROFNODE], int shortestDistance[NUMBEROFNODE], int nodeParent[NUMBEROFNODE])
{
    //Updates all adjecent vertices (!= 0), when the new distance is shorter then the old, akkumelated from start node.
    for (int i = 0; i < NUMBEROFNODE; i++)
    {
        if (graph[currentNode][i] != 0 && shortestDistance[currentNode] + graph[currentNode][i] < shortestDistance[i])
        {
            //the new distance is equal to the weight up to current node plus the new. 
            shortestDistance[i] = shortestDistance[currentNode] + graph[currentNode][i];
            nodeParent[i] = currentNode;
        }
    }
}

int findShortestUnvisited(int visited[NUMBEROFNODE], int shortestDistance[NUMBEROFNODE], int nodeParent[NUMBEROFNODE], int currentNode)
{
    int minimum = __INT_MAX__;

    //find the shortestest path that hasent been visited for (numberOfNodes - 1).
    for (int i = 0; i < NUMBEROFNODE; i++) // from 0 to 4
    {
        //pick the node that is not visited and dosent have infinite distance aka we dont know the distance yet.
        if (visited[i] == FALSE && shortestDistance[i] < minimum)
        {
            minimum = shortestDistance[i];
            currentNode = i;
        }
    }

    return currentNode;
}

void printResult(int nodeParent[NUMBEROFNODE], int shortestDistance[NUMBEROFNODE], int visited[NUMBEROFNODE])
{
    printf("Node \n");
    for (int i = 0; i < NUMBEROFNODE; i++)
    {
        printf("%d\t", i);
    }
    printf("\n\n");

    printf("Parent \n");
    for (int i = 0; i < NUMBEROFNODE; i++)
    {
        printf("%d\t", nodeParent[i]);
    }
    printf("\n\n");

    printf("Shortest Distance \n");
    for (int i = 0; i < NUMBEROFNODE; i++)
    {
        printf("%d\t", shortestDistance[i]);
    }
    printf("\n\n");

    printf("visited \n");
    for (int i = 0; i < NUMBEROFNODE; i++)
    {
        printf("%s\t", visited[i] == 0 ? "FALSE" : "TRUE");
    }
    printf("\n\n");
}
