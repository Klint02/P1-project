#include "trashLib.h"

void dijkstra(int map[NUMBEROFNODES][NUMBEROFNODES], int parentsMap[NUMBEROFNODES][NUMBEROFNODES])
{
    //Data representing nodes and their connection.
    int graph[NUMBEROFNODES][NUMBEROFNODES] = {/*     0  1  2  3  4  5  6  7  8  9*/
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

    int positionArr[NUMBEROFNODES] = {0}; //keeps track of nodes posistions when matrix is shifted.

    for (int i = 0; i < NUMBEROFNODES; i++) //asigns nodes their number according to the number of nodes.
    {
        positionArr[i] = i;
    }

    //Finds shortest path from every node to every node.
    for (int i = 0; i < NUMBEROFNODES; i++)
    {
        findShortestPath(graph, positionArr, map, i, parentsMap); //finds shortest path to every node from starting node.
        matrixShifter(graph);                                     //shifts matrix by one so the next node is now the starting node.
        getNodePlacement(1, positionArr);                         //shifts posistions array by one to keep track of node placement.
    }
}

//Gets node placement according to number of shifts done.
void getNodePlacement(int numberOfShifts, int positionArr[NUMBEROFNODES])
{
    int holder;
    //Shifts all nodes by one to the left according to how many shifts have been done on matrix.
    for (int count = 1; count <= numberOfShifts; count++)
    {
        holder = positionArr[0];
        for (int i = 0; i < NUMBEROFNODES; i++)
        {

            positionArr[i] = positionArr[i + 1];
        }
        positionArr[NUMBEROFNODES - 1] = holder;
    }
}

//Returns correct node placement in shifted posistion array
int getExactNodePos(int positionArr[NUMBEROFNODES], int getPosFor)
{
    int value = positionArr[getPosFor];
    return value;
}

//Calculates shortest path to every node according to start node by using a variation of dijkstras algorithm.
void findShortestPath(int graph[NUMBEROFNODES][NUMBEROFNODES], int positionArr[NUMBEROFNODES], int map[NUMBEROFNODES][NUMBEROFNODES], int interationCount, int parentsMap[NUMBEROFNODES][NUMBEROFNODES])
{

    //they are all false since they have not been visited.
    int visited[NUMBEROFNODES] = {FALSE};

    int shortestDistance[NUMBEROFNODES];

    //unviseted nodes have a distance of infinity since we dont know the distance.
    for (int i = 0; i < NUMBEROFNODES; i++)
    {
        shortestDistance[i] = __INT_MAX__;
    }

    //start node has a distance of 0 since that is the distance to itself.
    shortestDistance[0] = 0;

    //nodeParent defines the shortes path to a node from previous node. since no parent has been found yet all is 0
    int nodeParent[NUMBEROFNODES] = {0};

    int currentNode = 0;

    //runs until shortest route to every node has been calculated.
    for (int i = 0; i < NUMBEROFNODES; i++)
    {
        currentNode = findShortestUnvisited(visited, shortestDistance, nodeParent, currentNode);

        visited[currentNode] = TRUE;

        findLenghtsFromNode(currentNode, graph, shortestDistance, nodeParent);
    }

    makeMap(shortestDistance, map, positionArr, interationCount, parentsMap, nodeParent);
}

//make new matrix with absolute shortest distances to every node
void makeMap(int shortestDistance[], int map[NUMBEROFNODES][NUMBEROFNODES], int positionArr[NUMBEROFNODES], int iterationCount, int parentMap[NUMBEROFNODES][NUMBEROFNODES], int nodeParent[NUMBEROFNODES])
{
    for (int i = 0; i < NUMBEROFNODES; i++)
    {
        map[iterationCount][getExactNodePos(positionArr, i)] = shortestDistance[i];
        parentMap[iterationCount][getExactNodePos(positionArr, i)] = getExactNodePos(positionArr, nodeParent[i]);
    }
}

//updates parent and shortest distance array
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
    for (int i = 0; i < NUMBEROFNODES; i++)
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
