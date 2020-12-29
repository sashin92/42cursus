/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 18:11:07 by sashin            #+#    #+#             */
/*   Updated: 2020/12/29 20:39:50 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*val;
	size_t	s_len;
	size_t	idx;

	s_len = 0;
	idx = 0;
	while (s[s_len])
		++s_len;
	if (s_len < start)
	{
		if (!(val = (char *)malloc(sizeof(char))))
			return (0);
		val[0] = 0;
	}
	else
	{
		if (!(val = (char *)malloc(sizeof(char) * (len + 1))))
			return (0);
		while (idx < len && s[start + idx])
		{
			val[idx] = s[start + idx];
			++idx;
		}
		val[idx] = 0;
	}
	return (val);
}
