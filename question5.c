//Write a program to multiply two matrices. Before multiplication, verify whether the given matrices are compatible.

#include <stdio.h>
#define n 50

int main()
{
    int a[n][n], b[n][n], c[n][n];
    int r1, c1, r2, c2;
    int i, j, k, sum;

    printf("Enter the number of rows and columns of first matrix: ");
    scanf("%d%d", &r1, &c1);

    printf("Enter the number of rows and columns of second matrix: ");
    scanf("%d%d", &r2, &c2);

    if (c1 != r2)
    {
        printf("Matrices are not compatible for multiplication.\n");
        return 0;
    }

    printf("Enter the elements of first matrix:\n");
    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c1; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter the elements of second matrix:\n");
    for (i = 0; i < r2; i++)
    {
        for (j = 0; j < c2; j++)
        {
            scanf("%d", &b[i][j]);
        }
    }

    // Matrix multiplication
    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c2; j++)
        {
            sum = 0;
            for (k = 0; k < c1; k++)
            {
                sum += a[i][k] * b[k][j];
            }
            c[i][j] = sum;
        }
    }

    printf("Resultant matrix after multiplication:\n");
    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c2; j++)
        {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    return 0;
}
