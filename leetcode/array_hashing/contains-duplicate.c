#include <stdbool.h>
#include <stdio.h>

bool containsDuplicate(int *nums, int numsSize)
{
    for (int i = 0; i < numsSize; i++)
    {
        int itr = i;
        int val = nums[i];

        for (int j = 0; j < numsSize; j++)
        {
            if (itr == j)
                continue;

            if (val == nums[j])
            {
                return true;
            }
        }
    }

    return false;
}

int main(void)
{
    int nums[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(nums) / sizeof(nums[0]);

    bool ret = containsDuplicate(nums, n);
    if (ret)
        printf("Contains duplicate\n");
    else
        printf("Does not contain duplicate\n");

    return 0;
}
