#include <stdio.h>

int count_set_bits(int n)
{
    int count = 0;
    while (n)
    {
        count += n & 1;
        n >>= 1;
    }

    return count;
}

int count_set_bits_till_given_number(int n)
{
    int count = 0;

    for (int i = 0; i <= n; i++)
    {
        count += count_set_bits(i);
    }

    return count;
}

int main(void)
{
    int num = 10;
    printf("%i\n", count_set_bits_till_given_number(4));

    return 0;
}
