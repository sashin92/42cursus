/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 17:21:57 by sashin            #+#    #+#             */
/*   Updated: 2020/12/25 17:28:31 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int				ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t		idx;

	idx = 0;
	while (idx < n)
	{
		if (((char*)s1)[idx] != ((char*)s2)[idx])
			return (((char*)s1)[idx] - ((char*)s2)[idx]);
		++idx;
	}
	return (0);
}
