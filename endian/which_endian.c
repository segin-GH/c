#include <stdio.h>

int main()
{
    unsigned int num = 1;
    char *byte = (char *)&num;

    if (*byte == 1)
    {
        printf("System is Little Endian\n");
    }
    else
    {
        printf("System is Big Endian\n");
    }

    return 0;
}
