/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 17:13:34 by sashin            #+#    #+#             */
/*   Updated: 2021/07/07 11:55:19 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
**  ft_memchr() search c(converted to an unsigned char) in string s
** during n bytes.(ascending index)
**  if find c, return a pointer to the byte located, else return NULL.
*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			idx;
	unsigned char	*cp_s;

	cp_s = (unsigned char *)s;
	idx = 0;
	while (idx < n)
	{
		if (cp_s[idx] == (unsigned char)c)
			return (cp_s + idx);
		++idx;
	}
	return (NULL);
}
