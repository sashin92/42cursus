/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 16:08:42 by sashin            #+#    #+#             */
/*   Updated: 2021/07/07 11:55:17 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
** ft_memccpy() copies n bytes from src to dest during find c in src.
** c is converted to an unsigned char.
** if find c, return dest[location c] after copy of c.
** else, return NULL pointer.
** dst & src overlap behavior is undefined.
*/

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t		idx;

	if (!dest && !src)
		return (NULL);
	idx = 0;
	while (idx < n)
	{
		((unsigned char *)dest)[idx] = ((unsigned char *)src)[idx];
		if (((unsigned char *)src)[idx] == (unsigned char)c)
			break ;
		++idx;
	}
	if (idx == n)
		return (NULL);
	return (dest + idx + 1);
}
