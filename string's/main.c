# include <stdio.h>

int main (void)
{

    char *s = "HI!";                // array of char is called string;

    printf("%p\n", &s);             // " &s " -> give me the pointer addres ;   >> eg :: 0x7ffdf6f8fc10
    
    printf("%c\n", *s);            // " *s " -> give me whatever is there inside the pointers location; for eg : "H"

    printf("%s\n", s);             // just printing strings


// ... string data type ...

// typedef char *string;

//     string str;
//     str = "HI!";    
//     printf("%s\n", str);

}