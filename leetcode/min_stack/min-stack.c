#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int top_elem;
    int *min_arr;
    int *arr;
} MinStack;

MinStack *minStackCreate()
{
    MinStack *stk = (MinStack *)malloc(sizeof(MinStack));
    if (!stk)
    {
        return NULL;
    }

    stk->arr = (int *)malloc(500 * sizeof(int));
    if (stk->arr)
    {
        free((void *)stk);
        return NULL;
    }

    stk->min_arr = (int *)malloc(500 * sizeof(int));
    if (stk->min_arr)
    {
        free((void *)stk);
        free((void *)stk->arr);
        return NULL;
    }

    stk->top_elem = -1;
    return stk;
}

void minStackPush(MinStack *obj, int val)
{
    if (!obj)
    {
        return;
    }

    if (obj->top_elem == -1 || obj->min_arr[obj->top_elem] > val)
    {
        obj->top_elem++;
        obj->min_arr[obj->top_elem] = val;
        obj->arr[obj->top_elem] = val;
        return;
    }

    obj->top_elem++;
    obj->min_arr[obj->top_elem] = obj->min_arr[--obj->top_elem];
    obj->arr[obj->top_elem] = val;
}

void minStackPop(MinStack *obj)
{
    if (!obj)
    {
        return;
    }

    if (obj->top_elem == -1)
    {
        return;
    }

    obj->top_elem--;
    return;
}

int minStackTop(MinStack *obj)
{
    return obj->arr[obj->top_elem];
}

int minStackGetMin(MinStack *obj)
{
    int val = obj->min_arr[obj->top_elem];
    return val;
}

void minStackFree(MinStack *obj)
{
    free(obj->arr);
    free(obj->min_arr);
    free(obj);
}

int main(void)
{
    MinStack *stk = minStackCreate();
    minStackPush(stk, -2);
    minStackPush(stk, 0);
    minStackPush(stk, -3);
    printf(" Pushed \n");

    printf("%d\n", minStackGetMin(stk));
    minStackPop(stk);
    printf("%d\n", minStackTop(stk));
    printf("%d\n", minStackGetMin(stk));
    return 0;
}
