/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 18:11:07 by sashin            #+#    #+#             */
/*   Updated: 2020/12/25 22:03:13 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*val;
	size_t	s_len;
	size_t	i;
	size_t	j;

	s_len = 0;
	i = 0;
	j = 0;
	while (s[s_len])
		++s_len;
	while (s[i])
	{
		if (s[i] == (char)start)
		{
			val = malloc((len + 1) * sizeof(char));
			while (j < len)
			{
				val[j] = s[i + j];
				++j;
			}
			return (val);
		}
		++i;
	}
	return (0);
}
