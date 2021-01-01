/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 17:13:34 by sashin            #+#    #+#             */
/*   Updated: 2021/01/01 13:02:17 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**  ft_memchr() search c(converted to an unsigned char) in string s
** during n bytes.(ascending index)
**  if find c, return a pointer to the byte located, else return NULL.
*/

void			*ft_memchr(const void *s, int c, size_t n)
{
	size_t		idx;

	idx = 0;
	while (idx < n)
	{
		if (((char *)s)[idx] == c)
			return ((char *)s + idx);
		++idx;
	}
	return (NULL);
}
