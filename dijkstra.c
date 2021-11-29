#include "matrixShifter.h"

int main(void)
{

    int graph[NUMBEROFNODES][NUMBEROFNODES] = {{0, 1, 8, 0, 0},
                                               {1, 0, 3, 5, 9},
                                               {8, 3, 0, 1, 0},
                                               {0, 5, 1, 0, 2},
                                               {0, 9, 0, 2, 0}};
    int map[NUMBEROFNODES][NUMBEROFNODES] = {0};

    /*
                                               {0, 1, 4, 5, 7}
                                               {1, 0, 3, 4, 6}
                                               {4, 3, 0, 1, 3}
                                               {5, 4, 1, 0, 2}
                                               {7, 6, 3, 2, 0}

                                               
                                               
                                               
                                               */

    int positionArr[NUMBEROFNODES] = {0, 1, 2, 3, 4};

    for (int i = 0; i < NUMBEROFNODES; i++)
    {
        findShortestPath(graph, positionArr, map, i);
        matrixShifter(graph);
        getNodePlacement(1, positionArr);
    }

    printMatrix(map);

    return 0;
}

void getNodePlacement(int numberOfShifts, int positionArr[NUMBEROFNODES])
{
    int holder;
    for (int count = 1; count <= numberOfShifts; count++)
    {
        holder = positionArr[0];
        for (int i = 0; i < NUMBEROFNODES; i++)
        {

            positionArr[i] = positionArr[i + 1];
        }
        positionArr[NUMBEROFNODES - 1] = holder;
    }

    printf("0 is now node: %d\n", positionArr[0]);
    printf("1 is now node: %d\n", positionArr[1]);
    printf("2 is now node: %d\n", positionArr[2]);
    printf("3 is now node: %d\n", positionArr[3]);
    printf("4 is now node: %d\n", positionArr[4]);
}

int getExactNodePos(int positionArr[NUMBEROFNODES], int getPosFor)
{
    int value = positionArr[getPosFor];
    return value;
}

void findShortestPath(int graph[NUMBEROFNODES][NUMBEROFNODES], int positionArr[NUMBEROFNODES], int map[NUMBEROFNODES][NUMBEROFNODES],int interationCount)
{

    //they are all false since they have not been visited.
    int visited[NUMBEROFNODES] = {FALSE};

    //unviseted nodes have a distance of infinity since we dont know the distance. start node has a distance of 0 since that's the distance to itself.
    int shortestDistance[NUMBEROFNODES];

    for (int i = 0; i < NUMBEROFNODES; i++)
    {
        shortestDistance[i] = __INT_MAX__;
    }

    //nodeParent defines the shortes path to a node from previous node. since no parent has been found yet all a -1
    int nodeParent[NUMBEROFNODES] = {0};

    int trashCompactness[NUMBEROFNODES] = {0};

    int finalRoute[20] = {0};

    shortestDistance[0] = 0;
    trashCompactness[0] = 0;

    int currentNode = 0;

    for (int i = 0; i < NUMBEROFNODES; i++)
    {
        currentNode = findShortestUnvisited(visited, shortestDistance, nodeParent, currentNode);

        visited[currentNode] = TRUE;
        trashCompactness[currentNode] = 0;

        findLenghtsFromNode(currentNode, graph, shortestDistance, nodeParent);
    }

    makeMap(shortestDistance, map, positionArr,interationCount);

    printResult(nodeParent, shortestDistance, visited, positionArr);
}

void makeMap(int shortestDistance[], int map[NUMBEROFNODES][NUMBEROFNODES], int positionArr[NUMBEROFNODES], int iterationCount)
{
    for (int i = 0; i < NUMBEROFNODES; i++)
    {
        map[iterationCount][getExactNodePos(positionArr,i)] = shortestDistance[i];
    }
}

void findLenghtsFromNode(int currentNode, int graph[NUMBEROFNODES][NUMBEROFNODES], int shortestDistance[NUMBEROFNODES], int nodeParent[NUMBEROFNODES])
{
    //Updates all adjecent vertices (!= 0), when the new distance is shorter then the old, akkumelated from start node.
    for (int i = 0; i < NUMBEROFNODES; i++)
    {
        if (graph[currentNode][i] != 0 && shortestDistance[currentNode] + graph[currentNode][i] < shortestDistance[i])
        {
            //the new distance is equal to the weight up to current node plus the new.
            shortestDistance[i] = shortestDistance[currentNode] + graph[currentNode][i];
            nodeParent[i] = currentNode;
        }
    }
}

int findShortestUnvisited(int visited[NUMBEROFNODES], int shortestDistance[NUMBEROFNODES], int nodeParent[NUMBEROFNODES], int currentNode)
{
    int minimum = __INT_MAX__;

    //find the shortestest path that hasent been visited for (numberOfNodes - 1).
    for (int i = 0; i < NUMBEROFNODES; i++) // from 0 to 4
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

void printResult(int nodeParent[NUMBEROFNODES], int shortestDistance[NUMBEROFNODES], int visited[NUMBEROFNODES], int positionArr[NUMBEROFNODES])
{

    printf("Node \n");
    for (int i = 0; i < NUMBEROFNODES; i++)
    {
        printf("%d\t", positionArr[i]);
    }
    printf("\n\n");

    printf("Parent \n");
    for (int i = 0; i < NUMBEROFNODES; i++)
    {
        printf("%d\t", getExactNodePos(positionArr, nodeParent[i]));
    }
    printf("\n\n");

    printf("Shortest Distance \n");
    for (int i = 0; i < NUMBEROFNODES; i++)
    {
        printf("%d\t", shortestDistance[i]);
    }
    printf("\n\n");

    /*
    printf("visited \n");
    for (int i = 0; i < NUMBEROFNODES; i++)
    {
        printf("%s\t", visited[i] == 0 ? "FALSE" : "TRUE");
    }
    printf("\n\n");
    */
}