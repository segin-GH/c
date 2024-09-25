#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    uint8_t a;
    uint8_t b;
} TWO_NUMS;

TWO_NUMS num_set_1;
TWO_NUMS num_set_2;

void set_pointer_to_nums_set(int set_num, int new_num, TWO_NUMS **nums)
{
    switch (set_num)
    {
    case 1: {
        *nums = &num_set_1;
        break;
    }
    case 2: {
        *nums = &num_set_2;
        break;
    }
    default:
        break;
    }
    return;
}

int main(void)
{
    num_set_1.a = 1;
    num_set_1.b = 2;

    num_set_2.a = 3;
    num_set_2.b = 4;

    printf("%d\n", num_set_1.a);

    TWO_NUMS *nums;

    set_pointer_to_nums_set(1, 5, &nums);
    nums->a = 9;

    printf("S\n");
    printf("%d\n", num_set_1.a);
    return 0;
}
