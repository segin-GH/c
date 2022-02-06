#include <stdio.h>
#include <cs50.h>

int main (void)
{
    int number [] = {1,5,6,3,6,7,8,9,3,5};

    for (int i = 0; i < 10; i++)
    {
        if (number[i] == 4)
        {
            printf("found.\n");
            return 0;
        }

    }

    printf("notfound.\n");
    return 1;
}
