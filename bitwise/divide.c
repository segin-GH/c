#include <stdio.h>

int divide(int dividend, int divisior)
{
    int temp = dividend;
    for (int i = 0; i < divisior; i++)
    {
        temp = (temp >> 1);
        printf("temp(%i / %i): %i\n", dividend, divisior, temp);
    }
    return temp;
}

int main(void)
{
    int quoitient = divide(10, 3);
    printf("%i\n", quoitient);

    quoitient = divide(7, -3);
    printf("%i\n", quoitient);
    return 0;
}
