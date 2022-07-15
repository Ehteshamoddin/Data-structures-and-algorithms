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

// Method 1
void duplicate(struct Array *arr)
{
    int lastduplicate = 0;
    /* for (int i = 0; i < arr->length; i++)
    {
        if (arr->a[i] == arr->a[i + 1] && arr->a[i] != lastduplicate)
        {
            printf("\n%d ", arr->a[i]);
            lastduplicate = arr->a[i];
        }
    } */

    for (int i = 0; i < arr->length; i++)
    {
        for (int j = i + 1; j < arr->length; j++)
        {
            /* if (arr->a[i] == arr->a[j] && arr->a[i] != lastduplicate)
                printf("\n%d ", arr->a[j]);
            lastduplicate = arr->a[i]; */
            if (arr->a[i] == arr->a[j] && arr->a[i] != lastduplicate)
            {
                printf("\n%d ", arr->a[j]);
                lastduplicate = arr->a[i];
            }
        }
    }
}

void count_duplicate(struct Array *arr)
{
    int j = 0;
    for (int i = 0; i < arr->length - 1; i++)
    {
        if (arr->a[i] == arr->a[i + 1])
        {
            j = i + 1;
            while (arr->a[j] == arr->a[i])
            {
                j++;
            }
            printf("\n%d is apearing %d times ", arr->a[i], j - i);
            i = j - 1;
        }
    }
}

// Method 2
void duplicate_hash(struct Array arr)
{
    struct Array arr1 = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 25, 21};
    for (int i = 0; i < arr.length; i++)
    {
        arr1.a[arr.a[i]]++;
    }
    for (int i = 0; i <= arr1.length; i++)
    {
        if (arr1.a[i] > 1)
        {
            printf("\n%d is repeated %d times", i, arr1.a[i]);
        }
    }
}

int main()
{

    struct Array arr = {{3, 6, 8, 8, 10, 12, 15, 15, 15, 20}, 20, 10};
    display(arr);
    duplicate(&arr);
    count_duplicate(&arr);
    duplicate_hash(arr);

    return 0;
}