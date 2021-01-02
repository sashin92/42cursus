/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 21:30:47 by sashin            #+#    #+#             */
/*   Updated: 2021/01/02 14:24:57 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
