#include <stdio.h>
#include <stdlib.h>

int main()
{
    char i;
    char a[] = "How are you";

    int vcount = 0;
    int ccount = 0;
    for (char i = 0; a[i] != '\0'; i++)
    {
        if (a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u' || a[i] == 'A' || a[i] == 'E' || a[i] == 'I' || a[i] == 'O' || a[i] == 'U')
        {
            vcount++;
        }
        else if ((a[i] >= 65 && a[i] <= 90) || (a[i] >= 97 && a[i] <= 122))
        {
            ccount++;
        }
    }
    printf("%d", vcount);
    printf("\n%d", ccount);

    int words = 0;
    for (char i = 0; a[i] != '\0'; i++)
    {
        if (a[i] == ' ' && a[i - 1] != ' ')
        {
            words++;
        }
    }
    printf("\n%d", words + 1);
    return 0;
}