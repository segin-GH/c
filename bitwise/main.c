#include <stdbool.h>
#include <stdio.h>

bool get_bit(int num, int i)
{
    int mask = 1 << i;    // 0000 0001 -> 0000 0010
    int val = num & mask; // 1010 & 0010 = 0010
    return val != 0;      // 0010 != 0 -> true // 0000 != 0 -> false
}

bool set_bit(int num, int i)
{
    int mask = 1 << i;    //  0000 0001 << 2 = 0000 0100
    int val = num | mask; // 1010 | 0100 = 1110
    return val;
}

int clear_bit(int *num, int i)
{
    int mask = ~(1 << i);
    return *num & mask;
}

int main(void)
{
    int num = 0b1010;
    printf("%i\n", clear_bit(&num, 3));

    printf("%i", get_bit(num, 1));
    printf("%i", get_bit(num, 2));
    printf("%i", get_bit(num, 3));
    printf("%i\n", get_bit(num, 4));

    return 0;
}
