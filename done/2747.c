#include <stdio.h>

void traces();

int main()
{
    int i;
    traces();
    for (i = 0; i < 5; i++)
    {
        printf("|%*c|\n", 37, ' ');
    }
    traces();

    return 0;
}

void traces()
{
    int i;
    for (i = 0; i < 39; i++)
    {
        putchar('-');
    }
    putchar('\n');
    return;
}