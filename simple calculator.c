# include <stdio.h>
# include <cs50.h>

int main(void)
{
    long x = get_int("x : ");
    long y = get_int("y : ");
    long z = x + y;
    printf("z = %li\n",z);
}
