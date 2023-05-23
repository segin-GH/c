#include <stdio.h>

void print_array(int array[], int size);
void swap_array_using_pointer(int *array, int size);

int main(void)
{
    int arraySize;
    printf("How many numbers do you have : ");
    scanf("%i", &arraySize);
    int array[arraySize]; // intialized a array;

    for (int i = 0; i < arraySize; i++)
    {
        int temp;
        printf("Enter your %i element : ", i);
        scanf("%i", &temp);
        array[i] = temp;
    }

    print_array(array, arraySize);
    int *p = array;                         // intitalied a pointer
    swap_array_using_pointer(p, arraySize); // swaped the array using the function call
    print_array(array, arraySize);          // printed the array
}

void print_array(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%i", array[i]);
    }
    printf("\n");
}

void swap_array_using_pointer(int *array, int size)
{
    // printf("%i\n",*p);

    int newSize = size / 2;

    for (int i = 0; i < newSize; i++)
    {
        int j = (size - 1) - i;
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}