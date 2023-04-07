#include <stdio.h>

int main()
{
    int x = 0b00101010;

    int y = x & 0b11100000;
    int z = x & 0b00011111;
    printf("%i, %i",y, z);

}