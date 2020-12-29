/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 09:34:39 by sashin            #+#    #+#             */
/*   Updated: 2020/12/29 12:34:17 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			f_strjoin_length(char const *str)
{
	size_t		length;

	length = 0;
	while (str[length])
		length++;
	return (length);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	size_t		idx;
	size_t		s1_len;
	size_t		s2_len;
	char		*ns;

	s1_len = f_strjoin_length(s1);
	s2_len = f_strjoin_length(s2);
	if (!(ns = malloc(sizeof(char) * (s1_len + s2_len + 1))))
		return (0);
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
	ns[s1_len + s2_len] = 0;
	return (ns);
}
