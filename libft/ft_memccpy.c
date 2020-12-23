/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 16:08:42 by sashin            #+#    #+#             */
/*   Updated: 2020/12/23 16:42:14 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void			*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t		idx;

	idx = 0;
	while (idx < n)
	{
		((unsigned char*)dest)[idx] = ((unsigned char*)src)[idx];
		if (((unsigned char*)src)[idx] == c)
			break ;
		++idx;
	}
	return (dest + ((1 + idx) * sizeof(char)));
}
