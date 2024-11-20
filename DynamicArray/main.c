#include <stdio.h>
#include <stdlib.h>

int main()
{
    int row,col;
    int **ptrArr;
    int val;

    printf("Enter row: ");
    scanf("%i", &row);
    printf("Enter col: ");
    scanf("%i", &col);

    ptrArr = malloc(sizeof(int*) * row);

    for(int i = 0; i < row; i++){
        ptrArr[i] = malloc(sizeof(int) * col);
    }

    for(int i = 0; i < row; i++)
    {
        for(int j =0; j < col; j++)
        {
            scanf("%d",&val);
            ptrArr[i][j] = val;
        }
    }

    for(int i = 0; i < row; i++)
    {
        for(int j =0; j < col; j++)
        {
           printf("%d ",ptrArr[i][j]);
        }
        printf("\n");

    }
    return 0;
}

///2- try dynamic allocation for Array
/// of pointers to integers read and write

/// enter size
///
