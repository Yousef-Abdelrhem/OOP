#include <stdio.h>
#include <stdlib.h>

void Printarr(int *arr)
{
    printf("%s",arr);

}
int main()
{
    char arr[30]= "passed Array";
    Printarr(arr);
    return 0;
}


