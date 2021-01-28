/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 15:53:09 by sashin            #+#    #+#             */
/*   Updated: 2021/01/01 14:05:50 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**  ft_memcpy() copies n bytes from src to dest.
** dst & src overlap behavior is undefined.
** resturn dest.
*/

void			*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			idx;

	if (!dest && !src)
		return (NULL);
	idx = 0;
	while (idx < n)
	{
		((unsigned char *)dest)[idx] = ((unsigned char *)src)[idx];
		++idx;
	}
	return (dest);
}
