#include <stdio.h>

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void selection(int A[], int n)
{
    int i, j, k;
    for (i = 0; i < n - 1; i++)
    {
        for (j = k = i; j < n; j++)
        {
            if (A[j] < A[k])   
            {
                k = j;
            }
        }
        swap(&A[i], &A[k]);
    }
}

int main()
{
    int a[] = {3, 2, 5, 4, 8, 1, 6, 9};
    int n = 8;
    selection(a, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}