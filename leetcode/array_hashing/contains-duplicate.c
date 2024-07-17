#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct HashTable
{
    int *table;
    int size;
};

unsigned int hash(int key, int size)
{
    return key % size;
}

bool contains(struct HashTable *hashTable, int key)
{
    unsigned int index = hash(key, hashTable->size);
    while (hashTable->table[index] != -1)
    {
        if (hashTable->table[index] == key)
        {
            return true;
        }
        index = (index + 1) % hashTable->size;
    }
    return false;
}

void insert(struct HashTable *hashTable, int key)
{
    unsigned int index = hash(key, hashTable->size);
    while (hashTable->table[index] != -1)
    {
        index = (index + 1) % hashTable->size;
    }
    hashTable->table[index] = key;
}

bool containsDuplicate(int *nums, int numsSize)
{
    struct HashTable hashTable;
    hashTable.size = numsSize * 2;
    hashTable.table = (int *)malloc(hashTable.size * sizeof(int));
    for (int i = 0; i < hashTable.size; i++)
    {
        hashTable.table[i] = -1;
    }

    for (int i = 0; i < numsSize; i++)
    {
        if (contains(&hashTable, nums[i]))
        {
            free(hashTable.table);
            return true;
        }
        insert(&hashTable, nums[i]);
    }

    free(hashTable.table);
    return false;
}

int main()
{
    int nums[] = {1, 2, 3, 4, 5, 6, 7};
    int size = sizeof(nums) / sizeof(nums[0]);

    if (containsDuplicate(nums, size))
    {
        printf("The array contains duplicates.\n");
    }
    else
    {
        printf("The array does not contain duplicates.\n");
    }

    return 0;
}
