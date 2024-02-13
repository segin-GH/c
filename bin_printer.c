#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // adding this for the sleep function, because we're taking naps now

int main() {
    FILE *filePtr;
    unsigned char byte;
    int counter = 0;

    filePtr = fopen("ota.bin", "rb"); // "yourfile.bin" - hoping it's not just a diary of bad codebbb

    if (filePtr == NULL) {
        fprintf(stderr, "tried opening the void. file not found.");
        return EXIT_FAILURE;
    }

    while (fread(&byte, sizeof(byte), 1, filePtr)) {
        printf("%02x ", byte);
        counter++;

        if (counter == 16) {
            printf("\n");
            counter = 0;
        }
    }

    fclose(filePtr);
    return 0;
}

