#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, c = 0;
    /* char a[] = "decimal";
    char b[] = "medical"; */

    // Same method also handles duplicates also like below example
    char a[] = "verbose";
    char b[] = "observe";
    int h[26] = {0};

    for (i = 0; a[i] != '\0'; i++)
    {
        h[a[i] - 97] += 1;
    }
    for (i = 0; b[i] != '\0'; i++)
    {
        h[b[i] - 97] -= 1;
    }
    for (i = 0; i < 26; i++)
    {
        c++;
    }
    if (c == 26)
    {
        printf("Anagram");
    }
    else
    {
        printf("not Anagram");
    }
    return 0;
}