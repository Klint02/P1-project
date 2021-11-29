#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define NUMBEROFNODES 5

/*MatrixShifter*/
void printMatrix(int matrix[NUMBEROFNODES][NUMBEROFNODES]);
void matrixShifter(int matrix[NUMBEROFNODES][NUMBEROFNODES]);
void shiftMatrixLeft(int matrix[NUMBEROFNODES][NUMBEROFNODES]);
void copyArray(int matrix[NUMBEROFNODES][NUMBEROFNODES], int holderArr[NUMBEROFNODES]);
void shiftMatrixUp(int matrix[NUMBEROFNODES][NUMBEROFNODES], int holderArr[NUMBEROFNODES]);
void printArray(int array[NUMBEROFNODES]);
/*Dijkstra*/
int findShortestUnvisited(int visited[NUMBEROFNODES], int shortestDistance[NUMBEROFNODES], int nodeParent[NUMBEROFNODES], int currentNode);
void findShortestPath(int graph[NUMBEROFNODES][NUMBEROFNODES], int positionArr[NUMBEROFNODES], int map[NUMBEROFNODES][NUMBEROFNODES],int interationCount);
void findLenghtsFromNode(int currentNode, int graph[NUMBEROFNODES][NUMBEROFNODES], int shortestDistance[NUMBEROFNODES], int nodeParent[NUMBEROFNODES]);
void printResult(int nodeParent[NUMBEROFNODES], int shortestDistance[NUMBEROFNODES], int visited[NUMBEROFNODES],int positionArr[NUMBEROFNODES]);
void getNodePlacement(int numberOfShifts, int placeArr[NUMBEROFNODES]);
int getExactNodePos(int positionArr[NUMBEROFNODES], int getPosFor);
void makeMap(int shortestDistance[], int map[NUMBEROFNODES][NUMBEROFNODES], int positionArr[NUMBEROFNODES], int iterationCount);

