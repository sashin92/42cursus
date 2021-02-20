#include "ft_printf.h"
#include <stdio.h>

int main()
{
	int		i;
	int		a;
	int		*gos;


	printf("----------------ft_printf---------------\n");
	i = ft_printf("This is: |%.p|, %6.5%\n", gos);
	printf("return : %d\n", i);

	printf("\n\n\n------------------printf---------------\n");
	// ret = printf("this is %2147483646d", 42);
	// printf("%d\n", ret);

	a = printf("This is: |%p|, %6.5%\n", gos);
	printf("return : %d\n", a);
}
