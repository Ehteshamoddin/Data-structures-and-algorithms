#include <stdio.h>

void insertion(int A[], int n)
{
    int i, j, x;

    for (i = 1; i < n; i++)
    {
        j = i - 1;
        x = A[i];
        while (j > -1 && A[j] > x)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = x;
    }
}

int main()
{
    int a[] = {3, 2, 5, 4, 8, 1, 6, 9};
    int n = 8;
    insertion(a, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}