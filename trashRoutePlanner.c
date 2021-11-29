#include "trashLib.h"

int main(void)
{
    int *finalRoute;
    int finalDistance = 0;
    int finalRouteIndex = 0;
    finalRoute = planFinalRoute(finalRoute, &finalDistance, &finalRouteIndex);

    printf("ROUTE:");
    for (int i = 0; i < finalRouteIndex; i++)
    {
        printf("%d->", finalRoute[i]);
    }
    printf("END\n");

    printf("\nFinal distance: %d\n", finalDistance);

    free(finalRoute);
    return EXIT_SUCCESS;
}

int *planFinalRoute(int finalRoute[routeLength], int *finalDistance, int *finalRouteIndex)
{
    int map[NUMBEROFNODES][NUMBEROFNODES] = {0};
    int parentsMap[NUMBEROFNODES][NUMBEROFNODES] = {0};
    int trashCompactness[NUMBEROFNODES] = {0, 70, 60, 70, 60};

    int *routePointer = (int *)calloc(sizeof(int), NUMBEROFNODES * NUMBEROFNODES);
    dijkstra(map, parentsMap);

    int currentNode = 6;

    int targetNode = 7;

    printMatrix(map);

    printMatrix(parentsMap);

    segmentPlanner(currentNode, targetNode, finalRouteIndex, parentsMap, routePointer, finalDistance, map);

    routePointer = (int *)realloc((void *)routePointer, sizeof(int) * (*finalRouteIndex));
    return routePointer;
}

void segmentPlanner(int startNode, int endNode, int *finalRouteIndex, int parentsMap[NUMBEROFNODES][NUMBEROFNODES], int *routePointer, int *finalDistance, int map[NUMBEROFNODES][NUMBEROFNODES])
{

    int currentNode = startNode;
    *(routePointer + *finalRouteIndex) = currentNode;
    *finalRouteIndex += 1;
    while (currentNode != endNode)
    {
        *(routePointer + *finalRouteIndex) = parentsMap[endNode][currentNode];
        currentNode = parentsMap[endNode][currentNode];
        *finalRouteIndex += 1;
    }

    *finalDistance += map[startNode][endNode];
}

/* Array med hvilke noder der er over 70 (trashCompactness)

1. Prompt for startnode / Sæt startnode
2. Søg efter den node der er over 70, som er tættest på startnoden
3. Find distancen
4. Brug parentMap arrayet til at finde den hurtigste vej
5. Sæt vejen ind i final_array og at noden er blevet tømt (Sæt til 0 i array med noder over 70) + tilføj distancen til int med distance i alt
6. Søg igen efter den næste noder der er over 70, ved den nuværende node, som er tættest på startnoden
7. Repeat  */