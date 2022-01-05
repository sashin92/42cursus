/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:49:34 by sashin            #+#    #+#             */
/*   Updated: 2021/12/14 15:39:37 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	strjoin_length(char const *str)
{
	size_t		length;

	length = 0;
	while (str[length])
		length++;
	return (length);
}

char	*ft_strnjoin(char const *s1, char const *s2, size_t s2_len)
{
	size_t		idx;
	size_t		s1_len;
	char		*ns;

	s1_len = strjoin_length(s1);
	ns = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!ns)
		return (NULL);
	idx = 0;
	while (s1[idx])
	{
		ns[idx] = s1[idx];
		++idx;
	}
	idx = 0;
	while (idx < s2_len)
	{
		ns[s1_len + idx] = s2[idx];
		++idx;
	}
	ns[s1_len + s2_len] = '\0';
	return (ns);
}
