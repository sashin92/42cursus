/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 15:55:35 by sashin            #+#    #+#             */
/*   Updated: 2021/12/23 09:32:36 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/*
** - ft_strrchr() search c(converted to a char) in string s
** during n bytes.(decending index)
** - if find c, return a pointer to the byte located, else return NULL.
** - if c is '\0', ft_strrchr() locate the terminating '\0'.
*/

char	*ft_strrchr(const char *s, int c)
{
	int			idx;
	int			length;

	idx = 0;
	length = 0;
	while (s[length])
		++length;
	if (c == 0)
		return (&((char *)s)[length]);
	while (idx < length)
	{
		if (s[length - idx - 1] == c)
			return (&((char *)s)[length - idx - 1]);
		++idx;
	}
	return (NULL);
}
