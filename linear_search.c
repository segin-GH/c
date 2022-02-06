# include <stdio.h>
# include <cs50.h>
# include <string.h>

int main(void)
{
    string names [] = {"luffy","zoro","sanji","nami","robin","ace"};

    for (int i = 0; i < 6; i++)
    {
        if( strcmp (names[i] , "ace") == 0)
        {
            printf("found\n");
            return 0;
        }

    }
    printf("notfound\n");
    return 1;
}
