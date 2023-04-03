#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VALUES 100 // Maximum number of values we can handle

int main()
{
    char hex_string[] = "0xff, 0x00, 0x00, 0x00";
    int values[MAX_VALUES] = {0};
    int num_values = 0;
    char *token = strtok(hex_string, ", ");

    while (token != NULL && num_values < MAX_VALUES)
    {
        values[num_values++] = (int)strtol(token, NULL, 16);
        token = strtok(NULL, ", ");
    }

    for (int i = 0; i < num_values; i++)
    {
        printf("%d ", values[i]);
    }

    return 0;
}
