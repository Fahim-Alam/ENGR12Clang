#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
    int A[2][2]; // create a 2x2 matrix A

    // ask the user to enter the elements of matrix A
    printf("Enter the elements of matrix A:\n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("Enter Element in ROW=[%d], COL=[%d]: ", i, j);
            scanf("%d", &A[i][j]);
        }
    }

    // print the elements of matrix A
    printf("You have entered the following elements for Matrix A:\n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%d\n", A[i][j]);
        }
    }

    return 0;
}