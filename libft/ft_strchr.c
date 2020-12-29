/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 21:30:47 by sashin            #+#    #+#             */
/*   Updated: 2020/12/29 17:13:45 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strchr(const char *s, int c)
{
	int			idx;
	int			length;

	idx = 0;
	length = 0;
	while (s[length])
		++length;
	if (s == 0)
		return (0);
	if (c == 0)
		return (&((char *)s)[length]);
	while (s[idx])
	{
		if (s[idx] == c)
			return (&((char *)s)[idx]);
		++idx;
	}
	return (0);
}
