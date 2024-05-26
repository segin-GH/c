#include <stdio.h>

int main()
{
    int array_of_numbers[] = {1, 2, 3, 4, 5, 6, 7, 8};

    for (int i = 0; i < 8; i++)
    {
        printf("%i\n", *(array_of_numbers + i));
    }
}
