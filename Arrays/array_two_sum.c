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

void two_sum(struct Array arr, int k)
{
    for (int i = 0; i < arr.length - 1; i++)
    {
        for (int j = i + 1; j < arr.length; j++)
        {
            if (arr.a[i] + arr.a[j] == k)
            {
                printf("\n%d + %d = %d", arr.a[i], arr.a[j], k);
            }
        }
    }
}

// Two sum using hashing method
void two_sum_hash(struct Array arr, int k)
{
    struct Array arr1 = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 25, 20};
    for (int i = 0; i < arr.length; i++)
    {
        arr1.a[arr.a[i]]++;
    }

    for (int i = 0; i < arr.length - 1; i++)
    {
        if (arr1.a[k - arr.a[i]] != 0 && k - arr.a[i] >= 0)
        {
            printf("\n%d + %d = %d", arr.a[i], k - arr.a[i], k);
        }
        arr1.a[i]++;
    }
}

int main()
{

    struct Array arr = {{6, 3, 8, 8, 10, 16, 15, 15, 15, 1}, 20, 10};
    display(arr);
    two_sum_hash(arr, 14);

    return 0;
}