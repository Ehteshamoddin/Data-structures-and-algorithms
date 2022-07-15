#include <stdio.h>
#include <stdlib.h>

int main()
{
    char i;
    char a[] = "welcome";
    
    int count=0;
    for (char i = 0; a[i] != '\0'; i++)
    {
        count++;
    }
    printf("%d", count);
    return 0;
}