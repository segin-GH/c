#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b)
{
    return (*(char *)a - *(char *)b);
}

bool isAnagram(char *s, char *t)
{
    if (!s || !t)
    {
        return false;
    }

    if (strlen(s) != strlen(t))
    {
        return false;
    }

    size_t len_s = strlen(s);
    size_t len_t = strlen(t);

    qsort(s, len_s, sizeof(char), compare);
    qsort(t, len_t, sizeof(char), compare);

    for (int i = 0; i < len_s; i++)
    {
        if (s[i] != t[i])
            return false;
    }

    return true;
}

int main(void)
{

    bool ret = isAnagram("cat", "cat");
    if (!ret)
    {
        printf("Not a Anagram\n");
        return 1;
    }

    printf("Anagram\n");
    return 0;
}
