#include <stdio.h>
#define IN 1
#define OUT 0

int main()
{
    int state = OUT;
    int c;
    while ((c = getchar()) != EOF)
    {
        if ((c != '\n') && (c != ' ') && (c != '\t'))
        {
            putchar(c);
        }
        else
        {
            printf("\n");
        }
    }
}