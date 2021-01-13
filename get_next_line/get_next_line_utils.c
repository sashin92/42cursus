/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 20:27:44 by sashin            #+#    #+#             */
/*   Updated: 2021/01/13 22:37:23 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char			*ft_strdup(const char *s1)
{
	char		*s2;
	int			length;
	int			idx;

	length = 0;
	while (s1[length])
		++length;
	if (!(s2 = (char *)malloc((length + 1) * sizeof(char))))
		return (NULL);
	idx = 0;
	while (s1[idx])
	{
		s2[idx] = s1[idx];
		++idx;
	}
	s2[idx] = '\0';
	return (s2);
}

int				ft_strlen(char const *str)
{
	int			length;

	length = 0;
	while (str[length])
		length++;
	return (length);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	int			idx;
	int			s1_len;
	int			s2_len;
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
