/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 09:34:39 by sashin            #+#    #+#             */
/*   Updated: 2020/12/26 10:11:08 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t			f_length(char const *str)
{
	size_t		length;

	length = 0;
	while (str[length])
		length++;
	return (length);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		idx;
	size_t		s1_len;
	size_t		s2_len;
	char		*ns;
	
	s1_len = f_length(s1);
	s2_len = f_length(s2);
	
	ns = malloc(sizeof(char) * (s1_len + s2_len + 1));
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
	return (ns);
}
