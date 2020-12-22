#include <stdio.h>
#include <string.h>
#include <ctype.h>

int		main()
{
	char dest[50] = "abcde";
	char src[50] = "1234";
	// char dest[100] = "hastofmine";
	// char src[100] = "1234567890112";

	// printf("리턴 : %lu\n", strlcpy(dest, src, 4));
	// printf("결과 : %s\n", dest);

	

	// printf("%d\n", isalpha('G'));
	// printf("%d\n", isascii(127));
	printf("%zu\n%s\n", strlcat(dest, src, 1), dest);

}
