/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 10:05:27 by sashin            #+#    #+#             */
/*   Updated: 2021/01/06 14:35:45 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
** - ft_strchr() search c(converted to a char) in string s
** during n bytes.(ascending index)
** - if find c, return a pointer to the byte located, else return NULL.
** - if c is '\0', ft_strchr() locate the terminating '\0'.
*/

char			*ft_strchr(const char *s, int c)
{
	int			idx;
	int			length;

	idx = 0;
	length = 0;
	while (s[length])
		++length;
	if (c == 0)
		return (&((char *)s)[length]);
	while (s[idx])
	{
		if (s[idx] == c)
			return (&((char *)s)[idx]);
		++idx;
	}
	return (NULL);
}

/*
** - ft_strjoin() allocates (with malloc(3)) and returns a newstring,
** which is the result of the concatenation of 's1' and 's2'.
** - return the new string.  NULL if the allocation fails.
*/

size_t			ft_strlen(const char *s)
{
	size_t		length;

	length = 0;
	while (s[length])
		++length;
	return (length);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	size_t		idx;
	size_t		s1_len;
	size_t		s2_len;
	char		*ns;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (!(ns = malloc(sizeof(char) * (s1_len + s2_len + 1))))
		return (NULL);
	idx = 0;
	while (s1[idx])
	{
		ns[idx] = s1[idx];
		++idx;
	}
	idx = 0;
	while (s2[idx])
	{
		ns[s1_len + idx] = s2[idx];
		++idx;
	}
	ns[s1_len + s2_len] = '\0';
	return (ns);
}