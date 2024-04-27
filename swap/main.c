#include <stdio.h>
// # include <stdlib.h>

void swap(int *x, int *y);

int main(void)
{
    int x = 10, y = 20;

    printf("%i  %i  \n", x, y);

    swap(&x, &y); // passing by refrence

    printf("%i  %i  \n", x, y);
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
