#include "trashLib.h"

/*Prints all array results for dijkstra calculations*/
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

    printf("visited \n");
    for (int i = 0; i < NUMBEROFNODES; i++)
    {
        printf("%s\t", visited[i] == 0 ? "FALSE" : "TRUE");
    }
    printf("\n\n");
}

/*Prints the final calculated route.*/
void printRoute(int finalRouteIndex, int *finalRouteArray, int finalDistance)
{
    printf("ROUTE:");
    printf("0->");
    for (int i = 0; i < finalRouteIndex; i++)
    {
        printf("%d->", finalRouteArray[i]);
    }
    printf("END\n");

    printf("\nFinal distance: %d\n", finalDistance);
}

void printMatrix(int matrix[NUMBEROFNODES][NUMBEROFNODES])
{
    printf("\n");
    for (int i = 0; i < NUMBEROFNODES; i++)
    {
        for (int j = 0; j < NUMBEROFNODES; j++)
        {
            printf("%d  ", matrix[i][j]);
        }
        printf("\n");
    }
}

/*prints array with the length of "number of nodes"*/
void printArray(int array[NUMBEROFNODES])
{
    for (int i = 0; i < NUMBEROFNODES; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}