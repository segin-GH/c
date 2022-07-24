# include <stdio.h>
# include <cs50.h>

int main (void)
{
    int n = get_int("enter number of subjects : ");

    float scores [n];
    float ans = 0;

    for (int i = 0; i < n; i++)
    {
         scores[i] = get_int("enter your scores : ");

    }

    for (int j = 0; j < n; j++)
    {
        ans = ans + scores[j];

    }

    printf("%f\n",ans /3.0);

}
