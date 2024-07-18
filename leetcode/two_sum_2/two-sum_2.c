#include <stdio.h>
#include <stdlib.h>

int *twoSum(int *numbers, int numbersSize, int target, int *returnSize)
{
    int *arr = (int *)malloc(2 * sizeof(int));

    int left_ptr = 0;
    int right_ptr = numbersSize - 1;

    while (left_ptr < right_ptr)
    {
        printf("Left: %d, Right: %d\n", numbers[left_ptr], numbers[right_ptr]);

        if (numbers[left_ptr] + numbers[right_ptr] == target)
        {
            arr[0] = left_ptr + 1;
            arr[1] = right_ptr + 1;
            *returnSize = 2;
            return arr;
        }

        if (numbers[left_ptr] + numbers[right_ptr] > target)
        {
            printf("diff: %d > Target: %d\n", numbers[left_ptr] + numbers[right_ptr], target);
            right_ptr--;
        }

        if (numbers[left_ptr] + numbers[right_ptr] < target)
        {
            printf("diff: %d <  Target: %d\n", numbers[left_ptr] + numbers[right_ptr], target);
            left_ptr++;
        }
    }

    return arr;
}

int main(void)
{
    int numbers[] = {2, 7, 11, 15};
    int numbersSize = 4;
    int target = 9;

    int *returnSize = (int *)malloc(sizeof(int));
    int *result = twoSum(numbers, numbersSize, target, returnSize);

    printf("Result: %d %d\n", result[0], result[1]);

    return 0;
}
