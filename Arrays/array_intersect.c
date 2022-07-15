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

/* struct Array *intersect(struct Array *arr1, struct Array *arr2)
{
    int i, j, k;
    i = j = k = 0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->a[i] < arr2->a[j])
        {
            i++;
        }
        else if (arr1->a[i] > arr2->a[j])
        {
            j++;
        }
        else if (arr1->a[i] == arr2->a[j])
        {
            arr3->a[k++] = arr1->a[i++];
            j++;
        }
    }
    arr3->length = k;
    arr3->size = 10;

    return arr3;
} */

struct Array *intersect(struct Array *arr1, struct Array *arr2)
{
    int i, j, k;
    i = j = k = 0;

    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->a[i] < arr2->a[j])
            i++;
        else if (arr2->a[j] < arr1->a[i])
            j++;
        else if (arr1->a[i] == arr2->a[j])
        {
            arr3->a[k++] = arr1->a[i++];
            j++;
        }
    }

    arr3->length = k;
    arr3->size = 20;

    return arr3;
}

int main()
{

    /* struct Array arr1 = {{2, 3, 4, 15, 16}, 20, 5};
    struct Array arr2 = {{12, 15, 14, 25, 4}, 20, 5}; */

    struct Array arr1 = {{2, 9, 21, 28, 35}, 10, 5};
    struct Array arr2 = {{2, 3, 9, 18, 28}, 10, 5};
    struct Array *arr3;
    arr3 = intersect(&arr1, &arr2);
    display(*arr3);

    return 0;
}