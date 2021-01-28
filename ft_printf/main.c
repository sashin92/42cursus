

#include "ft_printf.h"
#include <stdio.h>

int main()
{
	int		i;

	i = ft_printf("idontknow 왜about %c%c%d\n", 48, 'g', 500);

	printf("왜%c\n", 48);
}