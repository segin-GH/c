#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DELIMITER "," // Fixed delimiter

// Function to parse a string into tokens and add them to an array up to the given size
int parseStringToArray(const char *input, size_t inputSize, char *tokens[], int arraySize)
{
    char buffer[512]; // Temporary buffer to hold the input string

    // Ensure the input size does not exceed the buffer size
    if (inputSize >= sizeof(buffer))
    {
        fprintf(stderr, "Input size exceeds buffer capacity.\n");
        return 0;
    }

    // Copy the input string to the buffer with safety
    strncpy(buffer, input, inputSize);
    buffer[inputSize] = '\0'; // Null-terminate the buffer

    int count = 0;
    char *token = strtok(buffer, DELIMITER);
    while (token != NULL && count < arraySize)
    {
        tokens[count++] = strdup(token); // Duplicate token and store in the array
        token = strtok(NULL, DELIMITER);
    }

    return count; // Return the number of tokens added to the array
}

int main()
{
    const char *input = "apple,banana,carrot,dog"; // Input string
    size_t inputSize = strlen(input);              // Calculate the size of the input
    int arraySize = 3;                             // Maximum size of the array
    char *tokens[arraySize];                       // Array to store tokens

    // Parse the string
    int tokenCount = parseStringToArray(input, inputSize, tokens, arraySize);

    // Print the tokens
    printf("Parsed tokens (up to array size):\n");
    for (int i = 0; i < tokenCount; i++)
    {
        printf("%s\n", tokens[i]);
        free(tokens[i]); // Free the duplicated token
    }

    return 0;
}
