/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 15:55:35 by sashin            #+#    #+#             */
/*   Updated: 2020/12/29 17:16:36 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strrchr(const char *s, int c)
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
	while (idx < length)
	{
		if (s[length - idx - 1] == c)
			return (&((char*)s)[length - idx - 1]);
		++idx;
	}
	return (0);
}
