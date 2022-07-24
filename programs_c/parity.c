# include <stdio.h>
# include <cs50.h>

int main (void)
{
    while(true)
    {
        int n = get_int("Enter your number : ");

            if (n % 2 == 0)
            {
                printf("even\n");
            }
            else
            {
                printf("odd\n");
            }
    }
}
