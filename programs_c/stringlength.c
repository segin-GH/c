# include <stdio.h>
# include <cs50.h>

int string_length (string s);

int main (void)
{
    string name = get_string("Name : ");
   int ans = string_length(name);
     printf("%i\n",ans);
}

int string_length (string s)
{

    int i = 0;
    while (s[i] != '\0')
    {
        i++;

    }

   return i;
}
