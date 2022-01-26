# include <stdio.h>
# include <cs50.h>

int main()
{
    float cost = get_float ("what is the cost ?");
    float discount = get_float ("percentage of discount :  ");
    float ans = cost * discount / 100;
    
    printf("dicount price = %f,\n",cost - ans);
}
