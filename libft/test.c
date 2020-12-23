#include <stdio.h>
#include <string.h>
#include <ctype.h>

int		main()
{
	// int		 dest[7] = {1, 2, 3};
	// char	 src[50] = "what123";
	char dest[100] = "hastofmine";
	char src[100] = "1234567890";
	// char src[100] = "1234567890112";

	// printf("리턴 : %lu\n", strlcpy(dest, src, 4));
	// printf("결과 : %s\n", dest);

	// memccpy(dest, src, 'a', 50);
	
	printf("리턴값 : %s\ndest : %s\n", memccpy(dest, src, '4', 8), dest);
	// printf("%s\n", dest);

	// printf("%d\n", isalpha('G'));
	// printf("%d\n", isascii(127));
	// printf("%zu\n%s\n", strlcat(dest, src, 1), dest);

}
