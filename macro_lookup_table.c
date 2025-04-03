#include <stdint.h>
#include <stdio.h>
#include <time.h>

#define EVN_FORMAT_SD_START                                                                                            \
    "{\"Timestamp\":%d,\"DeviceId\":\"%s\",\"EventType\":\"DEV\",\"EventName\":\"FORMAT_SD_CARD_STATUS\",\"Value\":"   \
    "\"START\"}"
#define EVN_FORMAT_SD_DONE                                                                                             \
    "{\"Timestamp\":%d,\"DeviceId\":\"%s\",\"EventType\":\"DEV\",\"EventName\":\"FORMAT_SD_CARD_STATUS\",\"Value\":"   \
    "\"DONE\"}"
#define EVN_FORMAT_SD_FAIL                                                                                             \
    "{\"Timestamp\":%d,\"DeviceId\":\"%s\",\"EventType\":\"DEV\",\"EventName\":\"FORMAT_SD_CARD_STATUS\",\"Value\":"   \
    "\"FAILED\"}"

// Mock function to return a timestamp
int get_timestamp()
{
    return (int)time(NULL); // Returns the current UNIX timestamp
}

// Mock function to return a device UUID
const char *get_device_uuid()
{
    return "123e4567-e89b-12d3-a456-426614174000"; // Example UUID
}

#define LOG_EVENT(event)                                                                                               \
    do                                                                                                                 \
    {                                                                                                                  \
        char event_buffer[256];                                                                                        \
        snprintf(event_buffer, sizeof(event_buffer), event, get_timestamp(), get_device_uuid());                       \
        printf("%s\n", event_buffer);                                                                                  \
    } while (0)

typedef struct
{
    uint16_t event_id;
    uint32_t timestamp;
} actionable_events_t;

int main()
{
    printf("Size of actionable_events_t: %lu\n", sizeof(actionable_events_t));
    LOG_EVENT(EVN_FORMAT_SD_START);
    LOG_EVENT(EVN_FORMAT_SD_DONE);
    LOG_EVENT(EVN_FORMAT_SD_FAIL);
    return 0;
}
