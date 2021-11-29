#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0
#define NUMBEROFNODES 10
#define routeLength 20
#define CompactnessLimit 70

/*matrixShifter.c*/
void printMatrix(int matrix[NUMBEROFNODES][NUMBEROFNODES]);
void matrixShifter(int matrix[NUMBEROFNODES][NUMBEROFNODES]);
void shiftMatrixLeft(int matrix[NUMBEROFNODES][NUMBEROFNODES]);
void copyArray(int matrix[NUMBEROFNODES][NUMBEROFNODES], int holderArr[NUMBEROFNODES]);
void shiftMatrixUp(int matrix[NUMBEROFNODES][NUMBEROFNODES], int holderArr[NUMBEROFNODES]);
void printArray(int array[NUMBEROFNODES]);
/*dijkstra.c*/
void dijkstra(int map[NUMBEROFNODES][NUMBEROFNODES], int parentsMap[NUMBEROFNODES][NUMBEROFNODES]);
int findShortestUnvisited(int visited[NUMBEROFNODES], int shortestDistance[NUMBEROFNODES], int nodeParent[NUMBEROFNODES], int currentNode);
void findShortestPath(int graph[NUMBEROFNODES][NUMBEROFNODES], int positionArr[NUMBEROFNODES], int map[NUMBEROFNODES][NUMBEROFNODES], int interationCount, int parentsMap[NUMBEROFNODES][NUMBEROFNODES]);
void findLenghtsFromNode(int currentNode, int graph[NUMBEROFNODES][NUMBEROFNODES], int shortestDistance[NUMBEROFNODES], int nodeParent[NUMBEROFNODES]);
void printResult(int nodeParent[NUMBEROFNODES], int shortestDistance[NUMBEROFNODES], int visited[NUMBEROFNODES], int positionArr[NUMBEROFNODES]);
void getNodePlacement(int numberOfShifts, int placeArr[NUMBEROFNODES]);
int getExactNodePos(int positionArr[NUMBEROFNODES], int getPosFor);
void makeMap(int shortestDistance[], int map[NUMBEROFNODES][NUMBEROFNODES], int positionArr[NUMBEROFNODES], int iterationCount, int parentMap[NUMBEROFNODES][NUMBEROFNODES], int nodeParent[NUMBEROFNODES]);
/*trashRoutePlanner.c*/
int *planFinalRoute(int finalRoute[routeLength], int *finalDistance, int *finalRouteIndex);
void segmentPlanner(int *startNode, int *endNode, int *finalRouteIndex, int parentsMap[NUMBEROFNODES][NUMBEROFNODES], int *routePointer, int *finalDistance, int map[NUMBEROFNODES][NUMBEROFNODES]);
int findClosestTrash(int map[NUMBEROFNODES][NUMBEROFNODES], int trashCompactness[NUMBEROFNODES], int node);
void collectTrash(int *finalRouteIndex, int parentsMap[NUMBEROFNODES][NUMBEROFNODES], int *routePointer, int *finalDistance, int map[NUMBEROFNODES][NUMBEROFNODES], int trashCompactness[NUMBEROFNODES]);
