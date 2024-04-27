#include < stdio.h>
#include <string.h>
#include <time.h>

#define BUF_SIZE 30
#define TIMEOUT 1

int main(void)
{
    char ScanString[20];
    char string[BUF_SIZE] = ""; // initialize the buffer to empty string
    int maxbufVal = BUF_SIZE - 1;
    int how_much_buf_filled = 0;
    time_t startTime = time(NULL);

    for (;;)
    {
        printf("Enter a String: ");
        scanf("%s", ScanString);

        // Check if adding the new string will exceed buffer size
        if (strlen(string) + strlen(ScanString) > maxbufVal)
        {
            printf("Buffer full! Sending data to Uart\n");
            memset(string, 0, sizeof(string));
            how_much_buf_filled = 0;
            startTime = time(NULL);
        }
        else if (time(NULL) - startTime > TIMEOUT)
        {
            printf("Timeout occurred\n");
            memset(string, 0, sizeof(string));
            how_much_buf_filled = 0;
            startTime = time(NULL);
        }

        // Append the input string to the buffer
        strcat(string, ScanString);
        how_much_buf_filled = strlen(string);
        printf("Buffer contents: %s, size: %d\n", string, how_much_buf_filled);
    }

    return 0;
}
