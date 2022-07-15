#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j;
    char a[] = "python";
    char last = ' ';

    for (i = 0; a[i] != '\0'; i++)
    {
        for (j = i + 1; a[j] != '\0'; j++)
        {
            if (a[i] == a[j])
            {
                printf("\n%c is duplicate", a[j]);
                a[j] = -1;
            }
        }
    }

    /* for (i = 0; a[i] != '\0'; i++)
    {
        for (j = i + 1; a[j] != '\0'; j++)
        {
            if (a[i] == a[j])
            {
                printf("\n%c", a[j]);
                a[j] = -1;
            }
        }
    } */

    return 0;
}