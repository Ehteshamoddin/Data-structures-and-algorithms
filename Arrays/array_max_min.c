#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int a[100];
    int size;
    int length;
};

void display(struct Array arr)
{
    printf("Elements are :\n");
    for (int i = 0; i < arr.length; i++)
        printf("%d ", arr.a[i]);
}

// Finding maximum and minimum in single scan
void min_max(struct Array arr)
{
    int min, max;
    min = max = arr.a[0];
    for (int i = 1; i < arr.length; i++)
    {
        if (arr.a[i] < min)
        {
            min = arr.a[i];
        }
        if (arr.a[i] > max)
        {
            max = arr.a[i];
        }
    }
    printf("\n%d is minimum and %d is maximum",min,max);
}
int main()
{

    struct Array arr = {{5, 8, 3, 9, 6, 2, 10, 7, -1, 4}, 20, 10};
    display(arr);
    min_max(arr);

    return 0;
}