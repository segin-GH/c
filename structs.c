# include <cs50.h>
# include <stdio.h>
# include <string.h>

typedef struct
{
    string name;
    string number;
}
person;


int main (void)
{
    person people[2];

    people[0].name = "carter";
    people[0].number = "+1-617-495-1000";

    people[1].name = "david";
    people[1].number = "+1-949-468-2750";

    for(int i = 0 ; i < 2 ; i++)
    {
        if (strcmp(people[i].name,"david") == 0)
        {
            printf("%s\n",people[i].number);
            return 0;
        }
    }
    return 1;

}
