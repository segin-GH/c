# include <stdio.h>
# include <cs50.h>

int main()
{
    float cost = get_float ("what is the cost ?");
    float discount = get_float ("percentage of discount :  ");
    float ans = cost*discount;
            ans = ans / 100;
             ans = cost - ans;
    printf("dicount price = %f,\n",ans);
}
