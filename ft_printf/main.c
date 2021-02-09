#include "ft_printf.h"
#include <stdio.h>

int main()
{
	int		i;

	printf("----------------ft_printf---------------\n");
	i = ft_printf("This is: |%2d|\n", 42);
	printf("return : %d\n", i);
}
