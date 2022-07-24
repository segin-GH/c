# include <stdio.h>
# include <stdlib.h>

# include <string.h>

void copyString( char *t ,char *s );
void upperCase_string(char *_t , char *_s);


int main(void)
{
    char *s = "hi!";    
    char *t = malloc(strlen(s)+1);   // using function called malloc() to alocate memory

    copyString(t,s);                  // special function that copy a complete string
    printf("%s\n",t);  
    upperCase_string(t,s);          // special function that which converts the whole string to uppercase
    printf("%s\n",t);
    printf("%s\n",s);

    free(t);                        // using function called free() to free the memory

}

void upperCase_string(char *_t , char *_s)
{
    int strlength = strlen(_s);

    for (int i = 0; i < strlength; i++)
    {

        if(_s [i] >= 'a' && _s [i] <= 'z')
        {
            _t [i] = (_s [i] - 32);
        }

    }
}


void copyString( char *t ,char *s )
{
    int n = (strlen(s)+ 1);

    for (int i = 0; i < n; i++ )
    {
        t [i] = s [i];
    }
}