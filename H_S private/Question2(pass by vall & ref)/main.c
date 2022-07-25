# include <stdio.h>

void swap(int *x, int *y);
void print(int x, int y);

int main(void)
{
    int x = 10, y = 20;     // initalized two numbers

    print(x,y);         // passing by value for printing in terminal
    swap( &x, &y);      // passing by refrence for performing swap function
    print(x,y);         // printing in terminal
}

void print(int x, int y)
{
   printf("x : %i  y : %i  \n",x,y);
}

void swap(int *x, int *y)
{
    int temp = *x;      
    *x = *y;
    *y = temp;
    
}