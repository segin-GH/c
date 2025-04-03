#include <stdio.h>

// Macro to convert month name to month number
#define MONTH_TO_NUM(M)                                                                                                \
    (((M)[0] == 'J' && (M)[1] == 'a') ? 1 : /* Jan */                                                                  \
         ((M)[0] == 'F') ? 2                                                                                           \
                         : /* Feb */                                                                                   \
         ((M)[0] == 'M' && (M)[2] == 'r') ? 3                                                                          \
                                          : /* Mar */                                                                  \
         ((M)[0] == 'A' && (M)[1] == 'p') ? 4                                                                          \
                                          : /* Apr */                                                                  \
         ((M)[0] == 'M' && (M)[2] == 'y') ? 5                                                                          \
                                          : /* May */                                                                  \
         ((M)[0] == 'J' && (M)[2] == 'n') ? 6                                                                          \
                                          : /* Jun */                                                                  \
         ((M)[0] == 'J' && (M)[2] == 'l') ? 7                                                                          \
                                          : /* Jul */                                                                  \
         ((M)[0] == 'A' && (M)[1] == 'u') ? 8                                                                          \
                                          : /* Aug */                                                                  \
         ((M)[0] == 'S') ? 9                                                                                           \
                         : /* Sep */                                                                                   \
         ((M)[0] == 'O') ? 10                                                                                          \
                         : /* Oct */                                                                                   \
         ((M)[0] == 'N') ? 11                                                                                          \
                         : /* Nov */                                                                                   \
         ((M)[0] == 'D') ? 12                                                                                          \
                         : /* Dec */                                                                                   \
         0)

// Macro to calculate epoch time
#define EPOCH_TIME(YEAR, MONTH, DAY, HOUR, MIN, SEC)                                                                   \
    ((((YEAR)-1970) * 365 * 24 * 60 * 60) + (((MONTH)-1) * 30 * 24 * 60 * 60) + (((DAY)-1) * 24 * 60 * 60) +           \
     ((HOUR)*60 * 60) + ((MIN)*60) + (SEC))

// Extract components from __DATE__ and __TIME__
#define COMPILE_YEAR                                                                                                   \
    (__DATE__[7] - '0') * 1000 + (__DATE__[8] - '0') * 100 + (__DATE__[9] - '0') * 10 + (__DATE__[10] - '0')
#define COMPILE_MONTH MONTH_TO_NUM(__DATE__)
#define COMPILE_DAY (__DATE__[4] == ' ' ? (__DATE__[5] - '0') : ((__DATE__[4] - '0') * 10 + (__DATE__[5] - '0')))
#define COMPILE_HOUR ((__TIME__[0] - '0') * 10 + (__TIME__[1] - '0'))
#define COMPILE_MIN ((__TIME__[3] - '0') * 10 + (__TIME__[4] - '0'))
#define COMPILE_SEC ((__TIME__[6] - '0') * 10 + (__TIME__[7] - '0'))

// Final epoch timestamp
#define COMPILE_EPOCH EPOCH_TIME(COMPILE_YEAR, COMPILE_MONTH, COMPILE_DAY, COMPILE_HOUR, COMPILE_MIN, COMPILE_SEC)

int main()
{
    printf("Compile time epoch: %ld\n", (long)COMPILE_EPOCH);
    return 0;
}
