#include <stdio.h>
#define R 6
#define C 7
int matrix[R][C] =
{
        {1,1,1,1,1,1,1},
        {1,1,0,1,1,1,1},
        {0,1,0,1,1,0,1},
        {1,1,1,1,1,0,1},
        {1,0,0,0,0,1,1},
        {0,1,0,0,0,1,1},
};
int resultMatrix[R][C] =
{
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0},
};
void printPathSolution()
{
    int i, j;
    for (i = 0;i < R;i++)
    {
        for (j = 0;j < C;j++)
        {
            printf("%d\t", resultMatrix[i][j]);
        }
        printf("\n\n");
    }
}

void printMatrix()
{
    int i, j;
    for (i = 0;i < R;i++)
    {
        for (j = 0;j < C;j++)
        {

            printf("%d\t", matrix[i][j]);
        }
        printf("\n\n");
    }

}
int findpath(int r, int c)
{
    if ((r == R - 1) && (c == C - 1))
    {
        resultMatrix[r][c] = 1;
        return 1;
    }
    if (r >= 0 && c >= 0 && r < R && c < C && resultMatrix[r][c] == 0 && matrix[r][c] == 1)
    {
        resultMatrix[r][c] = 1;
        if (findpath(r + 1, c))
            return 1;
        if (findpath(r, c + 1))
            return 1;
        if (findpath(r - 1, c))
            return 1;
        if (findpath(r, c - 1))
            return 1;
        resultMatrix[r][c] = 0;
        return 0;
    }
    return 0;
}
int main()
{

    printf("\t||*||\t GIVEN MATRIX\t||*||\n\n");
    printMatrix();
    printf("\n\n\n");

    if (findpath(0, 0)) {
        printf("\t||*||\t SOLUTION OF PATH\t||*||\n\n");
        printPathSolution();
    }

    else
        printf("\tBooo!!!There is no path to walk...\n\tYou should check the MATRIX again...\n");
    return 0;
}