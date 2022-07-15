#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    char a[] = "finding";
    char b[26] = {0};

    for (i = 0; a[i] != '\0'; i++)
    {
        b[a[i] - 97]++;
    }
    for (i = 0; i < 26; i++)
    {
        if (b[i] > 1)
        {
            printf("%c ", i + 97);
            printf("%d ", b[i]);
            printf("\n");
        }
    }

    return 0;
}