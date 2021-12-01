#include "trashLib.h"

/*TODO: Pointer to null error: Hvis ingen node har har 70 eller over compactness. */

int main(void)
{
    int *finalRoute = NULL;
    int finalDistance = 0;
    int finalRouteIndex = 0;

    finalRoute = planFinalRoute(finalRoute, &finalDistance, &finalRouteIndex);

    if (finalRoute != NULL)
    {
        printRoute(finalRouteIndex, finalRoute, finalDistance);
    }
    else
    {
        printf("ERROR: Pointer to NULL, memory could not be reallocated.");
    }

    free(finalRoute);
    finalRoute = NULL;

    return EXIT_SUCCESS;
}

/*create route with shortest path to all trash nodes with correct trash compactness and then return to start.*/
int *planFinalRoute(int finalRoute[ROUTELENGTH], int *finalDistance, int *finalRouteIndex)
{
    int map[NUMBEROFNODES][NUMBEROFNODES] = {0};
    int parentsMap[NUMBEROFNODES][NUMBEROFNODES] = {0};
    int trashCompactness[NUMBEROFNODES] = {0};

    int truckFullness = 0;

    compactnessRandomizer(trashCompactness);
    printArray(trashCompactness);

    /*Allocates the biggest case use of memory for route array*/
    int *routePointer = (int *)calloc(sizeof(int), NUMBEROFNODES * NUMBEROFNODES);

    if (routePointer != NULL)
    {
        dijkstra(map, parentsMap);

        collectTrash(finalRouteIndex, parentsMap, routePointer, finalDistance, map, trashCompactness, &truckFullness);
    }

    /*Reallocates memory to new array size specified by finalRouteIndex*/
    routePointer = (int *)realloc((void *)routePointer, sizeof(int) * (*finalRouteIndex));

    if (routePointer != NULL)
    {
        return routePointer;
    }
    else
    {
        return NULL;
    }
}

/*Assigns random values from 0-100 to trash compactness array.*/
void compactnessRandomizer(int trashCompactness[NUMBEROFNODES])
{
    srand(time(NULL));

    for (int i = 1; i < NUMBEROFNODES; i++)
    {
        trashCompactness[i] = rand() % 100;
    }
}

/*Runs segment planner for all nodes that needs to be visited.*/
void collectTrash(int *finalRouteIndex, int parentsMap[NUMBEROFNODES][NUMBEROFNODES], int *routePointer, int *finalDistance, int map[NUMBEROFNODES][NUMBEROFNODES], int trashCompactness[NUMBEROFNODES], int *truckFullnessPtr)
{

    int currentNode = 0;
    int targetNode = __INT_MAX__;

    /*run until all trash nodes have been visited*/
    while (targetNode != 0)
    {
        targetNode = findClosestTrash(map, trashCompactness, currentNode, truckFullnessPtr);
        segmentPlanner(&currentNode, &targetNode, finalRouteIndex, parentsMap, routePointer, finalDistance, map);
    }

    /*return to node 0*/
    segmentPlanner(&currentNode, &targetNode, finalRouteIndex, parentsMap, routePointer, finalDistance, map);
}

/*Calculates best route from any node to any other node and stores route data.*/
void segmentPlanner(int *startNode, int *endNode, int *finalRouteIndex, int parentsMap[NUMBEROFNODES][NUMBEROFNODES], int *routePointer, int *finalDistance, int map[NUMBEROFNODES][NUMBEROFNODES])
{
    int currentNode = *startNode;

    while (currentNode != *endNode)
    {
        *(routePointer + *finalRouteIndex) = parentsMap[*endNode][currentNode]; /*stores route in array on the correct index.*/
        currentNode = parentsMap[*endNode][currentNode];

        *finalRouteIndex += 1; /*Keeps track of final route array length*/
    }

    *finalDistance += map[*startNode][*endNode]; /*Stores distance visited.*/
    *startNode = *endNode;
}

/*Find the closest node with a trash compactness over 69*/
int findClosestTrash(int map[NUMBEROFNODES][NUMBEROFNODES], int trashCompactness[NUMBEROFNODES], int node, int *truckFullnessPtr)
{
    int trashNode = -1;
    int currentNode = node;
    int shortestDistance = __INT_MAX__;

    printf("Truck is now %d procent full\n", *truckFullnessPtr);

    for (int i = 0; i < NUMBEROFNODES; i++)
    {
        if (trashCompactness[i] >= COMPACTNESSLIMIT && map[currentNode][i] < shortestDistance)
        {
            trashNode = i;
            shortestDistance = map[currentNode][i];
        }
    }

    if (trashNode != -1 && *truckFullnessPtr < TRUCKLIMIT) /*checks if trash node has been found and if truck is full*/
    {
        *truckFullnessPtr += 25;         /*Truck gets filled with value 25 when node is emptied*/
        trashCompactness[trashNode] = 0; /*Node is emptied*/

        printf("\n");

        printf("Going to TRASH NODE: %d\n", trashNode);

        printArray(trashCompactness);

        return trashNode;
    }
    else
    {
        return FINISH; /*no trash nodes has been found so return node 0 as next target.*/
    }
}