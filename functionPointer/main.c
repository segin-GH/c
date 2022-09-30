# include <stdio.h>
# include <stdlib.h>

int sum(int a ,int b)
{
	return(a+b);
}


int main(void)
{
	printf(" : %i\n",sum(5,5));
	int (*ptr)(int, int);
	ptr = &sum;
	int d = (*ptr)(4,8);
	printf("::%i\n",d);
	return 0;
}
