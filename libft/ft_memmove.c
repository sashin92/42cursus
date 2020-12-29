/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 16:48:33 by sashin            #+#    #+#             */
/*   Updated: 2020/12/29 17:04:03 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t			idx;
	unsigned char	temp[len];

	idx = 0;
	while (idx < len)
	{
		temp[idx] = ((unsigned char *)src)[idx];
		++idx;
	}
	idx = 0;
	while (idx < len)
	{
		((unsigned char *)dest)[idx] = temp[idx];
		++idx;
	}
	return (dest);
}
