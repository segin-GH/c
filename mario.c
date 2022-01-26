# include <stdio.h>
# include <cs50.h>

int main(void)
{
    int n;
    int m;
    do
    {
        n = get_int("width : ");
        m = get_int("height : ");

    }
    while ( n < 1 && m < 1);


    for(int i = 0; i < n; i++)
    {
        printf("\n");
        
        for (int j = 0; j < m; j++)
        {
            printf("* ");

        }

    }

    printf("\n");
}
