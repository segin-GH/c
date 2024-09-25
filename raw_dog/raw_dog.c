#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ESC_CHAR 0x7D
#define SOF_CHAR 0xAA
#define EOF_CHAR 0x55
#define XOR_MASK 0x20

typedef struct
{
    uint8_t  soh;
    uint8_t  ver;
    uint16_t cmd;
    uint8_t  ssoh;
    uint16_t len;
    void    *buff;
    uint32_t crc;
    uint8_t  id;
    uint8_t  eot;
} frame_frm_t;

uint8_t *rm_esc_sequence(uint8_t *data, size_t data_len)
{
    size_t i = 0, j = 0, filtered_len = 0;

    while (i < data_len)
    {
        if (data[i] == ESC_CHAR)
        {
            i += 2; // Skip escape character and the following XOR-ed byte
        }
        else
        {
            i++;
        }
        filtered_len++;
    }
    printf("Filtered length: %zu\n", filtered_len);

    // Allocate memory for filtered data with the correct size
    uint8_t *filter_data = malloc(sizeof(uint8_t) * filtered_len);
    if (!filter_data)
    {
        printf("Memory allocation failed\n");
        return NULL;
    }

    i = 0;
    printf("Filtered data: ");
    while (i < data_len)
    {
        if (data[i] == ESC_CHAR) // If escape character is detected
        {
            i++;                                     // Skip the escape character
            filter_data[j++] = (data[i] ^ XOR_MASK); // Apply XOR mask and store result
            printf("%02x", filter_data[j - 1]);      // Print the unescaped byte
            i++;
        }
        else
        {
            filter_data[j++] = data[i++];       // Copy non-escaped byte
            printf("%02x", filter_data[j - 1]); // Print the byte
        }
    }
    printf("\n");

    return filter_data; // Return the filtered data
}

int main(void)
{
    uint8_t mock_data[] = {0xAA, 0x01, 0x7D, 0x8A, 0x00, 0x01, 0x04, 0x00, 0x7D, 0x8A, 0x7D,
                           0x75, 0x7D, 0x5D, 0x30, 0xFF, 0x00, 0x00, 0x00, 0x7D, 0x8A, 0x55};
    // uint8_t mock_data[] = {0xAA, 0x7d, 0x8a, 0x55};

    uint8_t *filter_data = rm_esc_sequence(mock_data, sizeof(mock_data) / sizeof(uint8_t));

    int i = 0;
    printf("Filtered daaf: ");
    while (i < 17)
    {
        printf("%02x", filter_data[i]);
        i++;
    }
    printf("\n");

    // Create an instance of frame_frm_t
    frame_frm_t frame = {0};

    // Fill the structure
    frame.soh  = filter_data[0];                         // 1 byte
    frame.ver  = filter_data[1];                         // 1 byte
    frame.cmd  = (filter_data[2] << 8) | filter_data[3]; // 2 bytes
    frame.ssoh = filter_data[4];                         // 1 byte
    frame.len  = (filter_data[5] << 8) | filter_data[6]; // 2 bytes

    // Allocate memory for buff and copy data (if necessary, you can adjust based on your needs)
    frame.buff = malloc(frame.len);
    memcpy(frame.buff, &filter_data[7], frame.len); // Copy 'len' bytes into buff

    // Fill remaining fields
    frame.crc = (filter_data[7 + frame.len] << 24) | (filter_data[8 + frame.len] << 16) |
                (filter_data[9 + frame.len] << 8) | filter_data[10 + frame.len]; // 4 bytes

    frame.id  = filter_data[11 + frame.len]; // 1 byte
    frame.eot = filter_data[12 + frame.len]; // 1 byte

    // Debug print the filled structure
    printf("Frame contents:\n");
    printf("SOH:  0x%02X\n", frame.soh);
    printf("VER:  0x%02X\n", frame.ver);
    printf("CMD:  0x%04X\n", frame.cmd);
    printf("SSOH: 0x%02X\n", frame.ssoh);
    printf("LEN:  0x%04X\n", frame.len);
    printf("LEN:  0x%04X\n", frame.len);
    printf("CRC:  0x%08X\n", frame.crc);
    printf("ID:   0x%02X\n", frame.id);
    printf("EOT:  0x%02X\n", frame.eot);

    // Free allocated memory

    free(frame.buff);
}
