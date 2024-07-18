#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
    qsort(nums, numsSize, sizeof(int), cmp);

    int *arr = (int *)malloc(sizeof(int) * 2);

    for (int i = 0; i < numsSize; i++)
    {
        for (int j = i + 1; i < numsSize; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                arr[0] = i;
                arr[1] = j;
                *returnSize = 2;

                printf("arr[0] = %d, arr[1] = %d\n", arr[0], arr[1]);
                return arr;
            }
        }
    }

    *returnSize = 0;
    return arr;
}

int main(void)
{

    int nums[] = {2, 7, 11, 15};
    int target = 9;

    int returnSize;
    int *result = twoSum(nums, 4, target, &returnSize);

    printf("result[0] = %d, result[1] = %d\n", result[0], result[1]);

    int nums2[] = {3, 2, 3};
    int target2 = 6;

    int returnSize2;
    int *result2 = twoSum(nums2, 3, target2, &returnSize2);

    printf("result2[0] = %d, result2[1] = %d\n", result2[0], result2[1]);

    return 0;
}
