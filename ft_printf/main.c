#include "ft_printf.h"
#include <stdio.h>

int main()
{
	int		i;
	int		a;

	printf("----------------ft_printf---------------\n");
	i = ft_printf("This is: |%8d|\n", -42);
	printf("return : %d\n", i);

	printf("\n\n\n------------------printf---------------\n");
	// ret = printf("this is %2147483646d", 42);
	// printf("%d\n", ret);

	a = printf("This is: |%08d|\n", 42);
	printf("return : %d\n", a);
}
