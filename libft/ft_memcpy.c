/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 15:53:09 by sashin            #+#    #+#             */
/*   Updated: 2020/12/23 16:08:09 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void			*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		idx;

	idx = 0;
	while (idx < n)
	{
		((unsigned char*)dest)[idx] = ((unsigned char*)src)[idx];
		++idx;
	}
	return (dest);
}
