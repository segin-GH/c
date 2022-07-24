# include <stdio.h>

int main (void)
{


    char *s = "HI!";                // array of char is called string;

    printf("%p\n", &s);             // " &s " -> give me the pointer;   >> eg :: 0x7ffdf6f8fc10
    
    printf("%c\n", *s );            // " *s " -> give me whatever is there inside the pointers location; for eg : "H"

}