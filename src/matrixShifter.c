#include "trashLib.h"

//This function shifts the whole matrix appropriately so the next node is now the starting node.
void matrixShifter(int matrix[NUMBEROFNODES][NUMBEROFNODES])
{
    int holderArr[NUMBEROFNODES];
    shiftMatrixLeft(matrix);
    copyArray(matrix, holderArr);
    shiftMatrixUp(matrix, holderArr);
}

//Move all collums to the left in the matrix, collums at the start moves to the end.
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

//Copies first array in matrix
void copyArray(int matrix[NUMBEROFNODES][NUMBEROFNODES], int holderArr[NUMBEROFNODES])
{
    for (int i = 0; i < NUMBEROFNODES; i++)
    {
        holderArr[i] = matrix[0][i];
    }
}

//moves all arrays one row up in the matrix and paste copied array to the buttom to avoid it being overwritten
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
