#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int a[10];
    int size;
    int length;
};

void display(struct Array arr)
{
    printf("\nElements are :\n");
    for (int i = 0; i < arr.length; i++)
        printf("%d ", arr.a[i]);
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

struct Array *Union(struct Array *arr1, struct Array *arr2)
{
    int i, j, k;
    i = j = k = 0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->a[i] < arr2->a[j])
        {
            arr3->a[k++] = arr1->a[i++];
        }
        else if (arr1->a[i] > arr2->a[j])
        {
            arr3->a[k++] = arr2->a[j++];
        }
        else
        {
            arr3->a[k++] = arr1->a[i++];
            j++;
        }
    }

    for (; i < arr1->length; i++)
    {
        arr3->a[k++] = arr1->a[i];
    }
    for (; j < arr2->length; j++)
    {
        arr3->a[k++] = arr2->a[j];
    }
    arr3->length = k;
    arr3->size = 10;

    return arr3;
}


int main()
{

    struct Array arr1 = {{2, 3, 4, 15, 16}, 20, 5};
    struct Array arr2 = {{12, 15, 14, 25, 6}, 20, 5};
    struct Array *arr3;
    arr3 = Union(&arr1, &arr2);
    display(*arr3);

    return 0;
}