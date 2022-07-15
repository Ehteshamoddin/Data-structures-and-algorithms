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
    printf("Elements are :\n");
    for (int i = 0; i < arr.length; i++)
        printf("%d ", arr.a[i]);
}

void two_sum_sorted(struct Array *arr, int key)
{
    int i = 0;
    int j = arr->length - 1;
    // If sum is greater than k then j-- , if sum less than k then ++i
    while (i < j)
    {
        if (arr->a[i] + arr->a[j] == key)
        {
            printf("\n%d + %d = %d", arr->a[i], arr->a[j], key);
            i++;
            j--;
        }
        else if (arr->a[i] + arr->a[j] < key)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
}

int main()
{
    struct Array arr = {{6, 7, 9, 10, 12, 15}, 20, 6};
    display(arr);
    two_sum_sorted(&arr, 19);

    return 0;
}