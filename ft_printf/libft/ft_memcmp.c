/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 17:21:57 by sashin            #+#    #+#             */
/*   Updated: 2021/01/01 12:19:13 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_memcmp() compares s1 against s2 during n bytes.
** if find diff, differing s1 & s2 (s1 - s2) at differenced location.
*/

int				ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t		idx;

	idx = 0;
	while (idx < n)
	{
		if (((unsigned char *)s1)[idx] != ((unsigned char *)s2)[idx])
			return (((unsigned char *)s1)[idx] - ((unsigned char *)s2)[idx]);
		++idx;
	}
	return (0);
}
