#include "ft_printf.h"
#include <stdio.h>

int main()
{
	int		i;

	i = ft_printf("Idontknow 왜about %2d, %4d\n", -123, 432);
	printf("return : %d\n", i);
}
