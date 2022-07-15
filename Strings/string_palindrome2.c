#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j;
    char a[] = "nitin";

    for (i = 0; a[i] != '\0'; i++)
    {
    }
    for (j = 0, i = i - 1; j < i; i--, j++)
    {
        if (a[i] != a[j])
        {
            break;
        }
    }

    if (a[i] == a[j])
    {
        printf("Palindrome");
    }
    else
    {
        printf("Not Palindrome");
    }

    return 0;
}