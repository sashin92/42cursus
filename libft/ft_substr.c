/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 18:11:07 by sashin            #+#    #+#             */
/*   Updated: 2021/01/01 14:19:24 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_substr() allocates and returns a substring from the string 's'.
** The substring begins at index 'start' and is of maximum size 'len'.
** return substring. NULL if the allocation fails.
*/

static char		*substr_check_startlen(void)
{
	char		*val;

	if (!(val = (char *)malloc(sizeof(char))))
		return (NULL);
	val[0] = 0;
	return (val);
}

char			*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*val;
	size_t		s_len;
	size_t		idx;

	s_len = 0;
	idx = 0;
	while (s[s_len])
		++s_len;
	if (s_len < start)
		val = substr_check_startlen();
	else
	{
		if (!(val = (char *)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		while (idx < len && s[start + idx])
		{
			val[idx] = s[start + idx];
			++idx;
		}
		val[idx] = '\0';
	}
	return (val);
}
