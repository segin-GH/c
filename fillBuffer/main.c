#include <stdio.h>
#include <string.h>

#define BUF_SIZE 30

int main(void)
{
    char ScanString[20];
    char string[BUF_SIZE] = ""; // initialize the buffer to empty string
    int maxbufVal = BUF_SIZE - 1;
    int how_much_buf_filled = 0;

    for (;;)
    {
        printf("Enter a String: ");
        scanf("%s", ScanString);

        // Check if adding the new string will exceed buffer size
        if (strlen(string) + strlen(ScanString) > maxbufVal)
        {
            printf("Buffer full! Sending data to Uart\n");
            memset(string, 0, sizeof(string));
        }

        // Append the input string to the buffer
        strcat(string, ScanString);
        how_much_buf_filled = strlen(string);
        printf("Buffer contents: %s, size: %d\n", string, how_much_buf_filled);
    }

    return 0;
}
