#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool isPalindrome(char *s)
{
    if (!s)
    {
        return false;
    }
    printf("String: %s\n", s);

    int left_ptr = 0;
    int right_ptr = (strlen(s) - 1);

    while (left_ptr < right_ptr)
    {
        while (left_ptr < right_ptr && !isalnum(s[left_ptr]))
        {
            left_ptr++;
        }

        while (right_ptr > left_ptr && !isalnum(s[right_ptr]))
        {
            right_ptr--;
        }

        if (tolower(s[left_ptr]) != tolower(s[right_ptr]))
        {
            printf("left_ptr: %c != right_ptr: %c\n", s[left_ptr], s[right_ptr]);
            return false;
        }
        else
        {
            printf("left_ptr: %c == right_ptr: %c\n", s[left_ptr], s[right_ptr]);
        }

        left_ptr++;
        right_ptr--;
    }

    return true;
}

int main(void)
{
    char *str1 = "A man, a plan, a canal: Panama";
    char *str2 = "race a car";
    char *str3 = "0P";
    char *str4 = " ";

    if (isPalindrome(str1))
    {
        printf("String is palindrome\n");
    }
    else
    {
        printf("String is not palindrome\n");
    }

    if (isPalindrome(str2))
    {
        printf("String is palindrome\n");
    }
    else
    {
        printf("String is not palindrome\n");
    }
    //
    // if (isPalindrome(str3))
    // {
    //     printf("String is palindrome\n");
    // }
    // else
    // {
    //     printf("String is not palindrome\n");
    // }
    //
    // if (isPalindrome(str4))
    // {
    //     printf("String is palindrome\n");
    // }
    // else
    // {
    //     printf("String is not palindrome\n");
    // }

    return 0;
}
