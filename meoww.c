# include <stdio.h>

void meow (void);

int main()
{
    meow();
}


void meow (void)
{
    for (int i = 0; i < 3; i++)
    {
        printf("meow\n");
    }
