#include "trashLib.h"

void matrixShifter(int matrix[NUMBEROFNODES][NUMBEROFNODES])
{
    int holderArr[NUMBEROFNODES];
    shiftMatrixLeft(matrix);
    copyArray(matrix, holderArr);
    shiftMatrixUp(matrix, holderArr);
}

void shiftMatrixLeft(int matrix[NUMBEROFNODES][NUMBEROFNODES])
{
    int holder;
    int chooser;

    for (int lodretI = 0, destination = 0; lodretI < NUMBEROFNODES; lodretI++)
    {
        holder = matrix[lodretI][destination]; //holds first index in array.

        while (destination < NUMBEROFNODES)
        {
            if (destination != NUMBEROFNODES - 1)
            {
                matrix[lodretI][destination] = matrix[lodretI][destination + 1];
            }
            else
            {
                matrix[lodretI][destination] = holder;
            }

            destination++;
        }
        destination = 0;
    }
}

void copyArray(int matrix[NUMBEROFNODES][NUMBEROFNODES], int holderArr[NUMBEROFNODES])
{
    for (int i = 0; i < NUMBEROFNODES; i++)
    {
        holderArr[i] = matrix[0][i];
    }
}

void shiftMatrixUp(int matrix[NUMBEROFNODES][NUMBEROFNODES], int holderArr[NUMBEROFNODES])
{

    for (int i = 0; i < NUMBEROFNODES; i++)
    {
        for (int j = 0; j < NUMBEROFNODES; j++)
        {
            matrix[i][j] = matrix[i + 1][j];
        }
    }

    for (int i = 0; i < NUMBEROFNODES; i++)
    {
        matrix[NUMBEROFNODES - 1][i] = holderArr[i];
    }
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

void printArray(int array[NUMBEROFNODES])
{
    for (int i = 0; i < NUMBEROFNODES; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}