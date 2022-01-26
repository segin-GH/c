# include <stdio.h>
# include <cs50.h>

float discountn (float cost, float diccount);

int main()
{
    float cost = get_float ("what is the cost ?");
    float discount = get_float ("percentage of discount :  ");
    float ans = discountn(cost,discount);
    printf("ans = %f,\n",ans);
}

float discountn (float cost, float discount)
{
    float ans = cost * discount / 100;
    ans = cost - ans;
    return ans ;

}
