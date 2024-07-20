#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <uchar.h>

typedef struct
{
    int top_element;
    int max_element;
    char *array;
} Stack;

Stack *init(size_t size)
{
    Stack *stk = (Stack *)malloc(sizeof(Stack));
    if (!stk)
    {
        return NULL;
    }

    stk->array = (char *)malloc(size * sizeof(char));
    if (!stk->array)
    {
        free((void *)stk);
        return NULL;
    }

    stk->max_element = size;
    stk->top_element = -1;
    return stk;
}

bool push(Stack *stk, char s)
{
    if (!stk)
    {
        return false;
    }

    if (stk->top_element == stk->max_element - 1)
    {
        return false;
    }

    stk->top_element++;
    stk->array[stk->top_element] = s;
    return true;
}

bool pop(Stack *stk, char *s)
{
    if (!stk)
    {
        return false;
    }

    if (stk->top_element == -1)
    {
        return false;
    }

    *s = stk->array[stk->top_element];
    stk->top_element--;
    return true;
}

bool top(Stack *stk, char *s)
{
    if (!stk || !s)
    {
        return false;
    }

    if (stk->top_element == -1)
    {
        return false;
    }

    *s = stk->array[stk->top_element];
    return true;
}

bool isEmpty(Stack *stk)
{
    if (!stk)
    {
        return false;
    }

    if (stk->top_element == -1)
    {
        return true;
    }
    return false;
}

char get_opening_bracket(char k)
{
    char keys[] = {')', '}', ']'};
    char values[] = {'(', '{', '['};

    for (int i = 0; i < 3; i++)
    {
        if (keys[i] == k)
        {
            return values[i];
        }
    }
    return '\0';
}

bool isValid(char *s)
{
    if (!s)
    {
        return false;
    }
    int str_len = strlen(s);

    Stack *stack = init(str_len);
    char *val = malloc(sizeof(char));

    int i = 0;
    while (i < str_len)
    {
        int temp = s[i];
        if (temp == '(' || temp == '{' || temp == '[')
        {
            i++;
            push(stack, temp);
            continue;
        }

        if (temp == ')' || temp == '}' || temp == ']')
        {
            if (!pop(stack, val))
            {
                return false;
            }
            printf("pop=%c\n", temp);

            char open_bracket = get_opening_bracket(temp);
            if (*val != open_bracket)
            {
                return false;
            }

            printf("%c == %c \n", *val, open_bracket);
            i++;
            continue;
        }
    }

    if (isEmpty(stack))
    {
        return true;
    }

    return false;
}

int main(void)
{
    char *s = "()[]{}";
    char *s_1 = "(]";

    if (isValid(s))
    {
        printf("Valid parenteses\n");
    }
    else
    {
        printf("Not Valid parenteses\n");
    }

    return 0;
}
