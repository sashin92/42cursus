#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int		main()
{
	char	a[100] = "abbde";
	char	*pt;

	pt = memchr(a, 'b', 2);
	printf("%s\n", pt);

}
