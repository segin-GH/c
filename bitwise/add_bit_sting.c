#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    const char *str1 = "1100011";
    const char *str2 = "0000001";
    const char *str2 = "1100100";

    char ans[7] = {0};

    int carry = 0;

    for (int i = (strlen(str1) - 1); i >= 0; i--)
    {
        int f_bit = (str1[i] - '0');
        int s_bit = (str2[i] - '0');

        int sum = (f_bit ^ s_bit ^ carry) + '0';

        ans[i] = sum;

        carry = (f_bit & s_bit) | (s_bit & carry) | (f_bit & carry);
    }

    if (carry)
    {
        ans[0] = '1';
        printf("carry: %d\n", carry);
    }

    printf("Sum: %s\n", ans);
}
