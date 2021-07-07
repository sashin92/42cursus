/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 16:48:33 by sashin            #+#    #+#             */
/*   Updated: 2021/07/07 11:55:27 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
**  ft_memmove() copies len bytes from src to dest.
** dst & src overlap behavior is defined.(line 36 ~ 43)
** resturn dest.
*/

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t			idx;

	if (!dest && !src)
		return (NULL);
	idx = 0;
	if (dest < src)
	{
		while (idx < len)
		{
			((unsigned char *)dest)[idx] = ((unsigned char *)src)[idx];
			++idx;
		}
	}
	else
	{
		while (0 < len)
		{
			((unsigned char *)dest)[len - 1] = ((unsigned char *)src)[len - 1];
			--len;
		}
	}
	return (dest);
}
