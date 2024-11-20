#include <stdio.h>
#include <stdlib.h>

int main()
{
    int _size =0;
    printf("Enter the Size: ");
    scanf("%d",&_size);

    int *ptr = malloc(_size * sizeof(int));
    int num;
    for(int i = 0; i < _size; i++)
    {
        printf("Enter the number %d = ",i);
        scanf("%d",&num);
        ptr[i] = num;
    }

    for(int i = 0 ;i < _size;i++)
    {
        printf("%d ", ptr[i]);
    }

    printf("\n");

    /// way 2
    for(int i = 0; i < _size; i++)
    {
        printf("Way 2 Enter the number %d = ",i);
        scanf("%d",&num);
        *(ptr + i) = num;
    }

    for(int i = 0; i < _size; i++)
    {
        printf("%d ", *(ptr + i));
    }

    return 0;
}

/// way one using [] br
