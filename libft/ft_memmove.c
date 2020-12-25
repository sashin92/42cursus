/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 16:48:33 by sashin            #+#    #+#             */
/*   Updated: 2020/12/25 22:02:52 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t			idx;

	idx = 0;
	while (idx < len)
	{
		((unsigned char*)dest)[idx] = ((unsigned char*)src)[idx];
		++idx;
	}
	return (dest);
}
