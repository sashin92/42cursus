#include <stdio.h>

int		ft_strlcpy(char *dest, const char *src, size_t size);
int		ft_isalpha(int c);
int		ft_isalnum(int c);
int		ft_strlen(const char *s);
size_t	 ft_strlcat(char *dest, const char *src, size_t destsize);



int		main()
{
	char	dest[100] = "abcdefg";
	char	src[100] = "1234";

	// printf("%d\n%s\n", ft_strlcpy(dest, src, 2), dest);
	// printf("%d\n", ft_isalpha('A'));
	printf("숫자 : %lu\n결과 : %s\n", ft_strlcat(dest, src, 1), dest);
}
