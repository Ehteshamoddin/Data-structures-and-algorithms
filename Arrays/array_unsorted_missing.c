#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int a[20];
    int size;
    int length;
};

void display(struct Array arr)
{
    printf("Elements are :\n");
    for (int i = 0; i < arr.length; i++)
        printf("%d ", arr.a[i]);
}

void missing_multiple(struct Array *arr, int l, int n)
{
    l=1;
    struct Array arr1 = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 25, 14};
    for (int i = 0; i < arr->length; i++)
    {
        arr1.a[arr->a[i]]++;
    }
    for (int i = l; i < 13; i++)
    {
        if (arr1.a[i] == 0)
        {
            printf("\nMissing element is: %d", i);
        }
    }
}

int main()
{

    struct Array arr = {{3, 7, 4, 9, 12, 6, 1, 11, 2, 10}, 20, 10};
    display(arr);
    missing_multiple(&arr, 6, 6);

    return 0;
}