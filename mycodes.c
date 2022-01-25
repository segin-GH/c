# include <stdio.h>
# include <cs50.h>

int main ()
{
    string answer = get_string ("what is your name? ");
    printf("hello,%s\n",answer);
    return 0;
}

